#!/usr/bin/python

"""
linuxrouter.py: Example network with Linux IP router

This example converts a Node into a router using IP forwarding
already built into Linux.

The example topology creates a router and three IP subnets:

    - 192.168.1.0/24 (r0-eth1, IP: 192.168.1.1)
    - 172.16.0.0/12 (r0-eth2, IP: 172.16.0.1)
    - 10.0.0.0/8 (r0-eth3, IP: 10.0.0.1)

Each subnet consists of a single host connected to
a single switch:

    r0-eth1 - s1-eth1 - h1-eth0 (IP: 192.168.1.100)
    r0-eth2 - s2-eth1 - h2-eth0 (IP: 172.16.0.100)
    r0-eth3 - s3-eth1 - h3-eth0 (IP: 10.0.0.100)

The example relies on default routing entries that are
automatically created for each router interface, as well
as 'defaultRoute' parameters for the host interfaces.

Additional routes may be added to the router or hosts by
executing 'ip route' or 'route' commands on the router or hosts.
"""

from mininet.topo import Topo
from mininet.net import Mininet
from mininet.node import Node
from mininet.log import setLogLevel, info
from mininet.cli import CLI

class LinuxRouter( Node ):
    "A Node with IP forwarding enabled."

    def config( self, **params ):
        super( LinuxRouter, self).config( **params )
        # Enable forwarding on the router
        self.cmd( 'sysctl net.ipv4.ip_forward=1' )

    def terminate( self ):
        self.cmd( 'sysctl net.ipv4.ip_forward=0' )
        super( LinuxRouter, self ).terminate()


class NetworkTopo( Topo ):
    "A LinuxRouter connecting three IP subnets"

    def build( self, **_opts ):

        defaultIP = '192.168.1.1/24'  # IP address for r0-eth1
        router = self.addNode( 'r0', cls=LinuxRouter, ip=defaultIP )
        router1 = self.addNode( 'r1', cls=LinuxRouter, ip='192.168.4.1/24')

        s1, s2, s3, s4, s5 = [ self.addSwitch( s ) for s in ['s1', 's2', 's3','s4','s5'] ]

	#s1,s2,s3 connected to r0
        self.addLink( s1, router, intfName2='r0-eth1',
                      params2={ 'ip' : defaultIP } )  # for clarity
        self.addLink( s2, router, intfName2='r0-eth2',
                      params2={ 'ip' : '192.168.2.1/24' } )
        self.addLink( s3, router, intfName2='r0-eth3',
                      params2={ 'ip' : '192.168.3.1/24' } )

	#s4,s5 connected to r1
        self.addLink( s4, router1, intfName2='r1-eth1',
                      params2={ 'ip' : '192.168.4.1/24' } )
        self.addLink( s5, router1, intfName2='r1-eth2',
                      params2={ 'ip' : '192.168.5.1/24' } )

	#h1 in network1 (192.168.1.0) and network 4
	#h2 in network2 (192.168.2.0)
	#h3 in network3 (192.168.3.0)
	#h4 in network5
        h1 = self.addHost( 'h1', ip='192.168.1.100/24')
        h2 = self.addHost( 'h2', ip='192.168.2.100/24')
        h3 = self.addHost( 'h3', ip='192.168.3.100/24')
        h4 = self.addHost( 'h4', ip='192.168.5.100/24')
        for h, s in [ (h1, s1), (h2, s2), (h3, s3), (h4,s5)]:
            self.addLink( h, s )

        #defining new interfaces
        self.addLink( s4, h1, intfName2='h1-eth1', params2={'ip' : '192.168.4.100/24'})

def run():
    "Test linux router"
    topo = NetworkTopo()
    net = Mininet( topo=topo )  # controller is used by s1-s3
    net.start()
    
    info( '*** Routing Table on Router:\n' )
    net[ 'r0' ].cmd( 'route' )

    # Configure h1 to ip forward
    net['h1'].cmd('sysctl net.ipv4.ip_forward=1')
   
    #configure r1 to all networks via h1
    net['r1'].cmd('route add -net 192.168.1.0/24 gw 192.168.4.100 dev r1-eth1')
    net['r1'].cmd('route add -net 192.168.2.0/24 gw 192.168.4.100 dev r1-eth1')
    net['r1'].cmd('route add -net 192.168.3.0/24 gw 192.168.4.100 dev r1-eth1')

    #confiure r0 to all networks via h1
    net['r0'].cmd('route add -net 192.168.4.0/24 gw 192.168.1.100 dev r0-eth1')
    net['r0'].cmd('route add -net 192.168.5.0/24 gw 192.168.1.100 dev r0-eth1')

    #Connect h1
    net['h1'].cmd('route add -net 192.168.2.0/24 gw 192.168.1.1 dev h1-eth0')
    net['h1'].cmd('route add -net 192.168.3.0/24 gw 192.168.1.1 dev h1-eth0')
    net['h1'].cmd('route add -net 192.168.5.0/24 gw 192.168.4.1 dev h1-eth1')

    #configure h2 to all networks
    net['h2'].cmd('route add -net 192.168.1.0/24 gw 192.168.2.1 dev h2-eth0')
    net['h2'].cmd('route add -net 192.168.3.0/24 gw 192.168.2.1 dev h2-eth0')
    net['h2'].cmd('route add -net 192.168.4.0/24 gw 192.168.2.1 dev h2-eth0')
    net['h2'].cmd('route add -net 192.168.5.0/24 gw 192.168.2.1 dev h2-eth0')

    #configure h3 to all networks
    net['h3'].cmd('route add -net 192.168.1.0/24 gw 192.168.3.1 dev h3-eth0')
    net['h3'].cmd('route add -net 192.168.2.0/24 gw 192.168.3.1 dev h3-eth0')
    net['h3'].cmd('route add -net 192.168.4.0/24 gw 192.168.3.1 dev h3-eth0')
    net['h3'].cmd('route add -net 192.168.5.0/24 gw 192.168.3.1 dev h3-eth0')

    #configure h4 to all networks
    net['h4'].cmd('route add -net 192.168.1.0/24 gw 192.168.5.1 dev h4-eth0')
    net['h4'].cmd('route add -net 192.168.2.0/24 gw 192.168.5.1 dev h4-eth0')
    net['h4'].cmd('route add -net 192.168.3.0/24 gw 192.168.5.1 dev h4-eth0')
    net['h4'].cmd('route add -net 192.168.4.0/24 gw 192.168.5.1 dev h4-eth0')
    
    #pingall
    net.pingAll()
    CLI( net )
    net.stop()

if __name__ == '__main__':
    setLogLevel( 'info' )
    run()

# PRIYANSH SANGULE
# CS16B021
from mininet.net import Mininet
from mininet.node import Controller
from mininet.cli import CLI
from mininet.log import setLogLevel, info

def quizNet():
    net = Mininet(controller=Controller)
    net.addController('c0')

    #Begin EDIT
    
    #BROKER
    h1=net.addHost('h1',ip='10.0.0.1/8')
    
    h2=net.addHost('h2',ip='10.0.0.2/8')
    h3=net.addHost('h3',ip='10.0.0.3/8')    
    h4=net.addHost('h4',ip='10.0.0.4/8')
    h5=net.addHost('h5',ip='10.0.0.5/8')
    h6=net.addHost('h6',ip='10.0.0.6/8')
    
    # Publisher
    h7=net.addHost('h7',ip='10.0.0.7/8')
    #End Edit

    s1 = net.addSwitch('s1')

    net.addLink(h1,s1)
    net.addLink(h2,s1)
    net.addLink(h3,s1)
    net.addLink(h4,s1)
    net.addLink(h5,s1)
    net.addLink(h6,s1)
    net.addLink(h7,s1)
    

    net.start()
    CLI(net)
    net.stop()

if __name__ == '__main__':
    setLogLevel('info')
    quizNet()

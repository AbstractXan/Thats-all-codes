import socket

serverip = '10.0.0.2'
serverport = 1234

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
msg = "cs16b021 PRIYANSH SANGULE"

s.sendto(msg.encode(),(serverip,serverport))
print('Message Sent Successfully')

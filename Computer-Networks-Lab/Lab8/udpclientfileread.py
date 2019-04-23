import socket
import sys

print( 'IP entered: ',str(sys.argv[1]),'\nFile name to send: ', str(sys.argv[2]))
serverip = str(sys.argv[1])
serverport = 1234

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

with open(str(sys.argv[2]),"rb") as abc:
	msg = abc.read()
	#print(msg)

s.sendto(msg,(serverip,serverport))
print('File Sent Successfully')

while True:
	data, addr = s.recvfrom(1024)
	print(addr, " says: ", data)

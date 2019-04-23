import socket
import sys

print ('IP entered: ',str(sys.argv[1]),'\nFile name to writeto: ', str(sys.argv[2]))
port = 1234
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((str(sys.argv[1]),port))

print("sock is listening")
while True:
	data,addr = sock.recvfrom(1024*1024)
	#print(" recieved data is ", data)
	binary_file = open(str(sys.argv[2]),"wb")
	binary_file.write(data)
	binary_file.close()
	message="CS16B021 File Written Successfully"
	sock.sendto(message.encode(),addr)


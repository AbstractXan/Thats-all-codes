import socket

#### UDP SERVER ####
host = '10.0.0.2'
port = 1234

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((host,port))

print("Socket is listening")
data,addr = sock.recvfrom(1024)
print(" Recieved: ", data)

### TCP CLIENT ####
print(" Starting TCP Client")

HOST = '10.0.0.3'
PORT = 1234

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
	s.connect((HOST,PORT))
	msg='CS16B021 PRIYANSH SANGULE'
	s.sendall(msg.encode())

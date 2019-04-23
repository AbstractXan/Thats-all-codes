import socket

#### TCP SERVER ####
ip = "10.0.0.3"
port = 1234

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind((ip,port))
sock.listen(1)
print("Socket is listening")
conn, addr = sock.accept()

with conn:
	print('Connected by', addr)
	data  = conn.recv(1024)
	print(" recieved data is ", data.decode())
	conn.sendall(data)

### TCP CLIENT ####
with open("file.txt","rb") as abc:
	msg = abc.read()

print("Reading file successfull. Starting TCP Client.")

HOST = '10.0.0.4'
PORT = 1234

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
	s.connect((HOST,PORT))
	s.sendall(msg)

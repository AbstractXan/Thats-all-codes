import socket

#### TCP SERVER ####
ip = "10.0.0.4"
port = 1234

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind((ip,port))
sock.listen(1)
print("Socket is listening")
conn, addr = sock.accept()

with conn:
	print('Connected by', addr)
	data  = conn.recv(1024*1024)
	print(" recieved data is ", data.decode())
	binary_file = open("new.txt","wb")
	binary_file.write(data)
	binary_file.close()
	conn.sendall(data)

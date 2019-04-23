import socket
ip = "127.0.0.1"
port = 1234

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind((ip,port))
sock.listen(1)
print("sock is listening")
conn, addr = sock.accept()

with conn:
	print('Connected by', addr)
	while True:
		data  = conn.recv(1024)
		if not data:
			break
		print(" recieved data is ", data.decode())
		conn.sendall(data)

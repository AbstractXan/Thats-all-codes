#RUNS IN H2 (10.0.0.2)
import time
import paho.mqtt.client as mqtt

def on_message(clients, userdata, message):
	print("Recieved message: ", message.payload)
def on_connect(client, userdata, flags, rc):
	if rc == 0:
		global Connected
		Connected = True

Connected = False
client = mqtt.Client("AllECEsubscriber")
client.on_connect = on_connect
client.on_message = on_message
client.connect("10.0.0.1",8000)
client.loop_start()
while Connected != True:
	time.sleep(0.1)
client.subscribe("CS16B021/+/ECE")
while True:
	time.sleep(0.1)
client.disconnect()
client.loop_stop()

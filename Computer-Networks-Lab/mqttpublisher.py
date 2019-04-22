import paho.mqtt.client as mqtt

client = mqtt.Client("mymqttpublisher")
client.connect("10.0.0.1",8000)
client.publish("CS16B021/PG/ECE","PG ECE")
client.publish("CS16B021","ROLL NUM")
client.publish("CS16B021/UG/CSE","CSE")
client.publish("CS16B021/PG","PG")
client.publish("CS16B021/UG/ECE","UG ECE")




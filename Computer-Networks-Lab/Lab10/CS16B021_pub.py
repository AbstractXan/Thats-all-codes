import paho.mqtt.client as mqtt

#Publisher
client = mqtt.Client("mymqttpublisher")

#Broker at h1 (10.0.0.1,8000)
client.connect("10.0.0.1",8000)

#Publish message to any ECE
client.publish("CS16B021/PG/ECE","PG ECE")
#Publish message to CS16B021
client.publish("CS16B021","ROLL NUM")
#Publish message to any CSE
client.publish("CS16B021/UG/CSE","CSE")
#Publish message to any PG
client.publish("CS16B021/PG","PG")
#Publish message to CS16B021/UG/ECE
client.publish("CS16B021/UG/ECE","UG ECE")




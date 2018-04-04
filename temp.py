import requests as req
import json

rawrequest =req.get('https://api.github.com/search/repositories?q=language:java&sort=stars')
datajson = rawrequest.json()

with open('file.txt', 'w') as file:
     file.write(str(datajson))


temp1 = r1['items']
for i in temp1:
    print i['full_name']

import requests as req
import json
import time
import base64
import os
import datetime
import re

AheadUCT=19800 #If your Local time is ahead UCT (in sec)

curr_dir = os.getcwd();
print curr_dir

rawrequest =req.get('https://api.github.com/search/repositories?q=language:java&sort=stars')
datajson = rawrequest.json()
temp1 = datajson['items']

#Contains repos names
repos = []
#Prints and stores repositories names
for i in temp1:
    #print i['full_name']
    repos.append(i['full_name'])

#Acceses code in repository
for rep_name in repos:       
    try:
        Rep_throws=0
        Rep_catch=0
##
##        #Change directory to add codes for each repositories
        os.chdir(curr_dir)
        os.mkdir(str(rep_name).replace("/",""))
        os.chdir(curr_dir+'/'+str(rep_name).replace("/",""))
        print os.getcwd()
    except Exception as ex:
        print(str(ex))
        break
    
    try:    
        print " "
        print rep_name
        
        #Create new urls based on repo names fetched
        repos_url='https://api.github.com/search/code?q=in:file+language:java+repo:'+str(rep_name)
        repos_request = req.get(repos_url)

        while(int(repos_request.status_code)!=200):
        #    ratereq=(req.get('https://api.github.com/rate_limit') ).json()
        #    date=float(ratereq['resources']['search']['reset'])
        #    print('reset time: ', datetime.datetime.fromtimestamp(date).strftime('%Y-%m-%d %H:%M:%S'))
        #    print('curr time: ', datetime.datetime.fromtimestamp(time.time()).strftime('%Y-%m-%d %H:%M:%S'))
            
            
        #    time.sleep(date-time.time()+AheadUCT)
            time.sleep(0.5)
            repos_request = req.get(repos_url)

        print(repos_request.headers['X-RateLimit-Remaining'])
        repos_request_json = repos_request.json()    

       
        #Get new git_urls for source
        code_url_list = repos_request_json['items']
        for j in code_url_list:
            code_url=(j['git_url'])
            #print(code_url)

            code_req=req.get(code_url)
            while(int(code_req.status_code)!=200):
            #    ratereq=(req.get('https://api.github.com/rate_limit') ).json()
            #    date=float(ratereq['resources']['search']['reset'])
            #    print('reset time: ', datetime.datetime.fromtimestamp(date).strftime('%Y-%m-%d %H:%M:%S'))
            #    print('curr time: ', datetime.datetime.fromtimestamp(time.time()).strftime('%Y-%m-%d %H:%M:%S'))
            
            
            #    time.sleep(date-time.time()+AheadUCT)
                #time.sleep(0.5);
                code_req=req.get(code_url)
             
            code_request_json=code_req.json()
            code=base64.b64decode(code_request_json['content'])
            
            code_name=j['name']
            
            #Writes code files
            with open(code_name, 'w') as file:
                file.write(code)
        
            throws=[]
            catch=[]
            
            throws=re.findall(r'throws',code)
            catch=re.findall(r'catch',code)
            
            Rep_throws=Rep_throws+len(throws)
            Rep_catch=Rep_catch+len(catch)

            with open('stats', 'w') as stat:
                stat.write('Throws: '+str(Rep_throws))
                stat.write('Catches: '+str(Rep_catch))
            
    except Exception as e:
        print(str(e))
        #print (repos_request_json['message'])
        continue
    
    

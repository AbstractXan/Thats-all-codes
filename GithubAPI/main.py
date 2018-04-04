import requests as req
import json
import time

rawrequest =req.get('https://api.github.com/search/repositories?q=language:java&sort=stars')
datajson = rawrequest.json()

#Writes code files
with open('file.txt', 'w') as file:
     file.write(str(datajson))

#
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
        print " "
        print rep_name
        #Create new urls based on repo names fetched
        repos_url='https://api.github.com/search/code?q=in:file+language:java+repo:'+str(rep_name)
        repos_request = req.get(repos_url)

        while(int(repos_request.status_code)!=200):
            time.sleep(2)
            repos_request = req.get(repos_url)

        print(repos_request.headers['X-RateLimit-Remaining'])
        repos_request_json = repos_request.json()    

        #Get new git_urls for source
        code_url_list = repos_request_json['items']

        for j in code_url_list:
            print(j['git_url'])
        
    except Exception as e:
        print(str(e))
        print (repos_request_json['message'])

##        srch_wait_req=( req.get('https://api.github.com/rate_limit') ).json()
##        
##        wait_time = float(srch_wait_req['resources']['search']['reset'])
##
##        print (' Resuming time:' ,wait_time)
##        print (' Current time:', time.time())
##        wait_time = wait_time - time.time() -19800 ######GMT lag wrt location
##        print wait_time
##        if (wait_time > 0):
##            print ('Waiting for ', wait_time/(60) ,' minutes...')
##            time.wait(wait_time)
##            print ('Resuming...')
##        
##        #time.sleep(5)
        continue
    

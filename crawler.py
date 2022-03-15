import requests
from requests.packages.urllib3.exceptions import InsecureRequestWarning
from bs4 import BeautifulSoup
import sys
import os

url = "https://www.acmicpc.net/problem/" + sys.argv[2]

'''
# try to use proxy
proxy_host = "proxy.crawlera.com"
proxy_port = "8010"
proxy_auth = ":"
proxies = {
       "https": f"https://{proxy_auth}@{proxy_host}:{proxy_port}/",
       "http": f"http://{proxy_auth}@{proxy_host}:{proxy_port}/"
}

requests.packages.urllib3.disable_warnings(InsecureRequestWarning)
req = requests.get(url, proxies=proxies, verify=False)
'''
headers = {
    'accept': 'text/html',
    'accept-language': 'ko-KR,ko;',
    'sec-ch-ua': '" Not A;Brand";v="99", "Chromium";v="99", "Google Chrome";v="99"',
    'user-agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/99.0.4844.51 Safari/537.36'
}
req = requests.get(url, headers=headers)
if req.status_code != 200:
    print(f"GET request returned status code {req.status_code}")
    sys.exit(1)
soup = BeautifulSoup(req.text,"html.parser")
tags = soup.findAll('pre', attrs={'class': 'sampledata'})

for i in range(len(tags)):
    file_type = "ex_out" if i % 2 else "ex_in"
    file_number = str(i // 2 + 1)
    file_name = file_type + file_number
    #with open(os.path.join("BOJ/10998", file_name), 'w') as fp:
    with open(os.path.join(sys.argv[1], file_name), 'w') as fp:
        print(os.path.join(sys.argv[1], file_name))
        fp.write(tags[i].get_text())


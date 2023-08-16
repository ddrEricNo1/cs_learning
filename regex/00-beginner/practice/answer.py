import re, os, wget
from urllib.parse import quote

# -*- coding: UTF-8 -*-
# the URL for the website
pageUrl = "http://www.listeningexpress.com/studioclassroom/ad/"
print("Downloading the source code from the website")

# download the file
if not os.path.exists("./index.html"):
    wget.download(pageUrl, "./index.html")

with open("index.html", encoding='gbk') as f:
    content = f.read()

p = re.compile(r"javascript:p\('(.*?\.mp3)'\)")
links = p.findall(content)

downloadsPath = "Downloads/practice/"
if not os.path.exists(downloadsPath):
    os.makedirs(downloadsPath, exist_ok=True)

for link in links:
    fullAdr = pageUrl + quote(link)
    print(fullAdr)
    # wget.download(fullAdr, downloadsPath)


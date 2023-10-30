# Solution to question 6
## Question: Find an online data set. Fetch it using *curl* and extract out just two columns of numerical data. If you're fetching HTML data, **pup** may be helpful. For JSON data, try **jq**. Find the min and max of one column in a single command, and the difference of the sum of each column in another.

## **curl**
curl is a stool for transferring data from or to a server.

```shell
curl -o data.html https://stats.wikimedia.org/EN/TablesWikipediaZZ.htm#wikipedians 
cat data.html | sed -n "/table1/,/<\/table>/p" | grep "<tr" | sed "1,12d" | head -n3 |sed -E 's/(<[^>]*>)+/ /g' | sed 's/ &nbsp;/ -/g' | sed 's/&nbsp;//g' > data.txt
```

import re
import os

if __name__ == "__main__":
	file = open('./test_sed.txt')
	for line in file.readlines():
		content = str(line)
		pattern = re.compile(r'^.*Disconnected from (invalid | authenticating )?user .* [0-9]+ port [0-9]+ \[preauth\]$')
		for one in pattern.findall(line):
			print(one)

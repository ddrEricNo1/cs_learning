import re


content = """1shrrehshre
			2ljll4
			232352"""
if __name__ == '__main__':
	p = re.compile(r'^[0-9]')
	for one in p.findall(content):
		print(one)

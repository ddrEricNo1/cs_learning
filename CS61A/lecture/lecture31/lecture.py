import re
re.search('aardvark', S)	# Does S contain the subsring 'aardvark'?
re.fullmatch('[-+]?[0-7]+', S)	# Is all of s a properly formed signed octal number?
re.match(r'\s*[-+]?\d+', S)	# does s start with a decimal number, possibly preceded by whitespace? 

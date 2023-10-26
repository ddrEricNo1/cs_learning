#!/usr/bin/env python3
# shebang: provides the way that the shell will know how to run this program
# for nearly every system, a lot of binaries live in the path /usr/bin/env, it's gonna search in that path for the python binary, and then gonna uses that to interpret this file.
import sys
for arg in reversed(sys.argv[1:]):
	print(arg)


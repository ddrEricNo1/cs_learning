# One advantage of static analysis tool is that we don't need to run the codes and wait for 60 seconds for the output.

# pyflakes is a static analysis tool for python
import time

def foo():
    return 42

for foo in range(5):
    print(foo)

bar = 1
bat *= 0.2
time.sleep(60)
print(baz)

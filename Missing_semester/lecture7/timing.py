import time, random

n = random.randint(1, 10) * 100

# get the current time
start = time.time()

# do some work
print("Sleeping for {}s".format(n/1000))
time.sleep(n/1000)

print(time.time()-start)

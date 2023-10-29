#!/usr/bin/env python3
import signal, time

# this is super important which can save the current status of the program when the user types ctrl+c
def handler(signum, time):
    print("\nI got a SIGINT, but I am not stopping")

signal.signal(signal.SIGINT, handler)
i = 0
while True:
    time.sleep(1)
    print("\r{}".format(i), end="")
    i += 1


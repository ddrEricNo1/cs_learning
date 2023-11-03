# Debugging and profiling

## Debugging

### Printf debugging and Logging

1. A first approach to debug a program is to add print statements around where you have detected the problem, and keep iterating until you have extracted enough information to understand what is responsible for the issue. 

2. A second approach is to use logging in your program, instead of ad hoc print statements.

Programs like **ls** or **grep** are using ANSI escape codes, which are special sequences of characters to indicate your shellto change the color of the ouput. For example, executing the command **echo -e "\e[38;2;255;00mThis is red\e[0m"** prints the message **This is red** in red on your terminal. 

logging: create the logs and record when some things happen

Most programs write their own logs somewhere in your system. In UNIX systems, it is commonplace for programs to write their logs under **/var/log**. More recently, systems have started using a system log, which is increasingly where all of your log messages go. 

client-side error

in UNIX system, loggers are placed at **/var/log**

**lnav**: log file navigator

### Debuggers

In python, this is the python debugger **pdb**.

Here is a brief description of some of the commands **pdb** supports:

- l(ist): Displays 11 lines around the current line or continue the previous listing.

- s(tep): Execute the current line, stop at the first possible occasion.

- n(ext): continue execution until the nextline in the current function is reached or it returns.

- b(reak): set a breakpoing 

- p(rint): evaulate the expression in the current context and print its value.

- r(eturn): continue execution until the current function returns.

- q(uit): quit the debugger

### Specialized tools

Whenever the programs need to perform actions that only the kernel can, they use **system calls**. There are commands that let you trace the syscalls your program makes. In Linux there's **strace**. 

Below is an example of using **strace** to show **stat** syscall traces for an execution of **ls**. 

**strace**: system call tracer. 

A system call (syscall), is where a program crosses the boundary between user code and the kernel. The two basic jobs of a modern operating system are *abstraction* and *multiplexing*. 

**Abstraction**: For example, when your program wants to read and write to disk, it doesn't need to speak the **SATA** protocol, or **SCSI**...
It speaks in a single, commmon vocabulary of directories and files, and the opearting system translates the abstract vocabulary into whatever has to be done with the actual underlying hardware you have. 

**Multiplexing**: your programs and mine each get fair access to the hardware, and don't have the ability to step on each other - which means that your program can't be permitted to skip the kernel, and speak raw SATA or SCSI to the actual hardware, even if it wanted to.

For almost everthing a program wants to do, it needs to talk to the kernel. Want to read or write a file? Make the **open()** syscall, and then the syscalls **read()** or **write()**. Talk on the network? You need the syscalls **socket()**, **connect()** and again **read()** and **write()**. Make more processes? First **clone()** (inside the standard C library function **fork()**), then you probably want **execve()** so the new process run its own program, and you probably want to interact with that process somehow, with one of **wait4()**, **kill()**, **pipe()** and a host of others. Even looking at the clock requires a system call, **clock_gettime()**.

> stat system call: This function returns information about a file, in the buffer pointed to by **statbuf**. It retrive information about the file pointed to by *pathname*.  

```shell
# On Linux
sudo strace -e lstat ls -l > /dev/null
```

### Static Analysis tools

find the error without executing the codes
pyflakes: static analysis tool

## Profiling
Even if your code functionality behaves as you would expect, that might not be good enough if it takes all your CPU or memory in the process. 

profiling is about how to optimize the codes

### Timing

Down below is an example in Python using the **time** module.

```python
import time, random
n = random.randint(1, 10) * 100

# get current time
start = time.time()

# do some work
print("Sleeping for {} ms".format(n))
time.sleep(n/1000)

# compute time between start and now
print(time.time() - start)

# Output
# Sleeping for 500 ms
# 0.5713930...
```

Wall clock time can be misleading since your computer might be running other processes at the same time or waiting for events to happen. It is common for tools to make a distinction between *Real*, *User* and *Sys* time. In general, User + Sys tells you how much time your process actually spent in the CPU.

- *Real*: wall clock elapsed time from start to finish of the program, including the time taken by other processes and time taken while blocked(e.g., waiting for I/O or output), it is the time from start to finish of this call. 

- *User*: amount of time spent in CPU rnning user code

- *Sys*: Amount of time spent in the CPU running kernel code

### Profilers

#### CPU

There are two types of profilers:
* Tracing profilers: keep a record of every function call your program makes.

* Another type of profiler: sampling profiler. **The issue with tracing profilers is that they add a lot of overhead**. A sampling profiler is gonna execute your program and every some defined period, it's gonna stop your program and look at the stack trace and say you are right now in this point in the hierarchy, identifying which function is gonna be executing at that point. 

In python, we can use the **cProfile** module to profile time per function call.

```python
import sys, re

def grep(pattern, file):
    with open(file, 'r') as f:
        print(file)
        for i, line in enumerate(f.readlines()):
            pattern = re.compile(pattern)
            match = pattern.search(line)
            if match is not None:
                print("{}: {}".format(i, line), end="")


if __name__ == "__main__":
    times = int(sys.argv[1])
    pattern = sys.argv[2]
    for i in range(times):
        for file in sys.argv[3:]:
            grep(pattern, file)
```

We can profile this code using the following command. Analyzing the output we can see that IO is taking most of the time and that compiling the regex takes a fair amount of time as well. SInce the regex only needs to be compiled once, we can factor it out of the for. 

```shell
python -m cProfile -s tottime grep.py 1000 '^(import|\s*def)[^,]*$' *.py
```

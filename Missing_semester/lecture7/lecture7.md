# Debugging and profiling

## Debugging

logging: create the logs and record when some things happen

client-side error

in UNIX system, loggers are placed at **/var/log**

**lnav**: log file navigator

pyflakes: static analysis tool

## Profiling
profiling is about how to optimize the codes

- *Real*: wall clock elapsed time from start to finish of the program, including the time taken by other processes and time taken while blocked(e.g., waiting for I/O or output)

- *User*: amount of time spent in CPU rnning user code

- *Sys*: Amount of time spent in the CPU running kernel code

There are two types of profilers:
* Tracing profilers: execute with your codes and everytime your code enters a funciton call, they kind of take a note of it. 

* Another type of profiler: sampling profiler. **The issue with tracing profilers is that they add a lot of overhead**. A sampling profiler is gonna execute your program and every some defined period, it's gonna stop your program and look at the stack trace and say you are right now in this point in the hierarchy, identifying which function is gonna be executing at that point. 

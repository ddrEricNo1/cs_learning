# Solutions to lecture 7

## 1. Use **journalctl** on LInux or **log show** on Mac OS to getthe super user accesses and commands in the last day. If there aren'tany you can execute some harmless commands such as **sudo ls** and check again. 

```shell
journalctl | grep  sudo
```

## 2. Here are some sorting algorithm implementations. Use **cProfile** and **line_profiler** to compare the runtime of insertion sort and quicksort. What is the bottleneck of each algorithm? Use then **memory_profiler** to check the memory consumption, wht is insertion sort better? Check now the inplace version of quicksort. Chanllenge: Use **pref** to look at the cycle counts and cache hits and misses of each algorithm. 

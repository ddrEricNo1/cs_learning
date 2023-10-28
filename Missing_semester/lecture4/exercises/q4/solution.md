# The solution to Q4
## Qeustion: Find your average, median, and max system boot time over the last ten boots. Use **journalctl** ton Linux and **log show* on macOS, and look for log timestamps near the beginning and end of each boot. On Linux, they may look something like: 

> Logs begin at ...

and

> systemd[577]: Startup finished in ...

```shell
# filter the data from journalctl and store it into a txt file
# write a script to get the latest 10 boot-up time
# the following codes are stored in getlog.sh

#!/usr/bin/env zsh
for i in {0..9}; do
	journalctl -b-$i | grep -E "Startup finished in" | tee data.txt
done

# run the script and store it into a txt file named startupData.txt
```

**Get the maximum system boot time**

```shell
cat startupData.txt | grep -E "systemd\[1\]" | sed -E "s/.*=\ (.*)s\.$/\1/" | sort | tail -n1
```

**Get the minimum system boot time**

```shell
cat startupData.txt | grep -E "systemd\[1\]" | sed -E "s/.*=\ (.*)s\.$/\1/" | sort -r | tail -n1
```

**Get the average system boot time**

Here we need to use the calculator to calculate the sum of all the ten startup time and divide it by 10.
One handy calculator is to use the command **bc**, which stands for Berkeley Calculator

```shell
cat startupData.txt | grep -E "systemd\[1\]" | sed -E "s/.*=\ (.*)s\.$/\1/" | paste -sd+ | bc -l | awk '{print $1/10}'

# 这条指令中的paste -sd+是一条一条粘贴，并且用+作为分隔符，传入bc进行计算
```

For the command paste, the optionss:
* -d: delimiter, is used to reuse the characters in stead of TABs
* -s: serial, paste one file at a time instead of in parallel

**Get the median system boot time**

```shell
cat startupData.txt | grep -E "systemd\[1\]" | sed -E "s/.*=\ (.*)s\.$/\1/" | sort | paste -sd\ | awk '{print ($5+$6)/2'}
```

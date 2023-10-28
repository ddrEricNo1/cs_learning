# Solution for Question 5
## Question: Look for boot messages that *are not shared* between your paste three reboots (see *journalctl*'s *-b* flag). Break this task down into multiple steps. First, find a way to get just the logs from the paste three boots. There may be an applicable flag on the tool you use to extract the boot logs, or you can use *sed '0,/STRING/d'* to remove all lines previous to one that matches STRING. Next, remove any parts of the line that always vaires (like the timestamp). Then de-duplicate the input lines and keep a count of each one (*uniq* is your friend). And finally, eliminate any line whose count is 3 (since it was shared among all the boots).

```shell
for i in {0..2}; do
	journalctl -b-$i | grep -E "Startup finished in" > data.txt
```

```shell
cat data.txt | sed -E "s/.*pi\ (.*)/\1/" | sort | uniq -c | sort | awk '$1!=3 {print }'
```

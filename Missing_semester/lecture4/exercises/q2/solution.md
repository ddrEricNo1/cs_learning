# solution to question 2

## 1. Find the number of words (in /usr/share/dict/words) that contain at least three *a* s and don't have a 's' ending.

```shell
cat /usr/share/dict/words | tr "[:upper:]" "[:lower:]" | grep -E "^([^a]*a){3}.*$" | grep -v "s$" | wc -l
```

在字符串中查找满足出现次数的字符:

```shell
grep -E "([^a].*a){3}.*$" 
```

在字符串中查找不满足条件的字符串

```shell
# -v: invert match
# Selected lines are those not matching any of the specific patterns.
grep -v "s$"
```

## 1b). What are the three most common last two letters of those words?

```shell
cat /usr/share/dict/words | tr "[:upper:]" "[:lower:]" | grep -E "^([^a]*a){3}.*$" | grep -v "s$" | sed -E "s/.*([a-z]{2})$/\1/" | sort | uniq -c | sort | tail -n3
```

## 1c). How many of those two-letter combinations are there?

```shell
cat /usr/share/dict/words | tr"[:upper:]" "[:lower:]" | grep -E "^([^a]*a){3}.*$" | grep-v "s$" | sed -E "s/([a-z]{2})$/\1/" | sort | uniq -c | wc -l
```

## 1d). Challenge: which combinations do not occur?

```shell
# to solve this problem, firstly we need to generate all the combinations of the possibile outcomes using the shell.

# below is the script file named all.sh
#!/usr/bin/env zsh
for i in {a..z}; do
	for j in {a..z}; do
		echo "$i$j"
	done
done
```

Then store the output result into a txt file

```shell
./all.sh > all.txt
```

Then store the ground truth outcome into a file named occurance.txt

```shell
cat /usr/share/dict/words | tr "[:upper:]" "[:lower:]" ｜ grep -E "^([^a]*a){3}.*$" | grep -v “s$" | sed -E "s/.*([a-z]{2})$/\1/" | sort | uniq > occurance.txt
```

Then make the comparisions between the ground truth outcome vs. the expected using the command **diff**.

```shell
# the option --unchanged-group-format='' means to set all the same sub-strings between these two files to the null string

diff --unchanged-group-format='' <(cat occurance.txt) < (cat all.txt) | wc -l
```


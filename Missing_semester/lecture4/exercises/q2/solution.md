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


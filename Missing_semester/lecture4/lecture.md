# Data Wrangling
Explanation: have data in one format, and want it in some different formats, images, loggers

## sed
It is a stream editor, which is a modification of an earlier program called ed, it lets us make changes to the contents of the stream

> One of the most common things you do with sed is to run replacement expressions on an input stream

```shell
echo "abb" | sed 's/[ab] //'
# it will replace the first matching pattern with the given string. If want to replace all the matching patterns, add g at the end of the command.
```

# Data Wrangling
Explanation: have data in one format, and want it in some different formats, images, loggers

## sed
It is a stream editor, which is a modification of an earlier program called ed, it lets us make changes to the contents of the stream

> One of the most common things you do with sed is to run replacement expressions on an input stream

```shell
echo "abb" | sed 's/[ab] //'
# it will replace the first matching pattern with the given string. If want to replace all the matching patterns, add g at the end of the command.

```

## awk
**awk** is a column-based stream processor, more focused on column-based data. It scans each input file for lines that match any of a set of patterns specified literally inprog or in one more files specified as -f progfile. 

```shell
# it will match all the lines with the pattern that the number of occuracne is 1 and start with c, ends with e, and it will print out the entire lines
awk '$1 == 1 && $2 ~ /^c.*e$/ {print $0}
```

For example, we have a txt file containing some names here (assuming the name of the file is test.txt):

*   chinese
*   chippie
*   ciserve
*   clemente
*   clide
*   clive
*   cube
*   test
*   test

And we want to print out all the names that appear once and starting with the charcter c, and ends with e.

```shell
# it will firstly add the whole contents of the file into a stream, and then use pipeline to send it into sort, and uniq -c
# uniq -c: will count the number of occurance of each entry
# awk is good at processing column-based data. In this example, it will find all the data that the first column is 1, and for the second column, it should start with the character c and ends with the character e, then print the entire line out
cat test.txt | sort | uniq -c | awk '$1 == 1 && $2 ~ /^c.*e$/ {print $0}' 
```

Another interesting example:

```shell
# ffmpeg: used for encoding and decoding videos
# dev/video0: web cam video device
# - usually tells a program to use standard input / output rather than the files 
# gzip: used to compress the file 
# tee: reads the input, prints it to stdout and to a file
ffmpeg -loglevel panic -i /dev/video0 -frames 1 -f image2 - | convert - -colorspace gray - | gzip | ssh tsp 'gzip -d | tee copy.png' | feh -
```


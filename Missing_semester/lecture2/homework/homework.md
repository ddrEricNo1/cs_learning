# Homework

## 1. Read man ls and write an ls command that lists files in the following manner:

\- Includes all files, including hidden files

\- Sizes are listed in human readable format (e.g. 454M instead of 454279954)

\- Files are ordered by recency

\- Output is colorized

A sample output would look like this:

![截屏2023-09-17 00.33.16](/Users/eric/Desktop/截屏2023-09-17 00.33.16.png)

-a: Include directory entries whose names begin with a dot('.')

-l: list files in the long format. 

-h: When used with **-l** option, use unit suffixes: Byte, Kilobyte, Megabyte, Gigabyte, Terabyte and Petabyte in order to reduce the number of digits to four or fewer using base 2 for sizes.

-G: Enable colorized output. 

-t: Sort by descending time modified (most recently modified first).

<p style="color:red">Solution: ls -al -h -G -t</p>

## 2. Write bash functions Marco and polo that do the following. Whenever you execute marco the current working directory should be saved in some manner, then when you execute polo, no matter what directory you are in, polo should cd you back to the directory where you executed Marco. For ease of debugging you can write the code in a file macro.sh and (re)load the definitions to your shell by executing source marco.sh.

```shell
#!/bin/sh
path=($pwd)
echo "$path" > /Users/eric/Desktop/cs_learning/Missing_semester/lecture2/homework/q2/tmp_dir.txt
```

```shell
#!/bin/sh
path=$(cat < /Users/eric/Desktop/cs_learning/Missing_semester/lecture2/homework/q2/tmp_dir.txt)
cd "path"
```

上述代码中，polo的执行需要写成source polo.

原因在于：如果直接运行该脚本，会创建一个子shell，并且在子shell中逐个执行脚本中的指令；而子shell从父shell中集成了环境变量，但是执行后不会改变父shell的环境变量。而source的作用是在当前shell环境下读取并执行脚本中的命令

## 3. Say you have a command that fails rarely. In order to debug it you need to capture its output but it can be time consuming to get a failure run. Write a bash script that runs the following script and prints everything at the end. Bonus points if you can also report how many runs it took for the script to fail.

```shell
count=0
res=true
while($res==true)
do
	sh script
	if [[ $? -eq 1 ]]; then
		echo "fail at $count times"
		res=false
	fi
	let count+=1
done
```

## 4. As we covered in the lecture find's -exec can be very powerful for performing operations over the files we are searching for. However, what if we want to do something with all the files, like creating a zip file? As you have seen so far commands will take input from both arguments and STDIN. When piping commands, we are connecting STDOUT to STDIN, but some commands like tar take inputs from arguments. To bridge this disconnect there's the xargs command which will execute a command using STDIN as arguments. For example ls | xargs rm will delete the files in the current directory.

Your task is to write a command that recursively find all HTML files in the folder and make a zip with them. Note that your command should work even if the files have spaces(hint: check -d flag for xargs)

<p style="color: red">Solution: find . -name "*.html" -type f -print0 | xargs -0 tar vcf outcome.tar</p>

## 5. (Advanced) Write a command or script to recursively find the most recently modified file in a directory. More generally, can you list all files by recency? 

<p style="color:red">Solution: find . -type f -print0 | xargs -0 ls -lt | head -1</p>

find . -type f -print0: 查找当前路径下的所有文件，并将文件路径输入到standard output

xargs -0: change xargs to expect ('\0') as a separator instead of spaces and newlines.

 


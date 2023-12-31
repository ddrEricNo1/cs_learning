# lecture 2: Shell tools and scripting

1. **Shell scripting**

   To assignn variables in bash, use the syntax **foo=bar** and access the valie of the variable with **$foo**. Note that **foo = bar** will not work since it is interpreted as cakking the **foo** program with arguments **=** and **bar**. In general,  in shell scripts the space character will perform argument splitting. This behavior can be confusing to use at first. 

   Strings in bash can be defined with ' and " delimiters, but they are not equivalent. Strings delimited with ' are literal strings and will not substitutevariable values wheras " delimited strings will.

   ```shell
   foo=bat
   echo "$foo"
   # print bar
   echo '$foo'
   # print $foo
   ```

   As with most programming languages, bash supports control flow techniques including **if**, **case**, **while** and **for**. Similarlym **bash** has functions that take arguments and can operate with them. Here is an example of a function that creates a directory and **cd** into it.
   
   ```shell
   mcd() {
   	mkdir -p "$1"
   	cd "$1"
   }
   ```
   
   **$1** is the first argument to the script. 
   
   **$0**: name of the script
   
   **$1 to $9**: arugments to the script. 
   
   **$@**: all the arguments
   
   **$#**: number of arguments
   
   **$?**: return code of the previous command
   
   **$$**: process identification number(PID) for the current script
   
   **!!**: entire last command, including arguments. 常见应用：当因为权限不足执行命令失败时，使用**sudo !!**再尝试一次

   **$_**: 上一条命令的最后一个参数

1.   Another comon pattern is wanting to get the output of a command as a variable. This can be done with **command substitution**. Whenever you place **$(CMD)** it will execute **CMD**, get the output of the command and sbustitute it in place. For example, if you do **for file in $(ls)**, the shell will first call **ls** and then iterate over those values.   
2.   **process substitution**. **< (CMD)** will execute **CMD** and place the output in a temporary file and substitute the **<(CMD)** with that file's name. **diff < (ls foo) < (ls bar)** will show differences between files in dirs **foo** and **bar**.

The codes below will list out all the files in the current directory, store it in a temporary file, and do the same thing to the parent directory, and concatenate them together. 

```shell
cat < (ls) < (ls ..)
```



```shell
#!/bin/zsh
# 这段脚本会遍历我们提供的参数，使用grep搜索字符串foobar，如果没有找到，则将其作为注释追加到文件中
# date will be substituted
echo "starting program at $(date)"
echo "running program $0 with $# arguments with pid $$" 

for file in "$@"; do
	grep foobar "$file" > /dev/null 2 > /dev/null
	# when patttern is not found, grep has exit status 1
	# we redirect STDOUT and STDERR to a null register since we don't care about them
	if [[ $? -ne 0 ]]; then
		echo "File $file does not have any foobar, adding one"
		echo "# foobar" >> "$file"
	fi
done
```

​				In the comparison we tested whether **$?** was not equal to 0. When performing comparisons in bash, try to use

 			   double brackets **[[ ]]** in favour of simple brackets **[ ]**. Chances of making mistakes are lower although it won't be

​				portable to **sh**. 



​				**What is the difference between [ and [[** ?

​				The open square bracket **[** (aka **test** command) and the **[[ ... ]]** test construct are used to evaluate expressions. 				**[[ ... ]]** works only. in the Korn shell, Bash, Zsh and recent versions of Yash and busybox **sh**. **[** and **test** are POSIX 				utilities. POSIX doesn't specify the **[[ ... ]]** construct though allows shells to treat **[[** as a keyword. 

2. **Shell globbing**

   When launching scripts, you will often want to provide arguments that are similar. Bash has ways of making this easier, expanding expressions by carrying out filename expansion. These techniques are often referred to as *Shell globbing*.

   * Wildcards - Whenever you want to perform some sort of wildcard matching, you can use **?** and ***** to match one or any amount of characters respectively. For instance, given files **foo**, **foo1**, **foo2**, **foo10**, and **bar**, the command **rm foo?** will delete **foo1** and **foo2**, whereas **rm foo*** will delete all but **bar**. 
   
   * curly braces {}. Whenever you have a common substring in a series of commands, you can use curly braces for bash to ezpand this automatically. This comes in very handy when moving or converting files. 
   
     ```shell
     convert image.{png, jpg}
     # will expand to
     convert image.png image.jpg
     
     cp /path/to/project/{foo,bar,baz}.sh /newpath
     # will expand to 
     cp /path/to/project/foo.sh /path/to/project/bar.sh /path/to/project/bar.sh /newpath
     
     # globbing techniques can also be combined
     mv *{.py,.sh} folder
     # will move all *.py and *.sh files
     
     mkdir foo bar
     # this creates fiels foo/a, foo/b, ..., foo/h, bar/a, bar/b, ..., bar/h
     touch {foo,bar}/{a...h}
     
     touch foo/x bar/y
     # show differences between files in foo and bar
     diff < (ls foo) < (ls bar)
     ```
   
     
   
   

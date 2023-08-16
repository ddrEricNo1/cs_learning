# Lecture 1: Shell



1. **Connecting programs**

   In the shell, programs have two primary "streams" associated with them: their input stream and their output stream. When the program tries to read input, it reads from the input stream, and when it prints something, it prints to its output stream. Normally, a program's input and output are both the terminal. However, we can also rewire those streams. 

   The simplest form of redirection is **< file** and **> file**. These let you rewire the input and output streams of a program to a file respectively:

   ```shell
   echo hello > hello.txt
   cat hello.txt
   cat < hello.txt
   cat < hello.txt > hello2.txt
   cat hello2.txt
   ```

   The **|** operator lets you chain programs such that the output of one is the input of another:

   ```shell
   % tail is used to display tje ;ast part of a file
   ls -l / | tail -n1
   % curl: transfer data from or to server
   % grep: find patterns in files using regular expressions
   curl --head --silent google.com | grep --ignore-case		
   ```


​				**Quoting**

​				Quoting is used to remove the special meaning of certain characters or words to the shell. Quoting can beused 

​				 to disable special treatment for special characters, to prevent reservedwords from being recognized as such,

 				and to prevent parameter expansion.

​				 **Each of the shell metacharacters has special meaning to the shell and must be quoted if it is to**

​			     **represent iteself**. When the command history expansion facilities are being used, the history expansion

​				 character, usually '!', must be quoted to prevent history expansion.  

2. **Exercises**

   a. create a new directory called **missing** under **/tmp**.

   ```shell
   cd /tmp
   mkdir missing
   ```

   b. Look up the **touch ** program. The **man ** program is your friend.

   c. use **touch** to create a new file called **semester** in **missing**.

   ```shell
   cd missing
   touch semester	
   ```

   d. write the following tnto that file, one line at a time.

   ```shell
   #!/bin/zsh
   curl --head --silent https://missing.csail.mit.edu
   ```

   ```shell
   # !即使被双引号包裹也具有特殊的含义
   echo '#!/bin/zsh' > semester
   echo 'curl --head --silent https://missing.csail.mit.edu' >> semester
   ```

   e. Try to execute the file, i.e. type the path to the script (./semester) into your shell and press enter. Understand why it doesn't work by sonsulting the output of  **ls**. (Hint: look at the permission bits of the file)

   ```shell
   # we cannot execute the file. The error is 'Permission denied: ./semester'
   # Here I use ls -al to check the permission bits of the file, and the output is:
   # drwxr-xr-x .
   # drwxrwxrwt ..
   # -rw-r--r-- semester
   ```

   f. run the command by explicitly starting the **sh** interpreter, and giving it the file **semester** as the first argument, i.e. **sh semester**. Why does this work, while **./semester** didn't?

   **Answer: **calling **sh semester**, the file **semester** is passed as an argument to the **sh** program, which will interpret this file. Even though we don't have permission to run **semester**, we do are allowed to run **sh**.

   g. Look up the **chmod** program (e.g. use **man chmod**)

   ```shell
   man chmod
   ```

   chmod is used to change file modes or access ontrol lists

   h. Use **chmod** to make it possible to run the command **./semester** rather than having to type **sh semester**. How does your shell know that the file is supposed to be interpreted using **sh**?  

   ```shell
   chmod +x ./semester
   ./semester
   ```

   ```shell
   #!/bin/sh
   # shebang
   # if a script is named with the path path/to/script, and it starts with the line 
   # !/bin/sh, then the program loader is instructed to run the program /bin/sh, passing path/to/script as the first argument. 
   ```

   i. Use **|** and **>** to write the "last modified" date output by **semester** into a file called **last-modified.txt** in your home directory.

   ```shell
   ./semester | grep --extended-regexp --ignore-case "last-modified:.*" > last-modified.txt
   ```

   

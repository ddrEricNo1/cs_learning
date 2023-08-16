# Homework 2

1. Read man ls and write an ls command that lists files in the following manner

   - Include all files, including hidden files
   - sizes are listed in human readable format (e.g, 454M instead of 454279954)
   - Files are ordered by recency
   - Output is colorized

   A sample output would look like this:

   ![Screenshot from 2023-08-01 09-09-14](/home/eric/Pictures/Screenshots/Screenshot from 2023-08-01 09-09-14.png)

   ```shell
   ls -a -h -l
   ```

   ![](/home/eric/Pictures/Screenshots/Screenshot from 2023-08-01 09-17-54.png)

2. Write bash functions macro and polo that do the following. Whenever you exercise macro the current working directory should be saved in some manner, then when you execute polo, no matter what directory you are in, polo should cd you back to the directory where you execute macro. For ease of debugging, you can write the code in a file named marco.sh and (re)load the definitions to your shell by executing source marco.sh.

   macro.sh

   ![Screenshot from 2023-08-01 10-00-37](/home/eric/Pictures/Screenshots/Screenshot from 2023-08-01 10-00-37.png)

   polo.sh

   ![Screenshot from 2023-08-01 10-01-57](/home/eric/Pictures/Screenshots/Screenshot from 2023-08-01 10-01-57.png)
3. Say you have a command that fails rarely. In order to debug it, you need to capture its output but it can be time consuming to get a failure run. Write a bash script that runs the following script until it fails and captures its standard output and error streams to files and prints everything at the end. Bonus points if you can also report how many runs it took for the script to fail.

   ![Screenshot from 2023-08-01 10-12-59](/home/eric/Pictures/Screenshots/Screenshot from 2023-08-01 10-12-59.png)

   ```shell
   #!/usr/bin/env bash
   cnt=1
   while true; do
   	source code.sh > error.log 2>&1
   	if [[ $? -eq 1 ]]
   	then
   		break
       else
   		echo "the shell runs good"
       fi
       echo "run $cnt times"
       cnt=$[$cnt+1]
   done
   ```
4. As we covered in the lecture find's -exec can be very powerful for performing operations over the files we are searching for. However, what if we want to do something with all the files, like creating a zip file? As you have seen so far commands will take input from both arguments and STDIN. When piping commands, we are connecting STDOUT to STDIN, but some commands like tar take inputs from arguments. To bridge this disconnect there's the xargs command which will execute a command using STDIN as arguments. For example, ls | xargs rm will delete the files in the current directory. Your task is to write a command that  recursively finds all HTML files in the folder and makes a zip with them. Note that your command should work even if the files have spaces.(hint: check -d flag for xargs)

   ```shell
   find . -name '*.html' | xargs -d '\n' tar czf archieve.zip
   ```

5. Write  a command or script to recursively find the most recently modified file in a directory. More generally, can you list all files by recency?

   ![Screenshot from 2023-08-01 17-30-55](/home/eric/Pictures/Screenshots/Screenshot from 2023-08-01 17-30-55.png)
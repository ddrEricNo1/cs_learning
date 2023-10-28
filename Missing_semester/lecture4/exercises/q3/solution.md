# The solution to Question 3
## Question: To do in-place substitution it is quite tempting to do something like *sed s/REGEX/SUBSTITUTION/ input.txt > input.txt*. However, this is a bad idea, Why? Use *man sed* to find out how to accomplish this.

**Ans**: sed /s/REGEX/SUBSTITUTION/ input.txt > input.txt will return a blank file, since **input.txt** on the right hand side of the ouput operator **>** will be made blank before the left hand side of the output operator could be applied. Because of file names conicide, an empty **input.txt** will be output to an empty **input.txt**.

```shell
# -i extension: edit files in-place similarly to -I, but treat each file independently from other files. 
```

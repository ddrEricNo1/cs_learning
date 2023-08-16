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

   
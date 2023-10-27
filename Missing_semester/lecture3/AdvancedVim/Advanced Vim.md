# Advanced Vim

Here are a few examples to show you the power of the editor. 

## Search and replace

**:s**: substitude command

```shell
# find each orruracne of 'foo' (in the current line only) and replace it with 'bar'
:s/foo/bar/g

# find each occurance of 'foo' (in all lines), and replace it with 'bar'
:%s/foo/bar/g

# change each 'foo' to 'bar', but ask for confirmation first.
:%s/foo/bar/gc

# change each 'foo' to 'bar' for all lines from line 5 to line 12(inclusive)
:5,12s/foo/bar/g


```

## Multiple windows
**:sp/:vsp**: to split windows
can have multiple views of the same buffer

## Macros
**q{character}**: to start recording a macro in register {character}

**q**: to stop recording

**@{character}**: replace the macro

Macro execution stops on error

**{number}@{character}**: executes a macro {number} times




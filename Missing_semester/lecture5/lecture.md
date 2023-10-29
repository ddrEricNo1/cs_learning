# Lecture5 : Command-line environment
* ctrl+c sends a signal SIGINT
* ctril+\ sends a signal SIGQUIT
* ctrl+z sends a signal SIGSTOP

if adding a sign '&' at the end of the instruction, it means that the program needs to run in the background. For example:

```shell
sleep 2000 &
```

can use the command **jobs** to check the current jobs

can use the coomand **bg** to ask the suspended job to continue at the background

```shell
# here %1 means the identiifier of that process, which can be referred via the command jobs
bg %1
```

To background an already running program you can do *ctrl + z* followed by **bg**. Note that the backgrounded processes are still children processes of your terminal, and will die if you close the terminal (this will send yet another signal, **SIGHUP**). To prevent that from happening you can run the program with *nohup* (a wrapper to ignore **SIGHUP**), or use **disown** if the process has already been started. 

to **kill** a command, use the command *kill* followed by the process identifier.

Another usage of the command **kill** is: it can send a signal to a process, for example:
*kill -STOP %1*, it will send a STOP command to the process with the identifier 1, which will pause that process again.

If we start a job by adding **nohup**, it means that that process cannot be hang up any more, which can be verified by the command **KILL -HUP %1"** (notice that in this example, **KILL** is used to send a signal  to a process)

**SIGKILL is a signal that cannot be processed by the program**


## Windows Multiplexer
**tmux**

three important concepts in **tmux**:

* sessions
* windows
* panes

## dotfiles


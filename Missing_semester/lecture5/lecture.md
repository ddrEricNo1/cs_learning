# Lecture5 : Command-line environment

## Job control

In some cases, we will need to interrupt a job while it is executing, for instance if a command is taking too long to complete (such as a *find* with a very large directory structure to search through). Most of the time, we can do **Ctrl-c** and the command will stop. But how does this actually work and why does it sometimes fail to stop the process?

Shell is using a UNIX communication mechanism called **signal** to communicate information to the process. When a process receives a signal and potentially changes the flow of execution based on the information that the signal delivered. For this reason, signals are *software interrupts*. 

* ctrl+c sends a signal SIGINT: signal interept
* ctril+\ sends a signal SIGQUIT: signal quit
* ctrl+z sends a signal SIGSTOP: signal stop, can be continue later via commands

if adding a sign '&' at the end of the instruction, it means that the program needs to run in the background. For example:

```shell
sleep 2000 &
```

can use the command **jobs** to check the current jobs
> Pecntage symbol followed by its job number (displayed by *jobs*)
> To refer to the last backgrounded job we can use the **$!** special parameter.

can use the coomand **bg** to ask the suspended job to continue at the background

**fg** is another command to continue the paused job, **fg** will continue the paused job in the foreground

**pgrep**: refer to jobs using their pid

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

* **sessions**

* **tmux** starts a new session

* **tmux new -s NAME** starts it with that name

* **tmux ls** lists the current sessions

* Within **tmux** typing **<C-b> d** detaches the current session

* **tmux a** attaches the last session. We can use **-t**flag to specify which 

* **windows**

* **<C-b> c** creates a new window. 
* **<C-b> N** go to the Nth window. Note they are numbered.
* **<C-b> p** goes to the prvious window.
* **<C-b> n** goes to the next window.
* **<C-b> ,** renames the curent window
* **<C-b> w** list current windows

* panes

## dotfiles
Basically, they are all config files
Many programs are configured using plain-text files known as dotfiles (because the file names begin with a **.**, so that they are hidden in the directory listing **ls** by default.
## Remote Machines

**ssh (Secure Shell)**

Executing commands
An often overlooked feature of **ssh** is the ability to run commands directly. 
**ssh foobar@server ls** will execute **ls** in the home folder of foobar. 
It works with pipes, so **ssh foobar@server ls | grep PATTERN** will grep locally the remote output of **ls** 
and **ls | ssh foobar@server grep PATTERN** will grep remotely the local output of **ls**. 


# Birthday-Bomb
An interactive puzzle using assembly implemented in C based on Imperial's Binary Bomb assignment.

# Setup Requirements
## For Windows:
- Install MinGW to use **gcc**, **gdb** and **make**.
- Follow all steps in [this link](msys2.org).
- Additionally install gdb using:
```
$ pacman -S mingw-w64-ucrt-x86_64-gcc
$ pacman -S mingw-w64-ucrt-x86_64-make
```
Use the UCRT64 terminal for the rest of the tutorial.

'ls' command to list files and directories.
'cd' command to change the directory.
The C source file can be opened in VSCode or Nano text editor using:
```
$ nano <file_name>
```
## For Linux Distros:
- Install **gcc**, **gdb** and **make**
### Ubuntu:
```bash
$ sudo apt install gcc gdb make
```
And respectively for other distros.

# Puzzle Setup

- Keep all the files in a single directory.
-  Use the make command to compile and link all files to produce a single executable: 'birthday_bomb'
## For Windows:
```
mingw32-make.exe all
```
## For Linux Distros:
```
make all
```
#
Keep only the following files and delete the rest:
1. birthday_bomb(.exe)
2. birthday_bomb.c
3. README.md

# Instructions
REMEMBER: 
- '$' stands for the bash (or any) shell prompt.
- 'gdb>' stands for the gdb prompt.

Notice that there is only one executable file and a C source file corresponding
to the main() function for the executable.

The files defining the phases are not given, hence the phases can not
directly be solved.

So, we make use of the wonderful tool (provided by the gods) - gdb.

- Run the following to startup 'gdb' for a given executable:
```
$ gdb <executable>
```
eg: $ gdb ./birthday_bomb

The original code has been pre-processed, compiled and setup for
dynamic-linking which has given the executable.

- This can be checked by the 'file' command.
```
$ file <file_name>
```
However, given the -g flag in the compilation process, some debugging info is
stored which we can use to our disadvantage.

This paves the entry for: **ASSEMBLY**

- To get some symbols and constants present in the executable, we can use
objdump.
```
$ objdump -t <executable>
```
This lists all the symbols that are used in the program (variables, functions,
etc.)

- The functions in the executable can be disassembled by a simple command in
gdb:
```
gdb> disas <function_name>
```
Lo and behold, you have the x86_64 assembly code for the function.

Hint: Try disassembling the functions corresponding to each phase.

- Run the program from gdb using the 'run' command.
```
gdb> run
```
- To stop at certain functions, use the 'break' command. It sets a breakpoint at
the start of the function.
```
gdb> break <func_name>
```
OR
```
gdb> break <mem_address>
```
- Use the 'next' command to go to the next assembly instruction. 
- Use the 'continue' command to go to the next breakpoint.
- Use the 'kill' command to kill the program.
- And most importantly, use 'quit' to quit gdb.

- Some addresses may be seen and we may want to check what is at the given
address.
```
gdb> print (char *) 0x1234 - Casts 0x1234 (memory location) to a char pointer and prints
gdb> print <variable_name> 
gdb> print /d $rax - Prints value in %rax (in decimal)
gdb> print /x $rax - Prints value in %rax (in hexadecimal)
```
**Remember, if it starts with '0x' it's in hexadecimal. Don't get confused!**

Now, it may get boring to re-enter the answers again and again while testing
the program. Hence, a text file can be created with each answer in a new line.
- Pass this as an argument to the executable while running.
```
$ ./birthday_test ans.txt
```
OR
```
gdb> run ans.txt
```
(Still, enter gdb using 'gdb ./birthday_test' and not 'gdb ./birthday_test ans.txt')

I think these gdb commands should be sufficient.

# x86-64 Architecture

I'm assuming a basic knowledge of x86-64 assembly. 
Syntax and other instructions can of course be looked up in case of any confusion. 

But just for simplicity:

You will need to know the different jump conditions, so open up a table of the
list online as a reference.

- %rax - Stored return values (%eax is the 32-bit version whereas %rax is the
64-bit version)
- %rdi - First argument to a function
- %rsi - Second argument to a function
- %rdx - Third argument to a function
- %rcx - Fourth argument to a function
- %r8  - Fifth argument to a function
- %r9  - Sixth argument to a function
	
If there are more arguments, they are stored in the stack.

There is a stack which is used to store values (usually local variables).
It is pointed by the %rsp or the %rbp register.

We take offsets from this (usually negative offsets) to store values.

- char  - 1 byte
- short - 2 bytes (a word)
- int - 4 bytes
- long - 8 bytes (usually)
- (char *) - 8 bytes

Some instructions can be followed by a suffix indicating size:
- b - byte
- w - word
- l - double word
- q - quad word

The registers are divided into two based on their use in function calls:
- Caller-saved
- Callee-saved

The caller-saved registers can be freely used by the callee (the function
called). So, if the caller needs any values stored in these registers, it must
store them separately (preferably in the stack).

Similarly, the callee-saved registers must be preserved for the caller. They
can be used by the callee, however, the original values must be restored before
returning.

Make sure to distinguish between the AT&T and Intel syntax for x86-64.

I think this is sufficient for now. All the best!

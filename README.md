# Operating Systems and Systems Programming

This repository contains the project work files from the course 'Operating Systems and Systems Programming'. 
The practical assignment is based on the popular projects from [ostep-projects](https://github.com/remzi-arpacidusseau/ostep-projects) repository.

---
### Task 1 - Unix Programming
The idea of this task was to write a simple c-program that uses a linked list to take in an input and reverses it. In a case where the user does not give the program any inputs, it will listen to the **standard input**. In case an input file is given it will read it and print the output to **standard output**. If two files are given then it will print the output to the output file.
This program should be invoked in one of the following ways:
```
prompt> ./reverse
prompt> ./reverse input.txt
prompt> ./reverse input.txt output.txt
```

---
### Task 2 - Unix Utilities
The idea of this task is to create a simple version of commonly used commands like cat, ls, etc.

Summary of what's in the folder:

- A bunch of single .c files for each of the utilities below: my-cat.c, my-grep.c, my-zip.c, and my-unzip.c.
- Each should compile successfully when compiled with the -Wall and -Werror flags.
- Each should (hopefully) pass the tests we supply to you.

Short summary of all the files

<dl>
  <dt>my-cat.c</dt>
  <dd> The program my-cat is a simple program. Generally, it reads a file as specified by the user and prints its contents.</dd>
  <dt>my-grep.c</dt>
  <dd>The second utility you will build is called my-grep, a variant of the UNIX tool grep. This tool looks through a file, line by line, trying to find a user-specified search term in the line. If a line has the word within it, the line is printed out, otherwise it is not.</dd>
  <dt> my-zip.c</dt>
  <dd>The third utility my-zip is a file compression tool.</dd>
  <dt>my-unzip.c</dt>
  <dd>The fourth utility my-unzip is a file decompression tool.</dd>
</dl>

---
### Task 4 - Kernel Hacking
> To develop a better sense of how an operating system works, you will also do a few projects inside a real OS kernel. The kernel we'll be using is a port of the original Unix (version 6), and is runnable on modern x86 processors. It was developed at MIT and is a small and relatively understandable OS and thus an excellent focus for simple projects.

Link to the task's [README](https://github.com/remzi-arpacidusseau/ostep-projects/blob/master/initial-xv6/README.md) 

To run the xv6 in a qemu-emulator you need to first install qemu and then do
```
make qemu
```

The goal of the project is simple: to add a system call to xv6. Your system call, getreadcount(), simply returns how many times the read() system call has been called by user processes since the time that the kernel was booted.

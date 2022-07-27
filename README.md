# 0x17. C - Simple Shell
## Description: 
In this project we are tasked with creating our own simple UNIX command interpreter. The program must have the exact same output as sh (/bin/sh)     as well as the exact same error output. The only difference is when you print an error, the name of the program must be equivalent to your argv[0].
   
## Instructions:
Compiling the program: gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

### Executing Commands in Interactive Mode:
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
 
### Executing Commands in Non-Interactive Mode:
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
 
## Authors:
**Nicholas French** | [github - MetaFrench](https://github.com/MetaFrench)
**Matthew Allen** | [github - mdallen5393](https://github.com/mdallen5393)
**Sarah Mcgowan** | [github - GoldLion1011](https://github.com/GoldLion1011)

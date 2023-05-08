# SimpleBashUtils-1
Development of Bash text utility cat.

Cat is one of the most frequently used commands on Unix-like operating systems. It has three related functions with regard to text files: displaying them, combining copies of them and creating new ones.
cat [OPTION] [FILE]...

1. -b (GNU: --number-nonblank) :
numbers only non-empty lines
2. -e implies -v (GNU only: -E the same, but without implying -v) :
but also display end-of-line characters as $
3. -n (GNU: --number) :
number all output lines
4. -s (GNU: --squeeze-blank) :
squeeze multiple adjacent blank lines
5. -t implies -v (GNU: -T the same, but without implying -v) :
but also display tabs as ^I

You need to develop a cat utility:

- Support of all flags (including GNU versions) specified above.
- The programs must be developed in C language of C11 standard using gcc compiler.
- Do not use outdated and legacy language constructions and library functions. 
- When writing code it is necessary to follow the Google style.
- The program must be executable files with command line arguments.
- The program must be built with Makefile with appropriate targets: s21_cat.
- If third-party libraries are used, there must be build scripts in makefile to connect/load them.
- Integration tests must cover all flag variants and input values, based on a comparison with the behavior of real Bash utility.
- The programs must be developed according to the principles of structured programming.
- You can use standard and non-standard C libraries, or you can use your own developed libraries from other projects.
- The statement of the message in the case of an error does not matter.


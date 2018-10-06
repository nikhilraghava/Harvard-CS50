# Harvard CS50: Introduction to Computer Science

My solutions to Harvard University's CS50 Introduction to Computer Science course offered at edX. I used both CS50's [CS50 IDE](cs5.io) and my own text editor (Sublime Text) on Linux (Ubuntu) and macOS respectively, together with CS50's C library - [libcs50](https://github.com/cs50/libcs50). Library references can be found [here](https://reference.cs50.net).

## CS50 IDE vs Local Development Environment

The teaching staff at Harvard CS50 have taken time to preconfigure the CS50 IDE environment for us, so clang works a bit differently on the IDE compared to your local development environment. To compile the C files using clang execute the following command (make sure you have CS50's library for C installed):

```bash
clang -o [output file name] [file name].c -lcs50
```

If you don't want to type out the clang command everytime you want to compile your C file, you can configure Make temporarily by executing the following commands in terminal.

```bash
cd
nano ~/.bash_profile
```

Paste the following lines at the beginning of the file and save it.

```bash
export CC="clang"
export CFLAGS="-ggdb3 -O0 -std=c99 -Wall -Werror"
export LDLIBS="-lcs50 -lm"
```

Now, to compile your C files:

```bash
make [name of C file without the .c extension]
``` 

## Progress

The table below shows my scores for the weekly problem set submissions.

|    Problem   | Correctness (out of 5) | Style (out of 5) | Score |
|:------------:|:----------------------:|:----------------:|:-----:|
|    Scratch   |            5           |         -        |  100% |
|     Hello    |            5           |         5        |  100% |
| Mario (Less) |            5           |         5        |  100% |
| Mario (More) |            5           |         5        |  100% |
|     Cash     |            5           |         5        |  100% |
|    Credit    |            5           |         5        |  100% |
|    Caesar    |            5           |         5        |  100% |
|   Vigenere   |            5           |         5        |  100% |


## License

Licensed under [GNU General Public License](https://github.com/nikhilraghava/Harvard-CS50/blob/master/LICENSE).
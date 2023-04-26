# Pipex

> This project is about handling pipes.

#### Score

<img width="200px" src="https://res.cloudinary.com/dk8lnfjpm/image/upload/v1678097637/42/125_100_wonrhe.png" />

## Mandatory Part

| Program name         | pipex                                                                                                                                                                   |
|:-------------------- |:----------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Turn in files**    | Makefile, *.h, *.c                                                                                                                                                      |
| **Makefile**         | NAME, all, clean, fclean, re                                                                                                                                            |
| **Arguments**        | file1 cmd1 cmd2 file2                                                                                                                                                   |
| **External functs.** | open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid<br/>ft_printf and any equivalent YOU coded |
| **Libft authorized** | Yes                                                                                                                                                                     |
| **Description**      | This project is about handling pipes.                                                                                                                                   |

Your program will be executed as follows:

`./pipex file1 cmd1 cmd2 file2`

It must take 4 arguments:

- **file1** and **file2** are **file names**

- **cmd1** and **cmd2** are **shell commands** with their parameters.

It must behave exactly the same as the shell command below:

```shell
$> < file1 cmd1 | cmd2 > file2
```

## Examples

```shell
$> ./pipex infile "ls -l" "wc -l" outfile
```

Should behave like: < infile ls -l | wc -l > outfile

```shell
$> ./pipex infile "grep a1" "wc -w" outfile
```

Should behave like: < infile grep a1 | wc -w > outfile

## Requirements

Your project must comply with the following rules:

- You have to turn in a Makefile which will compile your source files. It must not
  relink.

- • You have to handle errors thoroughly. In no way your program should quit unexpectedly (segmentation fault, bus error, double free, and so forth).

- Your program mustn’t have memory leaks.

- If you have any doubt, handle the errors like the shell command:
  < file1 cmd1 | cmd2 > file2

## Bonus part

You will get extra points if you:

**Handle multiple pipes.**

This:

```shell
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

Should behave like:

```shell
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```

**Support « and » when the first parameter is "here_doc".**

This:

```shell
$> ./pipex here_doc LIMITER cmd cmd1 file
```

Should behave like:

```shell
cmd << LIMITER | cmd1 >> file
```

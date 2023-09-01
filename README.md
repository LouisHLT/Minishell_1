# Minishell_1
## {EPITECH} | 1st year | PSU (Shell Programming)

⚠️ For Epitech students, don't copy-paste the code, be aware of the -42 ⚠️

### Subject : &nbsp;

You have to program a UNIX command interpreter.
This is one of the first step to be able to do 42sh project.

The interpreter is expected to display a prompt ( $> for example ) and then wait for you to write a command
line, which must be validated by a newline.
The prompt must be displayed again only after the command execution.
Only basic command lines are expected to executed; no pipes, redirections or any other advanced features.
The executables should be those found in the path, as indicated in the PATH variable.

If the executable cannot be found, you must display an error message and display the prompt again.
Errors must be dealt with and must display the appropriate message on the error output.
You must correctly handle the PATH and the environment (by copying and restoring the initial env).
You must implement the following builtins: cd, setenv, unsetenv, env, exit.

Your env builtin hasn’t to take any argument. Your unsetenv builtin hasn’t to support the “*” wildcard.

Read the subject for more details and examples.

Good luck.

========================

Grade PSU : C | Note : 12.1 | No crash

| Category                              | Percentage | Tests     |
|---------------------------------------|------------|-----------|
| Basic tests                           | 100%       | 5/5       |
| Path handling                         | 60%        | 3/5       |
| Path handling-eval                    | 60%        | 3/5       |
| Setenv and unsetenv                   | 100%       | 2/2       |
| Setenv and unsetenv-eval              | 100%       | 2/2       |
| Builtin cd                            | 66.7%      | 2/3       |
| Builtin cd-eval                       | 66.7%      | 2/3       |
| Line formatting (space and tabs)      | 100%       | 8/8       |
| Line formatting (space and tabs)-eval | 100%       | 8/8       |
| Error handling                        | 33.3       | 1/3       |
| Error handling-eval                   | 33.3%      | 1/3       |


<!--
| **End scores**                        | **21.6%**  | **11/51** | **Yes (7)** |
-->

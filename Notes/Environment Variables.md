Environment variables are a means of storing data that persists across many instances of the program

### Common one
![[Pasted image 20231126093606.png]]

### Programming Explicitly

A C program inherits the environment variables from the host machine and can access it in a couple different ways
```C
// notice that **envp is the third arguement to the main function in a C program
int main (int argc, char** argv, char **envp) {}

// to access it globally
char** environ;

// or through the function execve or execvp if you don't define any all of them
// get passed
execvp(char* prog, char* a1)

// if you want to use a env variable in your program use getenv()
if ((p = getenv("HOME")) == NULL) {
	p = "/tmp";
}
// chroot changes the processes notion of root to be the HOME else if home is
// defined then it uses /tmp
if (chroot(p) < 0) {
	perror(p);
	return(-1);
}

// the system command spawns a subshell that is often bin/sh or bash or zsh
// 
system("cd ~; nvim .")
```

### Dynamic Loading and Associated Attacks

Dynamic loading refers to a program using a libraries functions that are dynamically loaded.
To exploit this you can point a program to malicious library

the fix:
- Disallow this control by having setuid programs ignore environment variables and instead use only preset library stuff

### Programming Implicit

functions that call the shell or use the PATH
- system()
- popen()
- execlp()
- execvp()
	- exec derivatives

Don't trust env variables, try not to use them if security is at risk and if you have to use them for something sensitive then make sure their values are on a "whitelist" of possible values.


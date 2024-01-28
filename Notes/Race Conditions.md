A race condition is when the order of two or more different process or threads execution matters. It can cause security issues if they are done in the wrong order.

### Simple example

A program called send mail, that could access any file on the system, could be used by a malicious user to read any file. The naive fix is to do a check for access like this:
```C
if (access("xyz", R_OK) == 0) {
	// the problem is that this is this window between steps here where I could
	// rename another file to xyz and it would be able to read it, because
	// access() checked the first "xyz" and not the potentially renamed xyz
	// the reason this can be exploited like this is because the kernel has to
	// search through an array of files and as soon as it finds one named "xyz"
	// then it returns
	fopen("xyz");
}
```

The solution would be to not used hard coded file names

## The fix

```C
fp = fopen("xyz");
// check the file by the object information rather than the name
if (fstat(file(fp), &stbuf)) < 0) {
	// close if not should have access
	fclose(fp);
}
```

##### What is a symbolic link?
It is a file containing a path and when the kernel sees it it resolves the path

### Time of check to time of use race conditions


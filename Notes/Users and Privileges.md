### how to identify users
- who is running: getuid(2)
- whole privileges is it running with: geteuid(2)
- who is this user logged in as: getlogin(2)
#### whose terminal correspond to standard input, output, or error
- getlogin(3) or cuserid(3)
// dont use these unless you know they are a system call

### Establishing uid and managing privileges
users and groups
setuid and setgid
restricted users and groups

types of UIDs
- real UID -> UID of the user running the program
- effective UID -> UID of the user with whose privileges the process runs
- login/audit UID -> UID of the user who originally logged in
- saved UID -> UID before last change by program

obtaining these UIDs
- getuid(void) -> returns real UID
- geteuid(void) -> returns effective UID
- getauid(void) -> returns audit UID
- getlogin(void) [FreeBSD] -> return login (audit)

setting UIDs
```C
int setuid(uid_t uid) // change effective UID unless current EUID is 0 in which case change real, effective and saved UIDs to uid

int setruid(uid_t ruid) // cahnge real UID to ruid

int seteuid(uid_t euid) // cahnge effective, save UID to euid

int setreuid(uid_t ruid, uid_t euid) // change real UID to ruid, effecive and saved UID to euid

int setresuid(uid_t ruid, uid_t euid, uid_t suid) // change real UID to ruid, effective UID to euid, save UID to suid
```

### establishing groups and GIDs

pretty much the same as the single user stuff

keep in mind groups can be an attack vector



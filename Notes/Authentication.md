Do not make your own auth and session management system, use a framework

frameworks should:
- include httpOnly
- correctly set the domain and path parameters in the cookie
- prevent session tokens from being included in the urls or accepted as url params

long lasting session with auth tokens:
- server creates a token and stores it as a hash digest, NOT the actual token, and sends it to the client
- when the client comes back to access the token it gives the server the token and then it compares the token and the hash to see if it correct.

implement re login when a user is trying to access a sensitive feature

implement lockout after a certain amount of logins to guard against brute force attacks, such as guessing

### handle error messages during authentication

Use very generic error messages, do not expose any data about the failure, to avoid auth enumeration. 

### Session management

Make sure the lifecycle of the session is limited and that nothing about the token can be guessed or exposed

Role based access control:
- admin 
- regular
- guest

Discretionary access control:
- owners of the resource grant access to others like sharing on google drive
Identity based access control:
- instagram account type stuff

vertical privilege attack -> elevating privileges
horizontal privilege attack -> moving to another user who has different privileges

### How to mitigate brute force session id attacks

a formula to decide how long it will take to brute force a session id goes as follows:
(2<sup>B</sup> + 1 ) / 2 * A * S
- B is the number of bits of entropy in the session id
- A is the number of guesses an attacker can perform each second
- S is the current number of valid session IDs at any given moment

```python
# example - 64 bit session ID:
(2**32 + 1) / (2 * 1000 * 10000) = 429496
```


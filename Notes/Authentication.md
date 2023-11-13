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

Discretionary access contro:
- owners of the resource grant access to others like sharing on google drive
Identity based access control:
- instagram account type stuff

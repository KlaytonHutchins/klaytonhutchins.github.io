## Labs 2

### Challenge: Match Email Addresses

1. Paste the following at the top of the test string:

   ```
   YES
   Email: dobbs@example.com
   From: barb3@example.org
   Contact me at Dobbs@Example.Edu.
   
   NO
   Email: dobbs@example
   Email: dobbs@.example.com
   Email: dobbs@example.
   dobbs@
   Hey @example nice post!
   I like @ signs, they look like snails.
   @-delimited fields: dobbs@example@com
   ```

   Create an RE that matches the email addresses under YES but not those under NO.

2. When you have a working solution, modify the RE to capture the part of the address before the `@` (called the _local part_ of an email address, and the part to the right of the `@` (the _hostname_).


<hr>

[Prev](grouping.md) | [Up](README.md)


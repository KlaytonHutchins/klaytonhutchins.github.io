## Formatting Output

There are several _special characters_ that your program can output for some "special effects."

Each special character is preceded by a `\` character, which tells Java that the next character is something special.

| Character | Effect |
| --------- | ------ |
| `\n` | A "newline" character causes a line-feed (i.e., a new line) to be generated. |
| `\t` | A "tab" character causes a tab to be generated. This tab will cause the cursor to move to the next "tabstop," which usually occurs every eight character positions on the screen. |
| `\b` | A "backspace" character causes the cursor to back up. |
| `\"` | A literal double quote character — used in string literals. |
| `\\` | A literal backslash character — used in string literals. |
| `\'` | A literal single quote character — used in string literals, but not necessary. |

Each of these represents only one character of data, so we can assign them to `char` variables.
```java
char newLine = '\n';
```

We can also use them as literals in Strings.
```java
System.out.println("\t\tTwo tabs to the left of this text.");
```

If you want to _format_ your data, you must put the blanks, tabs, and newlines out to the screen yourself.

### Drill
`screenoutputkeyboardinput/drills/Formatting.java`
* Change the String literal to print  
  ```
  \\ His name was "Robert Paulson."  
  You cry now. //
  ```
* Make sure it is a single String literal.

<hr>

[Prev](output.md) | [Up](README.md) | [Next](stringoutput.md)


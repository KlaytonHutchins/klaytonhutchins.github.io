## ASCII

The ASCII character set is a standard defining, for character data, which bit-patterns represent which letters, numerals, and punctuation marks.

We have seen how letters have numerical values, like `A` is `65`.

In memory, `A` is represented as `01000001`.

This relationship is based on the ASCII character set.

ASCII characters use 1 byte of memory, and are numbered `0` to `127`.

### Practice Exercise
> ASCII character codes use only 7 of a byte's 8 bits. The other bit was used in older data transmission protocols.

ASCII codes represent:

* The letters of the American alphabet (both capital and small letters)

  * The ASCII character codes for the uppercase letters `A`-`Z` start at 65.

  * The lowercase letters `a`-`z` are also in ascending order starting at 97.

* Digit characters

  * The digit characters for `0`-`9` are in order starting at 48.

* Punctuation

  * These codes are scattered throughout the ASCII table.

* About 30 non-printable control codes

### Drill
> Go to http://www.asciitable.com/ and take a close look at how the letters and digits are organized in the table.


### Practice Exercise
> ##### Control Characters
> The first 32 ASCII characters are non-printable codes originally used to control teletypewriter machines. While some have no relevance in modern computing, many have been repurposed for programs that run in a terminal.  For example, ASCII 10 is the "line feed" code that told a teletype machine to rotate its platen up one line - this is now our familiar _newline_ character, `\n`.  This would normally have been followed by a "carriage return" code causing the machine's typing carriage to move all the way back to the left.  On Windows systems, both characters are used to separate lines.  On non-Windows systems only the `\n` newline is used.
> 
> In a terminal the first 26 control characters (after 0) can be typed using the _Ctrl_ key and the corresponding letter: the 10th letter is J, so _Ctrl_-J types a newline.  _Ctrl_-H types a backspace, _Ctrl_-G sounds a bell or beep if your terminal has sound enabled, _Ctrl_-I types a tab.
> ASCII 27 is _Ctrl_-[, the _Esc_ code.  ASCII 3 ("end of text") has been repurposed as _Ctrl_-C, "interrupt" (stop the current program in the terminal.)


### Drill
> `ASCIIData/com.example.characters.drills.ASCIICharacters`
> * In a `for` loop, iterate through the numbers `0` to `127`, printing each number and the character representation of that number (by casting it to a `char`) on a separate line.

<hr>

[Prev](standards.md) | [Up](README.md) | [Next](unicode.md)


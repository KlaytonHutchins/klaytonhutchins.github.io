## Unicode

The Unicode standard uses the same character codes as ASCII (`A` is `65`), but is 2 bytes, so it can represent 65,536 distinct character codes. These include the alphabets for languages from around the world, a wide range of symbols, and so on.

A `char` in Java is a Unicode character.

We can represent Unicode characters in Java with the escape `\u` followed by a 4-digit (hexadecimal) code.

```java
char one = '\u261d';
```

### Drill
> `ASCIIData/com.example.characters.drills.UnicodeOutput`
> * Write the characters `'\u261d'`, `'\u270a'`, `'\u270b'`, `'\u270c'` to the screen.

### Practice Exercise
> The Java compiler processes Unicode escapes anywhere it finds them.  For example:
> ```java
> int \u0078 = 42;        // This creates the variable x
> System.out.println(x);  // 42
> ```
>
> (Do not name your variables in this fashion.)
>
> Having a `\u` followed by something other than a valid Unicode value is a compiler error, even in a comment.

### Supplementary Characters
Unicode also defines some characters beyond the ones representable with 16 bits. In Java, these must be represented using more than one char value in sequence, via an encoding called **UTF-16**.

Characters beyond the 2 byte Unicode characters are called _supplementary characters_. They are actually stored as 4 bytes.

To output a supplementary character, we have to output two 16-bit characters.

### Displaying Unicode Characters
See http://www.unicode.org/charts/ for a list of characters.

This chart gives you the _code point_, a unique value assigned to each unicode character. You can search for its hexadecimal unicode value(s) at:

http://www.fileformat.info/info/unicode/char/search.htm

Then use the hexadecimal values in a `String`.

```java
// Using two hex values for code point 1f0a1
System.out.println("\uD83C\uDCA1");

```

Of you could use the code point with the static method `Character.toChars()`

```java
System.out.println(Character.toChars(0x1f0a1));
```

### Drill
> `ASCIIData/com.example.characters.drills.SuppChars`
> * Write the `String` `"\uD83C\uDCA1"` to the screen.
> * Add the statement `System.out.println(Character.toChars(0x1f0a1));`
> * Use `Character.toChars()` to output the code points `0x1F600` through `0x1F64F`. Add a newline every 16 characters.

<hr>

[Prev](ascii.md) -- [Up](README.md) -- [Next](labs.md)


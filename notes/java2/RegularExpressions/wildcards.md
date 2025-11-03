---
layout: default
title: Literals and Wild Cards
---

## Literals and Wild Cards

An ordinary letter or digit is interpreted literally (except when part of certain particular RE components... coming up)

`.` is a wildcard that matches any single character other than the newline `\n`.

### Drill
> * Try the pattern ` ` `.. `  (that's, _space_.._space_).
> * How about three dots (space...space)?
> * Just `...` without spaces?
> * `.`?

A pair of square brackets containing a sequence of characters matches an occurrence of any of those characters.

* This is called a _character class_:

  *  `[aeiou]` - match any vowel
  *  `[0123456789]` - match any digit
  *  `[a-z]` - match any lowercase letter.
    * In square brackets, a hyphen between two characters means a range; for a literal hyphen, include it next to either the opening or closing bracket
      * `[a-z-]` - match any lowercase letter or hyphen character;
  *  `[a-zA-Z]` - match any letter, upper or lower case.

  * A leading `^` inside the brackets inverts the meaning of the match:
    * `[^0123456789]` - match anything EXCEPT a digit

### Drill
> * Try the vowel pattern shown above, `[aeiou]`.
> * Now double it: `[aeiou][aeiou]`.
> * What's matched when you negate the class: `[^aeiou]`?
> * Try matching any occurrence of one of the first five capital letters in the alphabet.

Special character-class shorthands include:

* `\w` - match a "word" character (characters you'd use in a variable name): same as `[a-zA-Z0-9_]`
  * `\W` - match anything EXCEPT a word character: same as `[^a-zA-Z0-9_]`

* `\d` - match a digit character: same as `[0123456789]` or `[0-9]`
  * `\D` - match anything EXCEPT a digit: same as `[^0123456789]` or `[^0-9]`

* `\s` - match a white-space character: space, tab, carriage return, newline, form-feed, or vertical tab.
  * `\S` - match character EXCEPT white space

### Drill
> * Use the shorthand to match a single digit.
> * Try matching three digits in a row.

A character that would otherwise be an RE metacharacter can be escaped with a backslash or possibly with a character class:

  * `\[` - match an actual opening square bracket
  * `\.` or `[.]` - match an actual dot character
  * `\(` or `[(]` - match an actual parenthesis

### Drill
> * Forward-slashes, `/`, are used to enclose REs in many languages, and thus are a metacharacter (some languages allow you to choose your regex delimiter).
> * Can you match `/` in your test string?

<hr>

[Prev](options.md) -- [Up](README.md) -- [Next](assertions.md)


---
layout: default
title: Introducing Regular Expressions
---


### Patterns

Almost all modern languages and databases provide Regular Expression pattern matching.

On Linux and Unix (including MacOS) there many command-line tools (`grep`, `sed`, `awk`, `vi`, etc.) that process Regular Expressions.

```bash
# Print all lines in the file testdata.txt that start with a capital R:
grep ^R testdata.txt
```

* You can also find a number of online Regular Expression testers.

Regular Expressions allow us to efficiently apply a _pattern_ to any amount of source text.

> #### pattern
> Syntax that describes the text we want to match.

The pattern specified by a Regular Expression - a.k.a. RegExp, RegEx, or RE - consists of literal text to search for, as well as RE _metacharacters_ representing pattern components and features.

> #### metacharacter
> A character that is a language symbol with special meaning, not literal text.

RE patterns are by design compact, terse, and very precise.

### Drill
>
> Let's experiment with REs using http://regex101.com/  
>
> Open [testdata.txt](testdata.txt) in a new browser tab.  Select all the content, copy it, and paste it into the *TEST STRING* field at _regex101_.
>
> * Now, in the *REGULAR EXPRESSION* field enter the pattern `the`.
> * Notice that as you type the RE, matching text in the test string is highlighted.
> * Try adding a space at the end of the pattern.
> * Add a leading space.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](options.md)


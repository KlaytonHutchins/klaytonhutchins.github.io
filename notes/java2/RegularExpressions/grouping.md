---
layout: default
title: Grouping and Alternatives
---


`|` - match one of a list of pipe-separated alternatives

* `this|that|the other` - match "this" or "that" or "the other"

Parentheses define _groups_, which allow:

* Subexpressions: `th(is|at|e other)`

* Capture: `\((d\{3})\) (\d\d\d-\d\d\d\d)` - match a phone number of the form `(303) 555-1234`, and remember the area code and phone number after the match.

  * Captured groups are numbered left-to-right (starting with 1) as you count the opening parentheses.

  * Area code will be captured as group 1 (in some languages expressed as `$1` or `\1`).

  * Phone number will be captured as group 2.

### Practice Exercise
> Remember, captured groups start with 1, not 0 like most things in Java.

<br >

### Drill
> * Use the pattern `Re\w+` (what is `\w`?  what about `+`?).  Look at the *MATCH INFORMATION*.
> * Now group the matched word characters, `Re(\w+)` and look at what's captured.
> * Add a word character to the end and capture it: `Re(\w+)(\w)`.
> * Now capture all the word characters together: `Re((\w+)(\w))`.

### Practice Exercise
> Sometimes you want to group part of a pattern (say, for a set of alternatives), but not to capture it.  You can specify a non-capture group with `(?:)`:  `Re((?:\w+)(\w))`

<hr>

[Prev](1-labs.md) -- [Up](README.md) -- [Next](2-labs.md)


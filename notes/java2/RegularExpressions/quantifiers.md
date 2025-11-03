---
layout: default
title: Quantifiers
---

## Quantifiers

A quantifier specifies the number of occurrences of the item that precedes it:

* `*` - a sequence of zero or more if the item

  * `^\d*` - match text beginning with a sequence of digits, or with no digits at all.

A quantifier specifies the number of occurrences of the item that precedes it:

* `+` - a sequence of one or more if the item

  * `^\d+` - match text beginning with a sequence at least one digit.

* `?` - either zero or one of the item

  * `foo\d?` - match "foo", possibly followed by a digit.

* `{}` - specify exact, minimum, or minimum and maximum occurrences of the item

  * `\w{4}` - match a sequence of four word characters.
  * `\w{4,}` - match a sequence of at least four word characters.
  * `\w{4,7}` - match a sequence of at least four but no more than seven word characters.

### Drill
> * Try the pattern `at`.
> * Look closely at what's matched when you change it to `at*`.
> * Try `at+`, then `at{2}`.

### Practice Exercise
> Quantifiers are _greedy_ - that is, when multiple matches are possible they will match the longest.
> * Try the pattern `et.*h`
> * You can make a quantifier non-greedy ("lazy") by following it with a question mark.
> * Now try the pattern `et.*?h`

<hr>

[Prev](assertions.md) -- [Up](README.md) -- [Next](1-labs.md)


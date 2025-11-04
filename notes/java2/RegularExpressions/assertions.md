---
layout: default
title: Assertions
---


Also called _anchors_ or even _zero-width assertions_, these specify a _position_ in the source text, not any text itself.

* `^` - match the beginning of the source text.

* `$` - match the end of the source text.

* `\b` - match a boundary between word and non-word characters.

### Drill
> * Use the pattern `^Re`.
> * Now enable the `m` for multiline option.
> * Can you match a literal `.` at the end of a line?  Try it with and without the `m` option.
> * Use the pattern `the` and look closely at all the matches found.
> * Now try `\bthe`.
> * `the\b`.
> * `\bthe\b`.

### Practice Exercise
> When the `m` or `multiline` option is used,
> 
> * `^` matches the absolute beginning of the source text, or any position immediately after a newline.
> 
> * `$` matches the very end of the source text, or any position immediately before a newline.
> 
> * `\A` matches the absolute beginning of the source text.
> 
> * `\Z` matches the very end of the source text.


<hr>

[Prev](wildcards.md) -- [Up](README.md) -- [Next](quantifiers.md)


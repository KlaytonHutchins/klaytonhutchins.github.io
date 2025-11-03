---
layout: default
title: Options
---

#### Options

You can specify options that control how a Regex is processed.

* Case-insensitive (`i`): RE pattern matching is case-sensitive, unless you use the _case-insensitive_ option.

### Drill
> * Set the `i` for insensitive option and search for the string `re`.  Turn the option off and on a few times to see the difference.
> * Turn the `i` option off.

* Global (`g`): By default, once a match is found the regex stops processing; the _global_ option continues processing the RE over the rest of the input text.

### Drill
> * Turn the `g` for global option off and on a few times to see the difference.
> * Leave the `g` option on.

* Multiline (`m`): By default, `^` matches the very beginning of the input text, and `$` the very end; if the input text is actually multiple lines (text with embedded newlines), the _multiline_ option causes `^` to match the beginning and `$` to match the end of each embedded line.

### Drill
> * Search for the string `Re`.
> * Now change the search to `^Re` - the `^` means only match the pattern if it begins at the beginning of the data - you should see only one match.

<hr>

[Prev](intro.md) -- [Up](README.md) -- [Next](wildcards.md)


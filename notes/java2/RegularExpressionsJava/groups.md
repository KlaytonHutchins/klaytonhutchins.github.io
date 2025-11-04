---
layout: default
title: Capturing Group
---


Use parentheses () in the pattern to define a captured group.

```java
    Pattern p = Pattern.compile("(\\w+)(\\s+)(\\w+)");
    String s = "These     are     spaces";
    Matcher m = p.matcher(s);
```

* To match a literal open parenthesis, use "\(". To match a literal close parenthesis, use "\)"

If a match is found, the matched text from each group is stored in the `Matcher` object.

* `groupCount()` returns the number of capturing groups in the RE.

Retrieve the string for the corresponding group with `Matcher.group(int i)`.

* `group()` or `group(0)` returns the text matched by the entire regex.

```java
    if (m.find()) {
      String firstWord = m.group(1);
      String spaces = m.group(2);
      String secondWord = m.group(3);
      String fullMatch = m.group();  // or m.group(0)
      System.out.println("Group 1: [" + firstWord + "]"
                     + "\nGroup 2: [" + spaces + "]"
                     + "\nGroup 3: [" + secondWord + "]"
                     + "\nFull match: [" + fullMatch + "]");
      // Group 1: [These]
      // Group 2: [     ]
      // Group 3: [are]
      // Full match: [These     are]
    }
```

Subsequent replacement and append methods can refer to the first matched string as `$1`, the second as `$2`, etc.

```java
      String newString = m.replaceFirst("$3$2$1");
      System.out.println("Replaced string: " + newString);
      // Replaced string: are     These     spaces
```

### Drill
> `RegularExpressionsJava/com.example.java2.drills.AddressParser`
>
> Modify your `AddressParser`: change the regex to capture the ZIP and area code.  Modify the output to print only the ZIP and area code, not the entire line.

<hr>

[Prev](matcher.md) -- [Up](README.md) -- [Next](stringmethods.md)


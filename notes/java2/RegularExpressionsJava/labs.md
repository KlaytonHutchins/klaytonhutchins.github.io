---
layout: default
title: Lab
---

## Labs

1. Write a program with a non-static method that opens the file `regex_quotes.txt` and reads it one line at a time.  Have it pass each line to a method that prints the line if it begins with a hyphen (`-`).

   (Solution: RegexProcessor1.java)

1. Add a new method to the program that uses `Pattern` and `Matcher` to search a string of text for words beginning with a capital letters.  Have it print each capitalized word.  Call this method for each line from the file.

   (Solution: RegexProcessor2.java)

1. Modify the method from the previous solution.  Instead of printing each capitalized word separately, concatenate them into a single string consisting of the capitalized words in the current line of text, separated by spaces.  After finding all the capitalized words in the current line, print the resulting string.

   (Solution: RegexProcessor3.java)

1. Add a method to the program that will find all occurences of hyphenated words in the string (two words separated by a hyphen with no spaces, as in "_hyphenated-word_".)  Print these as they are found.  Now use capture groups to capture the two words themselves, without the hyphens. Print them out with square brackets around each word.

   (Solution: RegexProcessor4.java)

1. (Optional) Add a method to the program that takes a string of text, as well as a regex string and prints all sequences of the text that match the regex.  Call this method with several different regexes.

   (Solution: RegexProcessor5.java)

<hr>

[Prev](stringmethods.md) -- [Up](README.md)


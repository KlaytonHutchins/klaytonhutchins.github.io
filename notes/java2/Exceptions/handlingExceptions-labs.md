---
layout: default
title: Labs - Handling Exception
---

The purpose of this lab is to handle or declare exceptions, and call methods which every exception has.

`com.example.exceptions.labs.ExceptionsLab`

1. Run _ExceptionsLab.java_ and carefully examine the output, finding where each line of output was produced.  Now, in `method1`, uncomment the call to `method2`.  Does the code compile?

   Change the definition of `method1` so that it declares that it `throws Exception`.  Is this enough to compile the class?

   Add `throws Exception` declarations to methods until you can compile an run _ExceptionsLab.java_.

   (Solution: `com.example.exceptions.solutions.ExceptionsLab`)

2. In `run`, put the call to `method1` in a `try` block.  In the `catch` block, print a message saying that the exception was caught.

   Which methods can now remove their `throws` declarations?

   Which methods now complete normally?

   (Solution: `com.example.exceptions.solutions.ExceptionsLab2`)

3. In the `catch` block, add statements to print:
   * The exception's message.
   * The exception object as a `String`.
   * The exception's stack trace.

   (Solution: `com.example.exceptions.solutions.ExceptionsLab3`)

<hr>

[Prev](checkedExceptions.md) -- [Up](README.md) -- [Next](Throwable.md)


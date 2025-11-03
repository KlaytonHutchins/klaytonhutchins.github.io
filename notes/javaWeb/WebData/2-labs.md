---
layout: default
title: More Lab
---

## More Labs

1. Create a calculator web application whose HTML form contains two text boxes for numeric input as well as add, subtract, multiply, and divide buttons.

   Your servlet should read values from the form, convert numeric inputs to doubles, and perform math operations depending on which button was clicked. Then generate an HTML response to the user containing the results.
   * You can get the value of a submit button's data by name.
     ```html
     <input type="submit" name="add" value="Add">
     ```

     ```java
     request.getParameter("add");
     ```

  (Solution: _CalculatorSolution/_)

<hr>

[Prev](labs.md) -- [Up](README.md)


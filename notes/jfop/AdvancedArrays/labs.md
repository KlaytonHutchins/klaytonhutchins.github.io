---
layout: default
title: Lab
---

## Labs
We will now use use multidimensional arrays to group and use data.

1. Write a program called `SBScores` to print out the teams and scores of the first ten Super Bowls. (Find these on the internet. Note that since you know the data values, using the 2d array shortcut is a great idea here.)
   * Store the winning and losing score in a 2d array named `superBowlScores`.
   * Store the winning and losing teams in a 2d array called `superBowlTeams`.
   * Print the output in the format
     ```
      Green Bay 35 - Kansas City 10
     ```

   (Solution: _SBScores.java_)

2. Write a program that creates a 12 x 3 two-dimensional array. For each of the twelve months, store the name of the month, an abbreviation for the name, and the number of days (all as Strings).
   * Print out the abbreviation of the month in which you were born and how many days are in that month.
   * Modify your program to print out the name of each month that has 31 days.

   (Solution: _Months2DArray.java_)

3. Modify your program from (2) to ask the user for the month in which they were born, and print the name of the month, the abbreviation, and the number of days in the month.
   * Prompt the user and get the user's birth month in one method. Return a `String` to the caller.
   * Find the month data in a separate method that takes a 2d array of month data, and a month name. Return the month data to the caller.
    * What are the types of your input parameters?
    * What type do you return from the method if you're returning all of the data for a single month?
    * What will you return from the method if the month name is not recognized? An empty array? `null`? Be sure to handle this problem.

   (Solution: _Months2DArrayPrompt.java_)

<hr>

[Prev](varargs.md) -- [Up](README.md)


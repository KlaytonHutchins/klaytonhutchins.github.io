## Labs

1. Create a program with a `main` method. Declare and initialize an array for the days of the week, starting with Sunday.
   1. Print the days in order, but do not print Saturday and Sunday. Your logic should exclude these days by checking the array index.
   2. Do the previous option again, but your logic should check the array element against the String literals `Saturday` and `Sunday`.

   (Solutions: _DayOfWeekIterating1.java_, _DayOfWeekIterating2.java_)

2. In this lab you will see how `for` loops and arrays work well together. It looks long, but it is manageable if you go step-by-step.
   1. Write a program to declare an array with space for five `ints`. Prompt a user to enter five scores by repeating the prompt `Score 1: `, `Score 2: `, etc. Store the entries in the correct array index.
   2. Write a method called `calculateAverage` to calculate and return the average of all the scores. It should take one parameter and return a number value.
   3. To ensure that the method for calculating scores works, we are going to write a test method.
      1. Write a method called `public static void testCalculateAverage()`.
      2. In the method, declare and initialize an array of four `int`s whose average will divide evenly - no decimal place.
      3. Call the `calculateAverage` method and store the result in a variable.
      4. Use an `if` statement to check if the result is what you expected. If so, print the message `Passed`. If not, print the message `Failed` with the value that you expected and the value returned from the method.
      5. Call the `testCalculateAverage` method from `main`. Fix any errors in `calculateAverage`. Once the method works, comment out the call to `testCalculateAverage`.
   4. Now that we know calculating the average works, call the `calculateAverage` method in `main` and print the average for the user to see.

   (Solution: _AverageScores.java_)

3. Change your program from (2) to ask the user how many scores they are going to enter. Then prompt the user for that number of scores.  Use the value the user entered to create your array.

   (Solution: _AverageScoresPrompt.java_)

   * Modify the solution. After all of the elements have been read and printed, use a loop to find the largest number entered. Print the array index of the number and the number.

   (Solution: _AverageScoresLargest.java_)

4. Write a program whose `main` method declares and initializes an array of several `String`s with the names of animals, using `{}` shorthand initialization.
   In `main` write a `for` loop that loops 10 times.  Each time, it will choose and print the string at a randomly-selected index of the array.

   (Solution: _RandomString.java_)

### Practice Exercise
You may recall that `Math.random()` returns a randomly-generated `double` greater than or equal to `0.0` and less than `1.0`.  To turn that into an `int` within a given range:
* Multiply it by the highest number needed plus one.
  ```java
  // Random double from 0.0 through 19.9999...
  double d = Math.random() * 20;
  ```
* Convert it to an `int`, truncating off the fractional part.
  ```java
  // Convert to integer, now range is 0 through 19:
  int index = (int)d;
  ```
You can do this in one step:
```java
// Do it in one statement:
index = (int)(Math.random() * 20);
```

<hr>

[Prev](three-ways.md) -- [Up](README.md)


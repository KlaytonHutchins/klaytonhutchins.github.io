## Labs
In this set of labs we will write several programs to use expressions. There are many labs in this section. If you do not finish all of them, you can do so later.

Some useful formulas:
* &pi;: 3.141592653589793
* Area of a circle: &pi; * radius<sup>2<sup>
* Celsius: 5.0/9.0 (Fahrenheit - 32)
* Fahrenheit: (9.0/5.0 Celsius) + 32

(Note that Celsius and Fahrenheit use `double` values for division. If we used `int` values we would lose any remainder, so `5/9` would evaluate to `0`.)

1. Write a program that prompts the user to enter the radius of a circle, and reads the user's input into a floating-point variable. Have the program calculate the circumference of the circle, and print out both the radius and the circumference.

   (Solution: _Circle1.java_)

2. Modify your solution to _Circle1.java_ so that it also prints out the circle's area.

   (Solution: _Circle2.java_)

3. Write a program that accepts a Fahrenheit temperature as input and converts it into a Celsius temperature, which it prints out.

   (Solution: _FahrToCels.java_)

4. Accept two integers as input, say, i and j. Write a program that rounds off i to the next largest even multiple of the other integer j.
   ```
    NextMultiple = i + j - i % j
   ```
   To test your results, use the following test data: to round off 256 days to the next largest number of days that is evenly divisible by 7-day weeks. With i = 256 and j = 7, the next largest number of days that are evenly divisible into 7-day weeks is 259.

   (Solution: _NextLargestMultiple.java_)

5. Write a program that accepts the amount of a restaurant check and calculates the tip amount for a 10%, 15%, and 20% tip.

   (Solution: _CalculateTip.java_)

6. Write a program that accepts numeric values for the _total_ daily rainfall for a week. Print the daily rainfall and calculate and print the total rainfall for the week, as well as the _average_ rainfall for the week.

   (Solution: _DailyRainfall.java_)

<hr>

[Prev](precedence-order.md) | [Up](README.md)


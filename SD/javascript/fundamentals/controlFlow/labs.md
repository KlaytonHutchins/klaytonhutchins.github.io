## Control Flow Lab

Resources for this lab: [resources/labs](resources/labs)

1. Write a for loop that takes the value of `base`, and modifies a variable (`total`) to `base` to the power of `pow` in the following function:

    ```js
    let exponential = function(base, pow) {
      let total;

      /************* Your Code Here **************/

      /*******************************************/

      return total;

    }
    ```

1. The Fibonacci sequence is a series of numbers in which the first two numbers are 0 and 1. Each subsequent number is the sum of the previous two. So, the next Fibonacci number is (0+1)=1. The next is (1+1)=2. Then (1+2)=3...etc. The first two are pre-defined as 0 and 1. All subsequent numbers are calculated from there.  

   | n | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
   |---|---|---|---|---|---|---|---|---|---|---|----|
   |fib| 0 | 1 | 1 | 2 | 3 | 5 | 8 | 13| 21| 34| 55 |

   Modify the following function with a `while` loop to print the 'nth' Fibonacci number, where the variable `n` is that number's position. E.g. Fibonacci number 4 is `3`, fib7 is `13`.

    ```js
    let fibonacci = function(n) {
      let number;
      /************* Your Code Here **************/

      /*******************************************/
      return number;
    };
    ```

1. Complete the following 'reduce' function such that it will return the a value equal to the all of the values of the provided array (`arr`) combined through some operation (`op`), where `op` is a string like `+`. `-`, `*`, `/`.

   For example:  

    ```js
    reduce('+', [1,2,3]); // => 6
    ```

   If the provided operator (`op`) is not one of those listed above, return the string 'invalid operator' instead.  

    ```js
    let reduce = function(op, arr) {
      let total = arr[0];
      /************ Your Code Here *************/

      /*****************************************/
      return total;
    };
    ```

1. Complete the following `isLeapYear` function such that it will return `true` if the `year` provided is a leap year and `false` if the value is not a leap year.  

   **Leap Years** :  

   In the Gregorian calendar, a normal year consists of 365 days. Because the actual length of a sidereal year (the time required for the Earth to revolve once about the Sun) is actually 365.25635 days, a "leap year" of 366 days is used once every four years to eliminate the error caused by three normal (but short) years. Any year that is evenly divisible by 4 is a leap year: for example, 1988, 1992, and 1996 are leap years.  

   However, there is still a small error that must be accounted for. To eliminate this error, the Gregorian calendar stipulates that a year that is evenly divisible by 100 (for example, 1900) is a leap year only if it is also evenly divisible by 400.  

   For this reason, the following years are not leap years:

   1700, 1800, 1900, 2100, 2200, 2300, 2500, 2600

   This is because they are evenly divisible by 100 but not by 400.

    ```js
    let isLeapYear = function(year) {
      let leapYear;
      /************ Your Code Here *************/

      /*****************************************/
      return leapYear;
    };
    ```

<hr>

[Prev](tryCatchFinally.md) | [Up](README.md)


## Labs
These labs have us working with Java's wrapper classes to demonstrate their utility, methods, and interaction with primitives.

1. Write a program with two variables, one of type `double` and one `Double`.  Assign each of them the value `0.0 / 0.0` and print the results.

   (Solution: _NaNTest.java_)

2. This is `WrapperClasses/com.example.wrapperclasses.labs.AutoboxOverload`:

   ```java
   package com.example.wrapperclasses.labs;

   public class AutoboxOverload {
     public static void method(Object o) { System.out.println("In Object method"); }
     public static void method(Number n) { System.out.println("In Number method"); }
     public static void method(Long l)   { System.out.println("In Long method"); }

     public static void main(String[] args) {
       int var = 17;
       method(var);
     }
   }
   ```
   a. Without running it first, try to determine which method will be called at runtime (or if it will even compile.)

      (Solution: _AutoboxOverloada.java_)

   b. After running it, add another `method` that takes a parameter of type `long` (the primitive type).  Which method will run?

      (Solution: _AutoboxOverloadb.java_)

   c. Add another `method` that takes a parameter of type `Integer`.  Which method runs?  Why?

      (Solution: _AutoboxOverloadc.java_)

   d. Add another `method` that takes a parameter of type `int`.  Which method will run?

      (Solution: _AutoboxOverloadd.java_)

3. Write a program that prompts the user for two values: first an integer, second a boolean.  If the boolean is `true`, the program will print the numbers from `0` to the first argument.  If `false` it will print the numbers from the first argument to `0`.

   Test your program with various strings passed on the command line.

   (Solution: _CountUpOrDown.java_)

4. Given the following code, what if anything will be printed by the `println`?

   ```java
   public static void main(String[] args) {
     Integer i = Integer.valueOf(1000);
     increment(i);
     System.out.println(i);

   }
   private static Integer increment(Integer i) {
     i++;
     return i;
   }
   ```
   (Solution: _IntegerReferences.java_)

5. Write a program that reads a line of text as a `String` from the keyboard (using a `Scanner` and `nextLine()` to read in a string that may contain spaces).  It should then print out each character of the string, along with whether or not that character is an uppercase letter, a lowercase, or a digit.

   (Solution: _TestLetters.java_)

<hr>

[Prev](Boolean.md) -- [Up](README.md)


## Methods Instead of Repeating Code

One of the best uses of methods is to avoid repeated code:

```java
public class CalculateBalance {
  public static void main(String[] args) {
    double cost = 307.32;
    double balance = cost;

    double payment1 = 42.40;
    balance = balance - payment1;

    System.out.println("-----------------");
    System.out.println("---- BALANCE ----");
    System.out.println("-----------------");
    System.out.println(balance);
    System.out.println();

    double payment2 = 39.31;
    balance = balance - payment2;

    System.out.println("-----------------");
    System.out.println("---- BALANCE ----");
    System.out.println("-----------------");
    System.out.println(balance);
    System.out.println();
  }
}
```

The method repeats the exact same code for printing "BALANCE".
* This code should be moved into its own method, which is then called twice from main.

We call this re-structuring of code _refactoring_.

> #### refactoring
> Changing code so that the program has the same functionality, but the code is better structured.
>
> In other words, making a program better without breaking it.


### Drill
`Methods/src/drills/CalculateBalanceRefactor.java`
We will refactor this class to print the header with a method.
* Declare a new method `public static void printHeader()`.
* Copy the three `System.out.println` statements that print the "BALANCE" header into this method.
* Replace the existing `System.out.println` statements that print "BALANCE" with a call to `printHeader();`. Run the program.
* Change the `printHeader()` method to use forward slashes `/` instead of `-` characters.

<hr>

[Prev](review.md) -- [Up](README.md) -- [Next](return.md)


## Assignment Operators

It's very common to use the value of a variable in an expression, then assign the result of the expression back into the original variable.

```java
index = index + 1;
yearlyTotal = yearlyTotal + monthlyTotal;
product = product * factor;
whatsLeft = whatsLeft % 3;
name = name + "Dobbs";
```

Many of the basic operators have a corresponding _operate-assign_ operator.

```java
index += 1;                  // Same as index = index + 1;
yearlyTotal += monthlyTotal; // Same as yearlyTotal = yearlyTotal + monthlyTotal;
product *= factor;           // Same as product = product * factor;
whatsLeft %= 3;              // Same as whatsLeft = whatsLeft % 3;
name += "Dobbs";             // Same as name = name + "Dobbs";
```

* Note the variable being assigned must already be initialized.

  ```java
  int k;
  k += 4; // WILL NOT COMPILE. What are we adding 4 to?
  ```

  * This is true for the string concatenation operator `+`.

    ```java
    String novel;
    novel += "Call me Ishmael.";  // WILL NOT COMPILE. Variable novel hasn't been initialized.

    novel = "";        // Initialize novel with an empty string.
    novel += "Call me Ishmael.";
    ```

Like the simple assignment operator `=`, these other assignment operators have the lowest possible precedence, so all expressions in the statement complete before the assignment happens.

```java
total += total * rate + surcharge;
// Exactly the same as:
// total = total + total * rate + surcharge;
```

-----
```java
package examples;

public class OpAssign {
  public static void main(String[] args) {
    int numPeople = 11;
    float flight = 575.0F;
    float hotel = 876.35F;
    float carRental = 135.50F;
    float tripPrice = 0F;

    tripPrice += flight;
    tripPrice += hotel;
    tripPrice += carRental;

    System.out.println("Cost per person: $" + tripPrice);

    tripPrice *= numPeople;
    System.out.println("Total cost: $" + tripPrice);
  }
}
```
-----

<hr>

[Prev](booleanExpressions.md) | [Up](README.md) | [Next](prePostIncrement.md)


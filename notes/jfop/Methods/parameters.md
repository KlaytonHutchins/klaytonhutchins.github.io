## Sending Data to Methods

You can send data to a method.

The data you can send is defined in the method's declaration, inside its parentheses.

* Consider this method.

  ```java
  public static void isOddOrEven(int number) {
    if (number % 2 == 0) {
      System.out.println(number + " is even");
    } else {
      System.out.println(number + " is odd");
    }
  }
  ```
  * It has one _parameter_, `int number`.

> #### parameter
> A variable in a method declaration's parentheses.

A parameter is just a variable like other variables we have seen - it has a _type_ and a _name_, and we can use it in code.

When we call this method we must _pass_ `int` data.

> #### passing data
> Putting data in a method's parentheses when you call the method.

```java
isOddOrEven(12); //call the method and pass the value 12

int bottlesOnWall = 99;
isOddOrEven(bottlesOnWall); //call the method and pass the value
                            //stored in bottlesOnWall
```

If a method has one or more parameters, you must pass the correct number in the correct order.

```java
isOddOrEven(12);     // Just fine
isOddOrEven();       // WON'T COMPILE - need to pass a value
isOddOrEven(12.5);   // WON'T COMPILE - must be an int
```

<hr>

[Prev](using-return.md) | [Up](README.md) | [Next](parameters2.md)


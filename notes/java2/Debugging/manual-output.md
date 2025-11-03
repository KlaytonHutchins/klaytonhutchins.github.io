## Manual Output in Code

Another tried-and-true debugging technique involves putting extra print statements in your program.

Print a message to indicate that the program has reached some specific point correctly.

```java
amountDue = amountDue - payment;
System.out.println("We got past the calculation");
```

Print the contents of variables to see if they contain the values you expect at a particular point in your program.

```java
amountDue = amountDue - payment;
System.out.println("value: " + amountDue);
```

Once the print statements have served their purpose, you remove them and recompile the program.

<hr>

[Prev](commenting.md) -- [Up](README.md) -- [Next](conditional-output.md)


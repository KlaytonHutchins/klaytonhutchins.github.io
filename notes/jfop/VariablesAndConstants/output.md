---
layout: default
title: Printing Variable
---


When you use a variable in an output statement, the value stored in the variable is printed.
```java
double battingAverage = .345;
double thisYearBA = battingAverage;
//thisYearBA now has the value .345
battingAverage = .362;

System.out.println(battingAverage);
System.out.println(thisYearBA);
```

This variable value is printed when we use the `+` operator for concatenation with a `String`.
```java
int i_5 = 5;
double d_5 = 5.00001;
char c_5 = '5';

System.out.println("int 5: " + i_5);
System.out.println("double 5: " + d_5);
System.out.println("char 5: " + c_5);
```

> #### concatenation
> Joining strings and data end to end.
> ```java
>   System.out.println("int 5: " + i_5); //i_5 is the value 5
>   //Output: "int 5: 5"
> ```

### Drill
`variablesandconstants/drills/PrintingExample.java`
* Run the code listed above to see the output.

`variablesandconstants/drills/VariablePrinting.java`
* Add strings to the `System.out.println()` statements to display which variable is being output

<hr>

[Prev](assign.md) -- [Up](README.md) -- [Next](labs.md)


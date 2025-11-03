## For Loop - When and Why

### When to Use a `for` Loop

Use a `for` loop when you have to do something a certain number of times, such as:
* Asking a user to enter a number five times.
* Calculating a value where the same math is repeated over and over.

`for` loops are especially useful when we know the number of times something needs to execute.

### Why Use a `for` Loop

`for` loops keep us from repeating code. Rather than copy and paste the same statements several times, we can put the set of statements in a loop.

Additionally, because a `for` loop's body can execute a variable number of times, we do not have to hard-code how many times the code will execute:

```java
System.out.print("How many times should we repeat this code");
Scanner sc = new Scanner(System.in);
int end = sc.nextInt(); // variable, so it can change
for (int i=0; i < end; i++){
  //... some code to repeat
}
```

<hr>

[Prev](break-continue.md) | [Up](README.md) | [Next](labs.md)


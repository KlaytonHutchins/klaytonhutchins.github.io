## Reading from the Keyboard

All programs can read input from the keyboard, which programmers call standard input, or "standard in."
* In Java, `System.in` represents standard input.

Use a `Scanner` to read input.
* Store the input value in a variable (or use it immediately).
* When we ask the user for input, the program will pause and wait for the user to enter something.

### Steps to Reading and Using User Input
1. Create a Scanner.
   ```java
     java.util.Scanner scanner = new java.util.Scanner(System.in);
   ```

2. Prompt the user for input (or they won't know to enter anything).
   ```java
     System.out.print("Enter your age: ");
   ```

3. Read the data and store it in a variable of the correct type.
   ```java
     int age = scanner.nextInt();  //nextInt() for an int
   ```

4. Use the data.
   ```java
     System.out.println("You said your age is " + age);
   ```

5. Close the Scanner. (Once you do this, your program can no longer receive data - so do this as the last thing in your program.)
   ```java
     scanner.close();
   ```

In Java, you must use different `Scanner` method calls for reading different data types.
```java
String str = scanner.next();
int i = scanner.nextInt();
boolean b = scanner.nextBoolean();
double d = scanner.nextDouble();
```

### Drill
`screenoutputkeyboardinput/drills/ScannerInput.java`
* Add a prompt to the code so that the user knows to enter data.
* Output the data.
* Run the program.

### Input Type Errors
If the user does not enter the right type of data, the program could crash with a runtime error, like
```java
Exception in thread "main" java.util.InputMismatchException
  at java.util.Scanner.throwFor(Scanner.java:864)
  at java.util.Scanner.next(Scanner.java:1485)
  at java.util.Scanner.nextInt(Scanner.java:2117)
  at java.util.Scanner.nextInt(Scanner.java:2076)
  at ScannerInputSolution.main(ScannerInputSolution.java:12)
```

This is because Java accepts all user input as a `String` and then tries to convert it to the correct type.

### Drill
`screenoutputkeyboardinput/drills/ScannerInput.java`
* Add a statement to output the value read by `nextInt()`, with some appropriate text.  Run the program and input an integer.
* Run the program again and try entering a decimal value, or a String (like your first name).

<hr>

[Prev](stringoutput.md) | [Up](README.md) | [Next](labs.md)


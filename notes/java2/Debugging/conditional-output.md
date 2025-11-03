## Making Debugging Print Statements Conditional

An annoyance of debugging with print statements is:

* When you're debugging, you put the statements in your program.

* When you're done debugging, you take the extra statements out.

* If you find a problem later on, you put them back in...

* When you've fixed the problem, you take them back out...

* If you find another problem later on, you put them back in...

To fix this problem, put your debug print statements in a conditional statement.

We can use a static `boolean` variable to control all debugging statements.

```java
static boolean debug = true;

  // Somewhere in the program...
  if(debug) {
    System.out.println("We got past the calculation");
  }

  // Somewhere else...
  if(debug) {
    System.out.println("value: " + amountDue);
  }
```
Now if we change `debug` to `false` and recompile, messages are turned off.

Another technique is to define a method for printing debug messages.

```java
public static void debug(String msg) {
  boolean debugging = true;
  if (debugging) {
    System.out.println(msg);
  }
}
```
* Now we don't repeat `if(debug)` in our code.

  ```java
  // Somewhere in the program...
  debug("We got past the calculation");
  
  // Somewhere else...
  debug("value: " + amountDue);
  ```

### Practice Exercise
> When you are new to programming, adding System.out.println() statements to find bugs in your code is fine.
>
> However, these statements could accidentally appear in logs (text files that save output), and are considered unprofessional. There are better ways to debug.

<hr>

[Prev](manual-output.md) -- [Up](README.md) -- [Next](debugger.md)


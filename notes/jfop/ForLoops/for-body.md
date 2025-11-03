## `for` Loop Body ##

The first statement or first _code block_ after a `for` statement is considered its body.

> #### code block
> Anything in curly braces `{  }`. This defines _scope_, which is where a variable is available. For example...
>
> ```java
> int i = 0;
> for (i = 0; i < 5; i++) {
>   int iTimesTwo = 2 * i;
>   System.out.println(iTimesTwo);
> }
> // iTimesTwo is no longer available, i.e. "out of scope"
> System.out.println("i is still in scope with value " + i);
> ```

```

// Curly braces are required for multiple loop body statements
for (initialization; termination; increment) {
  loop body
  more loop body
}
```

Making the loop body a code block `{ }` is preferred, even if the body is only one statement.
* It makes the code more readable and prevents error.

```java
  // Preferred...
  for (int i=0; i<5; i+=1){
    System.out.println(i);  
  }

  // Works...
  for (int i=0; i<5; i+=1)
    System.out.println(i);

  // Misleading... is the second statement part of the for loop?
  for (int i=0; i<5; i+=1)
    System.out.print(i);
    System.out.print("\n");

  // Bug!
  for (int i=0; i<5; i+=1); // <-- ; is the first statement
    System.out.print(i);   // <-- does not compile, i is out of scope
```

### Practice Exercise
You can declare _or_ initialize multiple variables in the _initialization_ section of a `for` loop, but you can't do both.

```java
// Legal
for (int i = 0, j = 1; i + j < 12; i++, j++){  
  // ...
}

// Illegal - this redeclares j rather than initializing it in the for loop
int j;
for (int i = 0, j = 1; i + j < 12; i++, j++){  
  // ...
}
// Compiler error: Duplicate local variable j
```


### Drill
`ForLoops/src/drills/ForLoopBody.java`
* Write a `for` loop to print the numbers 10 to 1 on the screen.
* Write a `for` loop to find the sum of the values 1 to 10. Print the sum to the screen.
* Write a `for` loop to print the values 1 to 5. Output should be comma-separated: `1, 2, 3, 4, 5`.
  _Hint: the loop will need to check which iteration it is on to prevent a comma showing after `5`_.

`Forloops/src/drills/ForLoopBody2.java`
* The `for` loops in the block comment have errors. Copy each loop and paste below the block comment. Fix the code so that it can compile.

<hr>

[Prev](for-parts.md) | [Up](README.md) | [Next](break-continue.md)


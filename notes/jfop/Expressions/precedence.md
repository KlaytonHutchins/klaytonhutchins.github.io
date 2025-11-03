## Precedence

When expressions contain more than one operator, Java must determine what to evaluate first. Each operator's _precedence_ determines which operator executes first.

> #### precedence
> Rules specifying the order in which operators are evaluated when there are multiple operators in an expression.

Operators with higher precedence are evaluated first.

```java
c = b + 7; // The + has higher precedence than = so it's
           // evaluated first, and its result is the
           // right-hand operand of the =.
```

```java
c = 5 + b * 7; // The + operator looks for a right-hand operand.
               // b is shared between + and *. The * has higher
               // precedence than + so b * 7 is evaluated first,
               // and its result is used as the right-hand operand of the +.
```

### Associativity and Precedence

Associativity determines which operator gets evaluated first when an expression contains more than one operator with the same precedence.

```java
int a = 5;
int b = 10;
int c = 19;
a = b + c + 10; // +'s have the same precedence,
                // associativity is left to right. Take
                // b and add it to to c first, then add the
                // result to 10.

```

### Parentheses `( )` and Precedence
We can change the order of precedence by grouping expressions in parentheses.

```java
int b = 5;
int c = 2;
a = b * (c + 10); // * looks right for a right-hand operand.
                  // parentheses cause c + 10 to execute first
```

Imagine Java narrating this statement evaluation.

* "`a` ... A variable. What follows it?"
* "`=` ... Look to the right for something to put in this variable."
* "`b` ... A variable. Substitute its value."
* "`5` ... Is this part of another expression?"
* "`*` ... Yes. What is the other operand for `*` ? I'll keep reading to the right."
  * "`(` ... I have to evaluate whatever is in this `()` group before doing the multiplication"
  * "`c` ... A variable. Substitute its value."
  * "`2` ... Is this part of another expression? I'll keep reading to the right."
  * "`+` ... Yes. What is the other operand for `+` ? I'll keep reading to the right."
  * "`10` ... Is this part of another expression? I'll keep reading to the right."
  * "`)` ... No. And it's the end of a `()` group. I'll evaluate it."
* "`12` ... Is this part of another expression? I'll keep reading to the right."
* "`;` ... It's the end of the statement so I should now evaluate the previous expression."
* "`5 * 12` evaluates to `60`."
* "Take `60` from the right side of the `=` and assign it to `a`."


<hr>

[Prev](associativity.md) | [Up](README.md) | [Next](precedence-order.md)


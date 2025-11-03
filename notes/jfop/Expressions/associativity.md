## Associativity

Java reads statements left to right. When it sees operators, it looks for data to use with the operators. _Associativity_ determines in which order a given operator looks for its operands.

> #### associativity
> Where an operator looks for data.

```java
b = 4; // The = has right-to-left associativity. This means it
       // looks at the right-hand side for a value,
       // and assigns it to the variable on the left-hand side.
```

```java
int c = 5;
int d = c + 8; // The + has left-to-right associativity. It will
               // look at the left hand side and evaluate it,
               // then evaluate the right hand side, and then add the two.
               // In this example it substitutes the value 5 for c on the left,
               // finds the literal 8 on the right, and adds the two.
```

### Associativity Example

Java knows the associativity of operators. Let's imagine Java narrating what it "thinks" as it evaluates a statement. (Assume all variables have been declared.)

```java
b = 5 + 7;
```

* "`b` ... A variable. What follows it?"
* "`=` ... Look to the right for something to put in this variable."
* "`5` ... Is this part of another expression?"
* "`+` ... Yes. What is the other operand for `+` ? I'll keep reading to the right."
* "`7` ... Is this part of another expression? I'll keep reading to the right."
* "`;` ... It's the end of the statement so I should now evaluate the previous expression."
* "`5 + 7` evaluates to `12`."
* "Take `12` from the right side of the `=` and assign it to `b`."

Java will substitute variable values as it reads left to right. Look at the following example.

```java
int a = 9;
b = a + 7;
```

* "`b` ... A variable. What follows it?"
* "`=` ... Look to the right for something to put in this variable."
* "`a` ... A variable. Substitute its value."
* "`9` ... Is this part of another expression? I'll keep reading to the right"
* "`+` ... Yes. What is the other operand for `+` ? I'll keep reading to the right."
* "`7` ... Is this part of another expression? I'll keep reading to the right."
* "`;` ... It's the end of the statement so I should now evaluate the previous expression."
* "`9 + 7` evaluates to `16`."
* "Take `16` from the right side of the `=` and assign it to `b`."

<hr>

[Prev](shortcircuit.md) -- [Up](README.md) -- [Next](precedence.md)


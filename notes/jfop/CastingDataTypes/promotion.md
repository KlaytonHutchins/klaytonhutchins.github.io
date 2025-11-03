## Promotion of Data Types in Arithmetic

When Java does arithmetic, it will promote operands to the largest or most precise common type.

> #### promote
> Change _data_ to a different type for use in an expression.
>
> This does not change a variable's type, nor does it change the data stored in a variable.

```java
int i    = 0;
float f  = 1.0f;

float resultIF  = i * f;    // int*float promoted to float*float
double resultID = i * 2.0;  // int*double promoted to double*double

char c = 'A';
int resultCI    = c + 1;    // char+int promoted to int+int
```

### Practice Exercise
Promotion is happening in this statement.
```java
float fl = 1;  // int promoted to float
```

### Drill
`CastingDataTypes/com.example.casting.drills.Promotion`
* Try changing the types of the variables `resultIF`, `resultID`, and `resultCI` to the smaller or less-precise type, e.g. `int resultIF`. What compiler errors do you see?

<hr>

[Prev](implicit.md) | [Up](README.md) | [Next](int-promotion.md)


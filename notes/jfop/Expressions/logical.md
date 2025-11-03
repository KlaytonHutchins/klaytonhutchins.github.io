## Logical Expressions
Logical expressions are combinations of relational expressions.

A logical expression compares two true/false values and results in a single true/false value.

### Logical Operators
<table>
  <thead>
    <tr>
      <th>Name</th>
      <th>Operator</th>
      <th>Example</th>
      <th>Evaluates to <code>true</code> when...</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>AND</td>
      <td><code>&&</code></td>
      <td><code>a && b</code></td>
      <td><strong>both</strong> a and b are true</td>
    </tr>
    <tr>
      <td>OR</td>
      <td><code>||</code></td>
      <td><code>a || b</code></td>
      <td><strong>either</strong> a or b is true</td>
    </tr>
    <tr>
      <td>AND<sup>1</sup></td>
      <td><code>&</code></td>
      <td><code>a & b</code></td>
      <td><strong>both</strong> a and b are true</td>
    </tr>
    <tr>
      <td>OR<sup>1</sup></td>
      <td><code>|</code></td>
      <td><code>a | b</code></td>
      <td><strong>either</strong> a or b is true</td>
    </tr>
  </tbody>
</table>
<sub>[1] we rarely use this operator</sub>

### && - AND
Both of the _AND_ operator's operands must be true for the logical expression to evaluate to true.
```java
boolean maleOlderThan65 = sex == 'M' && age > 65;
```

### || - OR
If either of the _OR_ operator's operands are true, the expression will evaluate to true.
```java
boolean lessThan18orGreaterThan65 = age < 18 || age > 65;
```

### Practice Exercise
Each side of a logical expression **must** evaluate to a `boolean` result. The example below would generate a compiler error.
  ```java
    int age = 21;
    boolean isRegistered = true;
    boolean isRegisteredAnd21 = isRegistered && age = 21; //error
  ```
See the problem? The right side of the `&&` mistakenly uses the `=` operator, which results in a number. We cannot compare `boolean && int`. This code will not compile.

<br >

### Drill
`Expressions/src/drills/Logical.java`
* Add code to check if the salary is in the range of min and max and assign that value to `isExpectedSalary`.
* Add code to check and output whether the salary is "dreamy," where dreamy means it is  more than $10,000 greater than your max.
* Add code to check and output whether the salary is "laughable," where laughable means it is at least $5,000 less than your minimum salary requirement.

<hr>

[Prev](relational.md) -- [Up](README.md) -- [Next](shortcircuit.md)


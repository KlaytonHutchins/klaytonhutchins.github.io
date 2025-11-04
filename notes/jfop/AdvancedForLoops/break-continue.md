---
layout: default
title: Break and Continue With Enhanced For Loop
---


We can use the commands `break` and `continue` in enhanced `for` loops, just like we would in standard `for` loops.
* `continue` will skip the rest of the loop body and advance to the next loop iteration.
* `break` will exit the loop immediately.

```java
int [] scores = {76, 89, 51, 42, 69, 42, 81};
// only print scores over 70
for (int num : scores) {
  if (num < 70) {
    continue;
  }
  System.out.print(num + " ");
}
System.out.println();
// output: 76 89 81
```

```java
// Note: this scenario is imaginary
int [] readings = {55, 56, 49, -1, 43, -1, 54};
int sum = 0;
// if a negative reading is found, print an error message and stop processing
for (int i : readings) {
  if (i == -1) {
    System.out.println("ERROR: Negative reading found");
    break;
  }
  System.out.println("Adding reading " + i);
  sum += i;
}
// Output:
// Adding reading 55
// Adding reading 56
// Adding reading 49
// ERROR: Negative reading found
```

### Drill
`AdvancedForLoops/src/drills/ForEachBreakContinue.java`
* Write a foreach loop to display only odd numbers.
Output: `55 105 99 71 39 43`
* Change the loop to break if -100 is found.
Output: `55 105 99 71`

<hr>

[Prev](for-each.md) -- [Up](README.md) -- [Next](labs.md)


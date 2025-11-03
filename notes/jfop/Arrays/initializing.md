---
layout: default
title: Array Initialization Shortcut
---

## Array Initialization Shortcuts

Java gives us a shortcut to both _create_ and _initialize_ an array.

```java
char message[] = new char[3];
message[0] = 'H';
message[1] = 'i';
message[2] = '!';
```

We could do this same thing using the `{}` shortcut.
* The line below both creates the array of length `3` _and_ initializes the array elements.

```java
char message[] = {'H', 'i', '!'};
```

### Using the Array Shortcut `{}`

We can only use the array shortcut _by itself_ when we are declaring _and_ initializing an array.
```java
char message[] = {'H', 'i', '!'}; // Just fine.
```

```java
char message[];
message = {'H', 'i', '!'}; // WILL NOT COMPILE
```

If we want to use the shortcut with a variable that already exists, we have to use `new`.

```java
char message[] = {'H', 'i', '!'};

message = new char[] {'H', 'e', 'l', 'l', 'o'}; // reassign
```

Think of it as telling Java "reassign the variable `message` to point to this `new char` array containing the elements..."

### Practice Exercise
When using the array shortcut, you can append a comma after the last element. The length of the array is still the number of values provided - there is no empty element for the space after that comma.
```java
int[] ints = {0, 1, 2, };  // ints has only three elements
```

<br />

### Drill
`Arrays/src/drills/ArrayAccess2.java`
* Access all the `B` grades in the `grades` array and output them to the screen.
* Use values from the `firstNames` and `lastNames` arrays to create the names `Sarah Dobbs` and `Davey Jones`. Output the names to the screen.
* Declare and initialize an array containing your pet's name and the street you grew up on. (If you do not have a pet, use the value `null`.)
* Reassign the same array and initialize it with your middle name and a U.S. President's last name. (Use the array shortcut. If you do not have a middle name, use the value `null`.)

<hr>

[Prev](access.md) -- [Up](README.md) -- [Next](iterating.md)


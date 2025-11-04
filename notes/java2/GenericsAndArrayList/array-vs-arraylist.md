---
layout: default
title: Array vs. `ArrayList`
---


Arrays and `ArrayList`s are very similar.
* In fact, an `ArrayList` contains an array for storing elements.
  * We say the `ArrayList` is _backed_ by an array.
  * `ArrayList`'s main job is to manage the internal array so we don't have to.

The table below compares array operations to `ArrayList` operations.

* `i` is an integer index
* `arr` is an array
* `list` is an `ArrayList`

| Op  | Array          | ArrayList |
| --  | -----          | --------- |
|Size | `.length`      | `.size()` |
|Write| `arr[i] = obj` | `list.add(obj)` |
|     |                | `list.set(i, obj)` |
|Read | `obj = arr[i]` | `obj = list.get(i)` |

### Enhanced `for` Loops and `ArrayList`
An array and an `ArrayList` can be used in an enhanced for loop (or _foreach_ loop), and the syntax is exactly the same.

```java
String[] sArr = {"A", "B", "C", "D"};
for (String string : sArr) {
  // ...
}
```

```java
ArrayList<String> list = new ArrayList<>();
list.add("A");
list.add("B");
list.add("C");
list.add("D");

for (String string : list) {
  // ...
}
```

### Practice Exercise
> One advantage of using an array over `ArrayList` is, reading an array element with `[]` is marginally faster than using `ArrayList`'s `get` method.
>
> This is because the method call adds an extra step.
>
> ```java
> String s = sArr[0];       // assignment
>
> String st = list.get(0);  // method call + assignment
> ```
>
> Also, an array will usually consume less memory.
>
> Still, the ability of an `ArrayList` to grow dynamically outweighs this advantage.

<hr>

[Prev](replacing-inserting-removing.md) -- [Up](README.md) -- [Next](arraylist-size.md)


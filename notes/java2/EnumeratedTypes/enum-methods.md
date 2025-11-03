## `enum` Methods

Every `enum` is a class, and every `enum` constant is an instance, so each has methods.

### `enum` Constant Methods

#### `boolean equals(Object)`

This is the same as other `.equals` methods.

* Using `==` will yield the same result, because there is only one of each constant in an `enum`.

#### `toString()`
Returns the name of this enum constant, as contained in the declaration.

```java
System.out.println(Color.RED); // RED
```

#### `int ordinal()`
Each constant has a zero-based number for its position in the `enum` declaration.

```java
int pos = Color.RED.ordinal(); // 0
```

#### `int compareTo(otherEnumConstant)`
Every `enum` implements `Comparable`, so it can compare itself to other constant values.
* Natural order is determined by order in the `enum` definition.

```java
int compResult = Color.RED.compareTo(Color.GREEN);

System.out.println(compResult); // -1, RED comes before GREEN
```
### `static` Methods

The `enum` itself has `static` methods.

#### `static E[] values()`
This returns an array of the constants in this `enum`, in the order listed in the `enum`.

```java
Color[] values = Color.values();
```

#### `E valueOf(String)`
This will return the `enum` for a `String` value that matches one of the constants.

```java
Color val = Color.valueOf("RED"); // val = Color.RED

Color nope = Color.valueOf("PURPLE"); // IllegalArgumentException
```

### Drill
> `EnumeratedTypes/com.example.enums.drills.DayMethods`
>
> * Iterate through the `Day` constants, printing each `Day` name.
> * If the name contains the letter R, add a `*` next to the name.

<hr>

[Prev](using.md) -- [Up](README.md) -- [Next](enum-members.md)


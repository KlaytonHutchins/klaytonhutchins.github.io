---
layout: default
title: `String` Method
---

## `String` Methods

Because text is so important, every Java developer is expected to develop thorough knowledge of the `String` class and its methods.

### Drill
Go to the Javadoc for class `String` and reference the methods we cover here:
* https://docs.oracle.com/javase/8/docs/api/java/lang/String.html

#### `String alphabet = "abcdefghijklmnopqrstuvwxyz";`

### Getting information about a `String`

* `length`

  ```java
  System.out.println(alphabet.length()); // 26
  ```
* `equals`, `equalsIgnoreCase`

  ```java
  System.out.println(alphabet.equals("AbcDefGhiJklMnoPqrStuVwxYz")); // false
  System.out.println(alphabet.equalsIgnoreCase("AbcDefGhiJklMnoPqrStuVwxYz")); // true
  ```
* `startsWith`, `endsWith`

  ```java
  System.out.println(alphabet.startsWith("abc")); // true
  System.out.println(alphabet.endsWith("qrs")); // false
  ```
* `contains` - if another string occurs in this string, return false.

  ```java
  System.out.println(alphabet.contains("lmnop")); // true
  System.out.println(alphabet.contains("fed")); // false
  ```

* `indexOf` - if another string occurs in this string, return where it occurs (otherwise return -1).

  ```java
  System.out.println(alphabet.indexOf("ghi")); // 6
  System.out.println(alphabet.indexOf("giraffe")); // -1
  ```

### Getting at the `char` values in a `String`

The first character of a `String` is at position `0`.

* `charAt` - retrieves a single char from a certain position in the `String`

  ```java
  System.out.println(alphabet.charAt(9)); // What will this print?
  for (int i = 0; i < alphabet.length(); i++) {
    char c = alphabet.charAt(i);
    if ( c % 2 == 0 ) { // even-numbered character codes.
      System.out.println(c);
    }
  }
  ```
* `toCharArray` - copies the `String` contents into a new `char` array

  ```java
  char[] alphaChars = alphabet.toCharArray();
  System.out.println(alphaChars[5]); // What will this print?
  for (int i = 0; i < alphaChars.length; i++) {
    char c = alphaChars[i];
    if ( c % 3 == 0 ) { // Every third character.
      System.out.println(c);
    }
  }
  ```

* `getChars` - copies a region of the `String` into an existing `char` array.

  ```java
  char[] letters = new char[5];         // room for 5 chars.
  alphabet.getChars(5, 10, letters, 0); // copy five chars from alphabet into the
                                        // letters array, starting at letters[0]
  System.out.println(letters);
  ```

### Creating transformed `String` values

Once created, a `String` is immutable, so methods manipulating `String` contents _always_ return a **newly-created** `String`, leaving the original unchanged.

* `concat` - create a new `String` from the original and the argument.

  ```java
  String hello = "Hello";
  String helloWorld = hello.concat("World");
  System.out.println(helloWorld); // HelloWorld
  System.out.println(hello); // Hello
  ```

  * Because we can just use `+` we seldom use `concat`.

* `toUpperCase`, `toLowerCase` - create an all-uppercase or all-lowercase copy of the `String`.

  ```java
  System.out.println(alphabet.toUpperCase());
  // ABCDEFGHIJKLMNOPQRSTUVWXYZ
  System.out.println(alphabet);
  // abcdefghijklmnopqrstuvwxyz
  ```

* `trim` - remove whitespace from the beginning and ending of a string.

  ```java
  String trimmed = "\t   hello world \n".trim();
  System.out.println(trimmed.equals("hello world")); // true
  ```
  * For `trim`, "whitespace" means any character from Unicode \u0000 through "` `", including tabs, newlines, and control characters.
  * Spaces inside the string (between the first non-whitespace character and the last) are left alone.

* `split` - break a string into pieces based on a delimiter in the string's value.

  ```java
  String[] pieces = alphabet.split("m");
  // ["abcdefghijkl", "nopqrstuvwxyz"]
  ```

  * The delimiter itself is discarded.

    ```java
    String[] fields = "cat, dog, frog".split(", "); // split on ", "
    // ["cat", "dog", "frog"]
    ```

#### String Indexes

* `substring`

  * The first index is the zero-based starting point.

  * The second index is the index _after_ the end of the range.

    * If you omit the second index, `substring` returns the text from the first index to the end of the string.

  ```java
  // 0123456789
  // abcdefghijklmnopqrstuvwxyz
  String sub1 = alphabet.substring(4, 8);
  System.out.println(sub1); // efgh
  String sub2 = alphabet.substring(4);
  System.out.println(sub2); // efghijklmnopqrstuvwxyz
  ```
  * That is, the first index is _inclusive_, the second index is _exclusive_.

### Drill
`StringAndStringBuilder/src/com.example.stringstringbuilder.drills.SSNMasker`  (_src_ source folder)

`StringAndStringBuilder/test/com.example.stringstringbuilder.drills.SSNMaskerTests`  (_test_ source folder)
> 1. Run `SSNMaskerTests` as a JUnit Test.  It will fail.
> 2. In `SSNMasker` write the implementation of the `maskSSN` method, using `substring` and concatenation, so that the JUnit tests pass.

### Converting a Primitive to a `String`

`String` provides a `valueOf` method for generating the `String` representation of any primitive type.

```java
float f = 1.214f;
String fStr = String.valueOf(f);
System.out.println(fStr); // "1.214"
boolean b = true;
String bStr = String.valueOf(b);
System.out.println(bStr); // "true"
```

Because `String` is special, you can use concatenation as a shortcut:

```java
System.out.println("" + 1.214); // "1.214"
System.out.println("" + true); // "true"
System.out.println("" + null); // "null"
```

### Practice Exercise
The `+` concatenation operator only works when one of the operands is a `String`.
```java
System.out.println(null + true); // WILL NOT COMPILE
System.out.println(true + null); // WILL NOT COMPILE
> System.out.println(null + null); // WILL NOT COMPILE
> ```

<hr>

[Prev](theStringPool.md) -- [Up](README.md) -- [Next](StringBuilder.md)


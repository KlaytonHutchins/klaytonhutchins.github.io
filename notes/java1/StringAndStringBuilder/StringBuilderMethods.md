## `StringBuilder` Methods

`append` is `StringBuilder`'s workhorse for building text.

* `append` is overloaded to take any primitive or object type as a parameter.

  ```java
  double price = 4.99;
  int quantity = 12;
  StringBuilder sb = new StringBuilder("You ordered ");
  sb.append(quantity);
  sb.append(" items at a unit cost of ");
  sb.append(price);
  sb.append(" for a total of ");
  sb.append(quantity * price);
  ```

### Practice Exercise
`String`'s `concat` creates and returns a new `String`, leaving the original unmodified.  `StringBuilder`'s `append` modifies the existing `StringBuilder` object in-place.
* `String` does not have an `append` method.
* `StringBuilder` does not have a `concat` method.

* `append` returns a reference to its `StringBuilder` object, which allows you to chain additional `StringBuilder` method calls.

  ```java
  sb = new StringBuilder("You ordered ").append(quantity)
        .append(" items at a unit cost of ")
        .append(price)
        .append(" for a total of ")
        .append(quantity * price);
  ```


> #### method chaining
> Invoking a method that returns an object reference, and using that object reference to invoke another method.

* `insert` - insert text starting at a given offset, moving existing text to make room.

  ```java
  StringBuilder b = new StringBuilder("cat, frog, giraffe");
  b.insert(5, "dog, ");
  System.out.println(b);
  // "cat, dog, frog, giraffe"
  ```

* `delete` - remove a range of content from the `char` array, moving existing text to replace the deleted content.

  ```java
  b.delete(0, 5);
  System.out.println(b);
  // "dog, frog, giraffe"
  ```

* `replace` - replace a range of content with new content.

  ```java
  b.replace(5, 9, "rhinoceros");
  System.out.println(b);
  // "dog, rhinoceros, giraffe"
  ```

  * For `delete` and `replace`, just like `String`'s `substring`, the first index is _inclusive_, the second _exclusive_.

* `setCharAt` - replace a character at a certain index.

  ```java
  b.setCharAt(5, 'R');
  System.out.println(b);
  // "dog, Rhinoceros, giraffe"
  ```

* `reverse` - replace the text content with its reverse.

  ```java
  b.reverse();
  System.out.println(b);
  // "effarig ,soreconihR ,god"
  ```

`append`, `insert`, `delete`, `replace`, and `reverse` all return the `StringBuilder` reference and thus can be chained.

### Length vs. Capacity

`StringBuilder`'s `length` returns the length of the content in its `char` array.

`StringBuilder`'s `capacity` returns the length of the `char` array itself.

```java
StringBuilder builder = new StringBuilder(); // initial capacity 16 by default
builder.append("hello");
System.out.println(builder.length());   // 5 characters in the array
System.out.println(builder.capacity()); // char array size 16
```

`StringBuilder` grows its array as its capacity is reached, to twice the old capacity plus 2.

* When you anticipate adding a lot of text to an existing `StringBuffer` you can tell it to pre-grow its capacity.

  ```java
  builder.ensureCapacity(250);
  System.out.println(builder.length());   // 5 characters in the array
  System.out.println(builder.capacity()); // char array size now 250
  ```

* `trimToSize` reduces the `char` array to just enough for the content.

  ```java
  builder.trimToSize();
  System.out.println(builder.length());   // 5 characters in the array
  System.out.println(builder.capacity()); // char array size now 5
  ```

* `setLength` will either truncate content or create an internal array padded with `\u0000`, the null character.

  ```java
  builder.setLength(3);                   // 3 chars in array: "hel"
  System.out.println(builder);            // "hel"
  builder.setLength(10);                  // [h,e,l,,,,,,,]
  System.out.println(builder+"!!");       // "hel!!" '\u0000' does not show in output
  System.out.println(builder.length());   // 10
  ```

`ensureCapacity`, `trimToSize`, and `setLength` all have a `void` return type.

### Practice Exercise
Of course `StringBuilder` can't change the length of its array - an array's length is immutable.

When changing its capacity, the `StringBuilder` creates a new array, copying the existing content into it. While its method for doing this is efficient, the fewer times it has to do this the better your code's performance.

### StringBuilder and String

`StringBuilder` and `String` each extend `Object` directly - neither is a descendant of the other.

* Both `String` and `StringBuilder` are declared as `final` classes - you cannot create customized subclasses of either.

To assign a `StringBuilder`'s content to a `String`, call `StringBuilder`'s `toString` method.

```java
String s = new StringBuilder("world").insert(0, "hello ").toString();
// "hello world"
```

* You can pass a `StringBuilder` to a method like `println`, which when passed any object will invoke its `toString`.

  ```java
  System.out.println(new StringBuilder("world").insert(0, "hello "));
  ```

<hr>

[Prev](StringBuilder.md) | [Up](README.md) | [Next](toString.md)


## Arrays Revisited

Before discussing other collections in Java, recall these facts about arrays.

* We must know the size of the array when we instantiate it.
  ```java
  String[] arr = new String[5];               // array with 5 null slots
  String[] names = {"Alice", "Mad Hatter"};   // array with two Strings
  ```
* To retrieve an item from an array, find it by zero-based index.
  ```java
  System.out.println(names[0]); // Alice
  ```
* An empty array is filled with default values (zero for numeric primitives, `\u0000` for `char`, `false` for `boolean`, and `null` for object references).
  ```java
  System.out.println(arr[4]);   // {null, null, null, null}
  int[] ints = new int[3];      // {0, 0, 0}
  ```
* An array's size cannot change. Its `length` field is immutable.
  ```java
  System.out.println(names.length); // 2
  names.length = 1;                 // COMPILER ERROR - the final field
                                    // array.length cannot be assigned.

  names[2] = "Queen of Hearts";     // ArrayIndexOutOfBoundsException
  ```

### Practice Exercise
> The fact that an array cannot grow or shrink is a major limitation of arrays.

<hr>

[Prev](README.md) | [Up](README.md) | [Next](arraylist.md)


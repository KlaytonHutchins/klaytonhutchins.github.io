## String Methods That Use Regular Expressions

The `String` class provides methods that use regular expressions.

* `matches(regex)` returns true if the string matches the pattern.

  * The pattern must match the entire string, not just part of it.

    ```java
    "Hello, World".matches("\\w+");       // false
    "Hello, World".matches("\\w*, \\w+"); // true
    ```

* `split(regex)` returns a `String` array containing substrings from the original that were separated by text matching the regex.

  * The matched delimiter text is discarded.

    ```java
    String data = "One potato,two potahto,  three potayto, four";
    String[] fields = data.split(",\\s*");
    for (String field : fields) {
      System.out.println("Field: " + field);
    }
    ```

* `replaceFirst(regex, replacement)` returns a string with the first match of the regex replaced by the _replacement_ string.

  * The original string remains unchanged (a `String` is immutable after all).

    ```java
    String data = "One potato,two potahto,  three potayto, four";
    System.out.println(data.replaceFirst("po\\w+to", "giraffe"));
    // One giraffe,two potahto,  three potayto, four
    System.out.println(data);
    // One potato,two potahto,  three potayto, four
    ```

* `replaceAll()` replaces all matches with the replacement.

  ```java
  String data = "One potato,two potahto,  three potayto, four";
  System.out.println(data.replaceAll("po\\w+to", "giraffe"));
  // One giraffe,two giraffe,  three giraffe, four
  ```

### Drill
> `RegularExpressionsJava/src/com.example.java2.drills.Splitter`
> * The file `pets.txt`	has records whose fields are separated by a tab that's optionally preceded by a comma.
> * Add code to the loop to use a regex with split to split each line and use the fields to construct a `Pet` object and add it to the list.

<br >

### Practice Exercise
> These methods do not take parameters for setting regex options like `CASE_INSENSITIVE` and `MULTILINE`.  However, you can use _embedded flags_ in your regex string itself:
> ```java
> String regex = "(?i)(?m)^error"; // set CASE_INSENSITIVE and MULTILINE
> ```

<hr>

[Prev](groups.md) | [Up](README.md) | [Next](labs.md)


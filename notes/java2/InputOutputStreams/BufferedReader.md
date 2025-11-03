---
layout: default
title: `BufferedReader`
---

## `BufferedReader`

One of the most common computer file types is the _text file_: a file whose character-string records are separated by newlines (or similar record separator.)

* Lines vary in length from zero to any number of characters.

* Lines may be completely unstructured (plain old text), or delimited into fields by say, `,` characters (_comma-separated values_ or _CSV_ files), tabs (_TSV_), `:`, or some other pattern.

The `BufferedReader` class's `readLine` method allows us to easily read a text file one line at a time, retrieving each line regardless of length as a `String` rather than a `char` array.

`BufferedReader` needs a source of input: it just knows how to read lines, it doesn't care where they come from.

### `FileReader`

A `FileReader` wraps a stream of bytes coming from a `File`; it doesn't know how to read lines, just how to retrieve `char`s from the file.

* It has a constructor that takes a filename as a `String`.

  * Because the filename may be incorrect, this constructor throws `FileNotFoundException`, which must be either declared or caught by the caller.

    ```java
    try {
      FileReader fr = new FileReader(fileName);
    }
    catch (FileNotFoundException e) {
      System.err.println("Invalid filename: " + e.getMessage());
    }
    ```
You can pass a `FileReader` object to the `BufferedReader` constructor to provide its source of input.

```java
BufferedReader br = new BufferedReader(fr);
```

### Using `BufferedReader.readLine`

The `readLine` method:
* Reads characters up to and including the line terminator  - `\n`, `\r`, or `\r\n`.
* Discards the line terminator.
* Returns the line as a `String`.
* Leaves the input stream at the position it stopped, awaiting the next read operation.

When there is no more data to read, `readLine` returns `null`, which tells us we're at the end of the file.

Like most `java.io` operations, `readLine` throws `java.io.IOException` which we must declare or catch.

```java
try {
  FileReader fr = new FileReader(fileName);
  BufferedReader br = new BufferedReader(fr);
  String line;
  while ( (line = br.readLine()) != null) {
    System.out.println("Read the line: " + line);
  }
  br.close();
}
catch (FileNotFoundException e) {
  System.err.println("Invalid filename: " + e.getMessage());
  return;
}
catch (IOException e) {
  System.err.println("Problem while reading "+fileName+": "+e.getMessage());
  return;
}
```

### Practice Exercise
> Notice this line:
> ```java
> while ( (line = br.readLine()) != null) { /*...*/ }
> ```
> Because comparison, `!=`, has higher precedence than assignment, `=`, we override precedence by putting the assigment in parentheses, then comparing the resulting value to `null`.

<hr>

[Prev](FileObject.md) -- [Up](README.md) -- [Next](PrintWriterClass.md)


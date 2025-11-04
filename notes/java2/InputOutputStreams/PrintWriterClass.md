---
layout: default
title: `PrintStream` and `PrintWriter`
---


You've been using `PrintStream` since your first "Hello, World" program: `System.out` and `System.err` are `PrintStream` objects.

`PrintStream` provides `print`, `println`, and `printf`, as well as methods for writing `byte`s and `byte` arrays.

`PrintWriter` has all the same methods as `PrintStream`.

* A `PrintWriter` can also write `char` arrays instead of `byte` arrays.

You can construct a `PrintStream` using a `File`, an `OutputStream`, or a filename.

```java
try {
  FileOutputStream fs = new FileOutputStream("test.txt");
  PrintStream ps = new PrintStream(fs);
}
catch (FileNotFoundException e) {
  e.printStackTrace();
}
```
* You can construct a `PrintWriter` using a `File`, an `OutputStream`, a filename, or another `Writer` object.

  ```java
  FileWriter fw = new FileWriter("test.txt");
  PrintWriter pw = new PrintWriter(fw);
  ```

### Practice Exercise
> `PrintStream` was one of the first I/O classes in Java.  When writers were later added to `java.io` to handle character output, `PrintWriter` was created as a replacement for `PrintStream`.  However, `System.out` and `System.err` were already in wide use so they remain `PrintStreams`.  You will usually use `PrintWriter` in your own code.

The various output methods don't throw `IOException`, though constructors might.

```java
  String[] data = { "Cat", "Dog", "Frog", "Giraffe" };
  try {
    FileWriter fw = new FileWriter("test.txt");
    PrintWriter pw = new PrintWriter(fw);
    for (String string : data) {
      pw.println(string);
    }
    pw.close();
  }
  catch (IOException e) {
    e.printStackTrace();
  }
}
```

### Practice Exercise
> Output does not have to go to a file.  The `java.io` package has classes allowing you to use these I/O methods to read and write data in a `String` buffer in memory, or as data streamed between two Java objects in different threads of an application, among other possibilities.  We'll stick with text files here though.

<hr>

[Prev](BufferedReader.md) -- [Up](README.md) -- [Next](ClosingStreams.md)


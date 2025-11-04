---
layout: default
title: Overview of Stream
---


Input and output (I/O) between a Java program and outside systems is conducted through _streams_, which are ordered sequences of data.
  
* A stream is either an input stream, an output stream, or both at the same time.

Streams aren't just for file I/O; their uses include:

* Communication across network sockets.
* I/O to or from a *URL* object, including a servlet.
* Storing and retrieving data based on a `String`, `char[]`, or `byte[]`.
* Reading and writing Large Objects in a database with JDBC.
* Serialization of objects.

The `java.io` package contains the classes, methods, interfaces, and exceptions for basic I/O operations.

* Almost all of the methods in Java's I/O classes throw `java.io.IOException` (or one of its children).

### Bytes and Characters - Streams, Readers, and Writers

We can characterize any Java I/O stream as either a byte stream or a character stream.

#### Binary I/O - Streams

Byte streams always deal with data as streams of 8-bit bytes.

* Byte streams are referred to in Java as _Streams_, with class names like `InputStream` and `OutputStream`.

Any time binary, non-textual data is being manipulated, you will use a stream.

* An `int` written with an output stream is written as the 4-byte `int` bit pattern, not as readable text.

* Stream methods typically use `byte` arrays to receive and return data.

```java
import java.io.IOException;
import java.io.InputStream;

public class InputStreamExample {

  public static void main(String[] args) throws IOException {
    InputStreamExample ise = new InputStreamExample();
    ise.readBytes(System.in);
  }

  private void readBytes(InputStream in) throws IOException {
    byte[] byteBuffer = new byte[20];
    System.out.print("Type at least 20 keystrokes on the keyboard and hit Enter: ");
    in.read(byteBuffer); // Read bytes into buffer until it's full.
    for (byte b : byteBuffer) {
      System.out.println("byte: " + b);
    }
    return;
  }

}
```

#### Text I/O - Readers and Writers

Character streams use 16-bit Unicode characters.

* Character streams are referred to in Java as readers and writers, with class names like `FileReader` and `FileWriter`.

Any time textual data is being manipulated, you will use a reader or writer.

* An `int` written with a writer is written as a sequence of digit characters - readable text.

* For every input stream there is usually a corresponding reader class; for every output stream there is usually a corresponding writer class.

Readers and writers are built on top of streams - a reader has a stream connected to some source of bytes, and interprets those bytes as Unicode character codes.

```java
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class InputReaderExample {

  public static void main(String[] args) throws IOException {
    InputReaderExample ire = new InputReaderExample();
    ire.readText(System.in);
  }

  private void readText(InputStream input) throws IOException {
    // Wrap, or "decorate" the raw byte InputStream with a Reader
    // that interprets the bytes as characters.
    InputStreamReader reader = new InputStreamReader(input);
    // Array of char, not byte.
    char[] charBuffer = new char[20];
    System.out.print("Type at least 20 keystrokes on the keyboard and hit Enter: ");
    reader.read(charBuffer); // read chars into buffer until it's full.
    for (char c : charBuffer) {
      System.out.println("char: " + c);
    }
  }

}
```

### Drill
> Run `InputStreamExample`, then `InputReaderExample`.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](FileObject.md)


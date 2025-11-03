---
layout: default
title: Closing Stream
---

## Closing Streams

Upon opening a stream, your program may acquire resources such as file handles or sockets.

* You must remember to close your stream to release these resources.

  ```java
  FileReader fr= new FileReader("input.txt"); 
  BufferedReader bReader = new BufferedReader(fr); 
  // ...
  bReader.close();
  ```

* For output streams, `close` ensures any written output is flushed to its destination before your program finishes.

One use of a `finally` block is to ensure that a stream is closed whether or not an exception has occurred.

* Since the `close()` method itself may throw an exception, your code may end up unwieldy with a `try`/`catch` block embedded within a `finally` block.

  ```java
  BufferedReader bufIn = null;
  try {
    bufIn = new BufferedReader(new FileReader("input.txt"));
    String line;
    while ((line = bufIn.readLine()) != null) {
      System.out.println(line);
    }
  }
  catch (IOException e) {
    System.err.println(e);
  }
  finally {
    if (bufIn != null) {
      try {
        bufIn.close();
      }
      catch (IOException e) {
        System.err.println(e);
      }
    }
  }
  ```

### The `AutoCloseable` Interface and _`try`-with-resources_

Java 7 introduced the `AutoCloseable` interface:

```java
public interface AutoCloseable {
  void close() throws Exception;
}
```
Implementors of `AutoCloseable` can take advantage of _try-with-resources_ syntax.

* If an implementing object is declared within parentheses after the `try` keyword, Java will automatically invoke its `close` method regardless of how the `try`/`catch` terminates.

  ```java
  try ( BufferedReader bufIn = new BufferedReader(new FileReader("input.txt")) ) {
    String line;
    while ((line = bufIn.readLine()) != null) {
      System.out.println(line);
    }
  }
  catch (IOException e) {
    System.err.println(e);
  }
  ```

* Any catch or finally blocks associated with a _try-with-resources_ statement will run after the resources are closed.

* Since the closeable object must be declared in the `try`, it will be out of scope anywhere else.

### Practice Exercise
> The examples here of opening a file with a `BufferedReader`, reading a line at a time until the end of the file, and closing the file, is code you can copy and paste with minimal modification into any program that reads text data.

<hr>

[Prev](PrintWriterClass.md) -- [Up](README.md) -- [Next](labs.md)


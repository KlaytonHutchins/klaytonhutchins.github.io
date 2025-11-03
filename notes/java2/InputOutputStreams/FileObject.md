## `File` Object

You can use a `File` object to represent the path and filename of file.

* You can construct a `File` object using its relative or absolute pathname.

```java
File f = new File("./input.txt");
```

* The file's length, full directory location, and associated information can be retrieved from the `File` object.

  * `getName()`

  * `getCanonicalPath()`

  * `length()`

* The platform-specific path separator can also be used for more generic naming of paths.

  ```java
  File f = new File("." + File.separator + "input.txt");
  ```

A `File` does not need to represent a file stream that is currently open.

```java
import java.io.File;
import java.io.IOException;

public class FileInfo {
  public static void main(String[] args) {
    File f = new File("employee.txt");
    System.out.printf("The length of %s is %d bytes.%n",
        f.getName(), f.length());

    try {
      System.out.printf("%s has a full path of %s.%n",
          f.getName(), f.getCanonicalPath());
    }
    catch (IOException e) {
      System.out.println(e);
    }
  }
}
```

### Practice Exercise
> When you run a Java program in Eclipse, its _current working directory_ at runtime is the top-level folder of the project itself, not the package, _src_, or _bin_ directory.  Paths to files will be relative to the project directory.

### Drill
> Run `FileInfo`.

Many `java.io` methods take `File` object parameters.

* For convenience, some methods and constructors take filename `String` arguments which they convert internally to `File` objects.

<hr>

[Prev](OverviewofStreams.md) -- [Up](README.md) -- [Next](BufferedReader.md)


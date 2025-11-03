## Static Imports

`import` makes the names of classes and other types from another package part of our current namespace, so we can use them without fully-qualifying them.

* We still use an object reference to access fields and methods.

  ```java
  import com.example.utilities.parsing.Parser;
  // ...
    Parser parser = new Parser();
    parser.parse();
  ```

We can access static fields and static methods without an object reference, using the class name.

```java
//...
  public double getVolume() {
    double volume = 4.0/3.0 * java.lang.Math.PI * java.lang.Math.pow(this.radius, 3);
    return volume;
  }
```

Java allows us to import individual static field and method names into our current namespace using _static imports_.

```java
import static java.lang.Math.PI;
import static java.lang.Math.pow;
//...
  public double getVolume() {
    double volume = 4.0/3.0 * PI * pow(this.radius, 3);
    return volume;
  }
```

```java
import static java.lang.System.out; // out is a static field of java.lang.System

public class Hello {
  public static void main(String[] args) {
    out.println("Hello");
  }
}
```

* _Only_ static fields and methods can be imported this way.

* The syntax is `import static`, not `static import`.

* You can use the `*` wildcard to import all static fields and methods of a class.

```java
import static java.lang.Math.*;
//...
  public double getVolume() {
    double volume = 4.0/3.0 * PI * pow(this.radius, 3);
    return volume;
  }
```

### Practice Exercise
Remember, `import static` imports `static` members of a single class. `import` imports individual classes or entire packages.

<hr>

[Prev](imports.md) -- [Up](README.md) -- [Next](labs.md)


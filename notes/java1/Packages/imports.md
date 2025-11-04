---
layout: default
title: Import
---


To use a class defined in another package we use its _fully-qualified class name_:

```java
package com.example.utilities.app;

public class ParserDriver {
  public static void main(String[] args) {
    com.example.utilities.parsing.Parser parser;
    parser = new com.example.utilities.parsing.Parser();
    parser.parse();
  }
}
```

This gets tedious when we use a lot of classes from other packages.

`import` brings class names into our current program's namespace.

```java
package com.example.utilities.app;

import com.example.utilities.parsing.Parser;

public class ParserDriver2 {
  public static void main(String[] args) {
    Parser parser;
    parser = new Parser();
    parser.parse();
  }
}
```

* The special package `java.lang`, containing classes like `System` and `String`, is automatically imported in every Java program.

Note that we need the entire package name, even if we are in a sibling or parent package.

```java
package com.example;                         // We're in a parent package

// import utilities.parsing.Parser;                  // WILL NOT COMPILE
import com.example.utilities.parsing.Parser; // Correct.

public class MainApp {
  public static void main(String[] args) {
    Parser p = new Parser();
    p.parse();
  }
}
```

We can import individual class names one at a time, or include all names for an entire package using the wildcard `*`.

```java
package com.example.utilities.app;

import com.example.utilities.parsing.*;

public class ParserDriver3 {
  public static void main(String[] args) {
    Parser parser = new Parser();
    parser.parse();
  }
}
```

* Import only makes the other package's names part of our current namespace, it doesn't add actual code to our program.

  * There's no memory or code-size penalty for using `*`.

* Importing a package does not import any sub-packages.

If two imported packages define a class with the same name, we still have to fully-qualify that class in our code.

<hr>

[Prev](packageNames.md) -- [Up](README.md) -- [Next](staticImports.md)


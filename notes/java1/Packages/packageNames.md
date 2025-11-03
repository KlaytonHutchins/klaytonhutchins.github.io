## Package Names

Many Java projects are not applications to be run by users, but libraries of classes to be used by other Java developers in their applications.

This means our project may be published and included in somebody else's project alongside their own classes.

* Two different developers might reasonably have a package called _utilities_.

To minimize the chance of package name collisions, best practice is to choose _globally unique_ package names.

The recommended package naming convention is to use your organization's Internet domain name, in reverse order:

File _/Users/dobbs/Development/Java/com/example/utilities/parsing/Parser.java_:
```java
package com.example.utilities.parsing;

public class Parser {
  public void parse() { /* ... */ }
}
```

* Package names are all-lowercase, to avoid collisions with class names.

* The directory path still has to match the package name.

Each organization decides how to further subdivide and organize packages in their domain.

### Drill
In the `Packages` project use _File_ | _New_ | _Package_ to create a package named `com.example.mypackage.stuff`.
> * Now, outside of Eclipse, browse to your Eclipse workspace directory and find the _Packages_ project directory.  Under this find _src_, and review the package directory structure Eclipse created.


<hr>

[Prev](creatingPackages.md) | [Up](README.md) | [Next](imports.md)


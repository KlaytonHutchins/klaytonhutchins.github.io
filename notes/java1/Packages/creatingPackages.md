## Creating Packages

The `package` statement **must** be the first statement in your class.

* Only comments, not code, can precede the `package` statement.

Just as the name of the public class in a `.java` file must match the file's name, the name in the `package` declaration must match the directory the `.java` file is in.

* In the package name we replace the directory path separator (`\` on Windows, `/` everywhere else) with `.`.

  File _utilities/parsing/Parser.java_:
  ```java
  package utilities.parsing;

  public class Parser {
    public void parse() { /* ... */ }
    public static void main(String[] args) { /* ... */ }
  }
  ```

  * This allows us to organize our project's code hierarchically.

Note that we don't need to use the absolute pathname in our package name.

* If our code is in _/Users/dobbs/Development/Java/utilities/parsing/_, we just use the part of the path that's relevant:

  ```java
  package utilities.parsing;
  ```

To run a class in a package Java needs to know its _fully qualified name_ - that is, both its package and its class names.

```bash
cd /Users/dobbs/Development/Java/
java utilities.parsing.Parser
```

* `java` looks for a directory path matching the package name.

### Classpath

Normally you would make sure your current working directory is at the top of the package directory, so `java` can see the package path.

You can also tell `java` other places to look for packages and classes by specifying a _classpath_.

> #### classpath
> A list of directory locations where Java commands will look for packages and classes.  A classpath can list multiple directories separated by colon, `:`, on Unix/Linux systems or semicolon, `;`, on Windows.

You can set the classpath with the `-classpath` or `-cp` option on the command line, or via the `CLASSPATH` environment variable.

```bash
cd ~   # Go to my home directory
java -classpath /Users/dobbs/Development/Java utilities.parsing.Parser

export CLASSPATH=/Users/dobbs/Development/Java
java utilities.parsing.Parser
```

<br >

### Practice Exercise
One of the many tasks an IDE like Eclipse handles for us is automatically managing the classpath for each project.

<hr>

[Prev](introPackages.md) | [Up](README.md) | [Next](packageNames.md)


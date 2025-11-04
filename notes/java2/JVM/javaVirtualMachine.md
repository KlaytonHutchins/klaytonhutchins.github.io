---
layout: default
title: The Java Virtual Machine
---


![Java Virtual Machine (JVM)](images/jvm.png)

Running the `java` command launches the _Java Virtual Machine_ (_JVM_).

The JVM interprets _bytecode_ - the binary instructions created by the Java Compiler and stored in a `.class` file.

> #### bytecode
> Platform-neutral instructions interpreted by the JVM at runtime.

Bytecode is not specific to any computing platform.

* A Java program compiled on a Mac will run unchanged on Windows, Linux, or any other system with a standard JVM - hence Java's motto: **Write Once, Run Anywhere**.

  * It's the JVM itself that must be customized to each hardware/operating-system environment, not your Java code.

Bytecode consists of numeric instructions that access subroutines built into the JVM.

* The `.class` file also includes all the literal data values from your code, the names of all the classes your code uses, line number information for printing error messages, and other information needed by the JVM.

The JVM has many responsibilities including loading classes your application uses and detecting errors (exceptions).

* One major responsibility of the JVM is managing memory, cleaning up unused data as needed.

You must give `java` the name of a class containing a properly-defined `main` method:

```java
public static void main(String[] args) { /* ... */ }
```

* The class name you give on the `java` command line must correspond to a `.class` file of the same name.

  * If the `.class` file isn't found, or if it doesn't contain a proper `main`, an Error occurs and the JVM exits.

Java begins executing `main`, loading additional classes as needed.

The behavior of the JVM is defined by the [Java Virtual Machine Specification](https://docs.oracle.com/javase/specs/jvms/se8/html/index.html).

* The Sun/Oracle JVM, named _HotSpot_, is by far the most-used.

* Anyone can write their own JVM; as long as it conforms to the JVM Specification it will be able to run any bytecode.



<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](jre.md)


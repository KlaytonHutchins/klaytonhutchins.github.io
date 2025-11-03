## Labs
In this set of labs we will continue to use the `Drawable` interface from the [`java1/Interfaces`](../../java1/Interfaces/usingInterfaces-labs.md) project.

1. Create a new interface named `ThreeDPrintable` that extends `Drawable`, and declares a `void` method `threeDPrint`.  Create a class, `ThreeDModel`, that implements `ThreeDPrintable`.  Just use `println` statements in your method implementations.

   (Solution: _ThreeDPrintable1.java_, _ThreeDModel1.java_)

1. Create a `ThreeDPrinter` class with a private `ThreeDPrintable[]` field.  Make sure it gets initialized with a non-null array.  Give the class a public method allowing a user to add a `ThreeDPrintable` object to the array.  Define a `printAll3DObjects` method that 3-D prints each item in the array.  Create a `PrinterUser` class whose `main` creates a `ThreeDPrinter`, adds some model objects to it, and prints them.

   (Solution: _ThreeDPrinter1.java_, _PrinterUser1.java_)

1. Modify the `ThreeDPrintable` interface, adding a new abstract method `generateWireframe`.  What happens when you save this change?

   Solve this issue by making `generateWireframe` a `default` method, providing a method body with a `println`.

   (Solution: _ThreeDPrintable2.java_, _ThreeDModel2.java_, _ThreeDPrinter2.java_, _PrinterUser2.java_)

<hr>

[Prev](multipleInheritance.md) | [Up](README.md)


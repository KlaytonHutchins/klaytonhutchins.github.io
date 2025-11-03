## Order of Initialization

Java defines the order in which it initializes fields in a class.

1. `static` fields and static initializer blocks, in the order in which they appear in the file.
2. Instance fields and initializer blocks, in the order in which they appear in the file.
3. Constructor code.

`static` fields are initialized _once_, when the class is first used.

* Once the class's fields are initialized, Java doesn't need to initialize them again.

Instance fields are initialized _each time_ an object is created.

### When Does Java Initialize a Class?

Java will not initialize the static members of a class until a program uses the class.<sup>1</sup> This means when:

* An instance of the class is created.
* A static method of the class is invoked.
* A static field of the class is assigned.
* A non-constant<sup>$</sup> static field of the class is used.

<sub>$ - constants will be explained soon</sub>

### Drill
> `ObjectInitialization/com.example.objs2.drills.InitClassProgram`
>
> The classes in this example call static methods to print to the screen. This allows us to see when fields are initialized.
> * Look at `InitClassProgram`. It creates instances of `InitClassOne` and `InitClassTwo`. Review these to see what each does.
> * Run the program to see the order of initialization. Is it what you expected?
> * Create another instance of `InitClassOne`. Run the program again to see order of initialization.
>
> (Solution: _InitClassProgram.java_, _InitClassOne.java_, _InitClassTwo.java_ )
>
> `ObjectInitialization/com.example.objs2.drills.OrderOfInitQuiz`
> * Look at `OrderOfInitQuiz`. In the comments, write what you expect to see printed to the screen, based on order of initialization.
>
> (Solution: _OrderOfInitQuiz.java_)

[1] https://docs.oracle.com/javase/specs/jls/se8/html/jls-12.html#jls-12.4.1

<hr>

[Prev](init-instance.md) | [Up](README.md) | [Next](final.md)


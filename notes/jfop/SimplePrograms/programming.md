## Programming
A computer program is a set of detailed instructions that tell a computer to
perform some specific task.

Programs are detailed and carefully sequenced.

Computer programming is the art of communicating _algorithms_ to computers.

> #### algorithm ####
> A computational procedure whose steps are completely specified and elementary.[1]

A program has the instructions that tell the computer what we need done. Each time a computer needs to perform a specific task, it has to follow the same instructions — the computer program — over and over again.

### Drill
`simpleprograms/drills/`
* The classic program to write, no matter what language you're using, is a program that prints the words "Hello, world!" on your screen.
* Create a file called `Hello.java` and type the following program.
  * Be sure to type the program, rather than copying and pasting.
  ```java
  // A simple Hello, world program
  // Note: The file name must be the same as the
  // class name, with a .java extension.
  public class Hello {
    public static void main(String[] args) {
      System.out.println("Hello, world");
    }
  }
  ```
* Make sure the file name is the same as the class name, `Hello`, with a `.java` extension.
* Compile the program using the command `javac Hello.java`.
* If there are no errors, run the program with the command `java Hello`.


[1] Al Kelley & Ira Pohl, _A Book on C_.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](programming-process.md)


---
layout: default
title: The `main` Method
---

## The `main` Method

Since your very first Java program you've written this method:

```java
public static void main(String[] args) {
}
```
* We know this special method is what Java looks for as the starting point for running your program, but what about that `String[] args`?

### Drill
`ArgsArray/src/drills/`

In the `drills` folder create a new Java program, `ShowMe.java` and give it a `main` method.
* In `main` add:
  ```java
  System.out.println(args);
  ```
  and run the program.

---

### Practice Exercise
When you print the reference value for an array, you'll see something like:
* `[Ljava.lang.String;@3d4eac69`
* `[` means it's an array reference.
* `L` means the elements of the array are objects of a cLass.
* `java.lang.String;` is the class of objects the array holds.
* `@3d4eac69` is ... well, never mind for now.

---

To understand `args` we need to go back to the command line.

### Drill
Open a terminal and navigate to the Eclipse project folder for this section.
```bash
cd ~/SD/Java/workspace/   # Go to the workspace directory
ls                        # list the files and folders here
cd ArgsArray/             # Go to the project folder for this section
find .                    # Find and print the name of everything in and under the current directory.
cd bin/                   # This is where Eclipse puts compiled classes.
```
Were going to run our `ShowMe` program from the command line:
```bash
java drills.ShowMe
```
As we modify `ShowMe.java` in Eclipse and save, Eclipse compiles our changes and recreates `drills/ShowMe.class`, which we'll run in our terminal with `java drills.ShowMe`.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](argsArray.md)


## The `main` Method

We have been using `public static void main(String[] args)` in our programs. This `main` method is a special method that the `java` command knows to look for in order to run a program.

* If your class doesn't have a properly declared `main` method, Java can't
start your program.

* If your `main` method doesn't do anything, your program won't do
anything.

### Practice Exercise
If your `main` method is not defined correctly, the `java` command will throw an error. For example, this `main` method does not have the `[]` inside the parentheses.

```
public static void main(String args) {

}

Error: Main method not found in class MyClass, please define the main method as:
   public static void main(String[] args)
```

<hr>

[Prev](calling.md) -- [Up](README.md) -- [Next](why.md)


## Labs
In this lab we will use exceptions to validate user input.

Starter code in `Exceptions/com.example.exceptions.labs.shapes`.

Solutions in `Exceptions/com.example.exceptions.solutions.shapes`

1. Modify the setter for the `Circle` class's `radius`.  Unless the provided radius is greater than zero, throw an `IllegalArgumentException` with an appropriate message.  Do the same for the `width` and `height` setters in `Rectangle`.  What happens when you run `ShapeTester`?

   (Solution: _Circle.java_, _Rectangle.java_, _ShapeTester.java_)

2. Modify _ShapeTester_, adding a `try`/`catch` so that if an exception occurs while adding shapes, its message will be printed to STDERR, but any previously-added shapes will still be printed.

   (Solution: _ShapeTester2.java_)

3. Modify _ShapeTester_ again, so that if an exception occurs while adding a shape, shapes will continue to be added and all that were added will be printed.

   (Solution: _ShapeTester3.java_)

4. In `Circle`, change the setter for `radius` so that instead of `IllegalArgumentException` it throws `Exception`.  Make whatever additional changes are necessary so that you can run `ShapeTester`, with `ShapeTester` receiving any thrown exception.  Make the same changes to `Rectangle`.

   (Solution: _Circle2.java_, _Rectangle2.java_, _ShapeTester4.java_)

<hr>

[Prev](finally.md) -- [Up](README.md)


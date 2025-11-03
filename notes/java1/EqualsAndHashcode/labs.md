## Labs
In these labs we will practice using `equals` and `hashCode`.

1. The `RGBColor` class has three integer fields.  Add an `equals` method to `RGBColor` so the tests shown in `TestColor` come out correctly based on the values of the three integer fields.

   (Solution: _RGBColor.java_)

2. In `RGBColor`, implement the `hashCode` method. Starting with a prime number like `17`, multiply the prime number by itself and each of the three field values, adding the result back to the prime after each multiplication.

   (Solution: _RGBColor2.java_)

3. The `Triangle` class has two `int` fields, `base` and `height`.  Write an `equals` method for it so the tests in `TestTriangle` come out correctly.

   (Solution: _Triangle.java_)

4. The `ColorTriangle` class extends `Triangle`, adding a field of type `RGBColor`.  Give `ColorTriangle` an `equals` method that invokes `Triangle`'s `equals` to check `base` and `height`, and also uses `RGBColor`'s `equals` to compare the `color` field.

   (Solution: _ColorTriangle.java_)

5. In `Triangle`, comment out your `equals` method.  In the Eclipse _Source_ menu, use _Generate hashCode() and equals()_ to see Eclipse's default implementations for these methods.  Do the same with your `ColorTriangle` class.

   (Solution: _Triangle2.java_,
              _ColorTriangle2.java_)

<hr>

[Prev](hashCode.md) -- [Up](README.md)


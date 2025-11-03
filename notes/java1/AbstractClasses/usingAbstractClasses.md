## Using Abstract Classes

Users of subclasses can declare variables and method parameters of the abstract class type, assigning references to concrete subclass objects.

```java
// abstract      concrete
Number n    =    new Double(1.0);
```

* The using class is guaranteed the subclass objects implement the abstract methods.

```java
  public static void main(String[] args) {
    // java.lang.Number is an abstract class.
    Number[] nums = new Number[10];         // Array of 10 Number references

    nums[0] = Integer.valueOf(299_792_458);
    nums[1] = Double.valueOf(3.1415);
    nums[2] = Float.valueOf(2.414F);
    nums[3] = 6.626e-34;                    // Autobox double literal to Double.
    nums[4] = Double.valueOf(8.987e9);
    nums[5] = Byte.valueOf("13");
    nums[6] = Short.valueOf((short)32766);  // cast int literal to short.
    nums[7] = Double.valueOf(Double.parseDouble("6.022e23"));

    printNumbers(nums);
  }

  private static void printNumbers(Number[] nums) {
    for (Number number : nums) {
      if (number != null) {
        System.out.println( number.getClass().getSimpleName()
            + " as a long: "       + number.longValue()  // longValue() and doubleValue()
            + " and as a double: " + number.floatValue() // are abstract methods of Number
        );
      }
    }
  }
```

### Practice Exercise
> `java.lang.Class`
>
> Every object is an instance of some class.  A `Class` object represents a class or interface that the JVM has loaded at runtime.  The `getClass` method every object inherits from `java.lang.Object` returns a reference to a `Class` object describing the class that object belongs to.
> `Class` provides methods for retrieving all information about the class - its fields, methods, constructors, package, simple or fully-qualified class name, etc.
>
> `Class` also provides methods for causing a class to be loaded dynamically at runtime.

<hr>

[Prev](abstractMethods.md) -- [Up](README.md) -- [Next](labs.md)


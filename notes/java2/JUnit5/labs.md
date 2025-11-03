## Labs

The `String` method `public String substring(int beginIndex, int endIndex)` returns a substring of a `String` instance. Create a new JUnit 5 (_JUnit Jupiter_) test case for this method, with test methods that:

1. Test that `"abcdefg".substring(1, 5)` returns `"bcde"`.
1. Test that `"abcdefg".substring(0, 7)` returns `"abcdefg"`.
   * This method's purpose is to test that `beginIndex` is inclusive and `endIndex` is exclusive (note that character `7` is the `length()` of this `String`). The method should state this purpose.
1. Test that `substring` throws `IndexOutOfBoundsException`
   * if the `beginIndex` is negative.
   * if `endIndex` is larger than the length of this `String` object.
   * if `beginIndex` is larger than `endIndex`.
1. The [String specification](https://docs.oracle.com/javase/8/docs/api/java/lang/String.html) says `substring` throws `IndexOutOfBoundsException`; this is correct, according to the spec.
   * Test that the exception thrown by `substring` is actually `StringIndexOutOfBoundsException`, a subclass of `IndexOutOfBoundsException`.
     * Use the methods `getClass()` and `getSimpleName()` to get the exception's name.

(Solution: _SubstringTests.java_)

### Practice Exercise
> The `substring` specification is correct because `StringIndexOutOfBoundsException` _IS-A_ subclass of `IndexOutOfBoundsException`.
>
> Another JVM may throw `IndexOutOfBoundsException` - not its subclass - and still comply with the spec.
>
> Therefore, if we are asked what `substring` throws, we say `IndexOutOfBoundsException`.

<hr>

[Prev](exceptions.md) | [Up](README.md)


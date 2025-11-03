## `Boolean`

`Boolean`'s `valueOf` returns one of two pre-constructed `Boolean` objects: `Boolean.TRUE` or `Boolean.FALSE`.

```java
Boolean boolObject;
boolObject = Boolean.valueOf(true);
System.out.println( boolObject == Boolean.TRUE ); // true: valueOf returned reference to Boolean.TRUE
boolObject = Boolean.valueOf("true");
System.out.println( boolObject == Boolean.TRUE ); // true: valueOf returned reference to Boolean.TRUE
```

* Autoboxed `Boolean`s use these cached objects as well.

  ```java
  Boolean b = true;
  System.out.println(b == Boolean.TRUE); // true: autoboxing calls valueOf, which returned ref to Boolean.TRUE
  ```

`Boolean`'s `parseBoolean`, which is used by both `valueOf` and the `String`-argument constructor, returns `true` if the passed `String` is equal to `"true"`, ignoring case; otherwise `false`:

```java
public final class Boolean implements java.io.Serializable,
                                      Comparable<Boolean>
{
//...
    public static boolean parseBoolean(String s) {
        return ((s != null) && s.equalsIgnoreCase("true"));
    }
//...
}
```

* Whitespace is NOT ignored.

`Boolean`'s `toString` produces either `"true"` or `"false"`.

### Drill
Which of these statements will print `true`?

```java
System.out.println( Boolean.parseBoolean(" true ") );
System.out.println( Boolean.parseBoolean("true") );
System.out.println( Boolean.parseBoolean(null) );
System.out.println( Boolean.valueOf(true) );
System.out.println( Boolean.valueOf("trUE") );
System.out.println( Boolean.TRUE );
```

<hr>

[Prev](Character.md) | [Up](README.md) | [Next](labs.md)


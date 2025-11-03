## Interface Fields

An interface can declare fields, which are implicitly `public`, `static`, and `final`.

* That is, interface fields are constants that can't be changed by their implementing classes or anyone else.

* None of these modifier keywords is required, but any are allowed and no others are allowed.

* Interface fields are `final`; interfaces have no constructors and cannot define instance initializers, so initialize interface fields in their declarations.

  ```java
  public interface ConstantsInterface {
    // All of theses are valid interface field declarations
    // All are public, static, and final:
    public static final int A = 1;
    public static int B = 2;
    public final int C = 3;
    static final int D = 4;
    static int E = 5;
    final int F = 6;
    public int G = 7;
    int H = 8;
  }
  ```

Interface fields can be accessed directly via the interface, or via an implementing class or object.

```java
public class ConstantsImplementer implements ConstantsInterface {
  public void aMethod() {
    System.out.println(this.A);
    System.out.println(B);
    System.out.println(ConstantsInterface.C);
//    this.D = 100;  // WILL NOT COMPILE: final field can't be reassigned.
  }
}
```
```java
public class ConstantsTester {
  public static void main(String[] args) {
    ConstantsImplementer imp = new ConstantsImplementer();
    int x = imp.A;
    int y = ConstantsInterface.B;
    int z = ConstantsImplementer.C;
  }
}
```

### Drill
>
> What will happen when you try to compile and run this code?
>
> ```java
> interface SomeInterface {
>   int value = 0;
> }
> public class SomeClass implements SomeInterface {
>
>   public static void main(String[] args) {
>     SomeClass c = new SomeClass();
>     c.doStuff();
>   }
>
>   private void doStuff() {
>     value = 1;
>     System.out.println("Doing stuff: " + value);
>   }
>
> }
> ```
> 1. [ ] It will print "Doing stuff: 0"
> 2. [ ] It will print "Doing stuff: 1"
> 3. [ ] It will not compile
> 4. [ ] It will throw an exception at runtime
>
> (Solution: _SomeClass.java_)

<hr>

[Prev](intro.md) -- [Up](README.md) -- [Next](interfaceInheritance.md)


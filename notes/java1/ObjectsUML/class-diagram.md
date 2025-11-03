## UML Class Diagram

The class diagram is a static diagram which describes the class structure of an application.

It is the most common starting point for software developers and architects when designing a system.

### Class

A class is represented with a box containing three parts.

* Name
* Attributes (fields)
* Methods

![Class Diagram](images/classDiagram.png)

### Visibility

We denote the visibility of attributes and methods with the following notations.

| Marker | Visibility|
| ------ | --------- |
| + | public |
| # | protected |
| ~ | package |
| - | private |

### Attributes (Fields)

Attributes are listed by `name:Type`.

We add a visibility notation before each field.

`static` fields are underlined.

For the fields

```java
  private String str;
  protected int intField;
```

...we write

```
- str: String
# intField: int
```

### Methods

Each method is written using its signature and return type, in the form `visibility signature():ReturnType`.

Constructors do not list a return type.

For the constructor and methods
```java
  public ExampleClass(){

  }

  public String getStr() {
    return str;
  }

  public void setStr(String str) {
    if(str == null) {
      str = "";
    }
    this.str = capitalizeStr(str);
  }

  private String capitalizeStr(String input) {
    return input.toUpperCase();
  }

```
...we write
```
+ ExampleClass()
+ getStr():String
+ setStr(String):void
- capitalizeStr(String):String
```
Note that we do not use parameter names in the parentheses, just their types.

### Example Diagram

Note the `private` and `protected` fields, and `public` and `private` methods, of this class:
```java
public class ExampleClass {
  private String str;
  protected int intField;

  public ExampleClass() {

  }

  public String getStr() {
    return str;
  }

  public void setStr(String str) {
    if(str == null) {
      str = "";
    }
    this.str = capitalizeStr(str);
  }

  private String capitalizeStr(String input) {
    return input.toUpperCase();
  }
}
```

![ExampleClass class diagram](images/classDiagram2.png)

<hr>

[Prev](drawing-objects.md) | [Up](README.md) | [Next](has-a.md)


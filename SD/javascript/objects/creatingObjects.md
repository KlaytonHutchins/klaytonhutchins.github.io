## Creating JS Objects

JavaScript has a similar object constructor to object-oriented languages, and you can create a new instance of a JS object with the `new` keyword:

```javascript
let obj = new Object();
```

JavaScript object programming commonly simplifies object creation by using the *object literal syntax*:

```javascript
let literalObj = {};
```

### Example
* JS Objects are composed of *key-value* pairs, similar to a Java `HashMap`.

* A newly created instance of `HashMap` does not have any keys or values, it is an empty collection. This is roughly equivalent to a newly defined JavaScript object literal (`{}`).

```java
// Java
public static void main(String[] args) {
  Map<String, String> dog = new HashMap<>();
}
```

```js
// JavaScript
let dog = {};
```

<hr>

[Prev](overview.md) | [Up](README.md) | [Next](initializingWithProperties.md)


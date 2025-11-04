---
layout: default
title: Representation
---


REST clients and servers retrieve and transmit _representations_ of resource state.

In an OO application, this involves _serializing_ an in-memory object to a form that can be transmitted over HTTP.

* This serialized representation can be _deserialized_ to create an identical object.

> #### serialization
> Translating an object's state to a sequence of bytes that can be saved or transmitted, allowing reconstruction of a copy of the original object.

This representation can take many forms; XML and JSON are common.

```java
Book b = new Book(17, "Godel, Escher, Bach", new Author(3, "Douglas", "Hofstadter"), "978-0-465-02656-2");
```

* XML

  ```xml
  <book>
    <id>17</id>
    <title>Godel, Escher, Bach</title>
    <author>
      <id>3</id>
      <firstName>Douglas</firstName>
      <lastName>Hofstadter</lastName>
    </author>
    <isbn>978-0-465-02656-2</isbn>
  </book>
  ```

* JSON (JavaScript Object Notation)

  ```javascript
  {
    "id": 17,
    "title": "Godel, Escher, Bach",
    "author": {
                "id": 3,
                "firstName": "Douglas",
                "lastName": "Hofstadter"
              },
    "isbn": "978-0-465-02656-2"
  }
  ```



<hr>

[Prev](restEndpoints.md) -- [Up](README.md)


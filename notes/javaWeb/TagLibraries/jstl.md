---
layout: default
title: JSP Standard Tag Library
---

## JSP Standard Tag Library

The JSP Standard Tag Library (JSTL) was developed to encapsulate common functionality, such as conditionals and iteration, into reusable actions.

* The tags rely on an external dependency, so you must add them to your `pom.xml`.

  ```xml
  <dependency>
    <groupId>javax.servlet</groupId>
    <artifactId>jstl</artifactId>
    <version>1.2</version>
  </dependency>
  ```

  * This is in addition to the `javax.servlet-api` dependency.

    ```xml
    <dependency>
     <groupId>javax.servlet</groupId>
     <artifactId>javax.servlet-api</artifactId>
     <version>3.1.0</version>
    </dependency>
    ```

* To use the tags, you must add the `taglib` directive to your JSP page to specify the tag library uri and prefix.

```xml
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
```

We can combine the tags with JSP EL to change what our pages display.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](conditionals.md)


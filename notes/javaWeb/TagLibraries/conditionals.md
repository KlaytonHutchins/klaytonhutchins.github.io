---
layout: default
title: JSTL Conditional
---

## JSTL Conditionals

For a simple if statement, use the `<c:if>` tag.

```xml
<c:if test="${boolean expression}">
  <%-- content to include if the conditional is true --%>
</c:if>
```

For more complex conditionals, use the `<c:choose>` tag.

* Use `<c:when>` tags for each condition and an optional `<c:otherwise>` tag for any conditions that do not match.

  ```xml
  <c:choose>
    <c:when test="${boolean expression}">
      <%-- ... --%>
    </c:when>
    <c:when test="${boolean expression}">
      <%-- ... --%>
    </c:when>
    <c:otherwise>
      <%-- ... --%>
    </c:otherwise>
  </c:choose>
  ```

> ### Practice Exercise
> There is no `else` tag. You must use `<c:choose>` if you want to do an if/else-if/else.

<br >

> ### Drill
> `TagLibraries/src/main/webapp/WEB-INF/select.jsp`
>
> * If the selected Stock's price is over $75, surround it with a  `<strong>` tag.
> * If the selected Stock's price is under $35, surround it with an `<em>` tag.
>
> Be sure to add the `core` library's taglib to the JSP page.
>
> ```xml
> <%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
> ```
>
> Test cases: ZTS, AAC
>
> (Solution: _/WEB-INF/solutions/select.jsp_)

<hr>

[Prev](jstl.md) -- [Up](README.md) -- [Next](list-iteration.md)


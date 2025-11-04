---
layout: default
title: JSTL - Formatting
---


JSTL provides a set of tags to assist with Internationalization (I18N) of your JSP documents.

  * These tags are also referred to as formatting tags.

  * To use these tags, you must add a different taglib directive to specify the tag library uri and prefix.

  ```xml
  <%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt" %>
  ```

To format a number, use the `<fmt:formatNumber>` tag.

  * Use the value attribute to specify the number to format.

    * The value can contain JSP EL.

  * Use the type attribute to specify how to format.

    * Possible values are `currency`, `percent`, and `number`.

    ```xml
    <fmt:formatNumber value="18.99" type="currency"/>

    <fmt:formatNumber type="currency" value="${cartItem.price }"/>
    ```

To format a date, use the `<fmt:formatDate>` tag.

  * For the type attribute specify either `date`, `time`, or `both`.

> ### Drill
> `TagLibraries/src/main/webapp/WEB-INF/listStocks.jsp`
>
> * Format the Stock price as currency. (Don't forget to add the `fmt` taglib directive.)
>
> `TagLibraries/src/main/webapp/WEB-INF/select.jsp`
>
> * Format the Stock price as currency.
>
> (Solution: _TagLibraries/src/main/webapp/WEB-INF/solutions/listStocksFmt.jsp_, _TagLibraries/src/main/webapp/WEB-INF/solutions/selectFmt.jsp_)

<hr>

[Prev](map-iteration.md) -- [Up](README.md) -- [Next](escaping.md)


## JSTL - List Iteration

Use the `<c:forEach>` tag to iterate over arrays and collections.

* Specify the loop variable using the `var` attribute.
  * Use the loop variable as you would any other single EL variable.

* The `items` attribute is used to indicate what to iterate over, and the name used inside the `${ }` is what we added in the servlet.

  * Iterator, List, Set, and arrays are all allowed datatypes.
  * In the example below, the collection `students` has been added to the model.

  ```xml
  <c:forEach var="s" items="${students}">
  <tr>
    <td>${s.id}</td>
    <td>${s.name}</td>
  </tr>
  </c:forEach>
  ```

  We can give `var` any valid variable name.

  ```xml
  <ul>
  <c:forEach var="x" items="${students}">
    <li>${x.name}</li>
  </c:forEach>
  </ul>
  ```

> ### Drill
> `TagLibraries/com.example.taglibraries.drills.servlets.StockServletList`
>
> * Get all stocks from the StockProvider and add them to the request using `req.setAttribute(key, value)`.
>
> `TagLibraries/src/main/webapp/WEB-INF/listStocks.jsp`
> * Iterate through the Stocks and print all data in a table row.
>
> (Solution: _TagLibraries/src/main/webapp/WEB-INF/solutions/listStocks.jsp_, _com.example.taglibraries.solutions.servlets.StockServletList_)

<hr>

[Prev](conditionals.md) -- [Up](README.md) -- [Next](map-iteration.md)


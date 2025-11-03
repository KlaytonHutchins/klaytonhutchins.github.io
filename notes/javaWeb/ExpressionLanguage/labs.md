## Labs

If you have not finished the drills in this chapter, copy the source from

* `com.example.el.solutions.servlets.StockServletProperties`

* `src/main/webapp/WEB-INF/solutions/selectProperties.jsp`


In this set of labs we will modify our application to maintain and display a running list of requested stocks.

1. Add a `List<Stock>` field to `StockServletJSP` and initialize it to an `ArrayList` in `init()`.
   * When a user requests a valid stock, add it to the list.
   * Add the list to the model.

2. In `select.jsp`, output the list of stocks.
   * Can you use EL to call `${stock.toString()}` in the JSP, or does the JSP do so for you?

(Solution: _StockServletList.java_, _/WEB-INF/solutions/selectList.jsp_)

<hr>

[Prev](el-ops.md) -- [Up](README.md)


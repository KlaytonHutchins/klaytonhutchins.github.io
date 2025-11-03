## Labs

A servlet in this lab uses a `StockProvider` object that queries a database. We need to load the database it uses.

`JSPViews/DBSETUP.txt`

* Follow the instructions in this file to load the `stockdb` database.

Now we will change a servlet to display different JSP's depending on what it finds in the database.



1. Create a new JSP page `/WEB-INF/views/error.jsp`.
   * Add the text `Invalid Stock requested.`
   * Add a link to `selectJSP.html` to return to the search.
   * Style the page however you wish.

   (Solution: _WEB-INF/solutions/views/error.jsp_)

2. In `StockServletJSP`, if the requested stock does not exist, select your error page as the view. Otherwise, continue to select `/WEB-INF/select.jsp`.

   (Solution: _StockServletJSPError.java_)

<hr>

[Prev](mvc.md) | [Up](README.md)


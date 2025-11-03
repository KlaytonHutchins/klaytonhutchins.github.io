---
layout: default
title: Lab
---

## Labs
In this lab we will use JSTL and JSP to display information on a page. We will change the existing method in `StockServletList` to handle an additional request parameter, and, based on this parameter's presence, choose a different view to display different data.

1. Add a form to `index.html` to search for a Stock by first letter. Pass the parameter `search` to the URL `listStocks`.

2. In `StockServletList`, if `search` is passed, filter the list of Stocks for Stocks whose name or symbol starts with the search string. Add those stocks to the model, or add an empty list. Also add the search string to the model.

3. Modify `listStocks.jsp`.
   * Show the user's search string. Be sure to escape it.
   * If the list of Stocks is empty, display `No stocks found`.
   * Otherwise display the Stocks.

(Solution: _src/main/webapp/indexSearch.html_, _StockServletSearch_, _WEB-INF/solutions/results.jsp_)

<hr>

[Prev](escaping.md) -- [Up](README.md)


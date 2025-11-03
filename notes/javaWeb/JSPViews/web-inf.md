## The `WEB-INF` Directory
So far we have used JSP pages from the `WEB-INF` directory.

```java
req.getRequestDispatcher("/WEB-INF/select.jsp").forward(req, resp);
```

This is not required, but is good practice.
* `WEB-INF/` is not accessible to users directly; for example, a user cannot successfully request `http://examplesite.com/WEB-INF/select.jsp`

However, if we put our JSP pages in `src/main/webapp`, they could be accessible, depending on the web container.
* The server could return the JSP page's content without any processing.

We can ensure we are not sending any raw JSP by putting JSPs in `WEB-INF/` (or its subfolders) and using servlets to select our views.

> ### Drill
> With your `JSPViews` project running on Tomcat, request this page directly:
>
> http://localhost:8080/JSPViews/WEB-INF/select.jsp

<hr>

[Prev](using-jsp.md) -- [Up](README.md) -- [Next](mvc.md)


---
layout: default
title: Lab
---

## Labs
In this lab we will add our own servlet to the web application, and change the existing servlet to display a link that leads to the new servlet.

1. Create a servlet named `GoodbyeServlet` in the `...labs` package.
   * Be sure the class extends `HttpServlet`.
   * Override/implement the `doGet()` method.
   * Add to the response a valid HTML document saying "Goodbye World!".

1. Map the servlet to the URL `*.do` in `src/main/webapp/WEB-INF/web.xml`.
   * This means a request to `whatever.do` or `voo.do` will be handled by this servlet.

1. Add an HTML link in `src/main/webapp/index.html` to a URL that will reach your servlet, such as `inventory.do`.

1. Test the app by running it on Tomcat (_Run As->Run on Server_).

1. Open `...examples.HelloWorldServlet`. Add a link in the response HTML to your `Goodbye` servlet.

1. Test the app.

(Solution: _solutions.labs.GoodbyeServlet_, _solutions.labs.HelloWorldServletWithGoodbye_,  _src/main/webapp/index3.html_, _solutions.labs.webGoodbye.xml_ )

<hr>

[Prev](webxml.md) -- [Up](README.md) -- [Next](war.md)


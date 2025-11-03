---
layout: default
title: Servlet Lab
---

## Servlet Lab
In this lab we will change the output of an existing dynamic webapp and deploy it to Tomcat.

1. In `JavaWebIntro/src/main/webapp/index.html`, add a link to `inventory` with the text `List Inventory`.
   * Note: the link's destination is not `inventory.html` or `/inventory`.

1. In `JavaWebIntro/src/com.example.javaweb.labs.InventoryServlet`:
   * After `<body>`, add a `h1` header to the output stream, that says `Inventory`. Use `HelloWorldServlet` as an example for adding HTML to the response.
     ```java
     pw.println(" <h1>Inventory</h1>");
     ```

   * Add the products to the response as an unordered list.
     ```java
     pw.println("<ul>");
     for (String s : inventory) {
       pw.println("<li>");
       pw.println(s);
       pw.println("</li>");
     }
     pw.println("</ul>");
     ```

1. Run the project on the Tomcat server and access the servlet via `index.html`.

1. (Optional) Add Bootstrap configuration in the output's `<head>`, and place the content in a `<div class="container">`.

(Solution: _JavaWebIntro/src/main/webapp/index2.html_, _JavaWebIntro/src/com.example.javaweb.solutions.labs.InventoryServlet_ )

<hr>

[Prev](servlet.md) -- [Up](README.md) -- [Next](configuration.md)


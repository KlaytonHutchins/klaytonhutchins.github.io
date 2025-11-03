---
layout: default
title: Lab
---

## Labs
We will create a new Dynamic Web Application which displays lotto numbers, and deploy it to Tomcat.

1. Create a new Dynamic Web Project called `LotteryApp`.
   * Select the option to generate the _web.xml_ deployment descriptor.
1. Configure the project to use Maven.
   * Add the servlet-api dependency.
     ```xml
     <dependencies>
     	<dependency>
     		<groupId>javax.servlet</groupId>
     		<artifactId>javax.servlet-api</artifactId>
     		<version>3.1.0</version>
     	</dependency>
     </dependencies>
     ```
1. Create a new servlet `com.example.lotto.servlets.LotteryServlet`.
   * Be sure to extend `HttpServlet`.
   * Override `doGet()`.

1. Create a new HTML page, _src/main/webapp/index.html_. This will be the homepage of your web app.
   * Add a link to `numbers` reading _Get Lotto Numbers_.

1. Configure _web.xml_:
   *  _index.html_ is the welcome file.
   * Map _LotteryServlet_ to the URL `/numbers`.

1. Run your web app on Eclipse's Tomcat Server. Issues are likely mapping or file locations. Make sure _index.html_ is in the _src/main/webapp_ folder.

1. Your `LotteryServlet` class will get PowerBall numbers from another class.
   * Use `DynamicWebApps/com.example.lottery.powerball.PowerBallDrawing`, which returns a `PowerBallDrawingResult` object, or copy your PowerBall code.

1. In your servlet, use the PowerBall classes to generate PowerBall numbers, and add the numbers to the response as HTML.

(Solution: _LotteryAppSolution/_)

<hr>

[Prev](servlet.md) -- [Up](README.md) -- [Next](2-labs.md)


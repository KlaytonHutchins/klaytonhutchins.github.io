---
layout: default
title: Servlet Quiz
---


This quiz tests basic knowledge of HTML forms, passing data to Servlets, adding data to the JSP's model, and displaying the data using Expression Language.

### Setup
1. Download and import the zip file [ServletQuiz.zip](resources/ServletQuiz.zip)
2. _Refactor|Rename_ the project to `ServletQuiz_YOUR_GITHUB_USERNAME`


You will make changes in the following files. (Files include the instructions listed below.)

### `src/main/webapp/index.html`
Add a form to search for a planet by name.

Requirements:

* submit the data to the URL "getplanet" using a POST
* add a text field to pass the parameter "pname" to the "getplanet" URL
* (Don't forget to include a submit button)

### `com.example.quiz.servlets.PlanetServlet`
1. Get the request parameter `"pname"`
2. Use `pNameValue` to get a planet by name from the dao
3. If the planet from the DAO is not null, add it to the model with the key `"planet"`
4. Select and forward to the JSP view `"/WEB-INF/planetinfo.jsp"`

### `/WEB-INF/planetinfo.jsp`
* If "planet" is in the model, display the planet's name, orbit, and diameter.

* If "planet" is not in the model, display the text "No planet found".

## Completion
When you finish:
* Select your project and use _File_ | _Export_ | _Archive File_ to export your project to a ZIP file.
* Upload the ZIP export file to your private homework Slack channel.

<hr>

[Up](../README.md)

---
layout: default
title: Event Tracker
---

### Overview
This project is as much about using JSON and SpringREST as it is handling JSON responses with JavaScript.

You are embarking on a weekend project that you may or may not come back to afterwards, thus we would caution you to limit your scope significantly. Last weekend we created a RESTful API that provided us with the ability to perform full CRUD on an event entity of our choosing.

This weekend we will be building out the front end for this application using Javascript.

### Learning Objectives
* Adding scripts to a web application
* Send asynchronous requests to Java controllers with JavaScript's `XMLHttpRequest
* Consume and parse JSON responses with JavaScript  
* Build HTML with JavaScript  
* Send POST/PUT/DELETE requests with `XMLHttpRequest`

### Where to start?

1. Add JavaScript functionality
   * Create an `index.html` file in `src/main/resources/static/`
   * Create a `js/` folder in the `src/main/resources/static/` folder and add a `script.js` file. Source it into your `index.html` file.

1. Get all events and display them.
   * In an on load event lister, call a function that executes an `XMLHttpRequest` to get all of your event objects.

   When the request returns successfully, build a table to display the list of data.

1. Create a new event
   * On the main page there should be a form that allows you to create a new entity. This form can be hard coded into your HTML document. When the submit button is pressed it should build a JSON object from the form field valuse, and send it to your POST route. If the request is successful, reload your list of all the events so it includes your newly created object.

1. Update and delete
   * Once the table is built, if a row is clicked on, a detail view for just that one entity should be displayed. You will accomplish this by adding a `click` event listener to each row of your table.
   * In the detail view you should have a form giving you the option to edit the entity, and a delete button that would delete the current entity and reload the view all view.

1. Add data aggregation
   * Once your presentation for CRUD is working, add a function that uses the response data to present the data in some other form (For instance, total all of the hours you worked and calculate the amount of money you are owed. This would involve retrieving all of the "PunchCard" records, totaling their values, and displaying the total multiplied times your hourly rate somewhere on the page.)  

### Goal

Your objective for this project should be to do as much as you can. That is not to say as many features, but as much as you actually understand. Do not move onto the next step until you actually know what you just did and feel comfortable with what is happening. If you reach a point and are confused about what you are doing, or what you have done, ask questions, look for resources, or start over on that piece to ensure that you are comfortable with it. For some of you DOM manipulation will be tricky to conceptualize, others will struggle with AJAX and the nature of asynchrony, and some will have a hard time conceptualizing JSON as a representation of objects and feel uncomfortable routing with it. All of these difficulties are understandable and the reason we are doing this project is to struggle through them.  

#### Grading

This is a graded project.  You are expected to have your project completed by Monday morning.

You will be given either a pass or fail based on whether your code works given all of the following test conditions:

* A new event object implements full CRUD.  
* All interactions with the database are done so RESTfully.  
* App uses Javascript to access data and manipulate the DOM.  
* App presents the aggregated data in some additional format.  

If the project does work with all of the above test conditions, you will be given a *1* for this week's project.

If the project does not work with the above test conditions, you will be given a *0* for this week's project.

If you get a zero on the project, you can upgrade to a score of *.5* if you turn in a working project by the start of class the following Monday morning AND notify an instructor that you wish to get partial credit.

To turn in a project, you must push it to GitHub.  You must also deploy it to your AWS server.

You must include a README.md that describes your program and how to access it on AWS.

#### Deployment
*  [Deploying Spring Boot Apps](bootDeployment.md) 

<hr>

[Up](../README.md) | [Next](bootDeployment.md)

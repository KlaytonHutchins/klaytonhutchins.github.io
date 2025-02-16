---
layout: default
title: js Grandma
---
### Introduction / Goals
Remember *Deaf Grandma*? This is the new and improved version using JavaScript.  

We will use an HTML form to submit statements to Grandma. Her hearing isn't so great so she won't understand us unless we shout. She has become an avid gamer since we spoke to her last, so no matter what we say she will be shouting l33t speak back at us.  

This exercise will further acquaint you with:  

* Using js event listeners
* js selectors
* Creating DOM elements with js
* Appending js `HTMLElement`s to existing DOM elements

[resources/](resources/)

##### 1 : Build the conversation form
* Using javascript, create a new form and add it to the body. The form has the id and name 'grandmaForm'.
  ```html
    <form name="grandmaForm" id="grandmaForm">
  ```
* Using javascript, create an input element with type of 'text' and name of 'say'. Add this to your form.

* Using javascript, create an input element with type of 'submit' and name of 'submit'. Add this to your form.

##### 2 : Create a div with the id 'conversation'
* Using javascript, create a div with id of 'conversation' and add it to the body.

##### 3 : Talk to grandma!
* Create a function named `listenToGrandmaForm`, which will be the callback function used when the submit button is clicked.

* Remember to put `e.preventDefault();` as the first statement of your `listenToGrandmaForm` function.

* Inside of a `window.addEventListener("load", callback);` assign `listenToGrandmaForm` as the form submit button's callback.

* Clicking the submit creates a div inside of the `#conversation` div.

  The added div contains the text entered in the form. Grandma's response is also added to the `#conversation` div in a div. For example:
  ```html
  <div id='conversation'>
    <div>sup gramz</div>
    <div>U WAT M8?</div>
  </div>
  ```

* If user enters lowercase, grandma responds 'U WAT M8?'

* If user enters uppercase, grandma responds 'UR A n00b HACKZOR!'

* If user enters 'GOODBYE!', grandma responds 'L8R M8'`

##### 4 : Disable conversation after 'GOODBYE!'
* After 'GOODBYE!', no more text should be appended to the conversation if the button is clicked.

* **Note**: If you get this to pass, the screen will start flickering again due to the fact that you have removed the event listener with `e.preventDefault()`. At this point you have completed the lab.

* After deleting your event listener, you might try adding a new event listener to the submit button that has only 1 statement: `e.preventDefault();`.

<hr>

[Up](../README.md)

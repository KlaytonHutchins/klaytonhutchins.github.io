## Labs

### Key Logger
1. Create files named `keylogger.js` and `keylogger.html`.  

1. Add a single div element to your HTML document, `<div id="content"></div>`.

1. Add an event listener to your `.js` file that prints the word 'Down' to console when a 'keydown' event is observed.

1. Refactor your event listener to print the keyboard character that was pressed to the console. **Hint**: use the event object's `key` property to determine which key has been pressed.

1. Write a function that takes a string as an argument (the character pressed), selects the `#content` div on the page, and appends the character to the end of the div's `textContent`. Call this function each time your key events are triggered.

1. Refactor your event listener to observe backspacing. As of now when the delete is pressed it will print `Backspace` on the screen. Use conditional logic to determine if the delete button has been pressed and to alter the default behavior.

   **Think string manipulation. How could you remove the last character of a string?**

### Detailed View

1. Create two files `detail.html` and `detail.js`.

1. In your html file stub out the basic html structure. In the body of the document add the following:

    ```html
    <div id= "detail">
      <p id="title"></p>
      <p id="company"></p>
      <p id="salary"></p>
    </div>

    <h4>Jobs:</h4>
    <ul>
      <li id="0" class="list"></li>
      <li id="1" class="list"></li>
      <li id="2" class="list"></li>
      <li id="3" class="list"></li>
      <li id="4" class="list"></li>
    </ul>
    ```

1. In your `detail.js` file create an array of objects. Each object should have `title`, `company`, and `salary` properties. Feel free to use the following example
    ```js
    let jobs = [
      {
        company : "Amazon",
        title : "UX/UI Developer",
        salary : 72000
      },
      {
        company : "IBM",
        title : "Software Engineer",
        salary : 84000
      },
      {
        company : "Home Advisor",
        title : "Jr. Java Developer",
        salary : 65000
      },
      {
        company : "Fidelity",
        title : "Senior Software Engineer",
        salary : 137000
      },    
      {
        company : "Google",
        title : "IT Help Desk",
        salary : 48000
      }
    ];
    ```
1. Select all of the `li`s from the DOM using the provided `class` attribute, and store them in a variable. Iterate over the collection of `HTMLElements` and set their `textContent` to the `company` of the corresponding object in the array. At this point the list should be populated and display all of the company names.

1. Using the same loop you used in the previous step, add an eventListener to these `li`s that when clicked prints out the `textContent` of the element as well as its id.

    **Hint**: Use `e.target` to access the clicked element's `HTMLElement` object. Just like there is a `textProperty` on this object, there is also an `id` property. The provided id's correspond to the indexes of the array we created early. This will be useful soon.

1. Refactor your event listener to use the provided `id` to access the corresponding object in the array. Once you have access to the object, change the title, company, and salary `<p>` tag `textContent`s to represent the information from the selected object.

    **Hint**: The id of each `li` corresponds to its index in the jobs array.

    ```html
    <div id= "detail">
      <p id="title"></p>
      <p id="company"></p>
      <p id="salary"></p>
    </div>
    ```
1. JavaScript also lets us alter styles of selected elements. `target.style.property = value` would set the style of the specified property. Add a line that would change the background-color (`backgroundColor`) of the clicked `li`, `e.target`, to a light green color.  

1. With each click it turns the background color of the selected element green, but it does not turn the previously selected items back to white. Before the line where you change the `backgroundColor` of `e.target`, loop over all the `li` elements and turn each one of their backgrounds white.

   Now with each click it will reset all of the backgrounds before changing just the one you most recently clicked on.

<hr>

[Prev](eventObject.md) | [Up](README.md)


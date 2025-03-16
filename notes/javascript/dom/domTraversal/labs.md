---
layout: default
title: Labs
---

1. Create an HTML file named `traverse.html` and a JavaScript file named `traverse.js`.  

1. Write a well-formed HTML document in `traverse.html` and add an `<h1>` that says 'Hello World'.  

1. Import your `traverse.js` file into your `traverse.html` file using `<script src=''></script>`  

1. Add an unordered list of 5 list items to the HTML (don't put any text between the `<li>`s)  

1. Next to each of the list items, place a button with the text 'Edit' on it.  
    ```html
    <li></li><button class="edit">Edit</button>
    ```

1. In your `traverse.js` file, assign a 'click' event listener to each of your 'Edit' buttons. Do not create 5 separate callback function, rather create 1 that works for all 5 buttons.

1. When the 'Edit' button is clicked, it should use a `prompt` to prompt the user for a new value to place in that list item.  

1. When the user enters a new value for the list item, select the list item and change its `textContent` to match the entered text.

    *Hint: How are the buttons ordered in terms of a parent/child/sibling relationship?*  

1. Add another button next to each of the 'Edit' buttons, which will have 'Clear' on it.  

1. Assign event listeners to each of the 'Clear' buttons that will use `confirm` to confirm that the user wishes to delete the item. If the user affirms the deletion, use `textContent` to clear the corresponding list item's value. Otherwise, don't change the value.  

    ```html
    <li>Stuff</li><button class="edit">Edit</button><button class="clear">Clear</button>
    ```

    *Hint: the list item is the second previous sibling of whichever clear button has been clicked.*  

<hr>

[Prev](usingSelectedElement.md) -- [Up](README.md)


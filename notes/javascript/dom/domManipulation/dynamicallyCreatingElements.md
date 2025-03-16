---
layout: default
title: Dynamically Creating Elements
---
The document object is capable of creating new `HTMLElement` objects programmatically and adding them to the DOM tree.


### `createElement()`

The `createElement` method creates a `HTMLElement` that has no connection with the DOM. These objects can then be manipulated as much as we desire, and then appended into the appropriate position.

`createElement` takes a single string argument, the element tag name we are trying to create.

```javascript
let div = document.createElement('div');
```

Once created, elements can have attributes assigned to them as properties.

```javascript
let div = document.createElement('div');
div.id = 'myDiv';
div.textContent = 'This is a div'
console.log(div); // div#myDiv
```

### `appendChild()`
Created elements have no relationship to the DOM, until they are appended (i.e. added) to a Document element using `.appendChild(element)`.

```javascript
let div = document.createElement('div');
div.id = 'myDiv';
div.textContent = 'This is a div'

// add the div to the end of the body
document.body.appendChild(div);

console.log(div) // <div id='myDiv'></div>
```

> ### Skill Drill
> 1. Create a `<h1>` element using JavaScript.
> 1. Set the `<h1>` element's `textContent` to "Hello World".
> 1. Append the element to the body.

> ### Skill++
> There is also an `insertBefore()` method that allows you to insert a node as the previous sibling of the selected node.

<br>

### Appending Nested Elements Dynamically
To populate a list of items dynamically from an array of unknown size, you can use a series of loops, appending each item to the unordered list and then appending the updated element to the document.

```javascript
let items = [
		'apple',
		'banana',
		'coconut'
	];

let ul = document.createElement('ul');

items.forEach(function(value, index, array) {
	// create a new list item;
	let li = document.createElement('li');

	// assign the value at the current position
	// in the array to the list item's text value
	li.textContent = value;

	// append the list item to the unordered list
	ul.appendChild(li);
});

// append the entire unordered list to the body
document.body.appendChild(ul);
```

> ### Skill Drill
> 1. Create an array of your favorite foods.
> 1. Create a _ordered_ list element using JavaScript.
> 1. Loop over the array of foods, creating a `<li>` for each food and setting its text content accordingly.
> 1. Append the entire ordered list to the body.

<br>

### Appending Elements With Event Listeners
If you want a dynamically created element to have an event listener assigned to it, that assignment needs to be done **before** the element is appended to the dom.

There are some situations in which you will want to create a form. A form won't be very useful if it doesn't have an event listener that aggregates the provided data on submission.

Forms can be created and appended in the same way as any other elements:  
```html
<body>
	<script type="text/javascript">
		// create the form, give it a name
		let form = document.createElement('form');
		form.name = 'contactForm';

		// create an input field
		let fname = document.createElement('input');
		fname.name = 'fname'; // assign a name attribute
		fname.type = 'text'; // assign a type attribute
		fname.placeholder = 'First Name'; // assign a placeholder attribute

		// append the input to the form
		form.appendChild(fname);

		// create a submit input
		let submit = document.createElement('input');
		submit.name = 'submit'; // assign a name attribute
		submit.type = 'submit'; // assign a type attribute
		submit.value = 'Submit Form'; // assign a value attribute

		submit.addEventListener('click', function(e) { // Assign an event listener to the submit button variable

			e.preventDefault();
			let form = e.target.parentElement;

			// print the fname value to the console
			console.log(form.fname.value);

			// clear the form data
			form.reset();
		});

		// add the input to the form
		form.appendChild(submit);

		// add the form to the body
		document.body.appendChild(form);
  </script>
</body>
```

> ### Skill Drill
> 1. Create a page load event listener.
> 1. Inside of the events callback function, create a form element using js and assign it a name value.
> 1. Create two input field elements, one for an email, the other for a password. Append them to the form element.
> 1. Create a submit button and append it to the form.
> 1. Assign the submit button an event listener that when clicked prints out the values typed into the email and password input fields.
> 1. Append the form to the body.

<hr>

[Prev](formsAndEventListeners.md) -- [Up](README.md) -- [Next](dynamicallyRemoveElements.md)


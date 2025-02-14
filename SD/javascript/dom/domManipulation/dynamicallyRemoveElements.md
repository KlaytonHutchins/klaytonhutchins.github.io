## Dynamically Remove Elements
When a resource is no longer needed you may want to remove it from the DOM, or remove it and replace it with something else.

To remove elements from the DOM we use `Node.removeChild(node)`.

There is no method that removes a node directly. We always need to target the parent and then remove the child.

```html
<html>
  <head>
    <title>Some Page</title>
  </head>
  <body>
  	<ul id='list'>
  		<li>things</li>
  	</ul>

    <script type="text/javascript">
    	// Select list
    	let list = document.getElementById('list');

    	// Remove the list's first child (that is an Element Node)
    	list.removeChild(list.firstElementChild);

    </script>
  </body>
</html>
```

This is useful if you want to remove a specific item.
* Pass in the actual Element to remove to the `removeChild()` method).

If you want to remove a full list of items, simply continue removing Elements in a loop until there are none left:

```html
<html>
  <head>
    <title>Some Page</title>
  </head>
  <body>
  	<ul id='list'>
  		<li>things</li>
  		<li>things</li>
  		<li>things</li>
  		<li>things</li>
  		<li>things</li>
  		<li>things</li>
  		<li>things</li>
  	</ul>


    <script type="text/javascript">
    	let list = document.getElementById('list');

    	// While the Element has a firstElementChild...remove it
    	while (list.firstElementChild) {
	    	list.removeChild(list.firstElementChild);
    	}
    </script>
  </body>
</html>
```

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
> 1. Create an ordered list with 5 `<li>` elements inside of it in your HTML document.
> 1. Create an event listener for page load.
> 1. Inside of the callback function, target the entire list of items.
> 1. Use a loop to remove all of the nested `<li>` items.

If you would like to remove the entire Element (not just its children), you can select its parent by using the `parentElement` property and passing the Element to the `removeChild` method.

```html
<html>
  <head>
    <title>Some Page</title>
  </head>
  <body>
  	<ul id='list'>
  		<li>things</li>
  		<li>things</li>
  		<li>things</li>
  		<li>things</li>
  		<li>things</li>
  		<li>things</li>
  		<li>things</li>
  	</ul>


    <script type="text/javascript">
    	let list = document.getElementById('list');

    	list.parentElement.removeChild(list);
    </script>
  </body>
</html>
```

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
> 1. Look back at our previous Skill Drill example. If you look in the chrome elements tab the `<ol></ol>` is still present in the dom.
> 1. Alter the code to remove the entire `<ol>` object rather than just its children.

<hr>

[Prev](dynamicallyCreatingElements.md) | [Up](README.md) | [Next](labs.md)


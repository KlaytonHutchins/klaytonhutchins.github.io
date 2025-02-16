---
layout: default
title: Listening For Events
---
Event Listeners are methods registered on specific targets. The target of an event listener could be an HTML element, the Document object, or the Window object itself.

These methods dictate behavior that will happen when... a user clicks a button ... the mouse enters a specific area ... etc.

Each `HTMLElement` has properties that represent these keywords. When the property is associated with a method of your choosing, that behavior will be called by the browser.

### `addEventListener`
The method `target.addEventListener(type, callback)` takes two arguments, the type of the event, and a function. The invoking object `target` can be any element you have selected from the DOM.

`addEventListener(type, callback)` registers the event listener (`type`) onto the target. When the event is observed on the target, it triggers the `callback` (or `listener`), which is usually a function.

For this example we are going to use an event called `load`. The `load` event is triggered by the browser when the entire html document has been successfully loaded.

```javascript
// Print loaded to console when the window object loads
window.addEventListener('load', function(e){
	console.log('LOADED');
});
```

* Instead of using an anonymous function (as above), you can use a named function for the listener above.

```javascript
let confirmWindowLoad = function(e) {
	console.log('LOADED');
};

window.addEventListener('load', confirmWindowLoad);
```

> ### Skill Drill
> 1. Create two files called eventEx.html and eventEx.js.
> 1. Create a basic HTML structure in the html file and link to the eventEx.js file.
> 1. In your `.js` file write an event listener that notifies you when the document has loaded.

<hr>

[Prev](README.md) | [Up](README.md) | [Next](usingEventListeners.md)


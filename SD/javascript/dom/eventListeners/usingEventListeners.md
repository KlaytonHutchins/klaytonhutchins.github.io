## Using Event Listeners
There are a large number of events that you can observe and use, a full list can be found on MDN: [Events](https://developer.mozilla.org/en-US/docs/Web/Events)


### Click
One of the most common uses for event listeners is to observe 'click' events from users.

```html
<html>
  <head>
    <title>Some Page</title>
    </head>
    <body>
        <button id='btn'>My Button</button>

        <script type="text/javascript">
            // Store the button element in a variable
            let button = document.getElementById('btn');

            // Assign an event listener to a click event on the button
            button.addEventListener('click', function(e) {
                console.log('CLICKED!');
            });
        </script>
    </body>
</html>
```

The above example illustrates how you can add a 'click' event listener to a `<button>` element. Each time the user clicks the button, it will fire the anonymous function, and print 'CLICKED!' to the console.

Inside of that anonymous function is the only place we can write code that will be executed when the event is fired.

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
> 1. Add a button element to your HTML document. Give it a unique id.
> 1. Add a click event listener to the button. When the button is clicked print out a message to the console.
> 1. Add a second element `<h1 id="target">Second Element</h1>` to your HTML document.
> 1. When the button is clicked select the `<h1>` by its `id` and change the `textContent`.

### Key Events
JavaScript has a number of events that will tie into a user's keyboard.

* `keyup`: keyup is fired when a user releases a key on the keyboard.
* `keydown`: keydown is fired when a user presses a key on the keyboard.
* `keypress`: keypress is fired when a key that produces a character value is in the pressed position. Keypress, however, doesn't register a modifier or non-printing keys (`Shift`, `Esc`, `delete`) (the `keypress` event has been deprecated.)

All of these events follow this format:
```javascript
document.addEventListener("keydown", function(e){
  console.log("key pressed");
});
```

When using any of these events you can access the code or value of the key that triggered the event.
The `event` object is injected into the triggered callback function. This object has a few properties on it that allow us to access these values.

If the `q` button is pressed the following properties will yield:
```javascript
document.addEventListener("keydown", function(e){
  console.log(e.code);          //"KeyQ"
  console.log(e.key);           //"q"
});
```

The boolean properties `altKey`, `ctrlKey`, `metaKey`, and `shiftKey` indicate whether any of these modifier keys was active at the time of the event.

<hr>

[Prev](listeningForEvents.md) | [Up](README.md) | [Next](removingEvents.md)


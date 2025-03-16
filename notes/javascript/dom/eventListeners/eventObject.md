---
layout: default
title: Event Object
---
When an event listener is triggered, the callback function is passed the Event object.
* You may have noticed that all the examples have `e` passed into their callback functions. JavaScript injects this dependency into any method that represents an event listener.

```js
targer.addEventListener('click', function(e){})
```

The Event object is created when the event occurs and has properties pertaining to the event, including:  
  * `timestamp`: when the event was created  
  * `type`: the type of event  
  * `target`: the target to which the event was originally dispatched.      

This last property is particularly useful as it contains a reference to the object that triggered the event. In the case of a button click event, the target will be the button.

  * `target` allows us to access the properties and effect the properties of the `target` object in the callback, the `HTMLElement` that caused the event.

```html
<html>
  <head>
    <title>Some Page</title>
    </head>
    <body>
        <button id='btn'>Request Information</button>

        <script type="text/javascript">
            let btn = document.getElementById('btn');

            btn.addEventListener('click', function(e) {
                e.target.textContent = 'This Button Has Been Clicked';
            });
        </script>
    </body>
</html>
```

* Now, when the button is clicked, it will change the text on the button to 'This Button Has Been Clicked'

> ### Skill Drill
> 1. Add a button to your HTML document that says 'Off'.
> 1. When the button is clicked, change the text of the button to 'On'.
> 1. If the button is clicked again, it should toggle back to 'Off'. This process should continue indefinitely.  
> **You should only need one event listener**

<hr>

[Prev](acp.md) -- [Up](README.md) -- [Next](labs.md)


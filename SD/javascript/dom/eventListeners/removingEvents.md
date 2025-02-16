---
layout: default
title: Removing Event Listeners
---
If you wish to deactivate an event lister for any reason, there is a method `removeEventListener`.

The only intricacy of `removeEventListener` is that is requires the name of the callback function as an argument.
* Due to this we can not turn off events that were set up with anonymous functions.


```js
target.addEventListener('click', function(e){});
```

To avoid this problem, any event that you subsequently want to turn off needs to be set up with a named function.

```js
let callback = function(e){};
target.addEventListener('click', callback);
```

### `removeEventListener`
`removeEventListener(type, function)` uses the same two arguments required for setting up an event listener. The `type` is the event we are looking to turn off, and the `function` is the name of the callback function we originally set up the event with.

```js
target.removeEventListener("click", callback);
```

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
> 1. Create an html document with a button element.
> 1. Assign the button a `click` event that `console.log`s the number of times the button has been clicked. Make sure that the callback function is a named function as opposed to an anonymous one.
> 1. When the button has been clicked 5 times, remove the event listener.

<hr>

[Prev](usingEventListeners.md) | [Up](README.md) | [Next](acp.md)


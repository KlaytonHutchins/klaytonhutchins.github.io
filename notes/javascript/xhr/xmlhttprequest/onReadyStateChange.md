---
layout: default
title: Using `onreadystatechange`
---

The `XMLHttpRequest.onreadystatechange` property contains the event handler to be called when the `readystatechange` event is fired - that is, every time the `readyState` property of the XMLHttpRequest changes. 

The callback is called from the user interface thread.

```javascript
let xhr = new XMLHttpRequest();
xhr.open('GET', 'http://someURL.com');

// use the change in readyState to fire a callback
xhr.onreadystatechange = function(){};

xhr.send();
```

## Accessing the `readyState` Property

The `XMLHttpRequest.readyState` property returns the state an XMLHttpRequest client is in.

There are 5 ready states:

|Value|State|Description|
|:---:|:---:|---|
|0|UNSENT|Client has been created. open() not called yet.|
|1|OPENED|open() has been called.|
|2|HEADERS_RECEIVED|send() has been called, and headers and status are available.|
|3|LOADING|Downloading; responseText holds partial data.|
|4|DONE|The operation is complete.|

In asynchronous programming it is necessary to perform an operation when data has been returned by the server (whenever that may be). 

**The response data will be available when the `readyState` is 4.**

```javascript
let xhr = new XMLHttpRequest();

console.log('Before open(): ' + xhr.readyState); // 0 => UNSENT

xhr.open('GET', 'api/users');

console.log('After open(): ' + xhr.readyState); // 1 => OPENED

xhr.onreadystatechange = function() {
	console.log('In onreadystatechange: ' + xhr.readyState);
	// 2 => HEADERS_RECEIVED
	// 3 => LOADING
	// 4 => DONE

	if (xhr.readyState === 4) {
		console.log(xhr.readyState + ' Operation is complete');
		// 4 Operation is complete
	}
};

console.log('Before send(): ' + xhr.readyState); // 1 => OPENED
xhr.send();
console.log('After send(): ' + xhr.readyState); // 1 => OPENED
```

> ### Skill Drill
> 
> Modify your `app.js` to print the `readyState` before and after `open` as well as immediately before and after `send`, and refresh the browser.
>
> Now add a `console.log` of the `readyState` as the first line of the `onreadystatechange` function.
> 
> When you refresh the page to re-run the request, carefully note the order of events.


<hr>

[Prev](get-labs.md) | [Up](README.md) | [Next](status.md)


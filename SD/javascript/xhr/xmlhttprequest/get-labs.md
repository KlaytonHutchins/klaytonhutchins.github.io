---
layout: default
title: Labs
---

1. Create two files `xmlhttp.html` and `app.js`.  

1. Source your `app.js` file into your html doc.  

   * Create a window `load` event listener in your `app.js` file that prints out a message that the page has been loaded.  

1. In your onload function create an `XMLHttpRequest` object that will execute a `GET` request to `https://skilldistillery.github.io/people.json`

1. Create an `onreadystatechange` function that prints out the returned `responseText` if the request was successful.  

1. If the request fails, write code that prints out that an error occurred to the console.  

1. Change your `onreadystatechange` code to convert the `responseText` from JSON to javascript, and print out the first and last names from each returned object.  


<hr>

[Prev](send.md) | [Up](README.md) | [Next](onReadyStateChange.md)


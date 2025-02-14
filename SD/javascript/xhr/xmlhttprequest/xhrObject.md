## XMLHttpRequest Object

Literally 'eXtensible Markup Language Hypertext Transfer Protocol Request Object'.

XMLHttpRequest is an API that provides client functionality for transferring data between a client and a server. 

It provides an easy way to retrieve data from a URL without having to do a full page refresh. 

* This enables a Web page to update just a part of the page without disrupting what the user is doing. 
XMLHttpRequest is used heavily in AJAX programming.

XMLHttpRequest was originally designed by Microsoft and adopted by Mozilla, Apple, and Google. It's now being standardized at the WHATWG. Despite its name, XMLHttpRequest can be used to retrieve any type of data, not just XML, and it supports protocols other than HTTP (including file and ftp).

Example of fully formed XMLHttpRequestObject:

```javascript
  let xhr = new XMLHttpRequest();

  xhr.open('GET', 'api/users', true);

  xhr.onreadystatechange = function() {
    if (xhr.readyState === 4) {
      if (xhr.status === 200) {
        console.log(xhr.responseText);
        let data = JSON.parse(xhr.responseText);
        console.log(data);
      } else {
        console.error(xhr.status + ': ' + xhr.responseText);
      }
    }
  };

  xhr.send();
```

<hr>

[Prev](ajax.md) | [Up](README.md) | [Next](createAndOpenRequest.md)


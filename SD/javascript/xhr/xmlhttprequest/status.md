## Checking the Response Status with the `status` Property

The `XMLHttpRequest.status` property returns the numerical status code of the response of the XMLHttpRequest. 

The value of status will be 0 until the server response and `readyState` goes to 2.

The status codes returned are the standard HTTP status codes such as `200 Ok` or `404 Not found`.

```javascript
let xhr = new XMLHttpRequest();

console.log(xhr.status); // 0

// '/todo/1' is a valid route and the server will respond 200
xhr.open('GET', 'api/users/1');

console.log(xhr.status); // 0

xhr.onreadystatechange = function(){
	console.log(xhr.status);
	// 200
	// 200
	// 200

	if (xhr.readyState === 4) {
		console.log(xhr.status + ' Operation is complete');
		// 200 Operation is complete

		// GET RESPONSE DATA, UPDATE DOM, ETC.
	}
};

console.log(xhr.status); // 0
xhr.send(null);
console.log(xhr.status); // 0
```

Use `xhr.status` to anticipate and deal with different server responses.

```javascript
  let xhr = new XMLHttpRequest();

  xhr.open('GET', 'api/users', true);

  xhr.onreadystatechange = function() {
    if (xhr.readyState === 4) {
      if (xhr.status === 200) {
        let data = JSON.parse(xhr.responseText);
        console.log(data);
      }
      else if (xhr.status === 404) {
        console.error('api/users not found.');
      }
      else {
        console.error('Unknown error: ' + xhr.status + ': ' + xhr.responseText);
      }
    }
  };

  xhr.send();
```

<hr>

[Prev](onReadyStateChange.md) | [Up](README.md) | [Next](responseText.md)


## Selecting Forms and Form Attributes by Name
The Document object makes selecting forms easy using the `name` attribute on an HTML form.

When the browser encounters a `<form>` tag as it's rendering the page it will create a "shortcut" variable on the `document` for ease of access.

```html
<html>
  <head>
    <title>Some Page</title>
    </head>
    <body>
    	<form name='myForm'></form>

        <script type="text/javascript">
			    console.log(document.myForm); // <form name='myForm'> ... </form>
        </script>
    </body>
</html>
```

Similarly you can select the `input`s from within a form using their name attributes.

```html
<html>
  <head>
    <title>Some Page</title>
    </head>
    <body>
    	<form name='myForm'>
    		<input type='text' name='fname' />
    		<input type='text' name='lname' />
    		<input type='submit' name='submit' value='submit' />
    	</form>

      <script type="text/javascript">
		    console.log(document.myForm.fname); // <input type='text' name='fname' />
		    console.log(document.myForm.lname); // <input type='text' name='lname' />
		    console.log(document.myForm.submit); // <input type='submit' name='submit' value='submit' />
      </script>
    </body>
</html>
```

With these elements selected, we can access their html attributes as properties on their objects.

```html
<html>
  <head>
    <title>Some Page</title>
    </head>
    <body>
    	<form name='myForm'>
    		<input type='text' name='fname' />
    		<input type='text' name='lname' />
    		<input type='submit' name='submit' value='submit' />
    	</form>

      <script type="text/javascript">
  			console.log(document.myForm.fname.name); // fname
  			console.log(document.myForm.lname.name); // lname
  			console.log(document.myForm.submit.name); // submit
  			console.log(document.myForm.submit.value); // submit
      </script>
    </body>
</html>
```

This means that we can select values users enter into our fields with the `value` property when the form is submitted.

When a form is empty, the `value` property would be `""`.

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
> 1. Create a form with two text input fields and a submit button.
> 1. Assign the input fields default values, e.g. `<input name="fname" value="Jack" />`.
> 1. Print out the values of those input fields to the console.

<hr>

[Prev](README.md) | [Up](README.md) | [Next](formsAndEventListeners.md)


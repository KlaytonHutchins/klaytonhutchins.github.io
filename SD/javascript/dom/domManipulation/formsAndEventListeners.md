## Forms and Event Listeners
Up until this point we have been using the default form behavior on submission. Namely, when the user submits a form, the data within is submitted as part of a request to some route, and the response dictates what should happen next.

With JavaScript we need to prevent this behavior in order to use the data without refreshing the page.

The Event object gives us a method which allows us to prevent the default behavior of the target (in this case the submit button), with a method fittingly named `.preventDefault()`.

If we are adding an event listener to a form and forget to add the `preventDefault` method, the browser will refresh and we won't be able to extract any of the values.

```html
<body>
    <form name='myForm'>
        <input type='text' name='fname' />
        <input type='text' name='lname' />
        <input type='submit' name='submit' value='submit' />
    </form>

    <script type="text/javascript">
        document.myForm.submit.addEventListener('click', function(e) {
            // Don't submit the form
            e.preventDefault();

            // print out the submit buttons => parent (form) => fname input => value
            console.log(e.target.parentElement.fname.value); // Will print the user input value
            console.log(e.target.parentElement.lname.value); // Will print the user input value
        })
    </script>

</body>
```

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
> 1. Create a form with two text input fields and a submit button
> 1. Assign an event listener to the submit button. Remember, because it is a form submit we have to prevent the default action of the form.
> 1. When the button is clicked, print out the values the user entered into the text fields.
> 1. Reset the forms fields to there original value using `formName.reset()`.

### Cleanup
Now we can clean up our code and not repeat as much by storing `e.target.parentElement` in a variable:

```html
<body>
    <form name='myForm'>
        <input type='text' name='fname' />
        <input type='text' name='lname' />
        <input type='submit' name='submit' value='submit' />
    </form>

    <script type="text/javascript">
        document.myForm.submit.addEventListener('click', function(e) {
            e.preventDefault();
            let form = e.target.parentElement;

            console.log(form.fname.value);
            console.log(form.lname.value);

            // clear the input data
            form.reset()
        })
    </script>

</body>
```

<hr>

[Prev](selectingFormsByName.md) | [Up](README.md) | [Next](dynamicallyCreatingElements.md)


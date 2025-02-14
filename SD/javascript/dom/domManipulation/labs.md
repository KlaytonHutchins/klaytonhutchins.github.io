## Labs

1. Create an HTML file named 'manipulate.html', and a JS file named 'manipulate.js'.

1. Add an HTML form named 'shipping' with the following inputs (all are type='text' except where noted):
    * fname
    * lname
    * street
    * city
    * state
    * zip
    * Add Shipping button => submit

1. Add two `div`s to the bottom of the document with `id`s of `content` and `errors`, respectively.

1. In your JS file select the form, and add an Event Listener to its submit button. Remember to prevent the default behavior of the form submission. Log a message to make sure that this is working properly.

1. In your event listener, log each of the values the user entered in the form.

1. In your JavaScript file, create a function named `verifyFormData(fname,lname,street,city,state,zip)` which checks that:
    * all of the values are completed (i.e. not blank)
    * the zip can be converted to a number and is 5 characters long
    * state is two characters long

    If any of the above verifications fail, push a message detailing the error into an array (i.e. `'Zip code must be composed of 5 numbers'`).

    Return the array out of the method.  
    **Hint**: If the array has a length `arr.length > 0`, there must be errors with the information that was passed in. If the length equals 0, the data is correctly formatted.

1. Call `verifyFormData()` in your event listener's callback, and pass it your form input data.

1. If `verifyFormData()` returns an empty array, clear the form (i.e. remove it), and display the data to the screen using the `details` div. To display the screen you will need to create `HTMLElement`s with `createElement` for each of the form fields, and append them to the DOM.

1. If there are errors, `verifyFormData()` should return an array of strings (your error messages). If this is the case, iterate over the array in your callback function and create elements to display them in a list below the form, in the `errors` div. The form should not be removed from the DOM, allowing the user to reenter their inputs.

    Try to make the `li` text red.

<hr>

[Prev](dynamicallyRemoveElements.md) | [Up](README.md)


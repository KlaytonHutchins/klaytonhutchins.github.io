## `private` Methods

Sometimes we may restrict the visibility of a method to `private`.

The reason for this is we do not want users of the class to invoke those methods.

* We still want code in a method, but other classes don't get to call it.

Private methods are not part of the class's _interface_.

> #### interface
> The list of methods users of a class can call. Not all the methods, just the ones other classes can use.

In this way, we hide the details of the class and only show users of the class methods we decide they can call.

### Practice Exercise
> You may hear the term _API_. This stands for _Application Programming Interface_ and means the set of methods a system provides.
>
> That is, it's the list of methods that an application program can use to interface with the system.

<hr>

[Prev](final.md) -- [Up](README.md) -- [Next](labs.md)


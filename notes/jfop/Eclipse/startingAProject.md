## Starting a Project

Before you can edit any Java code, you must first create a _project_.

* A project is a related collection of source files and other resources.

* Eclipse will display selected files and folders that are in the project, based on the type of project it is.

The project name will become a subdirectory within your workspace directory.

* Once your project has been created, you will see the project name listed in the _Package Explorer_ view.


### Drill
* Close the _Welcome_ tab (you can always reopen it from the _Help_ menu.)
* Choose _File_ | _New_ | _Other..._.
* In the search field type `java p`, then select _Java Project_ from the search results.
  * Click **Next**
* In the Project Name text box enter `MyFirstProject`.
* Click **Finish**.
* If you are prompted to _Open Associated Perspective_, click **No**
* In the _Package Explorer_, open up your project and click on `src`.
* Go to _File_ | _New_ | _Other_.
  * Type `class` in the search field and select _Class_ from the results.
  * Click **Next**
  * For the _Name:_ enter `HelloEclipse`.
* Under _Which methods stubs would you like to create_, check the checkbox for _public static void main(String[] args)_
* Click **Finish**.

You'll see Eclipse created the class and opened it in the Java editor.  It also created a `main` method that's empty except for a "TODO" comment.
Under the "TODO" comment, add:
```java
System.out.println("Hello, Eclipse!");
```
* Type _Cmd_-S to save the editor contents.
* Now go to the _Run_ menu in the menubar and select _Run_.


<hr>

[Prev](workspaces.md) -- [Up](README.md) -- [Next](editorsViewsAndPerspectives.md)


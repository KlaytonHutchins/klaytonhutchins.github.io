## Configure Eclipse to integrate Tomcat

* In Eclipse, go to the Java EE perspective.

* Select the _Servers_ view.

  * If the _Servers_ view isn't visible, make sure you're in the Java EE perspective; try _Window_ | _Perspective_ | _Reset Perspective_; or, go to _Window_ | _Show View_ and find the _Servers_ view.

* In the _Servers_ view, click the link to create a new server.

  * In the `Apache` tree select `Tomcat v8.5 Server`

    * `Next`

  * For the Tomcat installation directory, `Browse...` to your _~/SD/Tools/apache-tomcat-8.5.28/_ folder and `Open`.

    * `Finish`
  
* Double-click on your Tomcat 8.5 server name to open the Server configuration editor.

  * Under _Server Locations_, select:
    
    `Use Tomcat Installation (takes control of Tomcat installation)`

  * _Cmd-S_ to save, and close the _Server_ configuration editor.



<hr>

[Prev](tomcatSetup.md) | [Up](README.md)


---
layout: default
title: What is JPA?
---

## What is JPA?

JPA stands for Java Persistence API. The Java Persistence API is a persistence mechanism which can be used in Java SE and Spring applications.

* It is designed to simplify the persistence of POJOs (Plain Old Java Objects), called *Entities* in relational databases.

  > #### entities ####
  > Instances of Java objects. These classes are configured to represent a table from a relational database, and store a row of data.

* It employs object-relational mapping (ORM) to accomplish this.

* ORM translates SQL tables and columns to Java classes and fields (*Entities*). Prior to JPA we had to do this manually.

JPA is mostly made up of interfaces, and each of these interfaces is implemented by yet another dependency known as a _persistence provider_.

>  #### persistence provider ####
>  The implementation of the JPA interfaces.

* We will be using the *Hibernate* persistence provider with JPA. Hibernate will actually manage the connection to the SQL database, JPA will handle the translation from SQL -> Java and back.

The creation and persistence of *Entities* is managed by an *EntityManager*. The *EntityManager* is just an object representing the persistence provider's connection to the database.

Once configured, the *EntityManager* will provide methods that make CRUD operations simple. All we have to worry about is writing the Java code; the
*EntityManager* will translate these methods to the corresponding SQL to complete your operation.

![Data access layers](./images/data_access_layers.svg)

<sub>Image courtesy of <a href="https://docs.jboss.org/hibernate/stable/orm/userguide/html_single/Hibernate_User_Guide.html">Hibernate Users Guide</a></sub>

The classes, interfaces, and annotations that we will use to interact with our data are predominantly located in the `javax.persistence` package.


### Drill

 You are going to create a new JPA Project and add to it over the next several sections, eventually creating an ***Entity*** that you can test with an ***EntityManager***.

1. Before we proceed with the hands on, we are going to download a plugin for STS. Workspaces are great for organizing code and reducing clutter, but it's annoying to have to switch back and forth between workspaces when you want to look at old code. Download the `macOS Eclipse Launcher` plugin from the Eclipse marketplace. This gives you the ability to have multiple STS windows open at once.
> 
> 1. In a terminal, navigate to your _SD/Java_ directory and make a new directory named *VideoStore*. In STS, select _File -> Open Workspace -> Other -> Browse_. This will open _Finder_, select the _VideoStore_ folder.
> 
>    * This might be a good time to configure workspace-specific settings, such as:
>      * Check the _Link with editor_ button in Package Explorer.
>      * In STS Preferences:
>        * _Java_ | _Compiler_ | _Compliance level_
>        * _Gradle_ | _Version_
>        * _Run/Debug_ | _Console_ | Uncheck _Limit console output_
>        * _General_ | _Workspace_ | Check _Show full workspace path_ (this will be helpful when we have multiple instances of Eclipse open in different workspaces)
>        * _General_ | _Web Browser_ | _Use external web browser_
> 
> 1. Create a new *JPA Project*. Be sure you do not do a new Java or Dynamic Web Project like we have in the past.  
>     
>     1. `File` | `New` | `Other`
>     
>     1. Type `jpa` in the filter field and choose `JPA Project`
>     
>     1. Click `Next`.
>    
> 1. On the *JPA Project* page, name the project ***JPAVideoStore***, click *Next*.
>
> 1. On the *Java* page, add three new source folders so our project structure follows current Gradle conventions:
>    * `src/main/resources`
>    * `src/test/java`
>    * `src/test/resources`
> 
>    Click *Next*
>
> 1. On the *JPA Facet* page for _JPA Implementation_, choose _Disable Library Configuration_.  Click *Finish*
>
>    * If prompted to open the JPA perspective, choose _Remember my decision_ and click *No*.
> 
>    * Don't worry if there appears to be a project error, a later step will clean that up.
> 
> 1. Open `src/main/java` and drag the `META-INF/` folder down to `src/main/resources`.
>  
> 1. Right-click on the project name and go all the way down to _Properties_.
>    * In _Project Facets_, make sure the _Java_ version is set to `1.8`, then click _Apply and Close_.
> 
> 1. Right-click on the project name and under _Configure_, choose _Add Gradle Nature_.
>    * Under _Window_ | _Show View_ | _Other_, find and open the _Gradle Tasks_ view.
> 
> 1. In the _Gradle Tasks_ view, open the project, and open the `build setup` group.
>    * Double-click the `build init` task - this will initialize the Gradle files for this project.  In _Gradle Executions_ it will appear to be running something.  Actually, it's waiting for some necessary input from us.
>    * Go to the _Console_ view where you'll see a series of prompts for options for this project.  Hit *Return* to accept the default for each question until you see `BUILD SUCCESSFUL`.
> 
> 1. Right-click on the project and do a _Refresh_, then a _Gradle_ | _Refresh Gradle Project_.  You should now see the gradle files.
> 

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](dependencies.md)


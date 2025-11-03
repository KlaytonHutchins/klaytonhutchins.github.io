## Event Tracker

### Overview

'Event Tracker' is a broad term for anything that keeps track of information over time. Examples of these applications are 'Mint' (financial tracking) and 'MyFitnessPal' (diet and exercise tracker). These are very involved applications with a huge feature set.

You are embarking on a weekend project that you may or may not come back to afterwards, thus we would caution you to limit your scope significantly. Examples of limited scope would be 'Gas Tracker' (keep track of your fill ups and total mileage to determine dollar/gallon in your car) or 'Timesheet' (track time in and time out to calculate total hours at some rate of pay).  

### Learning Objectives

* Create a JPA Project
  * Create a Java entity class POJO that models your database table.
  * Map your POJO using JPA.

* Configure a Spring Boot app to publish a REST API.
  * Use Spring REST annotations.
  * Use Spring Data JPA to perform all CRUD operations.
  * Send and receive JSON.

### Project Setup

We'll set up a new workspace for this project.

Note: be sure to do git commits as you complete each step.

1. Create a new STS workspace folder for your project.

   ```
   mkdir ~/SD/Java/EventTracker
   cd ~/SD/Java/EventTracker
   ```

   1. Create a `.gitignore`:
      ```
      .DS_Store
      Servers
      target
      build
      bin
      default
      .metadata
      # .settings
      .gradle
      *.war
      *.bak
      ```
1. Create a Githup repository named **EventTrackerProject** and copy the _create a new repository on the command line_ local repository setup commands.
   1. Run the commands in your new workspace to associate your workspace with the Github remote.

1. Create a `DB/` folder for your database files.
1. Use MySQL Workbench to create a database schema model and save the `.mwb` file in the `DB/` folder.
   * Give the schema an appropriate name.
   * Be sure to create a _appusername_@localhost account with a password for your database and the _table.modify_ role.
   * Create a single table for your entity, giving it an id and at least one other column (you can finish building out this table and any others you want later.)
   * Include a row of initial sample data so you can run a unit test.
   * Forward Engineeer your schema.

1. Open the `Xtreme9Lives` workspace in STS for reference.
1. Open the `~/SD/Java/EventTracker` workspace in STS.
1. Set workspace preferences:
   * **Java** | **Compiler** _Compiler compliance Level_: **`1.8`**
   * **Gradle**: **`Specific Gradle version`** (current latest version)
   * **Run/Debug** | **Console**: UN-check _Limit console output_.
   * **Apply and Close**

### Setup a JPA project for your JPA entity(s) and tests.

1. Create a new **JPA Project** with an appropriate name.
   1. Add new source folders to the build path:
      * `src/main/resources`
      * `src/test/java`
      * `src/test/resources`
   1. Under _JPA implementation_, choose **Disable Library Configuration**
   1. Do NOT open the JPA perspective.
1. Move the `META-INF` folder from `src/main/java` to `src/main/resources`.

#### Configure Gradle
1. Add Gradle Nature to the project.
1. Open the _Gradle Tasks_ view.
1. Under the `build setup` task group, run the `init` task.
1. Go to the _Console_ view and press _Return_ to answer the required questions until you get `BUILD SUCCESSFUL`.
1. Refresh the _Package Explorer_ view to see the new gradle files.
1. Copy the contents of the `build.gradle` from the **XtremeJPA** project into your new project's `build.gradle`; save and **Gradle Refresh**.

#### Configure the JPA Persistence Unit
1. Copy the `log4j.properties` file from **XtremeJPA** into your new project's `src/main/resources` and `src/test/resources` folders.
1. From the **XtremeJPA** `persistence.xml` copy the contents from between the `<persistence-unit>` tags (not the whole file) into your new project's `persistence.xml`, between the opening and closing `<persistence-unit>` tags.
1. Change the schema name in the JDBC URL to the name you gave your schema.
1. Set the values for user and password to the application user you created in your model.

#### Stub and test your entity
1. Choose an approriate package name for your project and change the `<class>` declaration with a new package name and the name of your entity class.
1. Create the new package and entity class in `src/main/java`.
1. Add the id field and one other field in the class (leave the rest for later).
1. Add no-arg ctor, gets/sets, toString, etc.
1. Annotate your entity.
1. Create a matching package under `src/test/java` and create a new JUnit test case for your entity.
1. Build out the JUnit test until it passes.

### Create a Spring Boot REST Project for your REST API controller(s), service, and Spring Data JPA repository
1. Copy the base package name from your entity class (the package name up to but not including `.entities`)
1. Create a new _Spring Starter Project_.
1. Paste the base package name into the _Package_ field.
1. Give the project an appropriate name (this project name will appear in the URL once you deploy the project.)
1. Set the build _Type_ to **Gradle**, the _Java Version_ to **8**, and _Packaging_ to **War**.
1. Add the _Spring Web_, _Spring Data JPA_, and _MySQL Driver_ dependencies.
1. Edit the boot projects `settings.gradle` and `build.gradle` to add the JPA project dependency.
1. Copy `application.properties` from XtremeRest; pick an unused port number, and change the database connect information (schema name in URL, username, and password) to match your schema.

### Where to start?

1. Finish building out your entity table(s) in MySQL workbench.
1. Finish building and testing your Java entity class to match.
1. Create repository(s), service(s), and REST controller(s).
1. Create controller and service logic to perform the basic CRUD operations of a REST API.
   * Test these routes using *Postman*
1. Deploy your project to your EC2 instance, and link to it from your portfolio web site.

### Goal

Your objective for this project should be to do as much as you can. That is not to say as many features, but as much as you actually understand.

Do not move onto the next step until you actually know what you just did and feel comfortable with what is happening. If you reach a point and are confused about what you are doing, or what you have done, ask questions, look for resources, or start over on that piece to ensure that you are comfortable with it.  

Make sure to commit and push once you have an MVP with full CRUD operations working.

##### Stretch Goals
* JUnit tests for your repository, service, and controller layers.
* Supplemental tables, mappings, and controller routes for nested CRUD.

#### Grading

This is a graded project.  You are expected to have your project completed by noon on Monday.  

Your project must be pushed to a Github repo named **EventTrackerProject**.

You must include a _README.md_ that describes your program and how to access it on AWS.  This must document your REST route URIs and HTTP methods, and what they do.

You must also deploy your app to your AWS server.

You will be given either a pass or fail based on whether your code works given all of the following test conditions:

  * A new event object implements full CRUD.  
  * All interactions with the database are done so RESTfully.  

If the project does work with all of the above test conditions, you will be given a *1* for this week's project.

If the project does not work with the above test conditions, you will be given a *0* for this week's project.

If you get a zero on the project, you can upgrade to a score of *.5* if you turn in a working project by the start of class the following Monday morning AND notify an instructor that you wish to get partial credit.


#### Deployment
*  [Deploying Spring Boot Apps](bootDeployment.md) 

<hr>

[Up](../README.md) -- [Next](bootDeployment.md)

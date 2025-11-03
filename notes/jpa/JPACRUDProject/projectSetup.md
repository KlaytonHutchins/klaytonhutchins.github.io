## Project Setup


#### Workspace Folder and Git Setup
1. Create a workspace for the project:
   ```bash
   mkdir ~/SD/Java/JPACrudProject
   ```

1. Create a `.gitignore`:
   ```bash
   cd ~/SD/Java/JPACrudProject/
   atom .gitignore
   ```

   ```
   .DS_Store
   Servers
   target
   build
   bin
   default
   .metadata
   .settings
   .gradle
   *.war 
   *.bak
   ```

1. Create a Github repository named **JPACRUDProject**.  

   * Copy the repository initialization commands from the repo page and run them in your _~/SD/Java/JPACrudProject/_ folder.

   * Do another `git add .` and a `git commit -m "Add .gitignore"`.

   * Be sure to add, commit, and push frequently throughout this project; for example, after completing each of the following setup sections would be a good time for a git commit.

#### MySQL Schema Setup

1. Create a folder for your database development files:

   ```bash
   mkdir ~/SD/Java/JPACrudProject/DB
   ```

1. Create a MySQL Workbench schema model.

   1. Set the name of the database physical schema to an appropriate name (we'll use `myprojectdb` as an example).

   1. Create `username@localhost` user with `table.modify` role for your database, where "_username_" is specific to your project.

      1. Make a note of your:
         * Schema name
         * Username
         * Password

   1. Save the MWB file to `~/SD/Java/JPACrudProject/DB/myprojectdb.mwb` (where _myprojectdb_ is a name appropriate for your schema.)

   1. Create your entity table with an appropriate table name.

      1. Give it an `id` INTEGER primary key column with AutoIncrement.
      1. Add one other column for now so you can test your Persistence Unit configuration.
      1. In the _Inserts_ tab, add one row of data with a column value we can check in a JUnit entity test; make sure to hit _Apply Changes_, then save your MWB file and forward engineer the schema.

#### Project Workspace Setup

1. In STS, use _File_ | _Open Workspace_ to open your _JPACrudProject_ folder while also leaving _VideoStore_ open for reference.

1. In the STS _Preferences_, change the following settings:

   * **Java** | **Compiler** _Compiler compliance Level_: **`1.8`**
   * **Gradle**: **`Specific Gradle version`** (current latest version)
   * **Run/Debug** | **Console**: UN-check _Limit console output_.
   * **General** | **Workspace**: _Show full workspace_
   * **Apply and Close**

#### JPA Project Setup

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
1. Copy the contents of the `build.gradle` from the **JPAVideoStore** project into your new project's `build.gradle`; save and **Gradle Refresh**.

#### Configure the JPA Persistence Unit

1. Copy the `log4j.properties` file from **JPAVideoStore** into your new project's `src/main/resources` and `src/test/resources` folders.
1. From the **JPAVideoStore** `persistence.xml` copy the contents from between the `<persistence-unit>` tags (not the whole file) into your new project's `persistence.xml`, between the opening and closing `<persistence-unit>` tags.
1. Change the schema name in the JDBC URL to the name you gave your schema.
1. Set the values for user and password to the application user you created in your model.

#### Stub out and test your entity

1. Choose an approriate package name for your project and change the `<class>` declaration with a new package name and the name of your entity class.
1. Create the new package and entity class in `src/main/java`.
1. Add the id field and one other field in the class (leave the rest for later).
1. Add no-arg ctor, gets/sets, toString, etc.
1. Annotate your entity.
1. Create a matching package under `src/test/java` and create a new JUnit test case for your entity.
1. Build out the JUnit test until it passes.

### Create a Spring Boot Project for your MVC controller, DAO, and DAO implementation.

1. Copy the base package name from your entity class (the package name up to but not including `.entities`)
1. Create a new _Spring Starter Project_.
1. Paste the base package name into the _Package_ field.
1. Give the project an appropriate name (this project name will appear in the URL once you deploy the project.)
1. Set the _Type_ to **Gradle** 
1. Set the _Java Version_ to **8**.
1. Set the _Packaging_ to **War**.
1. Add the _Spring Web_, _Spring Data JPA_, and _MySQL Driver_ dependencies.

1. Add JSP dependencies to the `dependencies` block in the Boot project's `build.gradle`:

   ```
   implementation 'javax.servlet:jstl:1.2'
   implementation 'org.apache.tomcat.embed:tomcat-embed-jasper'
   ```

1. Connect the projects using your Boot project's `settings.gradle` and `build.gradle`.

1. Do a Gradle refresh.

1. Update the Boot project's `application.properties` using the one from the _BootMVCVideoStore_ application.

   * Change the schema name in the datasource URL, the username, and the password to match your MySQL schema model.

1. Create `src/main/webapp/WEB-INF/` for your JSPs.  Static content (HTML, CSS, image files) will go in `src/main/webapp/`.

1. Create packages for your controller and DAO, and get a basic controller route and JSP view working.

### Next Steps

1. Finish designing your database schema. This will be a single-table application.  After completing the column definitions of your entity table, add data for them in the _Inserts_ tab and forward engineer.

1. Update your Java entity class adding fields for your new columns.  Don't forget getters/setters and a toString, and update the JUnit test appropriately.

1. With your DB and entity complete you can focus on implementing CRUD using MVC.

1. As you work, commit and push frequently.

<hr>

[Prev](README.md) | [Up](README.md)


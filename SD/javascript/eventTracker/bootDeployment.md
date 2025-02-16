---
layout: default
title: Deploying Spring Boot Apps
---

When we use _Run As..._ | _Spring Boot Application_ in our development environment, Eclipse:

1. Packages our application as an Executable JAR file, with our boot application class (the one with `main`) configured as the starting point.

2. Runs the application with the equivalent of the command-line:

   ```bash
   java -jar YourAppName.jar
   ```

   * Java opens the JAR file and reads the manifest to find the name of the class to execute (the `Main-Class`), then runs that class.

     ```java
     @SpringBootApplication
     public class MyRestApplication {
       public static void main(String[] args) {
         SpringApplication.run(MyRestApplication.class, args);
       }
     }
     ```

   * This uses the Boot application's embedded Tomcat server, running on the port specified in `application.properties`.

To run our app this way on our EC2 server, we would need to copy it to the server, then log in and run the above command from the command line.

* This will not automatically restart after a reboot the way Tomcat will.
* We would need to configure our app to run on a port other than 8080, which is already in use.
  * Each new Boot app would need its own port number, which we would also need to open on our server's firewall.

We can instead package our app in the standard WAR file format, and deploy it to the existing Tomcat on our server host the way we've deployed our previous MVC apps.

### A WAR-Deployable Spring Boot App

When we deploy to the existing Tomcat web container, Tomcat won't call our Boot application's `main` method.

* Instead, it needs another way of configuring and launching our application.

To do this, we modify our `main` class to extend `SpringBootServletInitializer`, overriding its `configure` method:

```java
@SpringBootApplication
public class MyRestApplication extends SpringBootServletInitializer {
  @Override
  protected SpringApplicationBuilder configure(SpringApplicationBuilder application) {
    return application.sources(MyRestApplication.class);
  }
  public static void main(String[] args) {
    SpringApplication.run(MyRestApplication.class, args);
  }
}
```

1. Open the Spring boot project you are trying to deploy to AWS.
1. In the application's runner class, the one with the `main` method, copy the class name to the clipboard.
1. Modify the runner class to `extend SpringBootServletInitializer`.
1. Override the `configure` method as follows:
   ```java
   @Override
   protected SpringApplicationBuilder configure(SpringApplicationBuilder application) {
     return application.sources(MAINCLASSNAME.class);
   }
   ```
   * Paste the runner class's name to replace `MAINCLASSNAME`.

1. If your app is called `EventTracker`, your application runner class should look like this when completed:

   ```java
   @SpringBootApplication
   public class EventTrackerApplication extends SpringBootServletInitializer {

     @Override
     protected SpringApplicationBuilder configure(SpringApplicationBuilder application) {
       return application.sources(EventTrackerApplication.class);
     }

     public static void main(String[] args) {
       SpringApplication.run(EventTrackerApplication.class, args);
     }
   }
   ```

### WAR File Creation

We can have Gradle build our WAR file for us.

1. Open your `build.gradle` file.
1. Add the `war` plugin `apply plugin: 'war'`
1. Add the following war task to specify where the war file should be created and what it should be called.
   ```
   apply plugin: 'war'
   war {
     enabled = true
     archiveFileName = "${archivesBaseName}.war"
     destinationDirectory = file("../")        // Project workspace directory
   }
   ```
1. _Gradle_ | _Refresh Gradle project_
  
   * In the _Gradle Tasks_ view, under `build`, you should now see a `war` task; don't run it yet, there's one more change to make.

### Add the _spring-boot-starter_tomcat_ Dependency

1. In the `dependencies` in `build.gradle`, add:

   ```java
   implementation ('org.springframework.boot:spring-boot-starter-tomcat')
   ```

1. _Gradle_ | _Refresh Gradle project_

This makes sure the Boot app's embedded tomcat doesn't interfere with the Tomcat server we'll deploy it to.

### Deploying
1. Use MySQL Workbench _Forward Engineer_ to dump your schema to a `.sql` file to your project's workspace directory.

1. Secure copy your dump file to your AWS instance (in your local terminal):
    * ***NOTE***: 123.45.6.78 is a placeholder for your IP address

    ```bash
    scp -i ~/.ssh/aws.pem ~/SD/Java/YOURWORKSPACENAME/dump.sql ec2-user@123.45.6.78:~
    ```

1. Secure Shell into your server and import your dump.sql into your sql server:

   * Connect to your AWS server from your terminal:

     ```bash
     ssh -i ~/.ssh/aws.pem ec2-user@123.45.6.78
     ```

    * On your remote server, load your dump.sql into MySQL:

      ```bash
      mysql -u root -p < ~/dump.sql
      ```

1. In the gradle tasks area select the project you are trying to deploy and run the `build/war` task.
    ![gradle war file](images/bootWarFile.jpg)

1. F5 Refresh the project and you will see a `WAR` folder with the generated war file inside.
    ![generated location](images/generatedWar.png)

1. Secure copy your `.war` file to your AWS instance (in your local terminal). Use your IP address, not the one in the example. Navigate into your projects directory in terminal and then execute:

    ```bash
    scp -i ~/.ssh/aws.pem WAR/YOURPROJECTNAME.war ec2-user@123.45.6.78:/var/lib/tomcat8/webapps/
    ```


<hr>

[Prev](README.md) | [Up](README.md)


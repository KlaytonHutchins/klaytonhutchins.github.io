---
layout: default
title: JUnit Dependencie
---

In order to test our entities, we must include JUnit in our project's dependencies.

Testing our entities will ensure that we have properly configured our JPA environment (in the `persistence.xml`) and annotated our entity classes correctly.

### Drill
> 1. First things first, we need to include testing dependencies in our `build.gradle` file.
>
>    ```groovy
>    ext {
>      hibernateVersion = "5.4.32.Final"
>      mySqlConnectorVersion = "8.0.27"
>      junit5Version = "5.8.2"
>    }
>    
>    // define project specific dependencies
>    dependencies {
>      implementation "mysql:mysql-connector-java:$mySqlConnectorVersion"
>      implementation "log4j:log4j:1.2.17"
>      implementation "org.hibernate:hibernate-core:$hibernateVersion"
>      implementation "org.hibernate:hibernate-c3p0:$hibernateVersion"
>      
>      testImplementation("org.junit.jupiter:junit-jupiter:$junit5Version")
>    }
>    ```
>
>    * Since this dependency is used only in testing, we add it to our dependencies with the `testImplementation` configuration.
>
> 1. Now we tell Gradle to use JUnit when its `test` task is run - add this after the `dependencies` block:
>       
>    ```groovy
>    test {
>        useJUnitPlatform()
>    }
>    ```
>   
> 1. Make sure you save your `build.gradle` before you run a Gradle refresh. Our project is now set up for creating JUnit tests.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](setupTesting.md)


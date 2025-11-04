---
layout: default
title: Test Setup
---


We'll put our JUnit test cases in the same package (`com.example.jpavideostore.entities`) as the entity classes they test.

They'll be in a different source folder, _src/test/java_, so Gradle knows not to include them in deployment.

When tests run, Hibernate will want a logging configuration file, _log4j.properties_.

### Drill
>
> If you haven't already, copy `log4j.properties` from _src/main/resources_ to _src/test/resources_.
> 
> * In the copy, change `log4j.logger.org.hibernate.type` from `trace` to `WARN`.
> 
> Inside of _src/test/java_ create a package named `com.example.jpavideostore.entities`.
>
> ```bash
> JPAVideoStore
> ├── src/main/java
> │   ├── com.example.jpavideostore.client
> │   │   ├── AddressClient.java
> │   │   ├── CustomerClient.java
> │   │   └── ...
> │   └── com.example.jpavideostore.entities
> │       ├── Address.java
> │       ├── Customer.java
> │       └── ...
> ├── src/main/resources
> │   ├── META-INF
> │   │   └── persistence.xml
> │   └── log4j.properties
> ├── src/test/java
> │   └── com.example.jpavideostore.entities
> │       ├── AddressTest.java
> │       └── CustomerTest.java
> ├── src/test/resources
>     └── log4j.properties
> ```
>

<hr>

[Prev](testingDependencies.md) -- [Up](README.md) -- [Next](creatingTestFiles.md)


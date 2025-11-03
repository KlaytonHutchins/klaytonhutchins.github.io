## Spring Boot Integration

### Additional Dependencies

The `Spring Web` dependency does not bring in support for traditional _Spring MVC_ with `.jsp` files.

To get this functionality we need to add three additional dependencies to our `build.gradle` file.

```
   implementation 'javax.servlet:jstl:1.2'
   implementation 'org.apache.tomcat.embed:tomcat-embed-jasper'
```

### Controller and DAO Files

Nothing will change in regards to creating Controller or DAO files.

Each type should have its own package, `com.example.bootmvc.controllers` and `com.example.bootmvc.data`, respectively.

### Drill
> 1. Add the two JSP dependencies above to the `dependencies` block in the *BootMVCVideoStore/build.gradle* and do a Gradle refresh.
> 1. Under the *src/main* folder, create the new Folder *webapp/WEB-INF*. **NOTE: this is not a src folder**
> 1. Create `com.example.bootmvc.controllers` and `com.example.bootmvc.data` packages.

<hr>

[Prev](integratingSpringBootAndJPA.md) -- [Up](README.md) -- [Next](multiProject.md)


---
layout: default
title: Including JPA Project
---


Adding other projects as sub modules of our _Spring Boot_ project requires editing the `build.gradle` and `settings.gradle` files.

#### `settings.gradle`
To include a project from the same workspace folder, add the following to the `settings.gradle` file:


```

includeFlat 'NameofProjectToInclude'
```


In our setup, the Spring Boot project includes the JPA project.

#### `build.gradle`
Now that Gradle knows about the project you are trying to include, we need to compile the project and include it as a dependency.

```
dependencies {
  implementation project(':NameofProjectToInclude')
  // ...
}
```

### Drill
> 1. Include `JPAVideoStore` as a sub project of `BootMVCVideoStore`.
>    * Open *BootMVCVideoStore/settings.gradle*
>      * MAKE SURE YOU ARE IN THE `settings.gradle` OF **BootMVCVideoStore**.
>        * add `includeFlat 'JPAVideoStore'`:
>
>      ```groovy
>      // settings.gradle
>      rootProject.name = 'BootMVCVideoStore'
>      
>      includeFlat 'JPAVideoStore'
>      ```
>    * This tells *MVCVideoStore* that it has a *sub project* named *JPAVideoStore*
> 1. Save and close *BootMVCVideoStore/settings.gradle*.
> 1. Open *BootMVCVideoStore/build.gradle*
>    * MAKE SURE YOU ARE IN THE `build.gradle` OF **BootMVCVideoStore**.
>    * Add the dependency to compile the `JPAVideoStore` project.
>
> 	 ```groovy
>		 dependencies {
>			 implementation project(':JPAVideoStore')
>
>			 // ...
>		 }
>    ```
> 1. Save and close *BootMVCVideoStore/build.gradle*.
> 1. Do a Gradle refresh of *BootMVCVideoStore*.

<hr>

[Prev](springBootIntegration.md) -- [Up](README.md) -- [Next](dao.md)


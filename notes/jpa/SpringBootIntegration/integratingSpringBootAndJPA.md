## Incorporating JPA into your Spring Boot Project

Integrating a JPA project into Spring Boot is simple.

* We will do this by creating a separate *Spring Boot Project*, and using *Gradle* to pull the JPA project into it.

* Gradle automates the inclusion of the JPA project into the Spring Boot Project. Each time our Web Project is built/deployed, Gradle loads in the JPA project.

### Practice Exercise
> ***NOTE***: This setup process is a good template for how to set up your group project.

<br >

### Drill
>
>***NOTE***: STS makes multiple project builds a little bit difficult to manage with a single Github repository. As a result, we recommend that you create a new *workspace* as an umbrella for each new site. In this workspace you will create a JPA and Spring Boot project. You will then initialize that *workspace* as a *Git* repository.
>
> For this drill, we will use the existing *VideoStore* workspace.
>
> 1. Open your *VideoStore* workspace.
>    * Execute a Gradle Refresh on your project to bring in all dependencies.
>    * In the _Gradle Tasks_ view, run the `verification` | `test` task and make sure all your JPA unit tests pass.
> 1. Create a new Spring Starter Project with the name `BootMVCVideoStore`.
>    * Set the _Type_ to `Gradle`.
>    * Set the _Java Version_ to `8`.
>    * Set the _Packaging_ to `War`.
>    * Set the _Package_ to `com.example.bootmvc`.
> 1. Add the `Spring Web`, `Spring Data JPA`, and `MySQL Driver` dependencies to your project.
>    * Be sure to include all three dependencies.
> 1. Build the project with `Finish`.

<hr>

[Prev](README.md) | [Up](README.md) | [Next](springBootIntegration.md)


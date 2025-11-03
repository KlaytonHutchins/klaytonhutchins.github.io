## Demo: Address List Route

Up to this point we haven't interacted with a database using Spring REST. Remember the _JPAVideoStore_ project we created during JPA week? We are going to use this pre-configured backend to create some resource routes for _Address_ and _Actor_ objects.

1. Find your JPAVideoStore project. Run one of your JUnit tests to make sure that your connections are still up and running.
   * If you broke or lost this project, use the provided solution in the [resources directory](./resources).

1. Create a separate Spring Starter Project called **VideoStoreREST**.
   * Walk through the standard process of creating a Spring Boot project.  
   * Give your project a base package of **`com.example`**.
   * Set _Type_ to **Gradle**, _Java Version_ to **8**, and _Packaging_ to **War**.
   * Be sure to include the **Spring Web**, **Spring Data JPA**, and **MySQL Driver** dependency bundles.

1. Edit the new project's `settings.gradle` file at the same level as your `build.gradle` file. Add JPAVideoStore as a sub project.
   ``` groovy
   rootProject.name = 'VideoStoreREST'

   includeFlat 'JPAVideoStore'
   ```

1. Add your JPAVideoStore project as a dependency to the `build.gradle` file, then run a _Gradle refresh_.
   ```groovy
   dependencies {
    	implementation project(':JPAVideoStore')

      // ...
   }
   ```
1. Configure your `port` and `datasource` in the `application.properties`.
   ```
   #### PORT CONFIG ####
   server.port=8081

   #### MYSQL DATASOURCE ####
   spring.datasource.url=jdbc:mysql://localhost:3306/sdvid?useSSL=false&&useLegacyDatetimeCode=false&serverTimezone=US/Mountain
   spring.datasource.username=student
   spring.datasource.password=student
   spring.datasource.driver-class-name=com.mysql.cj.jdbc.Driver
   ```

1. Create two packages, one called `com.example.videostorerest.data` and the other called `com.example.videostorerest.controllers`.

1. Create files called `AddressDAO`, `AddressDAOImpl`, and `AddressController` in their respective packages.

1. Annotate your DAOImpl as `@Transactional` and `@Service`. Include the _EntityManager_ as a field.
   ```java
   @Transactional
   @Service
   public class AddressDAOImpl implements AddressDAO {
     @PersistenceContext
     private EntityManager em;
   }
   ```  

1. Annotate the controller as a `@RestController` and `@Autowire` in your `AddressDAO`. Give the class a `@RequestMapping` so that all the subsequent routes are preceded by `api/`.

   ```java
   @RestController
   @RequestMapping("api")
   public class AddressController {
     @Autowired
     private AddressDAO addressDAO;
   }
   ```

1. Write a single DAO method that uses JPQL to query the database to retrieve and return a list of addresses.  

   ```java
   public List<Address> findAll(){
     String query = "Select a from Address a";
     return em.createQuery(query, Address.class).getResultList();
   }
   ```

1. Back in your controller, write a method that is mapped by the path `/api/addresses` which returns the result of calling the DAO method we just wrote.  

   ```java
   @RequestMapping(path="addresses", method=RequestMethod.GET)
   public List<Address> index(){
     return addressDAO.findAll();
   }
   ```

1. Run the program and hit the route `http://localhost:8080/api/addresses` in Postman. View the returned json data.  

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](addressShowRoute.md)


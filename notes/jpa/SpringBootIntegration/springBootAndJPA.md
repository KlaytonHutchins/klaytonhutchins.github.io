---
layout: default
title: Spring Boot and JPA
---

## Spring Boot and JPA

### Entities and `EntityManager`
_Spring Boot_ scans your project's base package for any `@Entity` classes and adds them to its default _Persistence Unit_.

The `JPA` dependency, set when creating the project, causes _Spring Boot_ to create an `EntityManager` for DAOs to use. The DAO's `@PersistenceContext` annotation allows _Spring Boot_ to autowire this `EntityManager`. _Spring Boot_ also creates a `TransactionManager` for your `@Transactional` DAOs.


```java
// Example:
package com.example.bootmvc.data;

@Service
@Transactional
public class MyDAOImpl implements MyDAO{
  @PersistenceContext
  private EntityManager em;

  // ...
}
```

Due to the automatic component scanning, any DAOImpl class annotated with `@Service`, `@Component`, or `@Repository` will have a bean created for it. This bean is eligible to be `@Autowired` into your Controller classes.

```java
// Example:
package com.example.bootmvc.controllers;

@Controller
public class MyController{
  @Autowired
  private MyDAO dao;

  // ...
}
```

### Finding an `@Entity` in Different Packages
If an `@Entity` class lives in a package outside your project's base package (e.g. it is in a different Eclipse project), use `@EntityScan("other.package.name")`

```java
@SpringBootApplication
@EntityScan("com.example.jpavideostore")
public class BootMvcVideoStoreApplication {

	public static void main(String[] args) {
		SpringApplication.run(BootMvcVideoStoreApplication.class, args);
	}
}

```

### Practice Exercise
> If Spring boot cannot find an entity, the app will still start. When a DAO attempts to query the database, the page and log will display errors like:
>
> ```
> org.hibernate.hql.internal.ast.QuerySyntaxException: Film is not mapped
> ```




### Drill
> 1. Add entity scanning configuration to `com.example.bootmvc.BootMvcVideoStoreApplication`
>    ```java
>    @SpringBootApplication
>    @EntityScan("com.example.jpavideostore")
>    public class BootMvcVideoStoreApplication {
>    
>	    public static void main(String[] args) {
>		    SpringApplication.run(BootMvcVideoStoreApplication.class, args);
>	    }
>    }
>    ```
>

<hr>

[Prev](dao.md) -- [Up](README.md) -- [Next](controller.md)


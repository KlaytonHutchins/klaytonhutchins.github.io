## `application.properties`

We must add configuration to `src/main/resources/application.properties` to connect Spring Boot to our database.

```
#### MYSQL DATASOURCE ####
spring.datasource.url=jdbc:mysql://localhost:3306/myprojectdb?useSSL=false
spring.datasource.username=username
spring.datasource.password=password
spring.datasource.driver-class-name=com.mysql.cj.jdbc.Driver
```

We can add additional configuration to enable Hibernate and SQL logging. Set these to `WARN` for fewer log messages.

```
logging.level.org.hibernate.SQL=DEBUG
logging.level.org.hibernate.type=TRACE
spring.jpa.show-sql=true
```

### Example `application.properties`
A full `application.properties` is shown below. It contains optional ViewResolver configuration, and sets the application to run on port `8081`.

```
#### PORT CONFIG ####
##### Alternate Tomcat port
server.port=8081


#### JSP VIEW RESOLVER ####
##### Include if you used a ViewResolver to shorten the names of your views
# spring.mvc.view.prefix: /WEB-INF/
# spring.mvc.view.suffix: .jsp


#### MYSQL DATASOURCE ####
##### Configure to match your Database
spring.datasource.url=jdbc:mysql://localhost:3306/sdvid?useSSL=false&useLegacyDatetimeCode=false&serverTimezone=US/Mountain
spring.datasource.username=student
spring.datasource.password=student
spring.datasource.driver-class-name=com.mysql.cj.jdbc.Driver


#### LOGGING ####
##### Set to WARN for fewer log messages
logging.level.root=WARN
logging.level.org.springframework.web=DEBUG
logging.level.org.hibernate.SQL=DEBUG
logging.level.org.hibernate.type=TRACE
spring.jpa.show-sql=true


#### TOMCAT ####
spring.datasource.tomcat.max-active=10
spring.datasource.dbcp2.max-idle=8
spring.datasource.dbcp2.max-wait-millis=10000
spring.datasource.dbcp2.min-evictable-idle-time-millis=1000
spring.datasource.dbcp2.min-idle=8
spring.datasource.dbcp2.time-between-eviction-runs-millis=1
```

### Drill
> 1. Add the configuration above to your `application.properties`.
>    * Make sure to configure the datasource to match your database URL and credentials.
> 1. Execute a Gradle refresh.
> 1. Run your `BootMVCVideoStore` application by running the `BootMvcVideoStoreApplication` class as a Spring Boot App. Your app will run on port `8081`.
> 1. Search for film with `id` 1.

<hr>

[Prev](controller.md) -- [Up](README.md) -- [Next](labs.md)


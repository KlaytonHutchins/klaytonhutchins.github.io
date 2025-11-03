## The `persistence.xml`

A persistence unit is a named set of entities (instances of POJOs annotated with `@Entity`) in your application, and the mapping of those entities to the database (Entity -> SQL and SQL -> Entity).

You will define persistence units (we will only have one) in a `persistence.xml` file located in the *src/main/resources/META-INF/* directory.

Declare the persistence unit name using the **name** attribute of the `<persistence-unit>` element.

```xml
<persistence-unit name="VideoStore">
  <!-- ... -->
</persistence-unit>
```
Identify which persistence provider you wish to use with the `<provider>` element (we are using Hibernate).

```xml
<persistence-unit name="VideoStore">
  <provider>org.hibernate.jpa.HibernatePersistenceProvider</provider>
  <!-- ... -->
</persistence-unit>
```

Provide configuration information for the persistence unit using the `<property>` element.

```xml
<persistence-unit name="VideoStore">
  <provider>org.hibernate.jpa.HibernatePersistenceProvider</provider>
    <!-- ... -->
  <properties>
    <property name="javax.persistence.jdbc.url"
            value="jdbc:mysql://localhost:3306/sdvid?useSSL=false" />
    <property name="javax.persistence.jdbc.user" value="student"/>
    <property name="javax.persistence.jdbc.password" value="student" />
    <property name="javax.persistence.jdbc.driver" value="com.mysql.cj.jdbc.Driver" />
  </properties>

</persistence-unit>
```

Standard elements include:

* *url* - the location of your database server.

* *user* - the username to access your database server.

* *password* - the password to access your database server.

* *driver* - the driver class to use for connecting to your SQL implementation.

You can also add provider specific configuration here.

* For Hibernate, there are debug configurables that can be toggled on and off to help you during development.

* For c3p0, you can configure the connection pool settings, dictating the length of time until the pooled connections time out, and the maximum number of connections.

### Drill
> 1. If you don't already have one, create a `persistence.xml` file in the *src/main/resources/META-INF* directory.
>
>    * Use the template below for the basic elements of your file.
>
>    * Name the persistence unit **VideoStore**.
>
>    * Add additional properties to the file to specify database and connection pool information as below.
>
>    ```xml
>    <?xml version="1.0" encoding="UTF-8"?>
>    <persistence version="2.2" xmlns="http://xmlns.jcp.org/xml/ns/persistence" 
>     xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" 
>     xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/persistence http://xmlns.jcp.org/xml/ns/persistence/persistence_2_2.xsd">
>      <persistence-unit name="VideoStore">
>        <provider>org.hibernate.jpa.HibernatePersistenceProvider
>        </provider>
>
>        <properties>
>          <property name="javax.persistence.jdbc.url" value="jdbc:mysql://localhost:3306/sdvid?useSSL=false&amp;useLegacyDatetimeCode=false&amp;serverTimezone=US/Mountain" />
>          <property name="javax.persistence.jdbc.user" value="student"/>
>          <property name="javax.persistence.jdbc.password" value="student" />
>          <property name="javax.persistence.jdbc.driver" value="com.mysql.cj.jdbc.Driver" />
>
>          <property name="hibernate.show_sql" value="false" />
>          <property name="hibernate.format_sql" value="false" />
>
>          <property name="hibernate.dialect" value="org.hibernate.dialect.MySQLDialect" />
>          <property name="hibernate.connection.provider_class" value="org.hibernate.connection.C3P0ConnectionProvider" />
>
>          <property name="hibernate.c3p0.max_size" value="5" />
>          <property name="hibernate.c3p0.min_size" value="0" />
>          <property name="hibernate.c3p0.acquire_increment" value="1" />
>          <property name="hibernate.c3p0.idle_test_period" value="300"/>
>          <property name="hibernate.c3p0.max_statements" value="0" />
>          <property name="hibernate.c3p0.timeout" value="60" />
>        </properties>
>      </persistence-unit>
>    </persistence>
>    ```
> 
> 1. Inside of `src/main/resources/` create a file named `log4j.properties`.
> 
>    * Add the following as its contents:
> 
>      ```
>      // Logging levels, from least verbose to most, are:
>      // OFF, FATAL, ERROR, WARN, INFO, DEBUG, TRACE, and ALL
>      // Change this line from WARN to INFO for more detailed logging
>      log4j.rootLogger=WARN, stdout
>      log4j.logger.org.hibernate.type=trace
>      log4j.appender.stdout=org.apache.log4j.ConsoleAppender
>      log4j.appender.stdout.layout=org.apache.log4j.PatternLayout
>      log4j.appender.stdout.layout.ConversionPattern=%d %p [%c] - %m%n
>      ```
> 
>    * Copy `log4j.properties` to `src/test/resources/`.
> 
>      In this copy, you might want to change `log4j.logger.org.hibernate.type=trace` to `log4j.logger.org.hibernate.type=WARN` to speed up and declutter the extensive unit testing you will be doing.

<hr>

[Prev](dependencies.md) | [Up](README.md) | [Next](entityClass.md)


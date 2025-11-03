## Spring MVC vs. Spring REST

### Dependencies

Spring Boot includes the necessary dependencies for us to get up and running with Spring REST using the `Web` starter dependency pack we included in our previous Boot builds.

Subdependencies of `spring-boot-starter-web` include:
* `spring-context` - `@Component`, `@Controller`, etc.
* `spring-web` - `@RequestMapping`, `@RequestParam`, `@RequestBody`, `@ResponseBody`, `@RestController`, etc.
* `spring-webmvc` - `DispatcherServlet`, `ModelAndView`, `ViewResolver`, etc.
* `spring-boot-starter-json` - This bundles the FasterXML `jackson` libraries for serializing and deserializing Java objects as XML, JSON, and several other formats.

### URL Patterns

The extension `.do` is a convention for Spring MVC routes that return views.

* A path like `getEmployees.do` in our controller, for example, would return an HTML view of employees.

REST applications use a noun-based path pattern like `/api/*` or `/rest/*`.

* A path like `/api/employees` in our controller would return raw employee data, serialized as XML or JSON.

The return value of an MVC controller method is either a `String` view name, or a `ModelAndView`, that results in an HTML view being generated for the client.

#### @ResponseBody

In a REST API, a controller method returns data directly to the client.

The `@ResponseBody` annotation changes the way Spring handles a controller method's return value from trying to map it to a generated view, to returning a JSON representation of an object, or a text value representation of a primitive type.

### Drill

1. Create a new Spring Starter Project called `MyFirstRestProject`
   * Make sure the project uses Gradle(Buildship 3.x)
   * Give your project values for group and description, and set the package to `com.example.rest`.
   * Add the `Spring Web Starter` dependency package.

1. Create a `com.example.rest.controllers` package.

   * Inside of this package, create a class named `TestController` and add the `@Controller` annotation above the class declaration.

1. Write a method named `ping()` that returns the String "pong":
   ```java
   @RequestMapping(path = "ping", method = RequestMethod.GET)
   @ResponseBody
   public String ping() {
     return "pong";
   }
   ```


<hr>

[Prev](README.md) | [Up](README.md) | [Next](testing.md)


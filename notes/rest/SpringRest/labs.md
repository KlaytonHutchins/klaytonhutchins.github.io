## Labs

1. Replace the `@Controller` annotation for `TestController` with `@RestController`, and remove `@ResponseBody` from the `ping` method.

1. In `TestController`, create a method named `echo` that's mapped to `"echo"` using the POST method.  It should take a `String` parameter annotated with `@RequestBody`.  It should return the parameter passed.

1. Test this endpoint using Postman.  Add a new request tab. Select **POST** as the method and `http://localhost:8080/echo` as the URL.  Under the request, click **Body**, and choose **raw**.  Enter a message like "Hello, REST!" and send the request.

<hr>

[Prev](mappingRequests.md) | [Up](README.md)


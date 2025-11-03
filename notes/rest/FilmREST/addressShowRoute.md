## Demo: Address Show Route

We have a list route working that returns all the addresses in our database. But what if we want a single address by its id?

1. Create a second method in your _DAO_ that retrieves a single `Address` by its id. Assume the id is going to be passed into the method as a parameter.
    ```java
    public Address findById(int id){
      return em.find(Address.class, id);
    }
    ```

1. In your controller create a second method called `show`. This method will take a path of `/api/addresses/{id}` where is the `{id}` is a URI parameter (PathVariable).
    ```java
    @RequestMapping(path="addresses/{id}", method=RequestMethod.GET)
    public Address show(@PathVariable int id){
      return addressDAO.findById(id);
    }
    ```

1. Run the program and hit the route `http://localhost:8080/api/addresses/1` in Postman. View the returned json data. Your should get
    ```json
    {
      "id": 1,
      "street": "47 MySakila Drive",
      "street2": null,
      "stateProvince": "Alberta",
      "city": "Lethbridge",
      "postalCode": "",
      "phone": "",
      "country": {
        "countryCode": "CA",
        "name": "Canada"
      }
    }
    ```

<hr>

[Prev](addressListRoute.md) -- [Up](README.md) -- [Next](addressCreateRoute.md)


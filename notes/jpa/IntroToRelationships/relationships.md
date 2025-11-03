## Entity Relationships

When you learned *Object Oriented Programming*, you saw how objects can contain other objects (or even collections of other objects) as fields.

Similarly, when you were taught SQL, you learned about how to use JOINs to gather data from multiple tables in a single request.

JPA allows us to combine the principles of *Object Oriented Programming* with the ability to query across SQL tables using Entity Relationships known as *Associations*.

JPA provides support for the same *associations* we are familiar with from our relational database models.

* *Associations* can be:

  * one-to-one

    * *A Customer* ***HAS ONE*** *Address*

  * one-to-many

    * *A Language* ***HAS MANY*** *Films*

  * many-to-one

    * *A Film* ***HAS ONE*** *Language*

  * many-to-many

    * *A Film* ***HAS MANY*** *Actors* **AND** *An Actor* ***HAS MANY*** *Films*

* Direction can be uni-directional or bi-directional.

> #### directional
> Which side of a relationship is aware of the relationship.
> * uni-directional: the child knows about the parent.
> * bi-directional: the parent also knows about the child.

There is an annotation for each _cardinality_ type which you apply to the field that holds the related entity.

> #### cardinality  
> The number of instances on each side of a relationship.

  * For bi-directional relationships, apply the cardinality annotation to both entities.

### Relationships in Our DB & Design Considerations
Between the customer and address table there is a _one-to-one_ relationship.
* A single customer contains a single address.
* Or, looking at it from the other side of the relationship, a single address belongs to single customer. We will map the customer to address relationship shortly.  

Between the address and country there is a _many-to-one_ relationship.
* Many addresses belong to a single country.
* Or, looking at it from the other side of the relationship, it is a _one-to-many_ relationship.
  * A single country contains many addresses. We will map the address to country relationship in the next chapter.  

Direction can be uni-directional or bi-directional. For direction it is best to think of the entities, not the database tables. For customer and address should you store an address field in customer? Or, should a customer be stored as a field in address? Or, both? The first and second cases are unidirectional, whereas the last case is bidirectional. Which choice is best is ultimately a design decision based on how you plan to use the data. 

<hr>

[Prev](README.md) | [Up](README.md) | [Next](accessingMultipleTables.md)


## DAO Interface Advantages

A class that calls methods on a variable whose type is a DAO interface is not coupled with a specific DAO implementation class.
* The class doesn't know which implementation class's methods it is calling; this is good.

In the future, we could change _which_ DAO implementation we use, and thus _where_ the class gets its data, by changing the object the interface variable refers to.


> ### Drill
>
> Previous versions of `StockServlet` have used a `StockProvider`, and then used the data it provided.
>
> The new `StockServlet` uses a DAO. In this drill, we will change the `StockServlet` to use a DAO that interacts with a database.
>
>
> `DAOPattern/`
>
> * Run the project on Eclipse's Server.
> * Search for the Stock `aapl`.
>
> `DAOPattern/com.example.daopattern.drills.servlets.StockServlet`
>
> `StockServlet` uses an `InMemoryStockDAOImpl` in its `init()` method.
> * Open `InMemoryStockDAOImpl` to see where it gets its data.
> * `init()` is called by the web container when it instantiates the servlet.
>
> ```java
> public class StockServlet extends HttpServlet {
>   private StockDAO stockDAO;
>
>   @Override
>   public void init() throws ServletException {
>     stockDAO = new InMemoryStockDAOImpl();
>   }
>   // ...
> }
> ```
>
> * Change this to use a `JDBCStockDAOImpl` instance.
> * Now search for different stocks, like `ZTS` or `PBI`.
>   * Note that you did not have to change any more servlet code because it uses the interface's methods.

<hr>

[Prev](dao-implementation.md) -- [Up](README.md) -- [Next](mock-object.md)


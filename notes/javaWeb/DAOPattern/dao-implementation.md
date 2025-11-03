---
layout: default
title: DAO Component
---

## DAO Components

The DAO pattern typically uses three components.

* **Data Object** - class representing the data to use.
* **DAO Interface** - an interface that provides methods for using the Data Objects.
* **DAO Implementation Classes** - classes implementing the DAO interface, and handling interaction with the underlying storage.


The example below uses `Stock` objects.

#### Data Object

```java
package com.example.daopattern.examples.stocks;

public class Stock {
  private String symbol;
  private String name;
  private double price;

  public Stock(String symbol, String name, double price) {
    this.symbol = symbol;
    this.name = name;
    this.price = price;
  }
  // getters and setters...
}
```

#### Interface
The DAO interface provides two methods for reading `Stock`s.

```java
package com.example.daopattern.examples.stocks;

import java.util.List;

public interface StockDAO {
  public Stock findStockBySymbol(String symbol);
  public List<Stock> getAllStocks();
}
```

#### Implementation Classes
This simple class creates `Stock` objects and keeps them in memory.
* Note how the class's name describes what the class does.

```java
package com.example.daopattern.examples.stocks;

import java.util.ArrayList;
import java.util.List;

public class InMemoryStockDAOImpl implements StockDAO {

  private List<Stock> stocks;

  public InMemoryStockDAOImpl(){
    stocks = new ArrayList<>();

    stocks.add(new Stock("aapl", "Apple" ,107.25));
    stocks.add(new Stock("fb", "FaceBook", 105.50));
    stocks.add(new Stock("goog", "Alphabet", 750.50));
    stocks.add(new Stock("nflx", "Netflix", 117.00));
    stocks.add(new Stock("twtr", "Twitter", 22.57));
  }

  @Override
  public Stock findStockBySymbol(String symbol) {
    for (Stock stock : stocks) {
      if(stock.getSymbol().equals(symbol)) {
        return stock;
      }
    }
    return null;
  }

  @Override
  public List<Stock> getAllStocks() {
    return new ArrayList<>(stocks);
  }
}
```

This implementation class reads data from a database, which involves connections and queries - things a user of the class should not care about.

```java
public class JDBCStockDAOImpl implements StockDAO {

  private static String url = "jdbc:mysql://localhost:3306/stockdb?useSSL=false&useLegacyDatetimeCode=false&serverTimezone=US/Mountain";
  private final String fullDataQuery = "SELECT symbol, company_name, quote"
      + " from SYMBOL ";
  // ... brevity ...

  @Override
  public Stock findStockBySymbol(String symbol) {
    Stock s = null;
    try {
      Connection conn = DriverManager.getConnection(url, user, pass);

      String sql = fullDataQuery + " WHERE symbol = ?";
      PreparedStatement st = conn.prepareStatement(sql);
      st.setString(1, symbol);
      ResultSet rs = st.executeQuery();
      if(rs.next()) {
        s = mapResultSetToStock(rs);
      }
      conn.close();
    }
    catch (SQLException e) {
      e.printStackTrace();
    }
    return s;
  }

  // ...
}
```

<hr>

[Prev](dao.md) -- [Up](README.md) -- [Next](changing-implementation.md)


## Labs
These labs require writing on paper or a whiteboard.

1. Create a class diagram to depict a `BankAccount`.
   ```java
   public class BankAccount {
    private double balance;
    private String accountId;

    public BankAccount(String accountId, double balance) {
      super();
      this.accountId = accountId;
      this.balance = balance;
    }

    public String getAccountId() {
      return accountId;
    }

    public void withdraw(double amount) {
      balance -= amount;
    }

    public void deposit(double amount) {
      double tempBalance = balance;
      tempBalance = tempBalance + amount;
      balance = tempBalance;
    }

    public double getBalance() {
      return balance;
    }
   }
   ```

2. Add a class diagram to represent a `User` class.
   * `User` has a first name and last name.
   * A `User` can have `0` to `5` `BankAccount`s.
   * `User` has a no-arg constructor.
   * `User` has `public String getFirstName()`, `public void setFirstName(String)`, `public String getLastName()`, `public void setLastName(String)`.
   * `User` has a method to add a `BankAccount` to its array of accounts.
   * `User` has a `public` method called `getAccounts` that returns its array of accounts.

(Solution: _ObjectsUML/src/userBankAccount.png_)

<hr>

[Prev](has-a.md) -- [Up](README.md)


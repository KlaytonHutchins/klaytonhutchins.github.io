## Data Entry with Exceptions
We will simulate a data entry system where users are prompted to enter numeric data, which is saved. The system will handle invalid input, and allow the user to enter a secret ADMIN interface.

### User Stories

1. As a system user I am prompted to enter a whole number so that my data is stored in the system.
   * The program will add each valid item to a `List<Integer>`.

1. As a user, if I enter non-numeric or floating-point data I am shown an error message, and the program continues so that I can enter numeric data.
   * Non-numeric data causes an exception, which the program must handle.
   * All invalid entries are written to another `List`.

1. As a user, if I type `EXIT` I am given confirmation that I am exiting the system, and the program ends. Otherwise I can continue entering numeric data into the system.


1. As a user, if I enter the string `ADMIN`, I am prompted to enter a password so that I can continue.

1. As a potential admin user, if I enter the secret password `PASSWORD`, I am presented with a menu so that I can choose from the following options:
   ```
   Options:
   1. View valid user input history
   2. View invalid user input history
   3. Exit Admin Menu
   ```

1. As an admin user, I can enter the following options to cause the following actions:
   * `1`: I can view the list of valid input.
   * `2`: I can view the list of invalid input.
   * `3`: I can exit this menu.
   * If I enter an invalid number or non-numeric character, I am prompted with the same menu.

1. As an admin user, if I enter the wrong password, I am returned to the data entry screen.
   * Create a custom _checked_ exception named `AdminAuthenticationException`. If the user enters an invalid password, exit the admin interface methods by throwing this exception.


### Stretch Goals
1. As an admin user, I want a menu option to allow me to see the maximum and minimum numbers entered.

1. As an admin user, I want a menu option to allow me to see the longest-length invalid data entered.

1. As an admin user, I want to be able to remove a single item from the list of invalid strings.
   * Should the user enter the String itself? The index of the String?

<hr>

[Up](../README.md)
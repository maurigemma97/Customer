# Customer
work with structs and arrays to build project that will allow you to add new customers, update existing customers, display all information, and terminate the program.

a.	Function menu:
This function should display a menu for the user with the choices given above. This function must return a value between 1-4. Use a data validation loop. 

b.	Function addcust:
This function should ask the user to enter data for a customer and simultaneously add it to the bottom of the array. 
This function must not accept negative values for the balance. Use a data validation loop and force the user to enter a valid balance.

c.	Function updatecust:
This function should ask the user for the customer's ID.  The function should then call a function called findcust(see description below).  
The function will use the return value from findcust (subscript) to update all of the customer information or state that the customer was not found. 
To update the data, the function should ask the user to enter new data for the customer. Do not accept negative values for the balance. 
Use a data validation loop and force the user to enter a valid balance..

d.	Function displaycust:
This function will print the data in a tabular form with headers.

e.	Function findcust:
This function will accept as parameters, the array, the number of customers and the id for the customer to be found. 
The function will use a linear search to return the subscript or return -1 if not found

# MC-Design_Shopping
**
Overview
This is a C++ console-based shopping application that allows users to perform various tasks such as adding, editing, deleting, listing products, and generating a receipt. The application is divided into two main user roles: Administrator and Buyer.

**Administrator : The administrator can add, edit, delete, and list products. To access the administrator functions, a username and password are required.
**Buyer : The buyer can select products to purchase and generate a receipt.

# Features
**Administrator Functions
**Add a Product: The administrator can add new products to the database by providing product details such as code, name, price, and discount.
**Modify a Product : Existing product details can be modified, including the product code, name, price, and discount.
**Delete a Product : The administrator can delete a product from the database using its product code.
**List Products : The administrator can view a list of all products in the database.**Overview
This C++ application is a simple command-line shopping system with two user roles: Administrator and Buyer. It allows administrators to add, edit, delete, and list products, while buyers can make purchases and receive a receipt. The application stores product information in a text file called "database.txt."

Features
Administrator
Login: Administrators can log in with a predefined username and password.
Add a Product: Add new products to the database, including a product code, name, price, and discount.
Modify a Product: Update product information based on the product code.
Delete a Product: Remove a product from the database by specifying its product code.
List Products: View a list of all available products.
Buyer
Buy Product: Buyers can select products, specify quantities, and receive a receipt with the total cost.
Go Back: Return to the main menu.
Usage
Main Menu: When you start the application, you will see the main menu with three options:

Administrator Login
Buyer
Exit
Administrator Login: Enter the username and password to access the administrator menu. Default credentials: "soufiane" and "123."

Administrator Menu: Once logged in as an administrator, you can perform the following actions:

Add a Product
Modify a Product
Delete a Product
List Products
Return to the Main Menu
Buyer: Select the "Buyer" option from the main menu to make purchases:

Choose products by entering their product codes and quantities.
Receive a detailed receipt with the total amount.
Optionally, print the receipt.
Exit: Choose the "Exit" option to exit the application.

File Storage
Product information is stored in a text file named "database.txt." Each line in the file represents a product and includes the following information:

Product Code
Product Name
Price
Discount
Printing Receipts
The application provides an option to print receipts. To enable this feature, you need to specify the printer name and filename in the code (replace "Printer Name" and "filename.txt" with your printer name and file name). The "print" command is used to initiate the printing process.

Dependencies
This application relies on the C++ Standard Library for basic input/output operations and file handling.

Developer
This shopping application was created by Soufiane Hammouda.

Note: Make sure to adjust the default credentials, printer name, and any other settings as needed for your specific use case.

Enjoy using the shopping application!

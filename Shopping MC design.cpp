#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

class shopping {
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping::menu() {
    int choice;
    string username;
    string password;

    cout << "\t\t\t\t ______________________________________\n";
    cout << "\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t|               Main Menu              |\n";
    cout << "\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t| _____________________________________|\n";
    cout << "\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t|            1) Administrator          |\n";
    cout << "\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t|            2) Buyer                  |\n";
    cout << "\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t|            3) Exit                   |\n";
    cout << "\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t|______________________________________|\n";
    cout << "\n\t\t\t\t           Please select!\n";
    cout << "\n\t\t\t\t           \n";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "\t\t\t Please Login \n";
        cout << "\n\t\t\t Enter username  : \t";
        cin >> username;
        cout << "\n\t\t\t Password    :   \t";
        cin >> password;

        if (username == "soufiane" && password == "123") {
            system("cls");
            administrator();
        } else {
            cout << "Invalid username/password\n";
        }
        break;

    case 2:
        system("cls");
        buyer();
        break;

    case 3:
        system("cls");
        exit(0);

    default:
        cout << "Please select from the given options \n";
    }

    menu();
}

void shopping::administrator() {
    int choice;
    cout << "\n\n";
    cout << "\n\t\t\t ________________________________";
    cout << "\n\t\t\t|                               |";
    cout << "\n\t\t\t|       Administrator menu      |";
    cout << "\n\t\t\t|_______________________________|";
    cout << "\n\t\t\t _______________________________ ";
    cout << "\n\t\t\t|                               |";
    cout << "\n\t\t\t|____ 1) Add a product _________|";
    cout << "\n\t\t\t|                               |";
    cout << "\n\t\t\t|____ 2) Modify a product ______|";
    cout << "\n\t\t\t|                               |";
    cout << "\n\t\t\t|____ 3) Delete a product ______|";
    cout << "\n\t\t\t|                               |";
    cout << "\n\t\t\t|____ 4) List the products _____|";
    cout << "\n\t\t\t|                               |";
    cout << "\n\t\t\t|____ 5) Back to main menu _____|";
    cout << "\n\t\t\t|_______________________________|";
    cout << "\n\n\t\t            Please enter your choice : ";

    cin >> choice;
    
    switch (choice) {
    case 1:
        system("cls");
        add();
        break;

    case 2:
        system("cls");
        list();
        edit();
        break;

    case 3:
        system("cls");
        list();
        rem();
        break;

    case 4:
        system("cls");
        list();
        break;

    case 5:
    	system("cls");
        menu();
        break;

    default:
        cout << "Invalid choice!";
    }

    administrator(); // Call the administrator function recursively after the switch case.
}

void shopping::buyer() {
    int choice;
    cout << "\t\t\t  Buyer \n";
    cout << "\t\t\t________________________________\n";
    cout << "\t\t\t|                               |\n";
    cout << "\t\t\t|_______1) Buy product__________|\n";
    cout << "\t\t\t|                               |\n";
    cout << "\t\t\t|_______2) Go back______________|\n";
    cout << "\t\t\t|                               |\n";
    cout << "\t\t\t|        Enter your choice      |\n";
    cout << "\t\t\t|_______________________________|\n";
    cout << "\t\t\t-----------------> ";

    cin >> choice;

    switch (choice) {
    case 1:
        receipt();
        break;

    case 2:
        system("cls");
        menu();
        break;

    default:
        cout << "Invalid choice";
    }

    buyer();
}

void shopping::add() {
    fstream data;
    int c;
    float p;
    float d;
    string n;
    
    data.open("database.txt", ios::in);
    cout << "\n\n\t\t\t Add new product";

    cout << "\n\n\t Existing Products:\n";
    while (data >> c >> n >> p >> d) {
        cout << "\t" << c << "\t" << n << "\t" << p << "\t" << d << endl;
    }
    data.close();
    
   
    cout << "\n\n\t Please enter the product's code : ";
    cin >> pcode;

    data.open("database.txt", ios::in);
    bool codeExists = false;

    while (data >> c >> n >> p >> d) {
        if (c == pcode) {
            codeExists = true;
            break;
        }
    }
    data.close();

    if (codeExists) {
    	system("cls");
        cout << "\n\n\t Product code already exists! Please enter a product code that does not exist.\n";
    
        add(); 
        return; 
    }

    	cout << "\n\n\t Please enter the product's name : ";
    	cin >> pname;
    	cout << "\n\n\t Please enter the product's Price : ";
    	cin >> price;
    	cout << "\n\n\t Discount on product : ";
    	cin >> dis;

    	data.open("database.txt", ios::app | ios::out);
   		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
    	data.close();
    	cout << "\n\n\t Record inserted!";
}

void shopping::edit() {
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    
    ifstream data("database.txt");
    if (!data) {
        cout << "\n\nFile doesn't exist! ";
        return;
    }
    
    ofstream data1("database1.txt");
    if (!data1) {
        cout << "\n\nError creating temporary file! ";
        return;
    }
    
    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code : ";
    cin >> pkey;

    while (data >> pcode >> pname >> price >> dis) {
        if (pkey == pcode) {
            cout << "\n\t\t Product new code : ";
            cin >> c;
            cout << "\n\t\t Name of the product : ";
            cin >> n;
            cout << "\n\t\t Price : ";
            cin >> p;
            cout << "\n\t\t Discount : ";
            cin >> d;
            data1 << " " << c << " " << n << " " << p << " " << d << "\n";
            cout << "\n\n\t\t Record edited ! ";
            token++;
        }
        else {
            data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        }
    }
    
    data.close();
    data1.close();

    if (token == 0) {
        cout << "\n\n Record not found. Sorry!";
    }
    else {
        remove("database.txt");
        rename("database1.txt", "database.txt");
    }
}

void shopping::rem() {
    fstream data, data1;
    int pkey;
    int token = 0;

    cout << "\n\n\t Delete product";
    cout << "\n\n\t Product code : ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "File doesn't exist";
        return;
    }

    data1.open("database1.txt", ios::app | ios::out);
    if (!data1) {
        cout << "\n\nError creating temporary file! ";
        return;
    }

    data >> pcode >> pname >> price >> dis;
    while (!data.eof()) {
        if (pcode == pkey) {
            cout << "\n\n\t Product deleted successfully";
            token++;
        } else {
            data1 << pcode << " " << pname << " " << price << " " << dis << "\n";
        }
        data >> pcode >> pname >> price >> dis;
    }

    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt", "database.txt");

    if (token == 0) {
        cout << "\n\n Record not found";
    }
}

void shopping::list() {
    fstream data;
    data.open("database.txt", ios::in);
    cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
    cout << "\n\n\t\t\t\tProducts List\t\t\n\n";
    cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
    cout << "ProNo\t\tName\t\t\t\tPrice\t\tDiscount\n";
    cout << "\n\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";

    data >> pcode >> pname >> price >> dis;
    while (!data.eof()) {
        cout << pcode << "\t\t" << setw(20) << left << pname << "\t\t" << price << "\t\t" << dis << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
    data.close();
}

void shopping::receipt() {
    system("cls");
    fstream data;
    int arrc[100], arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;
  
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n Empty database";
    } else {
        data.close();
        list();
        cout << "\n____________________________\n";
        cout << "\n|                            |";
        cout << "\n|    Please place the order  |";
        cout << "\n|____________________________|\n";
        do {
            m:
            cout << "\n\n Product Code : ";
            cin >> arrc[c];
            bool codeExists = false;

            // Check if the entered product code exists in the database
            data.open("database.txt", ios::in);
            int pcodeCheck;
            string pnameCheck;
            float priceCheck, disCheck;

            while (data >> pcodeCheck >> pnameCheck >> priceCheck >> disCheck) {
                if (pcodeCheck == arrc[c]) {
                    codeExists = true;
                    break;
                }
            }
            data.close();

            if (!codeExists) {
                cout << "\n\n Invalid product code. Please choose from the existing products.\n";
                goto m;
            }

            cout << "\n Product Quantity : ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\n\n Duplicate Product Code. Please try again!";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Want to buy another product? Press y for yes and n for no : ";
            cin >> choice;
        } while (choice == 'y');
        system("cls");

        cout << "\n\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ RECEIPT _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
        cout << "\nProduct Num.\tProduct Name\tQuantity \tPrice \tAmount \tAmount with discount\n";

        for (int i = 0; i < c; i++) {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
        }
        cout << "\n\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
        cout << "\n Total Amount : \n" << total;

        char printChoice;
cout << "\n\n Do you want to print the receipt? Press y for yes and n for no : ";
cin >> printChoice;
if (printChoice == 'y') {
    // Launch the printery using system command
    system("print /D:\"Printer Name\" filename.txt");
    // Replace "Printer Name" with the name of your printer
    // Replace filename.txt with the name of the file you want to print
    cout << "\n Receipt printed!";
}
        }
}

int main() {
    shopping shop;
    shop.menu();
    return 0;
}


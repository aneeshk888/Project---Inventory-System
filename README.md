Inventory Management System is a console-based C++ application that demonstrates intermediate-level programming and STL usage through a dynamic inventory of items. This project showcases real-world software modeling using classes and Standard Template Library (STL) containers such as std::vector and algorithms like std::sort, std::find_if.

Features
Our Inventory System provides the following features:
```
Add new items to inventory (name, quantity, price)
Remove an item by name
Search for an item by name
Display all inventory items (sorted alphabetically)
Update item if duplicate name exists
Menu-driven dashboard interface for user interaction
Project Requirements
The following C++ concepts and STL features are implemented:
```
```
Classes and Objects for data abstraction
Access Specifiers, Constructors
STL Containers- std::vector
STL Algorithms- std::sort, std::find_if, std::remove_if
Dynamic Memory Handling
Formatted I/O using iomanip
Looping, Conditionals, and Modular Design
A working C++ environment like g++, clang++, or IDEs such as Code::Blocks, Visual Studio Code, or Dev C++ is required.
```

Implementation Steps
Step 1: Define the Item Class
We define a class Item that holds individual item data:



```
class Item {
public:
    int id;
    std::string name;
    int quantity;
    float price;
​
    Item(int id, const std::string& name, int quantity, float price);
    void display() const;
};
This class supports:
```

Constructor initialization
Display method for formatted output
Step 2: Inventory Class with Vector
We use a class Inventory that manages a dynamic list of items using std::vector<Item>:



```
class Inventory {
private:
    std::vector<Item> items;
    int nextId = 1;
public:
    void addItem(const std::string& name, int quantity, float price);
    void removeItemByName(const std::string& name);
    void searchItemByName(const std::string& name) const;
    void displayInventory();
};
The Inventory class:
```

Manages IDs automatically.
Prevents duplicates (updates instead of adding)
Uses std::sort, std::find_if, std::remove_if
Step 3: Menu-Driven Dashboard
The menu allows users to interactively:
```
Add a new item
Remove existing item
Search item
Display all items
Exit program



void showMenu() {
    std::cout << "\n--- Inventory System ---\n"
              << "1. Add Item\n"
              << "2. Remove Item\n"
              << "3. Search Item\n"
              << "4. Display Inventory\n"
              << "5. Exit\n"
              << "Enter your choice: ";
}
Each option connects to Inventory class functions.
```

Step 4: Main Function


```
int main() {
    Inventory inventory;
    int choice;
​
    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(); // Clear newline
​
        std::string name;
        int quantity;
        float price;
​
        switch (choice) {
            case 1:
                std::cout << "Enter item name: ";
                std::getline(std::cin, name);
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                std::cout << "Enter price: ";
                std::cin >> price;
                inventory.addItem(name, quantity, price);
                break;
            case 2:
                std::cout << "Enter item name to remove: ";
                std::getline(std::cin, name);
                inventory.removeItemByName(name);
                break;
            case 3:
                std::cout << "Enter item name to search: ";
                std::getline(std::cin, name);
                inventory.searchItemByName(name);
                break;
            case 4:
                inventory.displayInventory();
                break;
            case 5:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
​
    return 0;
}

```
Execution & Output
On executing the program, users are greeted with a text-based dashboard. Input is handled through standard input, and the output is neatly formatted using std::setw and precision settings.


```
Example Output:



--- Inventory System ---
1. Add Item
2. Remove Item
3. Search Item
4. Display Inventory
5. Exit
Enter your choice: 1
Enter item name: Apple
Enter quantity: 10
Enter price: 1.5
​
Item added successfully.
​
--- Inventory System ---
...
Summary
The Inventory Management System project provides a complete application of:
```

OOP design principles
STL containers and algorithms
Formatted console interaction
It simulates the backend of a real-world inventory app and serves as an excellent learning tool for mastering C++ with STL in practical scenarios.

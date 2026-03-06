class Item {
public:
    int id;
    std::string name;
    int quantity;
    float price;

    Item(int id, const std::string& name, int quantity, float price);
    void display() const;
};

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

void showMenu() {
    std::cout << "\n--- Inventory System ---\n"
              << "1. Add Item\n"
              << "2. Remove Item\n"
              << "3. Search Item\n"
              << "4. Display Inventory\n"
              << "5. Exit\n"
              << "Enter your choice: ";
}



int main() {
    Inventory inventory;
    int choice;

    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(); // Clear newline

        std::string name;
        int quantity;
        float price;

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

    return 0;
}

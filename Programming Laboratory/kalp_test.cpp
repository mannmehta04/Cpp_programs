#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Item {
    public:
        string name;
        int quantity;

        Item(string n, int q) {
            name = n;
            quantity = q;
        }

        void display() {
            cout << "Name: " << name << "\tQuantity: " << quantity << endl;
        }
};

class Inventory {
    private:
        vector<Item> items;

    public:
        void load() {
            ifstream file("inventory.txt");

            if (file.is_open()) {
                string name;
                int quantity;

                while (file >> name >> quantity) {
                    Item item(name, quantity);
                    items.push_back(item);
                }

                file.close();
            }
        }

        void save() {
            ofstream file("inventory.txt");

            if (file.is_open()) {
                for (Item item : items) {
                    file << item.name << " " << item.quantity << endl;
                }

                file.close();
            }
        }

        void add() {
            string name;
            int quantity;

            cout << "Enter item name: ";
            cin >> name;
            cout << "Enter item quantity: ";
            cin >> quantity;

            Item item(name, quantity);
            items.push_back(item);

            save();
        }

        void remove() {
            string name;

            cout << "Enter item name: ";
            cin >> name;

            auto it = find_if(items.begin(), items.end(), [&name](Item item) { return item.name == name; });

            if (it != items.end()) {
                items.erase(it);
                save();
            } else {
                cout << "Item not found" << endl;
            }
        }

        void search() {
            string name;

            cout << "Enter item name: ";
            cin >> name;

            auto it = find_if(items.begin(), items.end(), [&name](Item item) { return item.name == name; });

            if (it != items.end()) {
                it->display();
            } else {
                cout << "Item not found" << endl;
            }
        }

        void display() {
            for (Item item : items) {
                item.display();
            }
        }
};

int main() {
    Inventory inventory;
    inventory.load();

    while (true) {
        cout << "1. Add item" << endl;
        cout << "2. Remove item" << endl;
        cout << "3. Search item" << endl;
        cout << "4. Display inventory" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inventory.add();
                break;
            case 2:
                inventory.remove();
                break;
            case 3:
                inventory.search();
                break;
            case 4:
                inventory.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Bird {
private:
    string name, species;
    float price;
    bool sold;

public:
    Bird() : sold(false), price(0.0) {}

    void setDetails() {
        cout << "Enter Bird Name: ";
        cin >> name;
        cout << "Enter Bird Species: ";
        cin >> species;
        cout << "Enter Bird Price: ";
        cin >> price;
        sold = false;
    }

    void display(int index) const {
        if (!sold) {
            cout << index + 1 << ". " << name << " (" << species << ") - $" << price << "\n";
        }
    }

    string getName() const { return name; }
    string getSpecies() const { return species; }
    float getPrice() const { return price; }
    bool isSold() const { return sold; }

    void markAsSold() { sold = true; }
};

class Client {
private:
    string name, contact;
    Bird bird;

public:
    void setDetails(Bird b) {
        cin.ignore();
        cout << "Enter Client Name: ";
        getline(cin, name);
        cout << "Enter Client Contact: ";
        getline(cin, contact);
        bird = b;
    }

    void display() const {
        cout << "Client: " << name
             << " | Contact: " << contact
             << " | Bought: " << bird.getName()
             << " (" << bird.getSpecies() << ") - $" << bird.getPrice() << "\n";
    }
};

class Admin {
private:
    string name, contact;

public:
    void setDetails() {
        cout << "Enter Admin Name: ";
        getline(cin, name);
        cout << "Enter Admin Contact: ";
        getline(cin, contact);
    }

    void display() const {
        cout << "Admin: " << name << " | Contact: " << contact << "\n";
    }
};

class BirdShop {
private:
    string shopName;
    Admin admin;
    vector<Bird> birds;
    vector<Client> clients;

public:
    void setupShop() {
        cout << "Enter Bird Shop Name: ";
        getline(cin, shopName);
        admin.setDetails();
    }

    void displayShopInfo() const {
        cout << "\n--- Welcome to " << shopName << " ---\n";
        admin.display();
    }

    void addBird() {
        Bird b;
        b.setDetails();
        birds.push_back(b);
        cout << "Bird added successfully!\n";
    }

    void viewBirds() const {
        cout << "\n--- Available Birds ---\n";
        for (size_t i = 0; i < birds.size(); ++i) {
            birds[i].display(i);
        }
    }

    void sellBird() {
        int choice;
        viewBirds();
        cout << "Enter the number of the bird to buy: ";
        cin >> choice;

        if (choice < 1 || choice > birds.size() || birds[choice - 1].isSold()) {
            cout << "Invalid choice or already sold.\n";
            return;
        }

        Bird selected = birds[choice - 1];
        Client client;
        client.setDetails(selected);

        birds[choice - 1].markAsSold();
        clients.push_back(client);

        cout << "Bird sold successfully!\n";
    }

    void viewClients() const {
        cout << "\n--- Client Records ---\n";
        for (size_t i = 0; i < clients.size(); ++i) {
            clients[i].display();
        }
    }

    void menu() {
        int option;
        do {
            cout << "\n--- Bird Shop Menu ---\n";
            cout << "1. Add Bird\n";
            cout << "2. View Birds\n";
            cout << "3. Sell Bird\n";
            cout << "4. View Client Records\n";
            cout << "5. Exit\n";
            cout << "Enter choice: ";
            cin >> option;

            switch (option) {
                case 1: addBird(); break;
                case 2: viewBirds(); break;
                case 3: sellBird(); break;
                case 4: viewClients(); break;
                case 5: cout << "Thank you for using Bird Shop System!\n"; break;
                default: cout << "Invalid option.\n";
            }
        } while (option != 5);
    }
};

int main() {
    BirdShop shop;
    shop.setupShop();
    shop.displayShopInfo();
    shop.menu();
    return 0;
}


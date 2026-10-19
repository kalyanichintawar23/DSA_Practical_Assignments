#include <iostream>
#include <string>

using namespace std;

struct Friend {
    string name;
    string mobile;
};

class PhoneBook {
    Friend book[100];
    int count;

public:
    PhoneBook() {
        count = 0;
    }

    void insertSorted(string name, string mobile) {
        int i = count - 1;
        while (i >= 0 && book[i].name > name) {
            book[i + 1] = book[i];
            i--;
        }
        book[i + 1].name = name;
        book[i + 1].mobile = mobile;
        count++;
    }

    int sentinelSearch(string target) {
        if (count == 0) return -1;

        string last = book[count - 1].name;
        book[count - 1].name = target;

        int i = 0;
        while (book[i].name != target) {
            i++;
        }

        book[count - 1].name = last;

        if (i < count - 1 || last == target) {
            return i;
        }
        return -1;
    }

    void display() {
        if (count == 0) {
            cout << "Phonebook is empty." << endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << book[i].name << " - " << book[i].mobile << endl;
        }
    }

    void addOrSearch() {
        string name, mobile;
        cout << "Enter friend's name: ";
        cin >> name;

        int index = sentinelSearch(name);

        if (index != -1) {
            cout << "Friend found! Mobile Number: " << book[index].mobile << endl;
        } else {
            cout << "Friend not found. Enter mobile number to add: ";
            cin >> mobile;
            insertSorted(name, mobile);
            cout << "Friend added successfully." << endl;
        }
    }
};

int main() {
    PhoneBook pb;
    int choice;

    do {
        cout << "\n--- PhoneBook Menu ---" << endl;
        cout << "1. Search / Add Friend" << endl;
        cout << "2. Display Phone Book" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            pb.addOrSearch();
        } else if (choice == 2) {
            pb.display();
        }
    } while (choice != 3);

    return 0;
}

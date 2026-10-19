#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    string number;
    string date;
    string time;
    Node* next;
};

Node* head = NULL;

void addCall()
{
    Node* newNode = new Node;

    cout << "Enter name: ";
    cin >> newNode->name;

    cout << "Enter phone number: ";
    cin >> newNode->number;

    cout << "Enter date: ";
    cin >> newNode->date;

    cout << "Enter time: ";
    cin >> newNode->time;

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Call added successfully.\n";
}

void displayCalls()
{
    if (head == NULL)
    {
        cout << "No calls found.\n";
        return;
    }

    Node* temp = head;

    cout << "\nCall Log\n";

    while (temp != NULL)
    {
        cout << "Name: " << temp->name << endl;
        cout << "Number: " << temp->number << endl;
        cout << "Date: " << temp->date << endl;
        cout << "Time: " << temp->time << endl;
        cout << "----------------------\n";

        temp = temp->next;
    }
}

void deleteCall()
{
    if (head == NULL)
    {
        cout << "No calls found.\n";
        return;
    }

    string number;
    cout << "Enter phone number to delete: ";
    cin >> number;

    Node* temp = head;
    Node* previous = NULL;

    while (temp != NULL && temp->number != number)
    {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Call not found.\n";
        return;
    }

    if (previous == NULL)
    {
        head = temp->next;
    }
    else
    {
        previous->next = temp->next;
    }

    delete temp;

    cout << "Call deleted successfully.\n";
}

void searchCall()
{
    if (head == NULL)
    {
        cout << "No calls found.\n";
        return;
    }

    string number;
    cout << "Enter phone number to search: ";
    cin >> number;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->number == number)
        {
            cout << "\nCall Found\n";
            cout << "Name: " << temp->name << endl;
            cout << "Number: " << temp->number << endl;
            cout << "Date: " << temp->date << endl;
            cout << "Time: " << temp->time << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Call not found.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== CALL LOG MANAGEMENT =====\n";
        cout << "1. Add Call\n";
        cout << "2. Display Calls\n";
        cout << "3. Search Call\n";
        cout << "4. Delete Call\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addCall();
                break;

            case 2:
                displayCalls();
                break;

            case 3:
                searchCall();
                break;

            case 4:
                deleteCall();
                break;

            case 5:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}

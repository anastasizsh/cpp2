#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Member {
public:
    Member(int id, const string& name);
    Member();
    void printStatus();
    bool extendMembership(int months);
    bool cancelMembership();
    int getId() { return id; }
private:
    int id;
    string name;
    int months;
};

Member::Member(int id, const string& name)
    : id(id), name(name), months(0) {}

Member::Member() : id(0), name(""), months(0) {}

void Member::printStatus() {
    cout << "Member " << id << " : " << name << ", subscription valid for " << months << " months" << endl;
}

bool Member::extendMembership(int months) {
    if (months < 0) {
        return false;
    }
    this->months += months;
    return true;
}

bool Member::cancelMembership() {
    this->months = 0;
    return true;
}

int findMember(Member members[], int size, int id) {
    for (int i = 0; i < size; ++i) {
        if (members[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

void printAllMembers(Member members[], int size) {
    bool noMembers = true;
    for (int i = 0; i < size; ++i) {
        if (members[i].getId() != 0) {
            members[i].printStatus();
            noMembers = false;
        }
    }
    if (noMembers) {
        cout << "No members in the system" << endl;
    }
}

void printAvailableCommands() {
    cout << "Available commands:\n";
    cout << "create [id] [name] - Create a new member with ID and name\n";
    cout << "delete [id] - Delete the member with ID\n";
    cout << "extend [id] [n] - Extend membership by n months\n";
    cout << "cancel [id] - Cancel the membership (set months to 0)\n";
    cout << "quit - Exit the program\n";
}

int main() {
    Member members[10];
    string command;

    printAvailableCommands(); // Print available commands at the start

    while (true) {
        cout << "What would you like to do?: ";
        getline(cin, command);
        stringstream ss(command);
        string action;
        ss >> action;

        if (action == "quit") {
            break;
        }
        else if (action == "create") {
            int id;
            string name;
            ss >> id;
            getline(ss, name);
            name = name.substr(1); // Remove leading space

            if (findMember(members, 10, id) != -1) {
                cout << "Cannot perform this operation: Member with ID " << id << " already exists." << endl;
            }
            else {
                bool created = false;
                for (int i = 0; i < 10; ++i) {
                    if (members[i].getId() == 0) {
                        members[i] = Member(id, name);
                        members[i].printStatus();
                        created = true;
                        break;
                    }
                }
                if (!created) {
                    cout << "Cannot perform this operation: Maximum number of members reached." << endl;
                }
            }
        }
        else if (action == "delete") {
            int id;
            ss >> id;
            int index = findMember(members, 10, id);
            if (index == -1) {
                cout << "Cannot perform this operation: Member with ID " << id << " does not exist." << endl;
            }
            else {
                members[index] = Member();
                cout << "Member " << id << " deleted." << endl;
                printAllMembers(members, 10);
            }
        }
        else if (action == "extend") {
            int id, months;
            ss >> id >> months;
            int index = findMember(members, 10, id);
            if (index == -1) {
                cout << "Cannot perform this operation: Member with ID " << id << " does not exist." << endl;
            }
            else if (!members[index].extendMembership(months)) {
                cout << "Cannot perform this operation: Invalid number of months." << endl;
            }
            else {
                members[index].printStatus();
            }
        }
        else if (action == "cancel") {
            int id;
            ss >> id;
            int index = findMember(members, 10, id);
            if (index == -1) {
                cout << "Cannot perform this operation: Member with ID " << id << " does not exist." << endl;
            }
            else {
                members[index].cancelMembership();
                members[index].printStatus();
            }
        }
        else {
            cout << "Unknown command" << endl;
            printAvailableCommands(); // Print available commands on unknown command
        }
    }

    return 0;
}
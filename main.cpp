#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Node {
    string caseNumber;
    string incidentPrimary;
    string gunshotInjury;
    string homicideVictimFirstName;
    string homicideVictimLastName;
    Node(string caseNum, string incPrimary, string gunInjury, string firstName, string lastName)
            :caseNumber(caseNum),
            incidentPrimary(incPrimary),
            gunshotInjury(gunInjury),
            homicideVictimFirstName(firstName),
            homicideVictimLastName(lastName),
            left(nullptr),
            right(nullptr){}
    Node* left;
    Node* right;
};

void insert(Node*& root, string caseNum, string incPrimary, string gunInjury, string firstName, string lastName) {
    if (!root) {
        root = new Node(caseNum, incPrimary, gunInjury, firstName, lastName);
        return;
    }
    if (caseNum < root->caseNumber) {
        insert(root->left, caseNum, incPrimary, gunInjury, firstName, lastName);
    } else {
        insert(root->right, caseNum, incPrimary, gunInjury, firstName, lastName);
    }
}

void printCaseNumbers(Node* root) {
    if (root) {
        printCaseNumbers(root->left);
        cout << root->caseNumber << endl;
        printCaseNumbers(root->right);
    }
}

Node* search(Node* root, string key) {
    if (!root || root->caseNumber == key) {
        return root;
    }
    if (key < root->caseNumber) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

int searchAndDisplay(Node* root) {
    string searchKey;
    string userResponse;
    do {
        cout << "Enter a Case Number to search: ";
        cin >> searchKey;
        Node* result = search(root, searchKey);
        if (result) {
            cout << "Case Number: " << result->caseNumber << ", "
                 << "Incident Primary: " << result->incidentPrimary << ", "
                 << "Gunshot Injury: " << result->gunshotInjury << ", "
                 << "Victim Name: " << result->homicideVictimFirstName << " " << result->homicideVictimLastName
                 << endl;
        } else {
            cout << "Case Number not found." << endl;
        }

        cout << "Would you like to search another case number? (yes/no): ";
        cin >> userResponse;
    } while (userResponse == "yes");
    return 0;
}


int main() {
    string filename = //Make this the file path of your csv file;
    ifstream file(filename);
    string header;
    getline(file, header);
    Node* root = nullptr;
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string caseNum;
        string incPrimary;
        string gunInjury;
        string firstName;
        string lastName;
        getline(iss, caseNum, ',');
        getline(iss, incPrimary, ',');
        getline(iss, gunInjury, ',');
        getline(iss, firstName, ',');
        getline(iss, lastName, ',');
        insert(root, caseNum, incPrimary, gunInjury, firstName, lastName);
    }
    cout << "Case Numbers: " << endl;
    printCaseNumbers(root);
    file.close();
    searchAndDisplay(root);
    return 0;
}

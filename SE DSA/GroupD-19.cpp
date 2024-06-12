#include <iostream>
#include <string>
using namespace std;

class Dictionary {
private:
    string keyword;
    string meaning;
    Dictionary* left;
    Dictionary* right;

public:
    Dictionary(string key, string mean) {
        keyword = key;
        meaning = mean;
        left = nullptr;
        right = nullptr;
    }

    // Function to insert a new keyword and its meaning
    void insert(string key, string mean) {
        insertNode(this, new Dictionary(key, mean));
    }

    // Function to display all keywords and their meanings
    void display() {
        displayNodes(this);
    }

    // Function to remove a keyword and its meaning
    void remove(string key) {
        removeNode(this, key);
    }

private:
    // Function to insert a new node into the dictionary
    void insertNode(Dictionary* root, Dictionary* newNode) {
        if (root == nullptr) {
            root = newNode;
            return;
        }

        if (newNode->keyword < root->keyword) {
            if (root->left == nullptr)
                root->left = newNode;
            else
                insertNode(root->left, newNode);
        } else if (newNode->keyword > root->keyword) {
            if (root->right == nullptr)
                root->right = newNode;
            else
                insertNode(root->right, newNode);
        }
    }

    // Function to display all nodes in the dictionary
    void displayNodes(Dictionary* root) {
        if (root != nullptr) {
            displayNodes(root->left);
            cout << root->keyword << " = " << root->meaning << endl;
            displayNodes(root->right);
        }
    }

    // Function to remove a node from the dictionary
    Dictionary* removeNode(Dictionary* root, string key) {
        if (root == nullptr) {
            cout << "Keyword not found." << endl;
            return root;
        }

        if (key < root->keyword)
            root->left = removeNode(root->left, key);
        else if (key > root->keyword)
            root->right = removeNode(root->right, key);
        else {
            if (root->left == nullptr) {
                Dictionary* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Dictionary* temp = root->left;
                delete root;
                return temp;
            }

            Dictionary* temp = minNode(root->right);
            root->keyword = temp->keyword;
            root->meaning = temp->meaning;
            root->right = removeNode(root->right, temp->keyword);
        }
        return root;
    }

    // Function to find the node with the smallest key
    Dictionary* minNode(Dictionary* node) {
        Dictionary* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }
};

int main() {
    Dictionary dict("root", "Root Node");
    int choice;
    string key, meaning;

    do {
        cout << "\n===========================================\n"
             << "\n******** Dictionary Management System *********\n"
             << "\n******** MENU ********\n"
             << "1. Add new keyword.\n"
             << "2. Display the contents of the Dictionary.\n"
             << "3. Delete a keyword.\n"
             << "4. Exit.\n"
             << "===============================================\n"
             << "\nEnter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter the keyword: ";
                cin >> key;
                cout << "Enter the meaning of the keyword: ";
                cin.ignore();
                getline(cin, meaning);
                dict.insert(key, meaning);
                break;

            case 2:
                cout << "\nThe words entered in the dictionary are:\n\n";
                dict.display();
                break;

            case 3:
                cout << "\nEnter a keyword to be deleted: ";
                cin >> key;
                dict.remove(key);
                cout << "\nThe word '" << key << "' has been deleted.\n";
                break;

            case 4:
                cout << "\n********** TERMINATED **********\n";
                break;

            default:
                cout << "\nPlease enter a valid option!\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
#include <fstream>
#include "AVL.h"

int main() {
    AVL tree;
    while (true) {
        tree.displayMenu();
        int choice = 0;
        cout << endl << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
        {
            cout << endl << "Reading file";
            fstream file("dictionary.txt");

            if (!file.is_open()) {
                cout << endl << "File not found";
                break;
            }

            string word;
            while (file >> word) {
                tree.insert(word);
            }
            cout << endl << "File read";
            break;
        }

        case 2:
        {
            string word;
            cout << endl << "Enter word: ";
            cin >> word;
            tree.autocomplete(word);
            break;
        }

        case 3:
        {
            string word;
            cout << endl << "Enter word: ";
            cin >> word;
            tree.remove(word);
            break;
        }

        case 4: 
            return 0;
        }

    }
    tree.displayMenu();

}
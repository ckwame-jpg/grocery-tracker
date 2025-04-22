// Author: Christopher Prempeh
// Assignment: CS 210 Project Three
// Course: CS-210
// File: GroceryTracker.cpp


#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <algorithm>

using namespace std;

class GroceryTracker {
private:
    map<string, int> itemCounts;
    string dataFilePath;

    void loadItems(const string& filename) {
        ifstream inFile(filename);
        string item;

        if (!inFile.is_open()) {
            cout << "Error: Could not open input file." << endl;
            return;
        }

        // Trim whitespace and count occurrences of each item
        while (getline(inFile, item)) {
            item.erase(remove(item.begin(), item.end(), '\r'), item.end());
            item.erase(item.find_last_not_of(" \n\r\t") + 1);
            ++itemCounts[item];
        }

        inFile.close();
    }

    void saveToFrequencyFile() {
        ofstream outFile(dataFilePath);

        if (!outFile.is_open()) {
            cout << "Error: Could not write to output file." << endl;
            return;
        }

        // Calculate maximum length for formatting output
        size_t maxLength = 0;
        for (const auto& pair : itemCounts) {
            if (pair.first.length() > maxLength) {
                maxLength = pair.first.length();
            }
        }

        for (const auto& pair : itemCounts) {
            outFile << left << setw(static_cast<int>(maxLength) + 2) << pair.first << ": " << pair.second << endl;
        }

        outFile.close();
        cout << "Data saved to " << dataFilePath << endl;
    }

    void printFrequencyForItem() {
        string item;
        cout << "Enter item name: ";
        cin.ignore();
        getline(cin, item);

        // Lookup frequency for the entered item
        if (itemCounts.find(item) != itemCounts.end()) {
            cout << "Frequency of " << item << ": " << itemCounts[item] << endl;
        } else {
            cout << item << " was not found in the records." << endl;
        }
    }

    void printAllFrequencies() {
        // Format and print the full frequency list
        size_t maxLength = 0;
        for (const auto& pair : itemCounts) {
            if (pair.first.length() > maxLength) {
                maxLength = pair.first.length();
            }
        }

        for (const auto& pair : itemCounts) {
            cout << left << setw(static_cast<int>(maxLength) + 2) << pair.first << ": " << pair.second << endl;
        }
    }

    void printHistogram() {
        // Generate the visual output of the frequency histogram
        for (const auto& pair : itemCounts) {
            cout << setw(12) << left << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }

public:
    GroceryTracker(const string& inputFile, const string& outputFile) {
        // Load items from the input file and save initial frequency data
        dataFilePath = outputFile;
        loadItems(inputFile);
        saveToFrequencyFile(); // Save immediately on start
    }

    void run() {
        // Main menu loop logic for user interactions
        int choice = 0;
        while (choice != 4) {
            cout << "\n===== Corner Grocer Menu =====\n";
            cout << "1. Search for item frequency\n";
            cout << "2. Display all item frequencies\n";
            cout << "3. Display histogram\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: printFrequencyForItem(); break;
                case 2: printAllFrequencies(); break;
                case 3: printHistogram(); break;
                case 4: cout << "Exiting... Goodbye!" << endl; break;
                default: cout << "Invalid input. Please try again." << endl; break;
            }
        }
    }
};

int main() {
    GroceryTracker tracker("/Users/chris/Documents/class/CS250/mod7/CS210_Project_Three_Input_File.txt", "/Users/chris/Documents/class/CS250/mod7/frequency.dat");
    tracker.run();
    return 0;
}
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void appendToFile(const string& input) {
    // Open the file in append mode
    ofstream outputFile("output.txt", ios::app);

    if (!outputFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return;
    }

    // Write the input to the file
    outputFile << input << endl;

    // Close the file
    outputFile.close();

    cout << "Text appended to file." << endl;
}

void deleteFirstLineIfMoreThanTenLines() {
    const int maxLines = 10;
    const string filename = "output.txt";

    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return;
    }

    // Count the number of lines in the file
    vector<string> lines;
    string line;

    while (getline(inputFile, line)) {
        lines.push_back(line);
    }

    inputFile.close();

    // Check if the file has more than 10 lines
    if (lines.size() > maxLines) {
        // Open the file in truncate mode to delete the first line
        ofstream outputFile(filename, ios::trunc);

        if (!outputFile.is_open()) {
            cerr << "Error opening the file for truncation!" << endl;
            return;
        }

        // Write lines 2 to n to the file
        for (size_t i = 1; i < lines.size(); ++i) {
            outputFile << lines[i] << endl;
        }

        outputFile.close();

        cout << "First line deleted as the file exceeded " << maxLines << " lines." << endl;
    }
}

int main() {
    string userInput;

    cout << "Enter text: ";
    getline(cin, userInput);

    // Call the function to append the input to the file
    appendToFile(userInput);

    // Check and delete the first line if the file has more than 10 lines
    deleteFirstLineIfMoreThanTenLines();

    return 0;
}


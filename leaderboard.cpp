#include <iostream>
#include <fstream>

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

int main() {
    string userInput;

    cout << "Enter text: ";
    getline(cin, userInput);

    // Call the function to append the input to the file
    appendToFile(userInput);

    return 0;
}

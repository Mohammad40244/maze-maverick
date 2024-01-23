#include <iostream>
#include <fstream>
#include <string>

// A bool function that takes a boolean value as a parameter
bool check(bool b) {
    return b;
}

// Function to increment a number in a file
int incrementNumberInFile(const std::string& fileName, bool incrementSecondLine) {
    std::ifstream inFile(fileName.c_str());  // Open the file for reading

    int number1 = 0, number2 = 0;
    
    if (inFile.is_open()) {
        // If the file exists, read the current numbers
        inFile >> number1;
        inFile >> number2;
        inFile.close();
    } else {
        std::cerr << "Error opening file for reading!" << std::endl;
        return 1;  // Return an error code
    }

    // Increment the first number
    number1++;

    // Increment the second number if the boolean is true
    if (incrementSecondLine) {
        number2++;
    }

    std::ofstream outFile(fileName.c_str());  // Open the file for writing

    if (outFile.is_open()) {
        // Write the updated numbers to the file
        outFile << number1 << std::endl;
        outFile << number2 << std::endl;
        outFile.close();
        std::cout << "Numbers written to file: " << number1 << " and " << number2 << std::endl;
    } else {
        std::cerr << "Error opening file for writing!" << std::endl;
        return 1;  // Return an error code
    }

    return 0;
}

int main() {
    std::string fileName;

    int x = 10, y = 7;

    // Use the result of check to determine won or lose
    bool result = check(x > y);

    // Get the file name from the user
    std::cout << "Enter the file name (without extension): ";
    std::cin >> fileName;

    // Append ".txt" extension to the file name
    fileName += ".txt";

    // Call the function to increment the number in the file
    int operationResult = incrementNumberInFile(fileName, result);

    return operationResult;
}


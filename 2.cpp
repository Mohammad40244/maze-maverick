#include <iostream>
#include <fstream>
#include <string>

// Function to increment a number in a file
int incrementNumberInFile(const std::string& fileName) {
    std::ifstream inFile(fileName.c_str());  // Open the file for reading

    int number = 0;
    if (inFile.is_open()) {
        // If the file exists, read the current number
        inFile >> number;
        inFile.close();
    } else {
        std::cerr << "Error opening file for reading!" << std::endl;
        return 1;  // Return an error code
    }

    // Increment the number
    number++;

    std::ofstream outFile(fileName.c_str());  // Open the file for writing

    if (outFile.is_open()) {
        // Write the updated number to the file
        outFile << number;
        outFile.close();
        std::cout << "Number written to file: " << number << std::endl;
    } else {
        std::cerr << "Error opening file for writing!" << std::endl;
        return 1;  // Return an error code
    }

    return 0;
}

int main() {
    std::string fileName;

    // Get the file name from the user
    std::cout << "Enter the file name (without extension): ";
    std::cin >> fileName;

    // Append ".txt" extension to the file name
    fileName += ".txt";

    // Call the function to increment the number in the file
    int result = incrementNumberInFile(fileName);

    return result;
}

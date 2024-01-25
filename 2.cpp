#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>

bool check(bool b) {
    return b;
}

int incrementNumberInFile(const std::string& fileName, bool incrementSecondLine) {
    std::ifstream inFile(fileName.c_str());

    int number1 = 0, number2 = 0, userNumber = 0;

    if (inFile.is_open()) {
        inFile >> number1;
        inFile >> number2;
        inFile >> userNumber;
        inFile.close();
    } else {
        std::cerr << "Error opening file for reading!" << std::endl;
        return 1;
    }

    number2++;

    if (incrementSecondLine) {
        number1++;
    }

    std::ofstream outFile(fileName.c_str());

    if (outFile.is_open()) {
        outFile << number1 << std::endl;
        outFile << number2 << std::endl;

        // Prompt the user to enter a new number and add it to the existing userNumber
        int newNumber;
        std::cout << "Enter a new number after your name: ";
        std::cin >> newNumber;
        userNumber += newNumber;

        outFile << userNumber << std::endl;

        std::time_t currentTime = std::time(0);
        std::tm* now = std::localtime(&currentTime);
        outFile << std::put_time(now, "%Y-%m-%d %H:%M:%S") << std::endl;

        outFile.close();
        std::cout << "Numbers written to file: " << number1 << ", " << number2 << ", and " << userNumber << std::endl;
    } else {
        std::cerr << "Error opening file for writing!" << std::endl;
        return 1;
    }

    return 0;
}

int main() {
    std::string fileName;
    int x = 10, y = 7;
    bool result = check(x < y);

    std::cout << "Enter the file name (without extension): ";
    std::cin >> fileName;
    fileName += ".txt";

    int operationResult = incrementNumberInFile(fileName, result);

    return operationResult;
}


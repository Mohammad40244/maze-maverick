#include <iostream>
#include <fstream>

bool createFile(const std::string& name) {
    std::string filename = name + ".txt";

    std::ifstream fileCheck(filename.c_str());
    if (!fileCheck.good()) {
        std::ofstream file(filename.c_str());
      //  std::cout << "File '" << filename << "' created successfully." << std::endl;
        return true;  // File created successfully
    } else {
       // std::cout << "File '" << filename << "' already exists. Choose a different name." << std::endl;
        return false;  // File already exists
    }
}

int main() {
    std::string name;
    std::cout << "Enter a name: ";
    std::cin >> name;

    if (createFile(name)) {
        // Continue with the rest of your program logic if the file was created successfully
    } else {
        // Handle the case where the file already exists
        // You may want to prompt the user for a different name or take appropriate action
    }

    
}

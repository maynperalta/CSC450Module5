#include <iostream>
#include <fstream> 
#include <string>

int main() {
	std::string cUserInput;
// Ask user for input
	std::cout << "Please type what you'd like to add to the file: ";
	std::getline(std::cin, cUserInput);
// Append user input to the existing file	
	std::ofstream myFile("CSC450_CT5_mod5.txt", std::ios::app);

	if (myFile.is_open()) {
		myFile << '\n' << '\n' << cUserInput << '\n';
		myFile.close();
		
		std::cout << "File successfully appended.\n";
	} else {
		std::cerr << "Error: Could not open file for appending.\n";
		return 1;
	}
// Open file for reading	
	std::ifstream inputFile("CSC450_CT5_mod5.txt");
	if (inputFile.is_open()) {
		std::string cLine;
		
		while (std::getline(inputFile, cLine)) {
			std::cout << cLine << "\n";
		}
		inputFile.close();
	} else {
		std::cerr << "Error: Could not open file for reading.\n";
		return 1;
	}
	myFile.close();
	return 0;
}

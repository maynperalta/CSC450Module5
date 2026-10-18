#include <iostream>
#include <fstream> 
#include <string>
#include <algorithm>

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
	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open file for reading.\n";
		return 1;
	}
	
	std::string fileContents;
	std::string cLine;
// Read and display file while preserving line breaks
	while (std::getline(inputFile, cLine)) {
		std::cout << cLine << '\n';
		fileContents += cLine;
		
		if (!inputFile.eof()) {
			fileContents += '\n';
		}
	}	
	inputFile.close();
// Reverse every character in contents
	std::reverse(fileContents.begin(), fileContents.end());
// Write reversed contents to a new file
	std::ofstream reverseFile("CSC450-mod5-reverse.txt");
	if (!reverseFile.is_open()) {
		std::cerr << "Error: Could not create reversed file.\n";
		return 1;
	}
	
	reverseFile << fileContents;
	reverseFile.close();
	
	std::cout << "\nReversed contents saved to CSC450-mod5-reverse.txt.\n";
	return 0;
}

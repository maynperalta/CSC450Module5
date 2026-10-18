#include <iostream>
#include <fstream> 
#include <string>
#include <algorithm>
#include <iterator>

// Reverses all characters in the source file
// and saves them to a separate output file

bool reverseFile() {
	std::ifstream inputFile("CSC450_CT5_mod5.txt", std::ios::binary);
	
	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open file for reading.\n";
		return false;
	}
// Read the entire file into a string 
	std::string fileContents (
		(std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
// Check for a file-reading error
	if (inputFile.bad()) {
		std::cerr << "Error: Failed while reading the file.\n";
		return false;
	}
	inputFile.close();
// Reverse the entire contents of the file.
	std::reverse(fileContents.begin(), fileContents.end());
// Write the reversed contents to a new file
	std::ofstream reverseFile("CSC450-mod5-reverse.txt", std::ios::binary | std::ios::trunc);
	if (!reverseFile.is_open()) {
		std::cerr << "Error: Could not create reversed file.\n";
		return false;
	}
	reverseFile.write(fileContents.data(), static_cast<std::streamsize>(fileContents.size()));
	
	reverseFile.close();
	
	if (!reverseFile) {
		std::cerr << "Error: Failed to write reversed content.\n";
		return false;
	}
	return true;
}

int main() {
	std::string cUserInput;
// Ask user for input
	std::cout << "Please type what you'd like to add to the file: ";
	
	if (!std::getline(std::cin, cUserInput)) {
		std::cerr << "Error: Could not read user input.\n";
		return 1;
	}
	if (cUserInput.empty()) {
		std::cerr << "Error: Input cannot be empty.\n";
		return 1;
	}
// Append user input to the existing file	
	std::ofstream myFile("CSC450_CT5_mod5.txt", std::ios::app);

	if (!myFile.is_open()) {
		std::cerr << "Error: Could not open file for appending.\n";
		return 1;
	}
	myFile << "\n\n" << cUserInput;
	myFile.close();
	
	if (!myFile) {
		std::cerr << "Error: Failed to write to the source file.\n";
		return 1;
	}
	std::cout << "File successfully appended.\n";
// Reverse the complete source file.
	if (!reverseFile()) {
		return 1;
	}
	std::cout << "Reversed contents saved to CSC450-mod5-reverse.txt.\n";
	return 0;
}

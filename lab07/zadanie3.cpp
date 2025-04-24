#include <iostream>
#include <fstream>
#include <string> 
#include <unordered_map>
#include <algorithm>

std::string INPUT_FILE = "pliczek.txt"; 

bool validate_dna(const char &dna){

	return (dna == 'A' || dna == 'T' || dna == 'C' || dna == 'G');
}

void to_upper(std::string &dna){

	std::transform(dna.begin(), dna.end(), dna.begin(), ::toupper);
}

int run(){

	std::ifstream file(INPUT_FILE);

	if (!file.is_open()){
		std::cerr << "Unable to open file" << std::endl;
		return -1;
	}
	std::string line;
	std::unordered_map<std::string, int> duplicates;
	int count = 0;

	while (std::getline(file, line)){
		to_upper(line);
		bool isvalid = std::all_of(line.begin(), line.end(), validate_dna);

		if (!isvalid){
			std::cerr << "invalid characters found." <<  std::endl;
			continue;
		}
		//celowo nie uzywam tutaj auto 
		std::unordered_map<std::string, int>::iterator dup_it = duplicates.find(line);
		if (dup_it == duplicates.end()){
			duplicates.insert({line, 1});
		}else{
			if (++(dup_it->second) == 2)
				count++;
		}
	}
	return count;
}

int main(int argc, char* argv[]){

	if (argc > 1)
		INPUT_FILE = argv[1];
	int counts = run();

	std::cout << counts << std::endl;
	return 0;
}

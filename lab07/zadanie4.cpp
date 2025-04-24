#include <iostream>
#include <fstream>
#include <string> 
#include <unordered_map>
#include <algorithm>
#include <vector>

/* dla podanego przykladowego inputu z tresci zadania, program bedzie wywalal blad, poniewaz
	zostal w nim uzyty nukleotyd wystepujacy w rna - U, a moj program to weryfikuje i w takiej sytuacji,
	pomija dana linie. Nie mam pewnosci czy napewno o to chodzi w zadaniu, poniewaz 'zignoruj błędne ciągi w pliku'
	rozumiem jako pominiecie ich, natomiast 'nie ignoruj wprowadzonego błędnego motywu' wskazuje, ze program mimo zlego
	motywu, powinien normalnie zadzialac */
	
std::string INPUT_FILE = "pliczek.txt"; 

void input(std::string &motive){

	std::cin >> motive;
}

bool validate_dna(const char &dna){

	return (dna == 'A' || dna == 'T' || dna == 'C' || dna == 'G');
}

void to_upper(std::string &dna){

	std::transform(dna.begin(), dna.end(), dna.begin(), ::toupper);
}

bool find_motif(const std::string &line, const std::string &motif){

	 return line.find(motif) != std::string::npos;
}

std::vector<int> run(){

	std::ifstream file(INPUT_FILE);

	if (!file.is_open()){
		throw std::runtime_error("Unable to open file");
	}
	std::string motif;
	input(motif);
	to_upper(motif);

	std::string line;
	std::vector<int> motif_indexes;
	int line_no = 0;

	while (std::getline(file, line)){
		to_upper(line);
		bool isvalid = std::all_of(line.begin(), line.end(), validate_dna);

		if (!isvalid){
			std::cerr << "invalid characters found at line: " << line_no << std::endl;
			continue;
			}
		if (find_motif(line, motif)){
			motif_indexes.push_back(line_no);
		}
		line_no++;
		}return motif_indexes;
}

void write_output(const std::vector<int> &motifs){

	if (motifs.empty())
		return;

	size_t len = motifs.size();
	for (size_t i=0; i < len; i++){
		std::cout << motifs[i];
		if (i != len -1)
			std::cout << ", ";
	}
}

int main(int argc, char* argv[]){

	if (argc > 1)
		INPUT_FILE = argv[1];
	std::vector<int> indexes = run();

	write_output(indexes);

	return 0;
}


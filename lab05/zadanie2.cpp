#include <cctype>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std; 

string INPUT_FILE("pliczek.txt");

struct dna_t{

	float rest,c,g;
	float gc_cont;
};

bool validate_dna(char dna){

	return (dna == 'A' || dna == 'T' || dna == 'C' || dna == 'G' ||
	dna == 'a' || dna == 't' || dna == 'c' || dna == 'g');
}

void calculate_gc(dna_t* result){

	float gc_sum = result->g+result->c;
	if (gc_sum != 0){
		float gc_cnt = gc_sum / (gc_sum + result->rest) * 100;
		result->gc_cont = round(gc_cnt * 100) / 100;	
	}
}

bool extract_sequence(char current_char){

	if (isdigit(current_char) || current_char == ':' || current_char == ' ')
		return false;
	return true;
}

bool dna_counter(string line, dna_t* result, int line_nr){

	size_t i = 0;
	while(i != line.size()){
		char d = line[i];
		if (!extract_sequence(d)){
			i++;
			continue;
		}
		if (!validate_dna(d)){
			cout << "Wrong letters found in this line! " << line_nr << endl;
			return false;
		}
		switch (d){
			case 'A':
			case 'a':
			case 'T':
			case 't':
				result->rest++;break;
			case 'C':
			case 'c':
				result->c++;break;
			case 'G':
			case 'g':
				result->g++;break;
		}i++;
	}return true;
}

bool run(){

	ifstream file(INPUT_FILE);
	if (file.is_open()){
		string line;
		int line_nr = 1;
		while(getline(file, line)){
			dna_t result = {0, 0, 0, 0.0};
			if (!dna_counter(line, &result, line_nr)){
				line_nr++;
				continue;
			}			
			calculate_gc(&result);
			cout << line_nr << ": " << result.gc_cont << '%' << endl;
			line_nr++;
		}
	}else {
		return false;
	}file.close();
	return true;
}

//robiac zadanie 3 wpadlem na to zeby tutaj to tez dodac
void usage(){
	cout << "---------" << endl;
	cout << "Usage: " << endl;
	cout << "./zadanie2 <input file>" << endl;
	cout << "If no input file is provided, default one is defined as pliczek.txt" << endl;
}

int main(int argc, char* argv[]){

	if (argc > 1){
		INPUT_FILE = argv[1];	
	}
	if (!run())
		usage();
	return 0;
}

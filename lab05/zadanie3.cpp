#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

string INPUT_FILE = "pliczek.txt";
string OUTPUT_FILE = "output.txt";

//tak dodatkowo zeby ladnie pokazywalo jak to ma dzialac
void usage(){
	cout << "----------" << endl;
	cout << "Usage: " << endl;
	cout << "./zadanie3 <input file> <output file>" << endl;
	cout << "If no input or output files are provided, defaults are *in* pliczek.txt *out* output.txt" << endl;
}

bool validate_dna(char dna){

	return (dna == 'A' || dna == 'T' || dna == 'C' || dna == 'G' ||
	dna == 'a' || dna == 't' || dna == 'c' || dna == 'g');
}

void write_to_file(string output){

	ofstream fout(OUTPUT_FILE, ios::app);
	if (fout.is_open())
		fout << output << "\n";
}

void compare_lines(string line1, string line2){

	/*poczatkowo chcialem przechowywac dane z porownan miedzy liniami w tablicy o ich dlugosci, potem pomyslalem o tablicy dynamicznej
	albo vectorahc jednak finalnie 	dotarlem do ostringstream, ktore wydaje mi sie najprostsze i najsensowniejsze w tym wypadku*/
	ostringstream ostring;

	for (size_t i = 0; i < line1.size(); i++){
		if (!validate_dna(line1[i]) || !validate_dna(line2[i])){
			ostring.str("");
			ostring << "invalid dna";
		}else if (toupper(line1[i]) != toupper(line2[i])){
			if (!ostring.str().empty()){
				ostring << ",";
			} ostring << i;
		}
	}if (ostring.str().empty())
		ostring << "sequences are the same";
	write_to_file(ostring.str());
}

bool run(){

	ifstream file(INPUT_FILE);
	if (file.is_open()){
		string line1, line2;
		while (getline(file, line1)) {
			if (getline(file, line2)){
				compare_lines(line1, line2);
			}
		}
	}file.close(); return true;
}

int main(int argc, char* argv[]){

	if (argc > 2){
		INPUT_FILE = argv[1];
		OUTPUT_FILE = argv[2];
	}else if (argc == 2)
		INPUT_FILE = argv[1];
	if (!run())
		usage();

	return 0;
}

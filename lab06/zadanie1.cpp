#include <cctype>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

string INPUT_FILE = "pliczek.txt";

struct dna{
	size_t l;
	char* seq;
};

bool validate_dna(const char dna){

	return (dna == 'A' || dna == 'T' || dna == 'C' || dna == 'G' ||
	dna == 'a' || dna == 't' || dna == 'c' || dna == 'g');
}

/*int kayak(char* dna, size_t len){

	char* left = dna;
	char* right = dna + len -1;
	while (left < right){
		if (!validate_dna(*left) || !validate_dna(*right))
			return 3;				
		if (tolower(*left) != tolower(*right))
			return 2;
		left++;right--;
	}
	return 1;
}
*/

int kayak(const string &dnastr, const size_t len) {

	size_t left = 0;
	size_t right = len - 1;
        while(left < right) {
        if(!validate_dna(dnastr[left]) || !validate_dna(dnastr[right]))
            return 3;
        if(tolower(dnastr[left]) != tolower(dnastr[right]))
            return 2;
        left++;
        right--;
    }
    return 1;
}
void run(const char* seq, const size_t len){

	string s(seq, len);
	int result = kayak(s, len);
		switch(result){
			case 3:
				cout << "INVALID" << endl;break;
			case 2:
				cout << "NO" << endl;break;
			case 1:
				cout << "YES" << endl;break;
	}
}

void read(){

	ifstream file(INPUT_FILE);
	size_t seq_no =0;
	if (!file.is_open()){
		cerr << "Unable to open file" << endl;
		return;
	}
	file >> seq_no;

	dna* sequences = new dna[seq_no];

	for (size_t i = 0; i < seq_no; i++){
		file >> sequences[i].l;
		sequences[i].seq = new char[sequences[i].l + 1];
		file >> sequences[i].seq;
		run(sequences[i].seq, sequences[i].l);

		delete [] sequences[i].seq;
	}
	file.close();
	delete [] sequences;
}

int main(int argc, char* argv[]){

	if (argc > 1)
		INPUT_FILE = argv[1];
	read();
	return 0;
}

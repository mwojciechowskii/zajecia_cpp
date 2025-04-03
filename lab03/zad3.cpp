#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void get_input(char* dna){

	cout << "Enter your sequence (q to quit):" << endl;
	cin >> dna;

	transform(dna, dna + strlen(dna), dna, ::toupper);
}

bool check_input_letters(char* dna){

	return (*dna == 'A' || *dna == 'T' || *dna == 'C' || *dna == 'G');
}

//wolalem rozwiazanie rekurencyjne :c
int count_substring(char* dna, char* substring){

	int counts = 0;
	while (*dna){
		if (!check_input_letters(dna) || !check_input_letters(substring)){
			cout << "invalid input, try again" << endl;
			return -1;
		}
		char* d = dna;
        char* s = substring;
        while (*s && *d && *s == *d) {
                s++;
                d++;
            }if (*s == '\0') {
                counts++;
            }dna++;
		}return counts; 
}

bool check_valid_input(char* dna){
	get_input(dna);
	if (dna[0] == 'Q')
		return false;
	return true;
}

int main(){

	char dna[1024];
	char substring[512];

	while(1){
		if (!check_valid_input(dna) || !check_valid_input(substring)){
			break;
		}	
		int result = count_substring(dna, substring);
		if (result == -1){
			continue;
		}else {
		cout << "your dna: " << dna << " your substring: " << substring << endl;
		cout << "appearances: " << result << endl;
		}
	}
	return 0;
}

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

//chwilke zajal mi pomysl rozwiazania rekurencyjnego
bool substring_check(char* dna, char* substring){

	if (*substring =='\0')
		return true;
	if (*dna == '\0')
		return false;
	if (*dna == *substring)
		return substring_check(dna + 1, substring + 1);
	return false;
}

int count_substring(char* dna, char* substring, int* counts){

	*counts = 0;
	while (*dna){
		if (!check_input_letters(dna) || !check_input_letters(substring)){
			cout << "invalid input, try again" << endl;
			return -1;
		}
		if (substring_check(dna, substring)) {
			(*counts)++;
		} dna++;
	}return *counts;	
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

	int counts = 0;

	while(1){
		if (!check_valid_input(dna) || !check_valid_input(substring)){
			break;
		}	
		if (count_substring(dna, substring, &counts) == -1){
			continue;
		}else {
		cout << "your dna: " << dna << "your substring: " << substring << endl;
		cout << "appearances: " << counts << endl;
		}
	}
	return 0;
}

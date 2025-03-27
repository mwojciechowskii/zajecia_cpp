#include <cstddef>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void get_input(char* dna){

	cout << "Enter your sequence (q to quit):" << endl;
	cin >> dna;

	transform(dna, dna + strlen(dna), dna, ::toupper);
}

bool check_input(char* dna){

	return (*dna == 'A' || *dna == 'T' || *dna == 'C' || *dna == 'G');
}

int transcript(char* dna){

	if (strlen(dna) != 0){
		while (*dna){
			if (check_input(dna)){
				switch (*dna){
					case 'A': 
						*dna = 'U';break;
					case 'T':
						*dna = 'A';break;
					case 'C':
						*dna = 'G';break;
					case 'G':
						*dna = 'C';break;
				}
			} else{
				cout << "Invalid input, try again" << endl;
				return -1;
				break;
			}dna++;
		}	
	}
	return 0;
}

int main(){

	char dna[1024];

	while (1){
		get_input(dna);	
		if (dna[0] == 'Q'){
			break;
		}
		cout << "Your sequence: " << dna << endl;
		if (transcript(dna) != -1){
			cout << "Your transcript:" << dna << endl;
		}	
	}
	return 0;
}

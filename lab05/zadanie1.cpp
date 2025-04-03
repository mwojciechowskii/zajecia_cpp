#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

void get_input(char* dna){

	cin >> dna;
	transform(dna, dna + strlen(dna), dna, ::toupper);
}

bool check_input(char* dna){

	return (*dna == 'A' || *dna == 'T' || *dna == 'C' || *dna == 'G');
}

struct dna_t{
	
	int a, t, c, g;
};

dna_t count_nucleotides(char* dna){

	dna_t cnt_dna {0, 0, 0, 0};

	while(*dna){
		if (!check_input(dna)){
			break;
		} else {
			switch (*dna){
				case 'A': cnt_dna.a++;break;
				case 'T': cnt_dna.t++;break;
				case 'C': cnt_dna.c++;break;
				case 'G': cnt_dna.g++; break;
			}
		}dna++;	
	}	
	return cnt_dna;
}

int main(){

	char dna[1024];
	
	while(1){
		get_input(dna);
		if (dna[0] == 'Q')
			break;
		dna_t lala = count_nucleotides(dna);
		cout << "A: " << lala.a << " T: " << lala.t << " C: " << lala.c << " G: " << lala.g << endl;
	}
	return 0;
}

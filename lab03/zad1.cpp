#include <cstddef>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

void get_input(char* dna){

	cout << "Enter your sequence (q to quit):" << endl;
	cin >> dna;

	transform(dna, dna + strlen(dna), dna, ::toupper);
}

bool check_input(char* dna){

	return (*dna == 'A' || *dna == 'T' || *dna == 'C' || *dna == 'G');
}

float count_nucleotides(char* dna, int* A, int* T, int* C, int* G){

	*A = *T = *C = *G = 0;

	size_t len = strlen(dna);

	if (len != 0){		
		while (*dna){
			if (check_input(dna)){
				switch (*dna) {
					case 'A': (*A)++; break;
					case 'T': (*T)++; break;
					case 'C': (*C)++; break;
					case 'G': (*G)++; break;
				} 
			}
			else {
				cout << "Invalid input" << endl;
				return -1;
				break;
			}++dna;
		}
		float gc_cnt = *C + *G;
		return (gc_cnt/len) * 100;
	} else { 
		return -1;
	}
}

int main(){

	char dna[1024];
	while (1){
		get_input(dna);
		if (dna[0] == 'Q'){
			break;
		}

		int A, T, C, G = 0;
		float cg_percentage = count_nucleotides(dna, &A, &T, &C, &G);
		if (cg_percentage == -1) {
            break;
        }
		cout << "A: " << A << endl;
		cout << "T: " << T << endl;
		cout << "C: " << C << endl;
		cout << "G: " << G << endl;
		cout << "CG percentage: " << cg_percentage << "%" << endl;
	} 

	return 0;
}

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void get_input(char* dna){
	//cout << "Enter your sequence (q to quit):" << endl;
	cin >> dna;
	transform(dna, dna + strlen(dna), dna, ::toupper);
}

bool check_input_letters(char* dna){

	return (*dna == 'A' || *dna == 'T' || *dna == 'C' || *dna == 'G');
}

bool check_transition(char* dna, char* dna2){
	return ((*dna == 'A' && *dna2 == 'G') || (*dna == 'G' && *dna2 == 'A') || (*dna == 'C' && *dna2 == 'T') || (*dna == 'T' && *dna2 == 'C'));
}

float tition_to_tversion(char* dna, char* dna2, float* transitions, float* transversions){

	*transversions = 0, *transitions = 0;

	while (*dna && *dna2){
		if (check_input_letters(dna) && check_input_letters(dna2)){
			if (*dna != *dna2){
				if (check_transition(dna, dna2))
					(*transitions)++;
				else
					(*transversions)++;
			}dna++; dna2++;
		} else {
			cout << "invalid input" << endl;
		}if (*transversions == 0)
			return -1;
	}
	return 0;
}

float calc_ratio(float* transitions, float* transversions, float* ratio){

	*ratio = *transitions/ *transversions;
	return *ratio;
}

bool check_valid_input(char* dna){
	get_input(dna);
	if (dna[0] == 'Q')
		return false;
	return true;
}
	
int main(){

	char dna[1024];
	char dna2[1024];
	float transitions = 0, transversions = 0;
	float ratio;

	while(1){
		if (!check_valid_input(dna) || !check_valid_input(dna2))
			break;
		if (tition_to_tversion(dna, dna2, &transitions, &transversions) == -1){ 
			cout << "no transversions found, do not divide by 0, try again" << endl;
			continue;
		}else {
			calc_ratio(&transitions, &transversions, &ratio);
			cout << ratio << endl;
		}
	}
	return 0;
}

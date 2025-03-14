#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string get_input() {
	string dna;
	cout << "Enter your sequence:" << endl;
	cin >> dna;
	transform(dna.begin(), dna.end(), dna.begin(), ::toupper);

	return dna;
}

char nt (char N){
	switch (N) {
		default:
			return 'N';	break;
		case 'A':
			return 'T';	break;
		case 'T':
			return 'A';	break;
		case 'C':
			return 'G'; break;
		case 'G':
			return 'C';	break;
	}
}

int main(){

	while (1){
		string dna = get_input();
		if (dna == "Q"){	
			break;
		}
		string seq = "";
		bool valid = true;

		for (char c : dna){
			char conv_check = nt(c);
			if (conv_check == 'N'){
				cout << "Invlaid input, try again" << endl;
				valid = false;
				break;
			}
			seq += conv_check;
		}	
		if (!valid){
				continue;
			}
		reverse(seq.begin(), seq.end());
		cout << "Your input DNA: " << dna	<< endl;
		cout << "Your complementary sequence backwards: " << seq << endl;
	}
	return 0;
}



#include <iostream>
#include <string>
#include <algorithm>
#include <array>

using namespace std;

array<int, 4> counter;
bool valid;

string get_input() {
    string dna;
    cout << "Enter your sequence:" << endl;
    cin >> dna;
    transform(dna.begin(), dna.end(), dna.begin(), ::toupper);

    return dna;
}

//dla odmiany iteracja nie jest wewnatrz funkcji main
void count_nt(string dna) {
    counter = {0};
    valid = true;

    for (char nt : dna) {
        switch (nt) {
            case 'A':
                counter[0]++; break;
            case 'T':
                counter[1]++; break;
            case 'C':
                counter[2]++; break;
            case 'G':
                counter[3]++; break;
            default:
                valid = false;
                break;
        }
        if (!valid) {
            break;
        }
    }
}

int main() {
	cout << "Enter q to leave" << endl;
    while (1) {
        string dna = get_input();
		if (dna == "Q"){
			break;
		}
		count_nt(dna);
		if (valid) {
            cout << counter[0] << "-" << counter[1] << "-" << counter[2] << "-" << counter[3] << endl;
        } else {
            cout << "You entered invalid letter, try again" << endl;
        }
    }
}

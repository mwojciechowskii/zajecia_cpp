#include <iostream>
#include <string>



int main(){
	
	int counter = 0;
	std::string dna;
	std::cin >> dna;

	for (int i =0; i < dna.length(); i++){
		if (dna[i] == 'A') {
			counter++;
		}
	}
	std::cout << counter << std::endl;

	return 0;

}



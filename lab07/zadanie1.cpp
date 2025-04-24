#include <iostream>
#include <iterator>
#include <string>

struct dna{
	std::string dna;
	int k;
};

void input(dna* input_dna){

	std::cin >> input_dna->dna;
	std::cin >> input_dna->k; 
}

void run(){
	
	dna input_dna;
	input(&input_dna);

	const char* first = input_dna.dna.c_str();
	const char* last = first + input_dna.dna.size() - input_dna.k + 1;

	while (last > first){
		std::cout.write(first, input_dna.k);
		std::cout << std::endl;
		first++;
	}	
}

int main(){
	
	run();
	return 0;
}

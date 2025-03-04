#include <cctype>
#include <iostream>

void complementary(char N){
	switch (N) {
		default:
			std::cout << "Blad, wpisano niepoprawny symbol!"<< std::endl;
			break;
		case 'Q':
			break;
		case 'A':
			std::cout << N << " jest komplementarne z T"<< std::endl;
			break;
		case 'T':
			std::cout << N << " jest komplementarne z A"<< std::endl;
			break;
		case 'C':
			std::cout << N << " jest komplementarne z G"<< std::endl;
			break;
		case 'G':
			std::cout << N << " jest komplementarne z C"<< std::endl;
			break;
	}
}

int main(){
	char N;
	std::cout << "If you wanna leave just write Q" << std::endl;
	while (1){
		std::cout << "enter your nucleotide: " << std::endl;
		std::cin >> N;
		N = toupper(N);
		complementary(N);
		if (N == 'Q'){
			break;
		}
	}
	return 0;
}

#include <iostream>

float bmi(float weight, float height){
	return weight / (height * height);
}

void decide(float b) {
	if (b < 18.5){
	std::cout << "Masz niedowage." << std::endl;
	} else if (b < 25) {
		std::cout << "Masz prawidlowa wage" << std::endl;
	} else if (b < 30) {
		std::cout << "Masz nadwage" << std::endl;
	} else{
		std::cout << "Masz otylosc" << std::endl;
	}

}


int main() {
	float kg, m;

	std::cout << "Podaj kg a potem metry" << std::endl;
	std::cin >> kg;
	std::cin >> m;
	float calculated_bmi = bmi(kg, m);
	
	decide(calculated_bmi);
	
	return 0;

}

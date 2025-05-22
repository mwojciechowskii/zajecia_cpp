#include <iostream>

//podmiana int na size_t chyba nie bedzie bledem w tym zadaniu
char* find_longest_homopolymer(char* dna, size_t length, size_t* out_len){

	if (*dna == '\0' || length == 0){
		*out_len = 0;
		return nullptr;
	}
	char* longest = dna;
	*out_len = 1;

	char* current = dna;
	size_t current_len = 1;

	for (size_t i = 1; i < length; i++) {
		if (dna[i] == dna[i-1]) {
			current_len++;
		} else {
			if (current_len > *out_len) {
				*out_len = current_len;
				longest = current;
			}
			current = dna + i;
			current_len = 1;
		}
	}
	if (current_len > *out_len) {
		*out_len = current_len;
		longest = current - (current_len - 1);
	}
	return longest;
}

int main(int argc, char* argv []){
	char dna [] = "ATTCG";
	size_t out_len = 0;
	size_t length = sizeof(dna) / sizeof(dna[0]) - 1;

	char* dna_ptr = find_longest_homopolymer(dna, length, &out_len);
	std::cout << "Character: " << *dna_ptr << std::endl;
	std::cout << "Length: " << out_len << std::endl;
	std::cout << "Index" << (dna_ptr - dna) << std::endl;

	return 0;
}

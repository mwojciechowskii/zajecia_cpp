#include <iostream>
#include <ostream>
#include <string>
#include <algorithm>
#include <unordered_map>

const std::unordered_map<std::string, char> codonMap = {
        // Alanine (A)
        {"GCU", 'A'}, {"GCC", 'A'}, {"GCA", 'A'}, {"GCG", 'A'},
        
        // Arginine (R)
        {"CGU", 'R'}, {"CGC", 'R'}, {"CGA", 'R'}, {"CGG", 'R'}, 
        {"AGA", 'R'}, {"AGG", 'R'},
        
        // Asparagine (N)
        {"AAU", 'N'}, {"AAC", 'N'},
        
        // Aspartic acid (D)
        {"GAU", 'D'}, {"GAC", 'D'},
        
        // Cysteine (C)
        {"UGU", 'C'}, {"UGC", 'C'},
        
        // Glutamic acid (E)
        {"GAA", 'E'}, {"GAG", 'E'},
        
        // Glutamine (Q)
        {"CAA", 'Q'}, {"CAG", 'Q'},
        
        // Glycine (G)
        {"GGU", 'G'}, {"GGC", 'G'}, {"GGA", 'G'}, {"GGG", 'G'},
        
        // Histidine (H)
        {"CAU", 'H'}, {"CAC", 'H'},
        
        // Isoleucine (I)
        {"AUU", 'I'}, {"AUC", 'I'}, {"AUA", 'I'},
        
        // Leucine (L)
        {"UUA", 'L'}, {"UUG", 'L'}, {"CUU", 'L'}, 
        {"CUC", 'L'}, {"CUA", 'L'}, {"CUG", 'L'},
        
        // Lysine (K)
        {"AAA", 'K'}, {"AAG", 'K'},
        
        // Methionine (M) - Start codon
        {"AUG", 'M'},
        
        // Phenylalanine (F)
        {"UUU", 'F'}, {"UUC", 'F'},
        
        // Proline (P)
        {"CCU", 'P'}, {"CCC", 'P'}, {"CCA", 'P'}, {"CCG", 'P'},
        
        // Serine (S)
        {"UCU", 'S'}, {"UCC", 'S'}, {"UCA", 'S'}, {"UCG", 'S'},
        {"AGU", 'S'}, {"AGC", 'S'},
        
        // Threonine (T)
        {"ACU", 'T'}, {"ACC", 'T'}, {"ACA", 'T'}, {"ACG", 'T'},
        
        // Tryptophan (W)
        {"UGG", 'W'},
        
        // Tyrosine (Y)
        {"UAU", 'Y'}, {"UAC", 'Y'},
        
        // Valine (V)
        {"GUU", 'V'}, {"GUC", 'V'}, {"GUA", 'V'}, {"GUG", 'V'},
        
        // Stop codons (|)
        {"UAA", '|'}, {"UAG", '|'}, {"UGA", '|'}
    };

bool validate_dna(const char rna){

	return (rna == 'A' || rna == 'U' || rna == 'C' || rna == 'G' ||
	rna == 'a' || rna == 'u' || rna == 'c' || rna == 'g');
}

void to_upper(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}
void input(std::string &input_rna){
	std::cin >> input_rna;
	to_upper(input_rna);
}

std::string run(){

	//translacja jest stopowana gdy natrafia na kodon STOP 
	std::string rna, aminoacids;
	input(rna);

	for (size_t i = 0; i +2 < rna.size(); i+=3){

		std::string codon = rna.substr(i, 3);
		for (char c:codon){
			if (!validate_dna(c)){
				throw std::runtime_error("Invalid character found");
			}
		}
		if (!codonMap.count(codon)){
			std::cerr << "invalid codon" << std::endl;
			break;
		}
		if (codonMap.count(codon)){
			if (codonMap.at(codon) == '|'){
				aminoacids.push_back(codonMap.at(codon));
				break;
			}else{
				aminoacids.push_back(codonMap.at(codon));
			}
		}	
	} return aminoacids;
}

int main(){
	
	std::string aminoacids = run();

	std::cout << aminoacids << std::endl;
	return 0;
}

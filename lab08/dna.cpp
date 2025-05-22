#include "dna.hpp"
#include <cstddef>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

Dna::Dna(const std::string &seq) : sequence(seq), counts {}{
	upper(sequence);
	if (!verify(sequence)){
		std::cerr << "Wrong DNA input " << sequence << std::endl;
		return;
	}
};

std::string Dna::file_read(const std::string &file, bool validfile){
	std::string seq;
    if (validfile) {
        std::ifstream op_file(file);
        if (!op_file.is_open()) {
            std::cerr << "Error opening file " << file << std::endl;
            return "";
        }
        std::string line;
        while (std::getline(op_file, line)) {
            seq += line;
        }
    }
    return seq;
}

//chyba o to chodzilo w nieduplikowaniu kodu
Dna::Dna(const std::string &file, bool validfile) : Dna(file_read(file, validfile)) {}

bool Dna::verify(const std::string &seq){
	counts = {0,0,0,0};
	for (char c : seq) {
		if (c == 'A' || c == 'T' || c == 'C' || c == 'G') {
			switch (c){
				case 'A': counts.a +=1; break;
				case 'T': counts.t +=1; break;
				case 'C': counts.c +=1; break;
				case 'G': counts.g +=1; break;
			}
		}else
		return false;
	}
	return true;	
}

void Dna::upper(std::string &seq) {
    std::transform(seq.begin(), seq.end(), seq.begin(), ::toupper);
}

float Dna::gc() const{
	int total = counts.a + counts.t + counts.g + counts.c;
	if (total == 0)
		return 0.0;
	return static_cast<float>(counts.c + counts.g) * 100/total;
}

std::string Dna::transcribe() const{
	std::string rna;
	for (char c : sequence){
		switch (c){
			case 'A': rna += 'U';break;
			case 'T': rna += 'A';break;
			case 'C': rna += 'G';break;
			case 'G': rna += 'C';break;
		}
	}
	return rna;
}

std::string Dna::reverse_complement() const{
	std::string rev_comp_dna;
	for (char c : sequence){
		switch (c){
			case 'A': rev_comp_dna.push_back('T');break;
			case 'T': rev_comp_dna.push_back('A');break;
			case 'C': rev_comp_dna.push_back('G');break;
			case 'G': rev_comp_dna.push_back('C');break;
		}
	}
	std::reverse(rev_comp_dna.begin(), rev_comp_dna.end());
	return rev_comp_dna;
}

int Dna::distance(const Dna &sequence_next) const{
	const std::string &seq1 = sequence;
	const std::string &seq2 = sequence_next.sequence;
	if (seq1.size() != seq2.size()){
		std::cerr << "Sequences are not the same length!" << std::endl;
		return -1;
	}
	int distance = 0;
	for (std::size_t i =0; i < seq1.size(); i++){
		if (seq1[i] != seq2[i]){
			distance++;
		}
	}
	return distance;
}

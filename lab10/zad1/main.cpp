#include <iostream>
#include <sstream>
#include <vector>
#include <string>

struct Dna{
	int a,t,g,c;
};
class MiniDna{
	public:
		MiniDna(const std::string &sequence) : sequence(sequence) {};
		std::string sequence;
		std::string::const_iterator begin() const { return sequence.begin(); }
		std::string::const_iterator end() const { return sequence.end(); }
};

template <typename T>
std::string cnt_nucl(const T& seq){
	Dna count{0,0,0,0};
	for (char c : seq){
		switch (c){
			case 'A': count.a++;break;
			case 'T': count.t++;break;
			case 'G': count.g++;break;
			case 'C': count.c++;break;
		}
	}
	std::ostringstream outstring;
	outstring << "A: " << count.a << " T: " << count.t << " C: " << count.c << " G: " << count.g;
	return outstring.str();
}

int main() {
    std::string dna1 = "AGCTGGGCCCAA";
    std::vector<char> dna2 = {'A', 'G', 'C', 'U', 'G', 'G', 'C'};
    MiniDna dna3("GGGCGCGTTA");

    std::cout << "GC-content std::string: " << cnt_nucl(dna1) << std::endl;
    std::cout << "GC-content std::vector: " << cnt_nucl(dna2) << std::endl;
    std::cout << "GC-content MiniDna:     " << cnt_nucl(dna3) << std::endl;

    return 0;
}

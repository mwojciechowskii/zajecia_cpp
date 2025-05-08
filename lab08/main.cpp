#include <iostream>
#include <dna.hpp>

/*zaprezentowanie mozliwosci tej klasy wydrukowal mi copilot, wlacznie ze stworzeniem makefile,
bo mi sie nie chcialo recznie tego pisac */
std::string dnaFile = "dna.txt";

int main(int argc, char* argv[]){
	
	if (argc > 1)
		dnaFile = argv[1];

	Dna dna1("ATCGATCG");
    std::cout << "dna1 constructed from string \"ATCGATCG\":" << std::endl;
    std::cout << "  GC content: " << dna1.gc() << "%" << std::endl;
    std::cout << "  Transcribed RNA: " << dna1.transcribe() << std::endl;
    std::cout << "  Reverse complement: " << dna1.reverse_complement() << std::endl;

    Dna dna2("ATCGATCA");
    std::cout << "\ndna2 constructed from const char* \"ATCGATCA\":" << std::endl;
    std::cout << "  GC content: " << dna2.gc() << "%" << std::endl;
    std::cout << "  Transcribed RNA: " << dna2.transcribe() << std::endl;
    std::cout << "  Reverse complement: " << dna2.reverse_complement() << std::endl;

    std::cout << "\nHamming distance between dna1 and dna2: " << dna1.distance(dna2) << std::endl;

    Dna dna3(dnaFile, true);
    std::cout << "\ndna3 constructed from file \"" << dnaFile << "\":" << std::endl;
    std::cout << "  GC content: " << dna3.gc() << "%" << std::endl;
    std::cout << "  Transcribed RNA: " << dna3.transcribe() << std::endl;
    std::cout << "  Reverse complement: " << dna3.reverse_complement() << std::endl;

    std::cout << "\nHamming distance between dna3 and dna1: " << dna3.distance(dna1) << std::endl;

}

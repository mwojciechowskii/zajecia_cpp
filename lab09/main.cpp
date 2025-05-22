#include <iostream>
#include <vector>
#include <thread>
#include <fstream>
#include <string>

#define THREADS 8
std::string filename = "long_dna.txt";

void count_nt(const std::string &dna, size_t start_idx, size_t end_idx, 
			  std::array<unsigned long int, 4> &local_counts) {

	for (size_t i = start_idx; i < end_idx && i < dna.size(); ++i) {
		char c = dna[i];
		switch (c) {
			case 'A': local_counts[0]++; break;
			case 'C': local_counts[1]++; break;
			case 'G': local_counts[2]++; break;
			case 'T': local_counts[3]++; break;
		}
	}
}

void usage(){
	std::cout << "Usage: ./main <no of threads> <FILE>" << std::endl;
	std::cout << "Default: 8 threads, long_dna.txt" << std::endl;
}

int main(int argc, char* argv[]) {
	int thread_count = THREADS;

	if (argc > 1) {
		thread_count = std::stoi(argv[1]);
	}
	if (argc > 2) {
		filename = argv[2];
	}

	std::ifstream FILE(filename);
	if (!FILE) {
		std::cerr << "Unable to open a file" << std::endl;
		usage();
		return 1;
	}
	std::string dna;
	std::getline(FILE, dna);
	FILE.close();

	std::vector<std::array<unsigned long int, 4>> thread_results(thread_count, {0,0,0,0});
	std::vector<std::thread> threads;

	size_t dna_size = dna.size();
	int CHUNK_SIZE = dna_size / thread_count + 1;

	for (int i = 0; i < thread_count; ++i) {
		size_t start_idx = i * CHUNK_SIZE;
		size_t end_idx = (i + 1) * CHUNK_SIZE;

		threads.emplace_back(count_nt, std::ref(dna), start_idx, end_idx, 
					   std::ref(thread_results[i]));
	}    
	for (auto &thread : threads) {
		thread.join();
	}

	std::array<unsigned long int, 4> final_counts = {0, 0, 0, 0};
    for (const std::array<unsigned long int, 4> &counts : thread_results) {
        final_counts[0] += counts[0];  
        final_counts[1] += counts[1];  
        final_counts[2] += counts[2];  
        final_counts[3] += counts[3];  
    }
    
    std::cout << "A: " << final_counts[0] << std::endl;
    std::cout << "C: " << final_counts[1] << std::endl;
    std::cout << "G: " << final_counts[2] << std::endl;
    std::cout << "T: " << final_counts[3] << std::endl;

	return 0;
}


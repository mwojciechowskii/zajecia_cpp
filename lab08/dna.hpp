#pragma once
#include <string>

class Dna{
	private:
		std::string sequence;
		bool verify(const std::string &sequence);
		void upper(std::string &seq);
		struct nucleotides{
		int a,t,c,g;
	} counts;
		static std::string file_read(const std::string &file, bool validfile);
			

	public:
		Dna(const std::string &sequence);
		Dna(const std::string &file, bool validfile);
		Dna(const char* sequence) : Dna(std::string(sequence)) {};
		float gc() const;
		std::string reverse_complement() const;
		std::string transcribe() const;
		int distance(const Dna &sequence_next) const;
};

#include <iostream>
#include <cstring>

/*problemem bylo niezwalnianie zaalokowanej pamieci przez program, 
 * na koncu funkcji dodalem usuniecie nieuzywanej juz, a zaalokowanej
 * pamieci. wyglada na to ze zaalokowano odpowiednia ilosc pamieci, poniewaz
 * string na ktorym jest wykonywana funkcja ma dlugosc 10, a alokuje sie +1 do 10.
 * Resztka zuzytej pamieci, ktora sama sie czysci, to pozostale operacje wykonane 
 * w kodzie. 11 Bajtow na iteracje * 1000000 daje zaalokowana liczbe + pozostale operacje 
 * HEAP SUMMARY:
==28686==     in use at exit: 0 bytes in 0 blocks
==28686==   total heap usage: 1,000,002 allocs, 1,000,002 frees, 11,073,728 bytes allocated
==28686==
==28686== All heap blocks were freed -- no leaks are possible
==28686==
==28686== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

/*
 * This function creates a dynamic copy of the input DNA string,
 * removes all occurrences of the substring "ATCG", and computes
 * the GC content on the modified string.
 */
double gc_content_without_atcg(const char *dna)
{
	size_t length = std::strlen(dna);
	char *copy = new char[length + 1];
	std::strcpy(copy, dna);

	size_t write_index = 0;
	for (size_t i = 0; i < length;)
	{
		if (i + 3 < length &&
			copy[i] == 'A' && copy[i + 1] == 'T' &&
			copy[i + 2] == 'C' && copy[i + 3] == 'G')
		{
			i += 4;
		}
		else
		{
			copy[write_index++] = copy[i++];
		}
	}
	copy[write_index] = '\0';

	size_t gc_count = 0;
	for (size_t i = 0; i < write_index - 1; i++)
	{
		if (copy[i] == 'G' || copy[i] == 'C')
		{
			gc_count++;
		}
	}

	double gc_content = write_index > 0 ? (double)(gc_count) / write_index : 0.0;

	delete[] copy;
	return gc_content;
}

#define ITERATIONS 1000000

int main()
{
	// This simulate processing large set of DNA sequences
	for (int i = 0; i < ITERATIONS; i++)
	{
		const char *dna = "CATCGGATTC";
		double gc = gc_content_without_atcg(dna);
		std::cout << "GC content without ATCG: " << gc << std::endl;
	}

	return 0;
}

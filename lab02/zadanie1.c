#include <stdio.h>

int main(){

	char dna[1000];
	int counter = 0;
	scanf("%s", dna);
	
	for (int i =0; dna[i] != '\0'; i++) {
		if (dna[i] == 'T'){
			++counter;
		}	
	}	
	printf("%d\r\n", counter);
	return 0;

}

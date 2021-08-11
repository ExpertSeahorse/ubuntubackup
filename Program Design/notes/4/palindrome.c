#include <stdio.h>
#define N 26

int main(){	
	char ch;
	int letter_cts[N] = {0};
	int i, count=0;
	printf("Enter a word: ");
	while((ch = getchar()) != '\n')
		letter_cts[ch-'a']++;
	
	printf("Enter the second word: ");
	while((ch = getchar()) != '\n')
		letter_cts[ch-'a']--;

	for (i=0; i<N; i++){
		if (letter_cts[i] == 0)
			count++;
	}

	if (count == N)
		printf("The words are anagrams.");
	else
		printf("The words are not anagrams.");

	printf("\n");
	return 0;
}

#include <stdio.h>

int main(){
	char words[50];
	int lines;
	printf("Print 100 V2\n");
	printf("Enter A sentence or words:");
	fgets(words, 50, stdin);
	for(lines=1; lines<=100; lines++)
	printf("%d. %s", lines, words);
}

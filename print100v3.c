#include <stdio.h>

int main(){
	char words[50];
	int lines;
	int times;
	printf("Print 100 V3\n");
	printf("Enter A sentence or words:");
	fgets(words, 50, stdin);
	printf("Enter Times you want to print:");
	scanf("%d", &times);
	for(lines=1; lines<=times; lines++){
	printf("%d. %s", lines, words);}
	return 0;
}

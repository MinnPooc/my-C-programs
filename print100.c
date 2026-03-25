#include <stdio.h>

int main(){
	char words[50];
	int lines = 1;
	printf("100x Printer.\n");
	printf("Enter a sentence or words:\n"); 
	fgets(words, 50, stdin);
	while(lines <=100){
	printf("%d.%s", lines, words);
	lines++;
	}
	return 0;
}

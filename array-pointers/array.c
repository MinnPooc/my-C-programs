#include <stdio.h>

int main(){
	int results[4];
	int w, y, z, i, j;
	int x[2][4];
	printf("Enter First Array: ");
	for(i=0; i < 4; i++){
	scanf("%d", &x[0][i]);
	}
	printf("\n");
	printf("Enter Second Array: ");
	for(j=0; j < 4; j++){
	scanf("%d", &x[1][j]);
	}
	for(y=0; y < 4; y++){
	printf("%d of first array:%d \n", y+1, x[0][y]);
	}
        for(z=0; z < 4; z++){
        printf("%d of second array:%d \n", z+1, x[1][z]);
        }
	printf("Sum of 2 arrays: ");
	for(w=0; w < 4; w++){
	results[w] = x[0][w] + x[1][w];
	printf("%d ", results[w]);
	}
	printf("\n");
}

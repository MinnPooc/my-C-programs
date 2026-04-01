#include <stdio.h>
int main(){
	int nums[100];
	int i, j, temp;
	int count=0;

	while((scanf("%d", &nums[0]))!=EOF){
	count++;}
	for(i=0;i<count-1; i++ ){
		for(j=i+1;j<count;j++)
		if (nums[i] <= nums[j]){
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;}
	};
	for(i=0;i<count;i++){
	printf("%d", nums[i]);
	}
	printf("\n");
	return 0;
}

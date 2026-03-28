#include <stdio.h>

int main(){
	int c;
	int nc = 0;
	int nl = 0;
	while((c = getchar())!= EOF){
	nc++;
	if(c == '\n'){
	nl++;}
	}
	printf("chars:%d\n",nc);
	printf("lines:%d\n",nl);
	return 0;
}

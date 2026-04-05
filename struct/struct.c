#include <stdio.h>

struct Person{
	int age;
	char name[50];};

int main(){
	struct Person person1;
	printf("Enter Person age: ");
	scanf("%d", &person1.age);
	int c = getchar();
	printf("Enter Person name: ");
	fgets(person1.name, 50, stdin);
	printf("Person name is: %s\n", person1.name);
	printf("Person age is : %d\n", person1.age);

}

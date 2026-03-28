#include <stdio.h>

#define CELC 'c'
#define FER 'f'

int main(){

        float ferh, celcius, upper, lower, step;
        char mode;
        printf("What do you want to convert?\n");
        printf(" c for Ferh to Celcius\n");
        printf(" f for Celcius to Ferh\n");
        printf("Enter Mode:");
        scanf("%c", &mode);
        if (mode == CELC)
        printf("Mode is ferh to Celc\n");
        else printf("Mode is Celc to Ferh\n");
        return 0;
}

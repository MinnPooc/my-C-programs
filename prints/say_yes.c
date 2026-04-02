#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Convert string to lowercase
void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char input[10];

    while (1) {  // Infinite loop until "Yes" is entered
        printf("Do you like me? (Yes/No): ");
        scanf("%9s", input);

        toLowerCase(input);  // convert input to lowercase

        if (strcmp(input, "yes") == 0) {
            printf("Yay! I like you too! ❤️\n");
            break;  // exit loop
        } else {
            printf("Oh, that's okay. Try again! 😅\n");
        }
    }

    return 0;
}

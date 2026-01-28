#include <stdio.h>

int main() {
    int age;
    char name[50];

    printf("Enter your age and name: ");
    int assignments = scanf("%d %s", &age, name);

    if (assignments == 2) {
        printf("You entered: Age=%d, Name=%s\n", age, name);
    } else {
        printf("Invalid input\n");
    }

    return 0;
}
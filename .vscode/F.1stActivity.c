#include <stdio.h>

void EvenandOdd(int num);

int main() {
    char tryAgain;
    int num;

    do {
        printf("Enter an integer between -100 and 100: ");
        scanf("%d", &num);

        if (num < -100 || num > 100) {
            printf("Number out of range, try again. 100 ra lagy kutob gahi'ag ulo oy dukol ka ron!.😤\n");
            continue;
        }

        EvenandOdd(num);

        printf("Do you want to try again? Pag dali oy!.😤 (y/n): ");
        scanf(" %c", &tryAgain);
    } while (tryAgain == 'y' || tryAgain == 'Y');

    printf("\nThank you for using the jha9's program!.🫶\n");

    return 0;
}

void EvenandOdd(int num) {
    if (num % 2 == 0)
        printf("%d is even.\n", num);
    else
        printf("%d is odd.\n", num);
}

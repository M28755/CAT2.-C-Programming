/*
NAME:       OMONDI MICHAEL OTIENO
REG NO:     PA106/G/28755/25


*/

#include <stdio.h>

int main()
{

    // Define and initialize the 2D array

    int scores[2][2] = {

        {{65, 92}, {84, 72}},

        {{59, 35}, {70, 67}}

    };

    // Print the elements using nested loops

    printf("Elements of the array:\n");

    for (int I = 0; I < 2; I++)
    {

        for (int j = 0; j < 2; j++)
        {

            printf("%d ", score[I][j]);
        }

        printf("\n");
    }

    return 0;
}

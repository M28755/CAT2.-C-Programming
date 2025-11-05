/*
NAME:       OMONDI MICHAEL OTIENO
REG NO:     PA106/G/28755/25
*/
#include <stdio.h>

#include <stdlib.h>

#define SIZE 100 // Maximum number of integers

// Function to read integers from input.txt

int readInput(int arr[])
{

    FILE *fptr = fopen("input.txt", "r");

    if (fptr == NULL)
    {

        printf("Error opening input.txt\n");

        return -1;
    }

    int count = 0;

    while (fscanf(fptr, "%d", &arr[count]) == 1 && count < SIZE)
    {

        count++;
    }

    fclose(fptr);

    return count;
}

// Function to calculate sum and average

void calculateStats(int arr[], int count, int *sum, float *average)
{

    *sum = 0;

    for (int I = 0; I < count; I++)
    {

        *sum += arr[I];
    }

    *average = (float)(*sum) / count;
}

// Function to sort the array (Bubble Sort)

void sortArray(int arr[], int count)
{

    for (int I = 0; I < count - 1; I++)
    {

        for (int j = 0; j < count - I - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {

                int temp = arr[j];

                arr[j] = arr[j + 1];

                arr[j + 1] = temp;
            }
        }
    }
}

// Function to write sorted data, sum, and average to output.txt

void writeOutput(int arr[], int count, int sum, float average)
{

    FILE *fptr = fopen("output.txt", "w");

    if (fptr == NULL)
    {

        printf("Error opening output.txt\n");

        return;
    }

    fprintf(fptr, "Sorted Integers:\n");

    for (int I = 0; I < count; I++)
    {

        fprintf(fptr, "%d ", arr[I]);
    }

    fprintf(fptr, "\nSum: %d\nAverage: %.2f\n", sum, average);

    fclose(fptr);
}

// Function to display contents of both files

void displayFiles()
{

    char ch;

    FILE *fptr;

    printf("\nContents of input.txt:\n");

    fptr = fopen("input.txt", "r");

    if (fptr == NULL)
    {

        printf("Error opening input.txt\n");
    }
    else
    {

        while ((ch = fgetc(fptr)) != EOF)
        {

            putchar(ch);
        }

        fclose(fptr);
    }

    printf("\nContents of output.txt:\n");

    fptr = fopen("output.txt", "r");

    if (fptr == NULL)
    {

        printf("Error opening output.txt\n");
    }
    else
    {

        while ((ch = fgetc(fptr)) != EOF)
        {

            putchar(ch);
        }

        fclose(fptr);
    }
}

int main()
{

    int arr[SIZE], count, sum;

    float average;

    count = readInput(arr);

    if (count == -1)
        return 1;

    calculateStats(arr, count, &sum, &average);

    sortArray(arr, count);

    writeOutput(arr, count, sum, average);

    displayFiles();

    return 0;
}

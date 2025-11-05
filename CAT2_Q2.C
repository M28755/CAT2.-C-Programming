/*
NAME:       OMONDI MICHAEL OTIENO
REG NO:     PA106/G/28755/25

*/
#include <stdio.h>

int main()
{
    float hours, wage;
    float grossPay, tax, netPay;

    // Input
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours);

    printf("Enter hourly wage: ");
    scanf("%f", &wage);

    // Calculate gross pay
    if (hours <= 40)
    {
        grossPay = hours * wage;
    }
    else
    {
        float overtime = hours - 40;
        grossPay = (40 * wage) + (overtime * wage * 1.5);
    }

    // Calculate tax
    if (grossPay <= 600)
    {
        tax = 0.15 * grossPay;
    }
    else
    {
        tax = (0.15 * 600) + (0.20 * (grossPay - 600));
    }

    // Calculate net pay
    netPay = grossPay - tax;

    // Output
    printf("\n--- Pay Summary ---\n");
    printf("Gross Pay: $%.2f\n", grossPay);
    printf("Taxes:     $%.2f\n", tax);
    printf("Net Pay:   $%.2f\n", netPay);

    return 0;
}

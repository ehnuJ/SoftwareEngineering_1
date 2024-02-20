// Author: Joon Hee Ooten
// Date: 2/8/23
// C Program 1
#include <stdio.h>
#include <stdlib.h>

// Prints monthly sales
void printMonthlySales(void)
{
    char Months[][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};    
    char line[256];
    int i = 0;
    
    printf("Monthly sales report for 2022:\n\n%-15s  %-20s \n\n", "Month", "Sales");
    FILE *file = fopen("Input.txt", "r");           // Opens file
    while (fgets(line, sizeof(line), file))         // Reads file line by line
        {printf("%-15s %s", Months[i++], line);}    // Prints the month followed by the sales of that month
    fclose(file);                                   // Closes file
    return;
}

// Prints sales summary
void printSalesSummary(void)
{
    char Months[][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    float temp;
    float max;
    float min;
    float avg = 0.0F;
    int i = 0;
    char *ptr;
    char line[256];
    int maxindex;
    int minindex;
    printf("Sales summary:\n\n");
    FILE *file = fopen("Input.txt", "r");
    while (fgets(line, sizeof(line), file))
    {
        temp = strtod(line, &ptr);          // Loop to turn the number from string to float
        avg += temp;                        
        if (max < temp)
        {
            max = temp;
            maxindex = i;
        }
        if (min > temp || i == 0)
        {
            min = temp;
            minindex = i;
        }
        i++;                                // Used for calculating average later
    }
    printf("%-15s %0.2f (%s)\n%-15s %0.2f (%s)\n%-15s %0.2f\n\n", "Minimum sales:", min, Months[minindex], "Maximum sales:", max, Months[maxindex], "Average sales:", (avg / 12)); //Ugly but works
    fclose(file);
    return;
}

// Six-Month moving average report
void SixMonthAverageReport(void)
{

    int i = 0;
    char *Months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    float Return[12];
    char *ptr;
    char line[256];

    FILE *file = fopen("Input.txt", "r");
    printf("Six-Month moving average report:\n\n");
    while (fgets(line, sizeof(line), file))
    {
        Return[i] = strtod(line, &ptr);
        i++;
    }
    for (i = 0; i <= 6; i++)
    {
        printf("%-15s - %-10s%0.2f\n", Months[i], Months[i + 5], (Return[i] + Return[i + 1] + Return[i + 2] + Return[i + 3] + Return[i + 4] + Return[i + 5]) / 6);
    }
    printf("\n\n");

    fclose(file);

    return;
}

// Sales report (highest to lowest)
void reportHighToLow(void)
{

    int i = 0;
    char *Months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    float Return[12];
    char *ptr;
    char line[256];

    FILE *file = fopen("Input.txt", "r");
    printf("Sales Report (Highest to Lowest):\n\n");
    printf("%-15s  %-20s \n\n", "Month", "Sales");

    while (fgets(line, sizeof(line), file))
    {
        Return[i] = strtod(line, &ptr);
        i++;
    }
    float temp = 0.0f;
    char *tempMonth[256];
    for (int i = 0; i < 12; i++)                // Sorting from smallest to biggest
    {
        for (int j = 0; j < 12 - i - 1; j++)
        {
            if (Return[j] > Return[j + 1])
            {
                tempMonth[0] = Months[j + 1];
                temp = Return[j + 1];
                Return[j + 1] = Return[j];
                Months[j + 1] = Months[j];
                Return[j] = temp;
                Months[j] = tempMonth[0];
            }
        }
    }
    for (i = 11; i >= 0; i--)                   // will print biggest to smallest
    {
        printf("%-15s %0.02f\n", Months[i], Return[i]);
    }
    printf("\n\n");
    fclose(file);
    return;
}

//main function
int main(void){
    printMonthlySales();
    printSalesSummary();
    SixMonthAverageReport();
    reportHighToLow();
}
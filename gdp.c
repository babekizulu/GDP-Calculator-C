#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 * @Desc: A library of formulae for economic indicators
 * @Author: Lwandle Babekizulu Dlamini
 */
struct GDPExpApproach
{
    double consumption;
    double investment;
    double governmentExpenditure;
    double netExports;
};

double gdpExpApproachSolution(double c, double i, double g, double nx)
{
    return c + i + g + nx;
}

struct GDPIncomeApproach
{
    double totalNationalIncome;
    double salesTaxes;
    double depreciation;
    double netForeignFactorIncome;
};

double gdpIncomeApproachSolution(double tni, double t, double d, double f)
{
    return tni + t + d + f;
}

double calculateGDP(int selectionNum)
{
    if (selectionNum == 1)
    {
        char proceed;
        printf("You have chosen the GDP Expenditure Approach\n");
        printf("Are you happy with your choice?\n");
        printf("(y/n)?: ");
        scanf("%c", proceed);
        if (proceed == 'n' || proceed == 'N')
        {
            return;
        }
        else if (proceed == 'y' || proceed == 'Y')
        {
            struct GDPExpApproach gdp;
            printf("Enter values for the following:\n");
            printf("Consumption: ");
            scanf("%lf", gdp.consumption);
            printf("Investment: ");
            scanf("%lf", gdp.investment);
            printf("Government Expenditure: ");
            scanf("%lf", gdp.governmentExpenditure);
            printf("Net Exports: ");
            scanf("%lf", gdp.netExports);

            return gdpExpApproachSolution(gdp.consumption, gdp.investment, gdp.governmentExpenditure, gdp.netExports);
        }
    }
    else if (selectionNum == 2)
    {
        char proceed;
        printf("You have chosen the GDP Income Approach\n");
        printf("Are you happy with your choice?\n");
        printf("(y/n)?: ");
        scanf("%c", proceed);
        if (proceed == 'n' || proceed == 'N')
        {
            return;
        }
        else if (proceed == 'y' || proceed == 'Y')
        {
            struct GDPIncomeApproach gdp;
            printf("Enter values for the following:\n");
            printf("Total National Income: ");
            scanf("%lf", gdp.totalNationalIncome);
            printf("Sales Taxes: ");
            scanf("%lf", gdp.salesTaxes);
            printf("Depreciation: ");
            scanf("%lf", gdp.depreciation);
            printf("Net Foreign Factor Income: ");
            scanf("%lf", gdp.netForeignFactorIncome);

            return gdpIncomeApproachSolution(gdp.totalNationalIncome, gdp.salesTaxes, gdp.depreciation, gdp.netForeignFactorIncome);
        }
    }
}

int initialPrompt(void)
{
    int selection;
    printf("Select an approach to calculate GDP:\n");
    printf("1. GDP Expenditure Approach\n");
    printf("2. GDP Income Approach\n");
    printf("(1/2)?: ");
    scanf("%i", selection);
    return selection;
}

int main(void)
{
    int selectionNum;
    double result;
    selectionNum = initialPrompt();
    printf("Gross Domestic Product = %f", calculateGDP(selectionNum));
}
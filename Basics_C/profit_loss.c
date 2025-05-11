#include <stdio.h>
int main()
{
    float cp, sp;
    printf("Enter the cost price of a product: ");
    scanf("%f", &cp);

    printf("Enter the selling price of a product: ");
    scanf("%f", &sp);
    // profit and loss %ages are calculated based on cost price of products
    if (sp > cp)
    {
        float profit = sp - cp;
        printf("ProfitPercentage = %.2f", ((profit / cp) * 100));
    }
    else
    {
        float loss = cp - sp;
        printf("LossPercentage  = %.2f", ((loss / cp) * 100));
    }
    return 0;
}
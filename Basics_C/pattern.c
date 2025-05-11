#include <stdio.h>
void p1(int rows);
void p2(int rows);
void p3(int rows);
void p4(int rows);
void p5(int rows);
void p6(int rows);
void p7(int rows);
void p8(int rows);
void p9(int rows);
void p10(int rows);
void p11(int rows);

int main()
{
    // p1(5);
    // p2(5);
    // p3(5);
    // p4(5);
    // p5(5);
    // p6(5);
    // p7(5);
    // p8(5);
    // p9(5);
    // p10(5);
    // p11(5);

    return 0;
}

void p1(int rows)
{
    /*
     *
     * *
     * * *
     * * * *
     * * * * *
     */
    printf("ROWS: %d\n", rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

void p2(int rows)
{
    /*
             #
           # #
         # # #
       # # # #
     # # # # #
     */
    printf("ROWS: %d\n", rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 1; j < rows - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void p3(int rows)
{
    /*
     * * * * *
     * * * *
     * * *
     * *
     *
     */
    printf("ROWS %d", rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows - i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

void p4(int rows)
{
    /*
      #####
       ####
        ###
         ##
          #
    */
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < rows - i; k++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void p5(int rows)
{
    /*
    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5
    */
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", j + 1);
        }
        printf("\n");
    }
}

void p6(int rows)
{
    /*
    1
    2 1
    3 2 1
    4 3 2 1
    5 4 3 2 1
     */

    for (int i = 0; i < rows; i++)
    {
        int k = i + 1;
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", k);
            k--;
        }
        printf("\n");
    }
}

void p7(int rows)
{
    /*
    A B C D E
      A B C D
        A B C
          A B
            A
    */
    for (int i = 0; i < rows; i++)
    {
        char alph = 'A';
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < rows - i; k++)
        {
            printf("%c", alph);
            alph++;
        }

        printf("\n");
    }
}

void p8(int rows)
{
    /*
    1
    2 3
    4 5 6
    7 8 9 10
    */
    int num = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }
}

void p9(int rows)
{
    /*
    A B C D E
      B C D E
        C D E
          D E
            E
     */
    for (int i = 0; i < rows; i++)
    {
        char alpha = 'A';
        for (int j = 0; j < i; j++)
        {
            printf(" ");
            alpha++;
        }
        for (int k = 0; k < rows - i; k++)
        {
            printf("%c", alpha);
            alpha++;
        }

        printf("\n");
    }
}

void p10(int rows)
{
    /*
     * * * * *
     *       *
     *       *
     *       *
     * * * * *
     */

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (i == 0 || i == rows - 1 || j == 0 || j == rows - 1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void p11(int rows)
{
    /*
          #
        # # #
      # # # # #
    # # # # # # #
    */

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < (rows - i) - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < (2 * i) + 1; k++)
        {
            printf("*");
        }

        printf("\n");
    }
}

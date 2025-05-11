#include <stdio.h>
#include <string.h>

int strLength(char str[]);
int count_occurrence(char str[], char input);
int count_vowels(char str[]);
int count_spaces(char str[]);
void reverse(char str[]);
void compare_str(char str1[], char str2[]);
char *tirm(char str[]);
int count_words(char str[]);

int main()
{
    // char name[100];

    // printf("Name: ");
    // fgets(name, sizeof(name), stdin);
    // name[strcspn(name, "\n")] = '\0';

    // printf("Length of %s is %d", name, strLength(name));
    // reverse(name);

    // printf("%s", name);

    // compare_str("admin", "ME");
    char str[] = "hii i am admin";
    // printf("Before trim: '%s'\n", str);
    // tirm(str);
    // printf("After trim: '%s'", str);
    printf("Word count: %d\n", count_words(str));

    return 0;
}

int strLength(char str[])
{
    int i = 0;
    while (str[i] != '\0')
        i++;

    return i;
}

int count_occurrence(char str[], char input)
{
    int i = 0, count = 0;
    while (str[i] != '\0')
    {
        if (str[i] == input)
            count++;
    }

    return count;
}

int count_vowels(char str[])
{
    int i = 0, count = 0;
    char v[] = "aeiouAEIOU";
    while (str[i] != '\0')
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            count++;
    }
    return count;
}

int count_spaces(char str[])
{
    int i = 0, count = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            count++;
    }
    return count;
}

void reverse(char str[])
{
    int left = 0, right = (strlen(str) - 1);
    while (left <= right)
    {
        char temp = str[right];
        str[right] = str[left];
        str[left] = temp;

        left++;
        right--;
    }
}

void compare_str(char str1[], char str2[])
{
    int flag = 0;
    for (int i = 0; str1[i] && str2[i]; i++)
    {
        if (str1[i] == str2[i])
            flag = 1;
        else
            flag = 0;
    }
    if (flag)
        printf("EQUAL");
    else
        printf("UNEQUAL");
}

char *tirm(char str[])
{
    int i = 0, j = 0, end = strLength(str) - 1;

    while (str[i] == ' ')
        i++;

    while (str[end] == ' ')
        end--;

    while (i <= end)
        str[j++] = str[i++];

    str[j] = '\0';

    return str;
}

int count_words(char str[])
{
    int count = 0;
    tirm(str);

    for (int i = 0; str[i]; i++)
    {
        if (str[i] == ' ')
        {
            if (str[i] == str[i + 1])
                continue;
            else
                count++;
        }
    }

    return count + 1;
}

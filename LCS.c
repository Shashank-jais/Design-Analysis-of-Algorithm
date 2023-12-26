#include <stdio.h>
#include <string.h>
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int LCS(char str1[], char str2[], int i, int j)
{
    if (i == strlen(str1) || j == strlen(str2))
        return 0;

    else if (str1[i] == str2[j])
        return 1 + LCS(str1, str2, i + 1, j + 1);
    else
        return max(LCS(str1, str2, i + 1, j), LCS(str1, str2, i, j + 1));
}
int main()
{
    char str1[100];
    char str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    int n = LCS(str1, str2, 0, 0);
    printf("The length of the longest common sequence: %d", n);

    return 0;
}
#include <stdio.h>
#include <string.h>

// Function to reverse string
void reverse(char str[], char rev[]) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    rev[len] = '\0';
}

// Function to check palindrome
int isPalindrome(char str[]) {
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        if(str[i] != str[len - i - 1])
            return 0;
    }
    return 1;
}

int main() {
    char str1[100], str2[100], rev[100];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    // i) Length
    printf("\nLength of string = %lu\n", strlen(str1));

    // ii) Reverse
    reverse(str1, rev);
    printf("Reversed string = %s\n", rev);

    // iii) Equality check
    if(strcmp(str1, str2) == 0)
        printf("Strings are equal\n");
    else
        printf("Strings are not equal\n");

    // iv) Palindrome check
    if(isPalindrome(str1))
        printf("String is a palindrome\n");
    else
        printf("String is not a palindrome\n");

    // v) Substring check
    if(strstr(str1, str2) != NULL)
        printf("Second string is a substring of first string\n");
    else
        printf("Second string is NOT a substring of first string\n");

    return 0;
}
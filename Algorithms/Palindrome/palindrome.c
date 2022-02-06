#include<stdio.h>
#include<string.h>

int palindrome(char* word) {
    int  i = 0, n = strlen(word);

    for (int i = 0; i < n; i++) {
        // For Debugging
        // printf("\n%c <=> %c", word[i], word[n-i-1]);

        if (word[i] != word[n-i-1]) return 0;
    }

    return 1;
}

int main() {

    char word[] = "racecar";
    char exp[] = "(racecar)";

    // For User Input
    // printf("Enter a string: ");
    // scanf(" %s", &word);


    if ( palindrome(word) )
        printf("\n%s is a palindrome", word);
    else
        printf("\n%s is not a palindrome", word);

    return 1;
}

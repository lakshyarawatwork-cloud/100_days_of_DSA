/*Problem Statement
Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

Input Format
A single string s.

Output Format
Print the first non-repeating character or '$' if none exists.

Sample Input
geeksforgeeks

Sample Output
f

Explanation*/
#include <stdio.h>
#include <string.h>

char firstNonRepeating(char *s) {
    int freq[26] = {0};

    for (int i = 0; s[i]; i++) freq[s[i] - 'a']++;

    for (int i = 0; s[i]; i++) {
        if (freq[s[i] - 'a'] == 1) return s[i];
    }

    return '$';
}

int main() {
    char s[100005];
    scanf("%s", s);

    printf("%c", firstNonRepeating(s));

    return 0;
}
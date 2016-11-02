

#include <stdio.h>
#include <string.h>

int isPalindSubstring(char *a, int length)
{
    int i;
    for (i = 0;i < length / 2;i++)
    {
        if (a[i] != a[length - 1 - i])
        {
            return 0;
        }
    }
    return 1;
}

char* longestPalindrome(char* s) 
{
    int i, m;
    int length, retval, maxSubstringLength;
    char *ptr;

    length = strlen(s);
    printf ("%d\r\n", length);
    for (i = length;i > 0;i--)
    {
        for (m = 0;m <= (length - i);m++)
        {
            if (isPalindSubstring(s + m, i))
            {
                ptr = (char *)malloc((i + 1) * sizeof(char));
                memcpy(ptr, s + m, i);
                ptr[i] = '\0';
                return ptr;
            }
        }
    }
    return NULL;
}


int main(void)
{
    char substring[] = "abcbb";
    char *ptr;

    ptr = longestPalindrome(substring);
    if (NULL!= ptr)
    {
        puts(ptr);
        free(ptr);
    }

    getchar();

    return 0;
}



#include <stdio.h>
#include <string.h>

void thisPrintf(const char *ptr, int size)
{
    int i;

    for (i = 0;i < size;i++)
    {
        printf ("%c", ptr[i]);
    }
    printf (":%d\r\n", size);
}

int lengthOfLongestSubstring(char* s)
{
    int hash[256], i, j, length, maxLength = 1, startIndex = 0;

    length = strlen(s);
    if (0 == length)
    {
        goto final;
    }
    for(i = 0;i < length;i++)
    {
        memset(hash, 0, sizeof(hash));
        hash[s[i]] = 1;
        for (j = i + 1;j < length;j++)
        {
            if (0 == hash[s[j]])
            {
                hash[s[j]] = 1;
            }
            else
            {
            	if ((j - i) > maxLength)
				{ 
                	maxLength = j - i;
                	startIndex = i;
				}
                break;
            }
        }
		if (length  == j)
		{
			if ((j - i) > maxLength)
			{ 
				maxLength = j - i;
				startIndex = i;
			}
		}
    }
final:
    thisPrintf(s + startIndex, maxLength);
    return maxLength;
}

int main(void)
{
    char thisString[] = "helloworld";
    
    //for (;;)
    {
        //scanf("%s", thisString);
        puts(thisString);
        lengthOfLongestSubstring(thisString);
        puts("");
    }
    getchar();
    return 0;
}

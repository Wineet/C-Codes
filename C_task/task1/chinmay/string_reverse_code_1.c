#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], reverse[100];
    int len, i, index, wordStart, wordEnd;

    printf("Enter any string: ");
    gets(str);

    len   = strlen(str);
    index = 0;

    // checking of words from the end of string
    wordStart = len - 1;
    wordEnd   = len - 1;

    while(wordStart > 0)
    {
        // find word until space character is found
        if(str[wordStart] == ' ')
        {
            // Add the word to the reverse string
            i = wordStart + 1;
            while(i <= wordEnd)
            {
                reverse[index] = str[i];

                i++;
                index++;
            }
            reverse[index] = ' ';
	    index++;

            wordEnd = wordStart - 1;
        }

        wordStart--;
    }

    // add the last word
    for(i=0; i<=wordEnd; i++)
    {
        reverse[index] = str[i];
        index++;
    }

    // Add NULL character at the end of reverse string
    reverse[index] = '\0';

    printf("Original string \n%s\n\n", str);
    printf("Reverse ordered words \n%s\n", reverse);

    return 0;
}
                                            
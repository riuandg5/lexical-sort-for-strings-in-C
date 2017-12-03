#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int num,i,j,k,lshort;

    //Get number of strings to arrange.
    printf("Enter number of words you want to arrange : ");
    scanf("%d",&num);

    //Declare num number of strings with available length of 100 characters.
    char word[num][100];

    //Input strings one by one.
    for(j=0;j<num;j++)
    {
        printf("Enter string %d : ",j+1);
        scanf("\n%[^\n]",word[j]); //exclude white spaces
    }

    //Method 1 : using strcmp
    for(k=0;k<num-1;k++)
        for(j=0;j<num-1;j++)
        {
            //Compare two strings using strcmp.
            //If 1st string is greater than 2nd then swap strings.
            if(strcmp(word[j],word[j+1])>0)
            {
                char temp[100]; //Temporary string
                strcpy(temp,word[j]);
                strcpy(word[j],word[j+1]);
                strcpy(word[j+1],temp);
            }
        }

    /*
    //Method 2 : Bubble sort algorithm
    for(k=0;k<num-1;k++)
    for(j=0;j<num-1-k;j++)
    {
        //Take two strings at a time.
        //Compare their length.

        //tshort = lenght of shorter string
        if(strlen(word[j])<=strlen(word[j+1]))
            lshort=strlen(word[j]);
        else
            lshort=strlen(word[j+1]);

        //Compare letter by letter of both strings till shorter string's length.
        for(i=0;i<lshort;i++)
        {
            //If ascii value of ith letter of 1st string is smaller than 2nd then do nothing.
            if(word[j][i]<word[j+1][i])
                break;

            //If ascii value of ith letter of 1st string is greater than 2nd then swap strings.
            else if(word[j][i]>word[j+1][i])
            {
                char temp[100]; //Temporary string
                strcpy(temp,word[j]);
                strcpy(word[j],word[j+1]);
                strcpy(word[j+1],temp);
                break;
            }
        }
    }
    */

    //Print arranged strings one by one.
    printf("\nArranging in dictionary order :\n\n");
    for(j=0;j<num;j++)
        printf("%s\n",word[j]);

    return 0;
}

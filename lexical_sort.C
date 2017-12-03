#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    //Get number of strings to arrange.
    printf("Enter number of words you want to arrange : ");
    int num;
    scanf("%d",&num);

    //Declare num number of strings with available length of 100 characters.
    char word[num][100];

    //Input strings one by one.
    for(int j=0;j<num;j++)
    {
        printf("Enter word %d : ",j+1);
        scanf("\n%[^\n]",word[j]); //include white spaces
    }

    //Bubble sort algorithm
    for(int i=0;i<num-1;i++)
        for(int j=0;j<num-1;j++)
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

    //Print arranged strings one by one.
    printf("\nArranging in dictionary order :\n\n");
    for(int j=0;j<num;j++)
        printf("%s\n",word[j]);

    return 0;
}

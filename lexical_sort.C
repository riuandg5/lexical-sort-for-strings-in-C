#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int num,i,j,k,tshort,tlong;
    
    //Get number of strings to arrange.
    printf("Enter number of words you want to arrange : ");
    scanf("%d",&num);
  
    //Declare num number of strings with available length of 100 characters.
    char b[num][100];
  
    //Input strings one by one.
    for(j=0;j<num;j++)
    {
        printf("Enter string %d : ",j+1);
        scanf("\n%[^\n]",b[j]); //exclude white spaces
    }
  
    //Bubble sort algorithm
    for(k=0;k<num-1;k++)
        for(j=0;j<num-1-k;j++)
        {
            /*Take two strings at a time.
              Compare their length.*/
            
            //tshort = lenght of shorter string
            //tlong = length of longer string
            if(strlen(b[j])<strlen(b[j+1]))
            {
                tshort=strlen(b[j]);
                tlong=strlen(b[j+1]);
            }
            else if(strlen(b[j])<strlen(b[j+1]))
            {
                tshort=strlen(b[j+1]);
                tlong=strlen(b[j]);
            }
            else
                tshort=strlen(b[j]); //or tshort=strlen(b[j+1]);
          
            //Compare letter by letter of both strings till shorter string's length.
            for(i=0;i<tshort;i++)
            {
                //If ascii value of ith letter of 1st string is smaller than 2nd then do nothing.
                if(b[j][i]<b[j+1][i])
                    break;
                
                //If ascii value of ith letter of 1st string is greater than 2nd then swap strings.
                else if(b[j][i]>b[j+1][i])
                {
                    char t[100]; //Temporary string
                    strcpy(t,b[j]);
                    strcpy(b[j],b[j+1]);
                    strcpy(b[j+1],t);
                    break;
                }
            }
        }
  
    //Print arranged strings one by one
    printf("\nArranging in dictionary order :\n\n");
    for(j=0;j<num;j++)
        printf("%s\n",b[j]);
  
    return 0;
}

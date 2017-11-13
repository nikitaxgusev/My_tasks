#include <stdio.h>
#include <stdlib.h>

int IsNumberHappy(int valueInput);
void GetMainArray(void);
void GetResult(int* k,int*mainArray);
int main(void)
{

    GetMainArray();


    return 0;
}
int IsNumberHappy(int valueInput)
{
    if(1==valueInput)
    {
        printf("Happy number - %d \n",valueInput);
        return 1;
    }

    if(0==valueInput/10)
        return 0;
    else
    {
        int NumA=valueInput/10%10;
        int NumB=valueInput%10;
        int NumC=valueInput/100;

        int aa=(NumA*NumA);
        int bb=(NumB*NumB);
        int cc=(NumC*NumC);
        int result=aa+bb+cc;
        return result;
    }
}
void GetMainArray(void)
{
    int element=0;
    int* mainArray=malloc(300);

    if(!mainArray)
    {
        printf("Allocation error.");
        exit (1);
    }

    FILE* fh;
    char* filename="test.txt";
    fh=fopen (filename,"r");

    if (fh == NULL){
        printf("file does not exists %s", filename);
        exit(-1);
    }
    const size_t line_size = 300;
    char* line = malloc(line_size);
    while (fgets(line, line_size, fh) != NULL)
    {
        int x=atoi(line);
        mainArray[element]=x;
        element++;
    }
    GetResult(&element,mainArray);
    free(line);
    fclose(fh);
    return mainArray;
}
void GetResult(int* element,int* mainArray)
{
    int i=0;
    for(i=0;i<(*element);i++)
    {
       int valueInput = mainArray[i];
       int resultNumber=IsNumberHappy(valueInput);

       while(resultNumber!=1)
       {
        if(0==resultNumber||resultNumber>1001){
            printf("False - %d\n",mainArray[i]);
             break;
        }
        resultNumber=IsNumberHappy(resultNumber);
        if(1==resultNumber)
            printf("Happy number - %d\n",mainArray[i]);
       }
    }

}


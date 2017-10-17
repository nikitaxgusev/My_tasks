// The task is from the site http://oop.afti.ru/tasks/dlinnaya-stroka
// The function was needed is char* inputString(FILE* fp, size_t size);
// Other functions are for training (strcpy_(),strlen_())
// 21:10 , 17.10.17

//I was fucked to find out about that fucking function
//Because I really forgot C
// HATE FUCKING POINTERS!
//BYE!


#include <stdio.h>
#include <stdlib.h>




int getline(char* str, size_t size);
char* inputString(FILE* fp, size_t size);
int strlen_(char*);
char *strcpy_(char *dest, char *src);

int main(void){
    char* str={"hello"};

    int len=strlen_(str);
    printf("%d",len);

    return 0;
}


int getline(char* str, size_t size)
{
    int i;
    int ch;

    for(i=0;i<size-1 && (ch=getchar())!= EOF && ch!='\n';++i)
    {
          str[i]=ch;
    }
    if(ch=='\n')
    {
        str[i]=ch;
        ++i;
    }
    str[i]='\n';
    return i;
}


char *inputString(FILE* fp, size_t size)
{
//The size is extended by the input with the value of the provisional
char* str;
int ch;
int len=0;
    // allocate memory 1st time
    str=realloc(NULL, sizeof(char)*size);

    //if it wasn't allocated , return a str
    if(!str)
        return str;

    //while the end of file, input from 'fp'
    while (EOF!=(ch=fgetc(fp)))
    {
        str[len++]=ch;
        if(len==size)
        {
            // allocate memory 2d time, if len of a string
            //equally allocating size, then try realloc (size*=2)
            str=realloc(str,sizeof(char)+(size*=2));

            //if it wasn't allocated , return a str
            if (!str)
                return str;
        }
    }

    //the end of a string
    str[len++]='\0';

    //returning str with size of len
    return realloc(str,sizeof(char)*len);
}



char *strcpy_(char *dest, char *src)
{
    char *orig = dest;
    while((*dest++ = *src++)!= '\0')
        ; // <<== Very important!!!
    return orig;
}


int strlen_(char* dest)
{
    int len=0;
    while((*dest++)!='\0')
    {
            len++;
    }
    return len;
}

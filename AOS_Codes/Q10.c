/* 
    Program : Write a C program to display all the files from 
              current directory which are created in particular month. 
*/

//Required Libraries
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<time.h>
#include<stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Function Display
void Display(int argc, char *argv[])
{
    char in[100],st[100],*ch,*ch1,c,buff[512];
    DIR *dp;
    int i;
    struct dirent *ep;
    struct stat sb;
    char mon[100];
    dp=opendir("./");

    //Logic To Print Files
    if (dp != NULL)
    {
        while(ep =readdir(dp))
        {
            if(stat(ep->d_name,&sb) == -1)
            {
                perror("stat");
                exit(EXIT_SUCCESS);
            }

            strcpy(mon,ctime(&sb.st_ctime));
            ch=strtok(mon," ");

            /*The first call to strtok() returns a pointer to the first token in the string pointed to by s1. Subsequent calls to strtok() must pass a NULL pointer as the first argument, in order to get the next token in the string.*/
            ch=strtok(NULL," ");
            if((strcmp(ch,argv[1]))==0)
            {
                printf("%s\t\t%s",ep->d_name,ctime(&sb.st_ctime));
            }
        }
        (void)closedir(dp);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Main function
int main(int argc, char *argv[])
{
    //Call To Display Function
    Display(argc,argv);

    return 0;
}
/*
    Program : Write a C program which receives file names as command line arguments 
              and display those filenames in ascending order according to their sizes.
*/

//Required Libraries
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<time.h>
#include<stdlib.h>

struct filelist
{
    char fname[100];
    int fsize;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Function To Accept File names and Display Them According to Given Condition
void Display(int argc,char *argv[])
{
    DIR *dp;
    int i = 0;
    int j = 0;
    int k = 0;

    struct dirent *ep;
    struct stat sb;
    
    char mon[100];
    
    struct filelist f1[100],temp;
    
    j=0;

    //Logic To Print Files According To Given Condition
    printf("Printing Files in Ascending order According To Their File Sizes : \n");    
    for(i=1;i < argc;i++)
    {
        dp = opendir("./");
        if(dp != NULL)
        {
            while(ep = readdir(dp))
            {
                if((strcmp(ep->d_name,argv[i]))==0)
                {
                    stat(ep->d_name,&sb);
                    strcpy(f1[j].fname,ep->d_name);
                    f1[j].fsize=sb.st_size;
                    j++;
                    break;
                }
            }
        }
        (void)closedir(dp);
    }

    for(i=0;i<j;i++)
    {
        for(k=0;k<=j;k++)
        {
            if(f1[i].fsize < f1[k].fsize)
            {
                temp=f1[k];
                f1[k]=f1[i];
                f1[i]=temp;
            }
        }
    }

    for(i=0;i<j;i++)
    {
        printf("%s\t%d\n",f1[i].fname,f1[i].fsize);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Main Function
int main(int argc,char *argv[])
{
    //Call To Display Function
    Display(argc,argv);
    
    return 0;
}

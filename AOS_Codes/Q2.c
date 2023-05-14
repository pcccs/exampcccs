/*
    Program : Write a C program that accept string as an argument and return all the files 
              that begins with that name in the current directory. 
              For example > ./a.out foo will return all file names that begins with foo.
*/

//Required Libraries
#include<stdio.h>
#include<dirent.h>
#include<string.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
//Function To Display Files 
void Display(int argc, char* argv[])
{
    DIR *d;
    char *position;
    struct dirent *dir;
    int i = 0;

    if(argc!=2)
    {
        printf("Provide suffiecient args");
    }

    //Logic To Display File
    else 
    {
        d = opendir(".");
        if (d)
        {
            while ((dir = readdir(d)) != NULL)
            {
                position=strstr(dir->d_name,argv[1]);
                i=position-dir->d_name;
                if(i==0)
                {
                    printf("%s\n",dir->d_name);
                }
            }
            closedir(d);
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Main Function With Command Line Arguments
int main(int argc, char* argv[])
{
    //Call To Display Function
    Display(argc,argv);
    
    return 0;
}

/*
    Program : Write a C program to find whether a given file is present in current directory or not. 
*/

//Required Libraries
#include <stdio.h>
#include <unistd.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Function To Check File Exist Or Not
void CheckExist(int argc, char *argv[])
{
    if(access(argv[1],F_OK)==0)
    {
        printf("File %s exists", argv[1]);
    } 
    else
    {
        printf("File %s doesn't exist.", argv[1]);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Main Function with Command line Arguments 
int main(int argc, char *argv[])
{
    //Call To CheckExist Function
    CheckExist(argc,argv);

    return 0;
}
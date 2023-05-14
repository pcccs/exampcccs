/*
    Program : Write a C program to find file properties such as inode number, 
              number of hard link, File permissions, File size, File access and 
              modification time and so on of a given file using stat() system call.
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Required Libraries
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Function To Display File information using Stat System Call
void Display(int argc, char *argv[])
{
    struct stat info;

    //Logic To Display Information of File 
    if (argc != 2) 
    {
        printf("Enter filename\n");
    }

    if (stat(argv[1], &info) == -1) 
    {
        printf("Stat error \n");
        exit(EXIT_FAILURE);
    }
    
    //Printing Below information of files
    printf("I-node number: %ld\n", (long) info.st_ino);
    printf("File size: %lld bytes\n",(long long) info.st_size);
    printf("Last file access: %s", ctime(&info.st_atime));
    printf("Last file modification: %s", ctime(&info.st_mtime));
    printf("No of hard links: %d\n",info.st_nlink);
    printf("File Permissions: \t");

    printf( (info.st_mode & S_IRUSR) ? "r" : "-");
    printf( (info.st_mode & S_IWUSR) ? "w" : "-");
    printf( (info.st_mode & S_IXUSR) ? "x" : "-");
    printf( (info.st_mode & S_IRGRP) ? "r" : "-");
    printf( (info.st_mode & S_IWGRP) ? "w" : "-");
    printf( (info.st_mode & S_IXGRP) ? "x" : "-");
    printf( (info.st_mode & S_IROTH) ? "r" : "-");
    printf( (info.st_mode & S_IWOTH) ? "w" : "-");
    printf( (info.st_mode & S_IXOTH) ? "x" : "-");

    putchar('\n');
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Main Function
int main(int argc, char *argv[]) 
{
    //Call To Display Function
    Display(argc,argv);

    return 0;
}
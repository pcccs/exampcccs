/*
    Program : Write a C program that behaves like a shell (command interpreter). It has its own 
              prompt say “NewShell$”. Any normal shell command is executed from your shell by 
              starting a child process to execute the system program corresponding to the command. 
              It should additionally interpret the following command.
             
             i) list f<dirname> - print name of all files in directory
             ii) list n <dirname> - print number of all entries
             iii) list i<dirname> - print name and inode of all files
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Required Libraries
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>

//Global Variables
char *buff,*t1,*t2,*t3,ch;
int pid = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Function To Display Output 
void list(char t2,char *t3)
{
    DIR *dir;
    struct dirent *entry;
 
 
    int cnt=0;
    dir=opendir(t3);

    if (dir==NULL)
    {    
 	    printf("Directory %s not found",t3);
 	    return;
    }
    switch(t2)
    {
        case 'f' : 
            while((entry=readdir(dir))!=NULL)
            {
                printf("%s\n",entry->d_name);
            }
            break;
    
        case 'n' :  
            while((entry=readdir(dir))!=NULL)
            {
                cnt++;                  	
                printf("Total No of Entries: %d\n",cnt);
            }
            
            break;
        case 'i' :  
            while((entry=readdir(dir))!=NULL)
            {
                printf("\n%s\t %d",entry->d_name,entry->d_ino);
            }
            break;
        default :  
            printf("Invalid argument");
    }
    closedir(dir); 
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Main Function
int main()
{
   while(1)
   {
        printf("myshell$");
 	   	fflush(stdin);
        t1=(char *)malloc(80);
        t2=(char *)malloc(80);
        t3=(char *)malloc(80);

        buff=(char *)malloc(80);
        fgets(buff,80,stdin); 	
        sscanf(buff,"%s %s %s",t1,t2,t3);

        if(strcmp(t1,"pause")==0)
        {
            exit(0);
        }
                    
        else if(strcmp(t1,"list")==0)
        {
            list(t2[0],t3);
        }
        else
        {
            pid=fork();
            if(pid<0)
            {
                printf("Child process is not created\n");
            }
                            
            else if(pid==0)
            {      	
                execlp("/bin",NULL);
                if(strcmp(t1,"exit")==0)
                {
                    exit(0);
                }           
                system(buff);
            }
            else
            {      	
                wait(NULL);
                exit(0);
            }
        }
    }

    return 0;
}
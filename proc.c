/**
 * Program on Process
 ***************************************************************************
 * +-------------------------------------------------------------+         *
 * |                     FILE HEADER                             |         *
 * +-------------------------------------------------------------+         *
 *                                                                         *
 * Program Statement: Write a program to create multiple processes as per  *
 *                    given process hierarchy graph. Parent process should *
 *                    be alive till any of the child process is alive.     *
 *                                                                         *
 *                                                                         *
 * Register N0:      1947203                                               *
 *                                                                         *
 *@Author:           Alen Grace Skaria                                     *                                             
 ***************************************************************************
 **/
   

/***********************************Standard Header Files***********************************/
#include<unistd.h>  //for built in funciton fork() and exec()
#include<stdio.h>   //for standard input and output
#include<stdlib.h>  //for exit() function
#include<signal.h>  //define the Signal MACROS
/******************************************************************************************/

/************************************* Function  Declaration***********************************/
 void process_create();
 void killchild_execparent();
 void killpare_killchild();
 void show_status();
 /*********************************************************************************************/
 int parent_id,child_id;  //globally asscessible using static storage class
 
 /************************************ Function Definition**********************************/
  void process_create()
  {
	  int i,n;
	  printf("Create N multiple process you want to create[?]: ");
	  scanf("%d",&n);
	 // child_id=getpid();
	  parent_id=getppid();
	  for(i=0;i<n;i++)
	  {
		if(fork() == 0)
		{
		 sleep(3);
		 printf("[son] pid will be %d from [parent] pid is %d\n",getpid(),parent_id);	
		 exit(0);
		}  
	  }
	  for(i=0;i<n;i++)
	  wait(NULL);    //to parent and child will go in wait state
	  
  }
  

   void killchild_execparent()
   {
    
   }
   
   void killpare_killchild()
   {
	   printf("You killed the dad\nNo Point of existence for the child\nProgram Exiting");
	   sleep(3);
	   int kill_parent;
	   if(getppid() == parent_id)
	   {
		kill_parent=kill(parent_id,SIGKILL);   
		if(kill_parent == 0)  //return type will be zero, then kill function will be successfull
		{
			kill(child_id,SIGKILL);
		}
	   }
   }
   
   void show_status()
   {
	printf("The parent process that currently executing is %d: ",parent_id);
   }
 /*******************************************************************************************/
 
 //START OF MAIN
int main() 
{ 
	int no_choice;
    printf("+-------------------------------+");
    printf("\n|        TASK ON PROCESS        | ");
    printf("\n+-------------------------------+");
    while(1)
    {
    printf("\n\n1-----> Create Multiple Process");
    printf("\n2-----> Kill a Child But Keep Executing the Parent Process");
    printf("\n3-----> If parent is killed, then Terminate Child Process");
    printf("\n4-----> Display the status of the Process");
    printf("\n5-----> Exit the Application as whole");
    
    printf("\nMake Your Choice: ");
    scanf("%d",&no_choice);
    if(no_choice == 1)
    {
	 process_create();
	}
	else if(no_choice == 2)
	{
		killchild_execparent();
    } 
    else if(no_choice == 3)
    {
	   killpare_killchild();
	}
    else if(no_choice == 4)
	{
		show_status();
    } 
    else
    {
	printf("Thank you for using the application !!!!");
	exit(0);	
	}
}//END OF WHILE
}
//END OF MAIN

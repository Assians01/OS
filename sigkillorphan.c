#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
#include<sys/wait.h>

int main()
{
	int ppid, pid, i;
	ppid = (int)getpid();
	pid = fork();
	

	/*if (ppid == (int)getpid())
	{	
		printf("parent \n"); 
	}
	else if (pid == (int)getpid())
	{
		 printf("child \n"); 
	}*/

	if(pid > 0)
	{
	    printf("child process id %d\t parent process id %d\n", pid, ppid);
	    
		i = 0;
		while(i++ < 20)
		{
			printf("in the parent process \n");
			sleep(1); 
			 if (i==7)
			{
				 //printf("I'm killed. Child is orphan!!!"); 
				 //kill(ppid, SIGKILL);
			}
		}

	} 

	else if(pid == 0) 
	{	
		i = 0; 
		while(i++ < 15) 
		{
			printf("in the child process \n");
			sleep(1);
			if (i == 7)
			{
			    //printf("Parent killed. I'm orphan!!!\n");
				kill(ppid, SIGKILL);
			}
		}
	}

 	else
	{
		printf("Something bad happened.");
		exit(0);
	}
	return 0;

}
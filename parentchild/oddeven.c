
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pId, i;
    pId = fork();
    if (pId < 0)
    {
        printf("Process creation is Unsuccessful!");
    }
    // The return value is 0 for a child process
    else if (pId == 0)
    {
        printf("Child process: Printing Odd Numbers");
        printf("\nChild : Child’s PID: %d", getpid());
        printf("\nChild : Parent’s PID: %d\n", getppid());
        for (i = 0; i <= 10; ++i)
        {
            if (i % 2 != 0)
            {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    // The return value is positive for a parent process
    else if (pId > 0)
    {
        wait(NULL);
        printf("\nParent process: Printing Even Numbers after Child");
        printf("\nParent : Parent’s PID: %d", getpid());
        printf("\nParent : Child’s PID: %d\n", pId);
        for (i = 0; i <= 10; ++i)
        {
            if (i % 2 == 0)
            {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    return 0;
}

/* 

Compile and Run

$> gcc oddeven.c
$> ./a.out

OUTPUT

Child process: Printing Odd Numbers 
Child : Child’s PID: 8523
Child : Parent’s PID: 8522
1 3 5 7 9

Parent process: Printing Even Numbers after Child
Parent : Parent’s PID: 8522
Parent : Child’s PID: 8523
0 2 4 6 8 10

*/

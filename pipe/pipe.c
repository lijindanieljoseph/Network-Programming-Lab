/* 
#include <stdio.h>
#include <unistd.h>

int main()
{
    int pipeFds[2], status, pId;
    char writeMsg[20] = "hello world";
    char readMsg[20];

    status = pipe(pipeFds);

    if (status == -1)
    {
        printf("Unable to create pipe\n");
        return 1;
    }

    pId = fork();

    // child process
    if (pId == 0)
    {
        read(pipeFds[0], readMsg, sizeof(readMsg));
        printf("\nChild Process receives data\n%s\n", readMsg);
    }
    // parent process
    else if (pId > 0)
    {
        printf("Parent Process sends data\n%s", writeMsg);
        write(pipeFds[1], writeMsg, sizeof(writeMsg));
    }

    return 0;
}

/* 

Compile and Run

$> gcc pipe.c
$> ./a.out

OUTPUT

Parent Process sends data 
hello world
Child Process receives data
hello world

*/

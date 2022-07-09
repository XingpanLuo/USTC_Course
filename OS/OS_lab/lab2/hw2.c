// #include <sys/types.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <wait.h>
// #include <sys/types.h>
// #define SIZE 5

// int main()
// {
//     // int nums[SIZE] = {0, 1, 2, 3, 4};
//     // int i;
//     // pid_t pid;
//     // pid=fork();
//     // if (pid == 0)
//     // {
//     //     for (i = 0; i < SIZE; i++)
//     //     {
//     //         nums[i] *= -i;
//     //         printf("CHILD:%d ", nums[i]);
//     //     }
//     // }
//     // else if (pid > 0)
//     // {
//     //     wait(NULL);
//     //     for (i = 0; i < SIZE; i++)
//     //         printf("PARENT:%d ",nums[i]);
//     // }
//     printf("before execl ..\n");
//     if(fork()==0){
//         execl("/bin/1s","ls",NULL);
//         printf("after execl ..\n");
//     }
//     else
//         wait(NULL);
        
//     return 0;
// }
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
//#include <wait.h>
int main() {
    // pid_t pid=fork();
    
    // if(pid < 0) {
    //     fprintf(stderr, "Fork Failed");
    //     return 1;
    // }
    // else if(pid == 0) {
    //     printf("test\n");
    //     execl("/bin/ls", "/bin/ls", NULL);
    //     printf("\nLINE J");
    // }
    // else {
    //     wait(NULL);
    //     printf("Child complete");
    // }
    printf("before execl..\n");
    execl("/bin/ls", "", NULL);
    printf("\nLINE J");
    return 0;
}
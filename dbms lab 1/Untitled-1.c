// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
//     printf("enter the number of elements: \n");
//     int n;
//     scanf("%d",&n);
//     int *ptr=NULL;
//     ptr=(int*)malloc(n*sizeof(int));
//     printf("enter the elements to be summed:");
//     int sum =0;
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d",ptr +i);
//         sum= sum + *(ptr+i);
      
//     }
//     printf("%d",(sum));
//     free(ptr);

#include <stdio.h>
#include <stdlib.h>
extern char **environ;
int main(int argc, char* argv[])
{
printf("\n This is a test program \n:");
char **tmp = environ;
while(*tmp != " ")
{
 printf("\n %s \n, *tmp");
 tmp++;
 }
return 0;
}






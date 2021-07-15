/*
Name: JAYATHILAKA H.A.D.T.T.
E no: E/16/156
Lab: Memory allocation

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *create(int s);
void generatedata(int p[],int s);
void printGivenArray(int a[],int s);
void bubblesort(int a[],int s);
void printBubbleSorted(int a[],int s);


int main()
{
    int s; //s=no of elements
    printf("Enter the size of the array: ");//get the size of the array
    scanf("%d",&s);

    if(s<=0){
        printf("Size should be positive and non zero value.\n");
        return 0;
    }

    int* a=create(s);     //  call the functions
    generatedata(a,s);    ////  call the functions
    printGivenArray(a,s); // call the functions
    bubblesort(a,s);     // call the functions
    printBubbleSorted(a,s);  // call the functions
return 0;
}

int *create(int s)  // create data for the array. s=size of the array
{
   int i=0;
   int *a;    // what is the value in p
   a=(int *)malloc(sizeof(double)*s);  //assign size of the p
   if(a!=NULL)   // if there is nothing in p address
   {
       for(i=0;i<s;i++)
       {
           a[i]=0;
       }
   }
   return a;  //return the pointer
}

void generatedata(int a[],int s)  // generate data using array p
{
    int k=0;
    if(a!=NULL){  // if there is nothing in p address
        srand(time(0));
        for(k=0;k<s;k++){
            a[k]=rand()%300+1;
        }
    }
}

void printGivenArray(int a[],int s) // print the given array
{
     int i;
     printf("The given array= ");  // if s==1 there is a specific way to display
     if(s==1){
           printf("{ %d } \n\n",a[0]);
     }else{                            // else it can display this way
           printf("{ %d, ",a[0]);
           for(i=1;i<s-1;i++){
                printf("%d, ",a[i]);
           }
           printf("%d } \n\n",a[s-1]);
     }
}


void bubblesort(int a[],int s)  // Bubblesorting
{
    int i;   //is s=1 there is nothing to sort
    if (s<=0)
        return ;
    for(i=0;i<s;i++){
            if(a[i]>a[i+1]){   // if a[i] is larger than a[i+1] they should swap
                int c,d;
                c=a[i];
                d=a[i+1];
                a[i]=d;
                a[i+1]=c;
            }
    }
    bubblesort(a,s-1); // do recursion
}


void printBubbleSorted(int a[],int s)   // print the sorted array
 {
     int i;
     printf("The sorted array= ");
     if(s==1){             // if s==1 there is a specific way to display
           printf("{ %d } \n",a[0]);
     }else{
           printf("{ %d, ",a[0]);     // else it can display this way
           for(i=1;i<s-1;i++){
                printf("%d, ",a[i]);
           }
           printf("%d } \n",a[s-1]);
     }
 }


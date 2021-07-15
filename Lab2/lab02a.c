#include<stdio.h>
#include<stdlib.h>
int main(){
    int x;
    printf("Enter a number: ");//get the no.
    scanf("%d",&x);
//see whether that given no prove any of the given axioms
if((x%15==0)||(x>999)||(x%5==0 && x%6==0 && x%18!=0)||((x>999)||(x%5==0 && x%6==0 && x%18!=0))){
    printf("%d is",x);
}else { // if not give an invalid message or something
 printf("Not special,not big,not weird and not scary");
 exit(0);
}

    if(x%15==0){// x is divisible by 15
        printf(" special");
    }

if (x%15==0){//x is greater than 999
    printf(",");
}else if(x>999){
printf(" big");
}

if(x%15==0 && x>999){ //x is exactly divisible by 5 & 6but not 18
    printf(",");
}else if(x%5==0 && x%6==0 && x%18!=0){
printf(" weird");
}

if ((x>999)||(x%5==0 && x%6==0 && x%18!=0)){ //x is big or weird
   printf(" and scary");
}else if((x<999)&&(x%5!=0 || x%6!=0 || x%18==0)){
 printf(" but not scary");
}

if(((x>999)||(x%5==0 && x%6==0 && x%18!=0))&&(x<999)){ // if x is weird which one that x prove correct
    printf(" but not big");
}else if(((x>999)||(x%5==0 && x%6==0 && x%18!=0))&&(x%5!=0 || x%6!=0 || x%18==0)){
printf(" but not weird");
}

return 0;
}


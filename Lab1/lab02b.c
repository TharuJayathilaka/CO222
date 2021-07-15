#include<stdio.h>
int main(){
    int x,a[3],i;
    printf("Enter the colour: ");
    for (i=0;i<3;++i){
            scanf("%d",&a[i]);}
//a[i]=component value
//b[i]=complement value
    int b[i],c[i],d[i],e[i];
    for (i=0;i<3;++i){
            if (a[i]<0 || a[i]>255){
                    printf("The component should be with in 0 and 255");
                    exit(0);
            }

            b[i]=255-a[i];
            c[i]=a[i]-b[i];// get the difference between component & complement
    if(c[i]>0){//checking whether c[i] is positive or not
         if (c[i]<=32){ //if the difference is 32 or less than 32
            d[i]=128+a[i];
                if (d[i]>255){ // if it exceed the range of component
                   e[i]=a[i]-128;
                   printf("%d ",e[i]);
                }else{
                   printf("%d ",d[i]);
                }
        }else{
            printf("%d ",b[i]);
        }

    }else{ // if difference is negative
        c[i]=b[i]-a[i];
        if (c[i]<=32){
            d[i]=128+a[i];
          if (d[i]>255){
               e[i]=a[i]-128;
               printf("%d ",e[i]);
          }else{
               printf("%d ",d[i]);
          }
       }else{
            printf("%d ",b[i]);
       }
    }
    }
return 0;
}


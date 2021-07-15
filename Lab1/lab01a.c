#include<stdio.h>
int main(){
    int x,y,p,q,s,r,v,h,t,u;  /* p=hours q=minutes, s=all minutes, r=hours,t=minutes,u=finaly all hours*/
    printf("Enter the start time: ");
    scanf("%d",&x);
    printf("Enter the duration: ");
    scanf("%d",&y);
    p=x/100;
    q=x-(p*100);
    v=y/100;
    h=y-(v*100);
    s=q+h;
    r=s/60;
    t=s-(r*60);
    u=r+p+v;
    if(u<24){  // to get normal time
    if(t<10){
         printf("End time is %d0%d",u,t);
        }else{
        printf("End time is %d%d",u,t);
       }
    }else{
            u=u-24;   //when the time exeed 24 hours
        if(t<10){
                if(u<10){
                printf("End time is 0%d0%d",u,t);
                }else{
                printf("End time is %d0%d",u,t);
                }
        }else{
            if(u<10){
                printf("End time is 0%d%d",u,t);
                }else{
                printf("End time is %d%d",u,t);
                }
        }


        }
return 0;
}

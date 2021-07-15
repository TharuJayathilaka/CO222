#include<stdio.h>
int main(){
double a,b,c,x,y,p,i;
printf("Enter the coefficients: ");
scanf("%lf %lf %lf",&a,&b,&c);
p=(b*b)-(4*a*c);  //get the delta value
if(p>=0){ // if delta value is positive, roots are not complex
x=(-b+sqrt(p))/(2*a);
y=(-b-sqrt(p))/(2*a);
  if(x==y){ //if there is only one root
printf("The solution is: %.2lf ",x);
  }else{ // otherwise there should be two roots
printf("The solutions are: %.2lf and %.2lf ",y,x);
  }
}else { //if delta value is negative, roots are complex
    x=-b/(2*a);
    y=sqrt(-p)/(2*a);
    if(x==0){
        printf("The solutions are %.2lfi and -%.2lfi",y,y);
    }else{
     printf("The solutions are %.2lf+%.2lfi and %.2lf-%.2lfi",x,y,x,y);
    }

  }
return 0;
}

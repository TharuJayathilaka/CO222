#include<stdio.h>


long long CtoI(char inputnum[],int size);
void ItoH(unsigned long long z,int size);
void BtoH(char inputnum[],int size);
void ItoB(long long z,int size,char inputnum[]);
void HtoB(char inputnum[],int size);
void BtoI(char inputnum[],int size);
void HtoI(char inputnum[],int size);
void ItoF(long long z);
void ItoD(long long z);
unsigned long long NItoH(unsigned long long z,int size);
void FtoI(char inputnum[],int size);
void print1(char inputnum[],int size);
void FtoB(char inputnum[],int size);
int errorsize1(int size);
int errorsize2(int size);
int conversionError(int size);
int errorLocation1(char inputnum[],int size);
int errorLocation2(char inputnum[],int size);
int errorLocation3(char inputnum[],int size);
int errorLocation4(char inputnum[],int size);
int error1(long long z,int size);






int main(int argc, char* argv[]){
  char a= argv[1][1]; // read the first input as a character
  char b= argv[2][1]; // read the second input as a character
  int j=0,i=0;  //get the size of the third input
  while(argv[3][i++]!='\0');
  int size=i-1; // size= the dimension of final input
  char inputnum[size];
  for(j=0;j<size;j++){
       inputnum[j]=argv[3][j];
  }

/*long long number;
number=CtoI(inputnum,size);
printf("%lld\n",number);*/


int y1=0,y2=0,y3=0;
if((a!='I')&&(a!='H')&&(a!='B')&&(a!='F')&&(a!='D')){
    fprintf(stdout,"ERROR: The input argument is wrong.\nPossible input arguments are -B -H -I -F and -D");
}else if((b!='I')&&(b!='H')&&(b!='B')&&(b!='F')&&(b!='D')){
    fprintf(stdout,"ERROR: The output argument is wrong.\nPossible output arguments are -B -H -I -F and -D");
}else if(argc!=4){
    fprintf(stdout,"ERROR: The number of arguments is wrong.\nUsage: ./clc -<input format> -<output format> <innput>");
}else if((a=='I')&&(b=='H')){//I=integer,H=8-digit hexadecimal representation
        y1=errorLocation3(inputnum,size);
        y2=error1(CtoI(inputnum,size),size);
        if((y1!=1)&&(y2!=1)){
           if(inputnum[0]!='-'){
              ItoH(CtoI(inputnum,size),size);
           }else{
               ItoH(NItoH(CtoI(inputnum,size),size),size);
           }
       }
}else if((a=='B')&&(b=='H')){    // give different output ufing this loop //binary to hexadecimal
    y1=errorsize1(size);
    y2=errorLocation1(inputnum,size);  // give errors
    if((y1!=1)&&(y2!=1)){
       BtoH(inputnum,size);
    }
}else if((a=='B')&&(b=='B')){  //
    y1=errorsize1(size);
    y2=errorLocation1(inputnum,size);
    if((y1!=1)&&(y2!=1)){
        print1(inputnum,size);
    }
}else if((a=='I')&&(b=='I')){
    y2=error1(CtoI(inputnum,size),size);
    y1=errorLocation3(inputnum,size);
    if((y1!=1)&&(y2!=1)){
        print1(inputnum,size);
    }
}else if((a=='H')&&(b=='H')){
    y1=errorsize2(size);
    y2=errorLocation2(inputnum,size);
    if((y1!=1)&&(y2!=1)){
        print1(inputnum,size);
    }
}else if((a=='D')&&(b=='D')){
    y1=errorLocation4(inputnum,size);
    if(y1!=1){
        print1(inputnum,size);
    }
}else if((a=='F')&&(b=='F')){
    y1=errorLocation4(inputnum,size);
    if(y1!=1){
        print1(inputnum,size);
    }
}else if((a=='I')&&(b=='B')){
    y2=error1(CtoI(inputnum,size),size);
    y1=errorLocation3(inputnum,size);
    if((y1!=1)&&(y2!=1)){
       ItoB(CtoI(inputnum,size),size,inputnum);
    }
}else if((a=='H')&&(b=='B')){
    y1=errorsize2(size);
    y2=errorLocation2(inputnum,size);
    if((y1!=1)&&(y2!=1)){
       HtoB(inputnum,size);
    }
}else if((a=='B')&&(b=='I')){
    y1=errorsize1(size);
    y2=errorLocation1(inputnum,size);
    if((y1!=1)&&(y2!=1)){
       BtoI(inputnum,size);
    }
}else if((a=='H')&&(b=='I')){
    y1=errorsize2(size);
    y2=errorLocation2(inputnum,size);
    y3=conversionError(size);
    if((y1!=1)&&(y2!=1)&&(y3!=1)){
       HtoI(inputnum,size);
    }
}else if((a=='I')&&(b=='F')){
    y2=error1(CtoI(inputnum,size),size);
    y1=errorLocation3(inputnum,size);
    if((y1!=1)&&(y2!=1)){
       if(inputnum[0]=='-'){
           fprintf(stdout,"-");
       }
       ItoF(CtoI(inputnum,size));
    }
}else if((a=='I')&&(b=='D')){
    y2=error1(CtoI(inputnum,size),size);
    y1=errorLocation3(inputnum,size);
    if((y1!=1)&&(y2!=1)){
       ItoD(CtoI(inputnum,size));
    }
}else if((a=='F')&&(b=='I')){
    y1=errorLocation4(inputnum,size);
    if(y1!=1){
       FtoI(inputnum,size);
    }
}else if((a=='D')&&(b=='I')){
    y1=errorLocation4(inputnum,size);
    if(y1!=1){
       FtoI(inputnum,size);
    }
}//else if((a=='B')&&(b=='F')){

else if((a=='F')&&(b=='B')){
        y1=errorLocation4(inputnum,size);
        if(y1!=1){
           FtoB(inputnum,size);
        }
}





return 0;
}


long long CtoI(char inputnum[],int size){
    long long numz=0;//numz= integer z
    int k;
    if(inputnum[0]!='-'){ //if input is a positive
        for(k=0;k<size;k++){
           numz=numz*10+(inputnum[k]-'0');  // by using ascii code values get the integer
        }  //z=Third input as an integer
    }else{ //if input is a negative
        for(k=0;k<size-1;k++){
           numz=numz*10+(inputnum[k+1]-'0');  // by using ascii code values get the integer
        }  //z=Third input as an integer
    }
return numz;
}

void ItoH(unsigned long long z,int size){  //integer to hexadecimal
        int num;
        num=0;
        //if(inputnum[0]!='-'){// if input is a positive
            char H[8];
            while(z>0){
                switch(z%16){ // get the remainder of z after it divided by 16
                   case 10: //assign relevant character to them
                       H[num]='A';
                       break;
                   case 11:
                       H[num]='B';
                       break;
                   case 12:
                       H[num]='C';
                       break;
                   case 13:
                       H[num]='D';
                       break;
                   case 14:
                       H[num]='E';
                       break;
                   case 15:
                       H[num]='F';
                       break;
                   default: // if remainder is less or equal to 9
                       H[num]=(z%16)+0x30;// convert integer to a string
                       break;
               }
               z=(z/16);
               num++;
            }
            printf("0x"); //et the output as given output
            int p;
            for(p=0;p<8-num;p++){
                fprintf(stdout,"0");
            }
            for(p=(num-1);p>=0;p--){
                fprintf(stdout,"%c",H[p]);
            }
            fprintf(stdout,"\n");
}





void BtoH(char inputnum[],int size){  //binary to hexadecimal
    if(size==32){  //if 32 bit
        int i,k,total=0;//convert every element of input to a integer
        for(i=0;i<size;i++){
            int t=1, m=0;
            m=(inputnum[i]-'0');//converting to integers
            for(k=1;k<=31-i;k++){
                t*=2;
            }
            int y=m*t;//get the decimal value of binary numbers
            total=total+y;// get the sum of all values and get the final final decimal number
        }
        int num;
        char H[8];
        num=0;
        while(total>0){//get the remainder of r and assign characters to them
            switch(total%16){
               case 10:
                  H[num]='A';
                  break;
               case 11:
                  H[num]='B';
                  break;
               case 12:
                  H[num]='C';
                  break;
               case 13:
                  H[num]='D';
                  break;
               case 14:
                  H[num]='E';
                  break;
               case 15:
                  H[num]='F';
                  break;
               default:
                  H[num]=(total%16)+0x30;
                  break;
          }
          total=(total/16);
          num++;
       }
       if(num<=8){
            fprintf(stdout,"0x");
       } //get the final output as given output
       int p;
       for(p=0;p<8-num;p++){
           fprintf(stdout,"0");
       }
       for(p=(num-1);p>=0;p--){
           fprintf(stdout,"%c",H[p]);
       }

   }else{
        int i,k,total=0;//convert every element of input to a integer
        for(i=0;i<size;i++){
            int t=1, m=0;
            m=(inputnum[i]-'0');//converting to integers
            for(k=1;k<=63-i;k++){
                t*=2;
            }
            int y=m*t;//get the decimal value of binary numbers
            total=total+y;// get the sum of all values and get the final final decimal number
        }
        int num;
        char H[16];
        num=0;
        while(total>0){//get the remainder of r and assign characters to them
            switch(total%16){
               case 10:
                  H[num]='A';
                  break;
               case 11:
                  H[num]='B';
                  break;
               case 12:
                  H[num]='C';
                  break;
               case 13:
                  H[num]='D';
                  break;
               case 14:
                  H[num]='E';
                  break;
               case 15:
                  H[num]='F';
                  break;
               default:
                  H[num]=(total%16)+0x30;
                  break;
          }
          total=(total/16);
          num++;
       }
       if(num<=16){
           fprintf(stdout,"0x");
       } //get the final output as given output
       int p;
       for(p=0;p<16-num;p++){
           fprintf(stdout,"0");
       }
       for(p=(num-1);p>=0;p--){
           fprintf(stdout,"%c",H[p]);
       }
   }
   fprintf(stdout,"\n");
}



void ItoB(long long z,int size,char inputnum[]){ // integers to binary
   int H[32],num=0;
   while(z>0){
        switch(z%2){   // get the binary values
            case 0:
                H[num]=0;
                break;
            case 1:
                H[num]=1;
                break;
        }
        z=(z/2);
        num++;
    }
    int p;
    if(inputnum[0]!='-'){      // make output 32 bit using zeros
        for(p=0;p<32-num;p++){
           fprintf(stdout,"0");
        }
        for(p=(num-1);p>=0;p--){
           fprintf(stdout,"%d",H[p]);
        }
    }else{
        fprintf(stdout,"1");
        for(p=0;p<31-num;p++){
           fprintf(stdout,"0");
        }
        for(p=(num-1);p>=0;p--){
           fprintf(stdout,"%d",H[p]);
        }
    }
    fprintf(stdout,"\n");
}



void HtoB(char inputnum[],int size){  // hexadecimal to binary
       int i=0;
       for(i=0;i<size;i++){
                    char c= inputnum[i];// get the every element of input separately and assign strings to them
                    switch(c){
                        case 'A':
                            fprintf(stdout,"1010");
                            break;
                        case 'B':
                            fprintf(stdout,"1011");
                            break;
                        case 'C':
                            fprintf(stdout,"1100");
                            break;
                        case 'D':
                            fprintf(stdout,"1101");
                            break;
                        case 'E':
                            fprintf(stdout,"1110");
                            break;
                        case 'F':
                            fprintf(stdout,"1111");
                            break;
                        case '0':
                            fprintf(stdout,"0000");
                            break;
                        case '1':
                            fprintf(stdout,"0001");
                            break;
                        case '2':
                            fprintf(stdout,"0010");
                            break;
                        case '3':
                            fprintf(stdout,"0011");
                            break;
                        case '4':
                            fprintf(stdout,"0100");
                            break;
                        case '5':
                            fprintf(stdout,"0101");
                            break;
                        case '6':
                            fprintf(stdout,"0110");
                            break;
                        case '7':
                            fprintf(stdout,"0111");
                            break;
                        case '8':
                            fprintf(stdout,"1000");
                            break;
                        case '9':
                            fprintf(stdout,"1001");
                            break;
                  }
       }
       fprintf(stdout,"\n");
}


void BtoI(char inputnum[],int size){ //binary to integers
   if(size==32){
        unsigned long long total=0;
        int k,i;//convert every element of input to a integer
        for(i=0;i<size;i++){
            int t=1, m=0;
            m=(inputnum[i]-'0');//converting to integers
            for(k=1;k<=31-i;k++){
                t*=2;
            }
            int y=m*t;//get the decimal value of binary numbers
            total=total+y;// get the sum of all values and get the final final decimal number
        }
        fprintf(stdout,"%llu\n",total);
    }
}


void HtoI(char inputnum[],int size){  //hexadecimal to integers
     if(size==8){
            unsigned long long total=0;
            int k,i;//convert every element of input to a integer
            for(i=0;i<size;i++){
                int t=1, m=0;
                m=(inputnum[i]-'0');//converting to integers
                if(m>9){
                    m=m-7;
                }
                for(k=1;k<=7-i;k++){
                    t*=16;
                }
                int y=m*t;//get the decimal value of binary numbers
                total=total+y;// get the sum of all values and get the final final decimal number
           }
           fprintf(stdout,"%llu\n",total);
     }
}


void ItoF(long long z){ //integer to floating point numbers
    fprintf(stdout,"%lld.00\n",z);
}

void ItoD(long long z){ //integer to floating point numbers
    fprintf(stdout,"%lld.00\n",z);
}



void FtoB(char inputnum[],int size){ //floating point numbers to binary
    int i;
    for(i=0;i<size;i++){
        if(inputnum[i]=='.'){
            //decimalpoint=i;
            break;
        }
    }
}






 unsigned long long NItoH(unsigned long long z,int size){//negative integer to hexadecimal
     int T[32],n=0;
   while(z>0){
        switch(z%2){
            case 0:
                T[31-n]=1;
                break;
             default:
                T[31-n]=0;
                break;
        }
        z=(z/2);
        n++;
         //printf("%d\n",T[31-n+1]);
    }
    int p;
    for(p=0;p<32-n;p++){
        T[p]=1;
         //printf("%d\n",T[n]);
    }
    unsigned long long total=0;
        int k,i;//convert every element of input to a integer
        for(i=0;i<32;i++){
            unsigned long long t=1;
        //converting to integers
            //printf("%d\n",T[i]);
            for(k=1;k<=31-i;k++){
                t*=2;
            }
            unsigned long long y=T[i]*t;//get the decimal value of binary numbers
            total=total+y;// get the sum of all values and get the final final decimal number
        }
        total=total+1;
        //printf("%llu",total);
return total;
}


void FtoI(char inputnum[],int size){  //floating point numbers to integers
    int i,p;
    for(i=0;i<size;i++){
                    char c= inputnum[i];//c= we get the every number of input as one bit character
                    if(c=='.'){
                        p=i;
                    }
    }
    if(p<11){
         fprintf(stdout,"WARNING: There is a possibility for a precision loss\n");
         for(i=0;i<p;i++){
                char c= inputnum[i];
                fprintf(stdout,"%c",c); // The final output
         }
    }else{
         fprintf(stdout,"ERROR: This conversion is not possible");
    }


    fprintf(stdout,"\n");
}

void BtoF(char inputnum[],int size){ // binary to floating point
    if(inputnum[0]==1){
        fprintf(stdout,"-");
    }
        int total=0;
        int k,i;//convert every element of input to a integer
        for(i=1;i<9;i++){
            int t=1, m=0;
            m=(inputnum[i]-'0');//converting to integers
            for(k=1;k<=8-i;k++){
                t*=2;
            }
            int y=m*t;//get the decimal value of binary numbers
            total=total+y;// get the sum of all values and get the final final decimal number
        }
        //exp=total-127;




}
void print1(char inputnum[],int size){
    int r;
    for(r=0;r<size;r++){
        fprintf(stdout,"%c",inputnum[r]);
    }
    fprintf(stdout,"\n");
}




int errorsize1(int size){

    if(size!=32&&size!=64){
        fprintf(stderr,"Error: The input size is wrong.");
        return 1;
    }else{
        return 0;
    }
}

int errorsize2(int size){

    if(size!=8&&size!=16){
        fprintf(stderr,"Error: The input size is wrong.");
        return 1;
    }else{
        return 0;
    }
}

int conversionError(int size){

    if(size!=8){
        fprintf(stderr,"Error: This conversion is not possible.");
        return 1;
    }else{
        return 0;
    }
}

int errorLocation1(char inputnum[],int size){
    int i;
    return 0;
    for(i=0;i<size;i++){
        if((inputnum[i]!=0)&&(inputnum[i]!=1)){
            fprintf(stderr,"ERROR: Input format error at location %d.",i);
            return 1;
        }

    }

}

int errorLocation2(char inputnum[],int size){
    int i;
    return 0;
    for(i=0;i<size;i++){
        if(inputnum[i]=='-'){
            fprintf(stderr,"ERROR: Input format error at location %d.",i);
            return 1;
            break;
        }
    }
}

int errorLocation3(char inputnum[],int size){
    int i;
    return 0;
    for(i=1;i<size;i++){
        if(inputnum[i]=='-'){
            fprintf(stderr,"ERROR: Input format error at location %d.",i);
            return 1;
            break;
        }
    }
}

int errorLocation4(char inputnum[],int size){
    int i,k=0,p;
    return 0;
    for(i=0;i<size;i++){
        if(inputnum[i]=='.'){
                k++;
                if(k>1){
                   p=1;
                   fprintf(stderr,"ERROR: Input format error at location %d.",i);
                   return p;
                   break;
                }
         }
     }
}

int error1(long long z,int size){
    if(z<=2147483647){
        return 0;
    }else{
        fprintf(stderr,"ERROR: The input size is wrong.");
        return 1;
    }
}








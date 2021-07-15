/* E no: E/16/156
   Name: Jayathilaka H.A.D.T.T.
   Lab 03                       */



#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int main(int argc, char* argv[]){
  char a= argv[1][1]; // read the first input as a character
  char b= argv[2][1]; // read the second input as a character

  int j=0,i;  //get the size of the third input
  while(argv[3][j++]!='\0');
    int size=j-1; // size= the dimension of final input
    if((a=='F')&&(b=='I')){//F=single precision floating point number, I=integer
            for(i=0;i<size;i++){
                    char c= argv[3][i];//c= we get the every number of input as one bit character
                    if(c=='.'){
                        exit(-1);
                    }else{
                        printf("%c",c); // The final output
                    }
            }
    }

    if((a=='H')&&(b=='B')){ //H=8-digit hexadecimal representation, B=32-bit binary representation
            for(i=0;i<size;i++){
                    char c= argv[3][i];// get the every element of input separately and assign strings to them
                    switch(c){
                        case 'A':
                            printf("1010");
                            break;
                        case 'B':
                            printf("1011");
                            break;
                        case 'C':
                            printf("1100");
                            break;
                        case 'D':
                            printf("1101");
                            break;
                        case 'E':
                            printf("1110");
                            break;
                        case 'F':
                            printf("1111");
                            break;
                        case '0':
                            printf("0000");
                            break;
                        case '1':
                            printf("0001");
                            break;
                        case '2':
                            printf("0010");
                            break;
                        case '3':
                            printf("0011");
                            break;
                        case '4':
                            printf("0100");
                            break;
                        case '5':
                            printf("0101");
                            break;
                        case '6':
                            printf("0110");
                            break;
                        case '7':
                            printf("0111");
                            break;
                        case '8':
                            printf("1000");
                            break;
                        case '9':
                            printf("1001");
                            break;
                  }
       }
   }
   if((a=='I')&&(b=='F')){ //I=integer, F=single precision floating point number
       for(i=0;i<size;i++){
            char c= argv[3][i];
            printf("%c",c);
       }
       printf(".00");
   }
    // converting string to a integer
    int k,z=0,q;   //q= length of the string array [3]
    if(argv[3][0]!='-'){ //if input is a positive
        q=strlen(argv[3]);  //get the length of the string
        for(k=0;k<q;k++){
           z=z*10+(argv[3][k]-'0');  // by using ascii code values get the integer
        }  //z=Third input as an integer
    }else{ //if input is a negative
        q=strlen(argv[3]);  //get the length of the string
        for(k=0;k<q-1;k++){
           z=z*10+(argv[3][k+1]-'0');  // by using ascii code values get the integer
        }  //z=Third input as an integer
    }
    if((a=='I')&&(b=='H')){//I=integer,H=8-digit hexadecimal representation
        int num;
        num=0;
        if(argv[3][0]!='-'){// if input is a positive
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
                printf("0");
            }
            for(p=(num-1);p>=0;p--){
                printf("%c",H[p]);
            }
        }else{ //not completed
            int H[8];
            printf("%d\n",z);
            while(z>0){
               switch(z%2){
                   case 0:
                       H[num]=1;
                       break;
                   case 1:
                       H[num]=0;
                       break;
               }
               z=(z/2);
               num++;
           }
           int p;
           for(p=(num-1);p>=0;p--){
                printf("%d",H[p]);
            }
       }
   }
   if((a=='B')&&(b=='H')){ //B=32 bit binary number, H=8-digit hexadecimal number
        int r=0;//convert every element of input to a integer
        for(i=0;i<size;i++){
            int m=0;
            m=(argv[3][i]-'0');//converting to integers
            int y=m*(pow(2,31-i));//get the decimal value of binary numbers
            r=r+y;// get the sum of all values and get the final final decimal number
        }
        int num;
        char H[8];
        num=0;
        while(r>0){//get the remainder of r and assign characters to them
            switch(r%16){
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
                  H[num]=(r%16)+0x30;
                  break;
          }
          r=(r/16);
          num++;
       }
       printf("0x"); //get the final output as given output
       int p;
       for(p=0;p<8-num;p++){
           printf("0");
       }
       for(p=(num-1);p>=0;p--){
           printf("%c",H[p]);
       }
   }
   return 0;
}

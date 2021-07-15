#include <stdio.h>
#include "map.h"
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  list_t list = create_list();

  char buff[100];
  if(argc <=1){                     // if there is no argument then return
    return 0;
  }
  FILE *file=fopen(argv[1],"r");    //read the file that mentioned before
  while(1){
    if(file!=NULL){
        fscanf(file,"%s", buff);    // get the strings of the file that mentioned before
    }else{                          // if there is not such a file
        printf(" The file does not exist");
        return 0;
    }
    int p,q;                       // remove symbols from a string
    for(p=0;buff[p]!= '\0'; ++p){
        while(!((buff[p]>='a' && buff[p]<='z')||(buff[p]>='A' && buff[p]<='Z')|| buff[p]=='\0')){
            for(q=p;buff[q]!= '\0'; ++q){
                buff[q]=buff[q+1];
            }
            buff[q]='\0';
        }
    }
    if(strcmp("END", buff) == 0) break;  //  END should be the last word of the file
    //printf("%s\n", buff);
    add(list, buff);
  }
  fclose(file);   //  close the file that mentioned here

  while(!isEmpty(list)) {
    node_t * tmp = remove_list(list);
    printf("%s:%d\n",tmp->val, tmp->count);
  }

  return 0;
}

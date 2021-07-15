#include "linked.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define MAX 5 // max number of cities.
#define NAMESIZE 20 // names should have this many or less chars

int main()
{
  list_t list = NULL;
  char *city;

  printf("Enter city names. Enter \"END\" to break\n");

//  city = (char *)malloc(sizeof(char) * NAMESIZE);
//  assert(city);
  int noCity=0;
  while(1) {
        city = (char *)malloc(sizeof(char) * NAMESIZE);
        assert(city);
        if(scanf("%s", city)>0)
        if(!strcmp(city, "END")) break; // break out of loop
           noCity++;
           assert(!head_insert(city, &list));
  }
  if(noCity>MAX){
     printf("The no of cities that you can add is 5.");
     return 0;
  }

  printf("Your way back: ");
  while(remove_list((void **)&city, &list)){
      printf("%s -> ", city);
  }
  printf("Thats it\n");
  return 0;
}


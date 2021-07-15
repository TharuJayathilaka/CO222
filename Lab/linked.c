#include "linked.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>

/********************************
 * add to head. Return 0 on success
 ********************************/
int head_insert(void *data, list_t *list)
{
  node_t*tmp;  // tmp is the new head add to the array
  tmp=(node_t*)malloc(sizeof(node_t));
  if(tmp){   //if the head is not null
     tmp->data=data;  // get me only the data part
     tmp->next=*list;  //get me only the link of the next data
     *list=tmp;
     return 0;
  }else{
      return -1;
  }
}


/********************************
 * Remove
 * Store value in data, free node and return 1
 ********************************/
int remove_list(void **data, list_t *list)
{
  if(*list){  //if the first address is not null
    node_t*tmp=*list;
    //node_t*holder;
    *data=tmp->data;
    //holder=tmp->next;=
    *list=(tmp)->next; // get the address of next data
    free(tmp);  // free the node
    tmp=NULL;   // should free the node as well as the data stored in the node.
    return 1;
  }
  return 0;
}




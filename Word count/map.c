#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"
#include "map.h"


list_t create_list()
{
  list_t list = (list_t)malloc(sizeof(struct list));
  if(list) list -> head = NULL;
  return list;
}

int isEmpty(list_t list)
{
#ifdef DEBUG
  assert(list);
#endif
  if(list) return ((list -> head) == NULL);
  else     return 0;
}


int add(list_t list, char *val)
{
#ifdef DEBUG
  assert(list);
  assert(val);
#endif
  assert(list);
  node_t*tmp=list->head;
  node_t*p;              //p=previous node
  if(val==NULL){         //there should be words to sort
    return 0;
  }
  while(tmp){
	  if(strcmp(val,tmp->val)==0){  // if the value is same, then the count must be increased by 1
		  tmp->count++;
		  return 0;
	  }else if(strcmp(val,tmp->val)<0){       // if the value is smaller than the tmp value, that should be there
	      node_t*sortednode=(node_t*)malloc(sizeof(node_t));  // get a new node which is named as first
	      sortednode->count=1;  // since it has used only once, count=1
	      sortednode->val=strdup(val);
	      sortednode->next=tmp;  //since this is before the tmp, next node address of first should be tmp
	      if(tmp==(list->head)){
            list->head=sortednode;  // updating the header
            return 0;
	      }
	      p->next=sortednode;  // then the previous one should point to the first one
	      return 0;
	  }else if(tmp->next==NULL){
	      break;
	  }
	  p=tmp;  // previous one should be tmp
	  tmp=tmp->next;  //tmp shouldbe the pointed next address
  }
  node_t*newtmp=(node_t*)malloc(sizeof(node_t)); // making the last node
  newtmp->count=1;
  newtmp->val=strdup(val);
  if(list->head==NULL){  // if there is nothing in the list
    list->head=newtmp;  // new tmp must be head and one before the null
    newtmp->next=NULL;
    return 0;
  }
  tmp->next=newtmp;  // the last option is newtmp should be the last
  newtmp->next=NULL;
  return 0;
}
  // This function should be implemented during the class itself
  // show it to an instructor before leaving the class.

node_t * remove_list(list_t list)
{
#ifdef DEBUG
  assert(list);
#endif

  node_t * tmp = list -> head;
  list -> head = (list -> head) -> next;
  return tmp;
}




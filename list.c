#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct node* newNode(int x, int y, int color, int type)
{
  nodeRef new = malloc(sizeof(struct node));
  if(new == NULL)
    exit(EXIT_FAILURE);
  new->x = x;
  new->y = y;
  new->color = color;
  new->type = type;
  new->next = NULL;
  return new;
}

void DestroyList(nodeRef first)
{
  if(first != NULL)
  {
    DestroyList(first->next);
    free(first);
    first = NULL;
  }

}

void addNode(nodeRef first, nodeRef newNode)
{
  while(first->next != NULL)
  {
    first = first->next;
  }
  first->next = newNode;
}
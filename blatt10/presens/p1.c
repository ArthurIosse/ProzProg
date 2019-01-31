#include <stdio.h>
#include <stdlib.h>

struct Spieler
{
  int a;
  struct Spieler * next;
};

struct Spieler* addtop(struct Spieler* head,struct Spieler* new)
{
  if (head == NULL) head = new;
  else{
  new->next = head;
  head = new;
  }
  return head;
}


int main(int argc,char *argv[])
{

  struct Spieler * one = (struct Spieler*)malloc(sizeof(struct Spieler));
  struct Spieler * players = NULL;

  players = one;
  players->a = 1;
  players->next = NULL;
  //players = one;

  struct Spieler * two = (struct Spieler*)malloc(sizeof(struct Spieler));
  two->a = 2;

  one = addtop(one,two);


  for (players = one ; players!=NULL ; players = players->next)
  {
  printf("%d\n",players->a);
  }

  return 0;
}

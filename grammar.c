#include "grammar.h"


void createNode(struct Node *noeud, char *tagName, char *value, int lg)
{
  if (noeud ==NULL)
  { // dans le cas d'un échec d'un malloc
    exit(-1);

  }

  struct subNode f;
  f = (struct subNode)malloc(sizeof(struct subNode));
  if (f ==NULL)
  {
    exit(-1); // dans le cas d'un échec du malloc

  }

  strcpy(noeud->tag, tagName);
  strcpy(noeud->buf, value);
  noeud->len=lg;
  noeud->fils = &f;
}


void addSubNode(struct Node *pere, struct Node *f)
{
  struct subNode *liste = pere->fils;
  struct subNode *prec;

  if (liste==NULL)
  {
    (pere->fils) = (struct subNode)malloc(sizeof(struct subNode)); // faire une vérif sur le malloc?
    (pere->fils)->sub = f;
    (pere->fils)->suivant = NULL;

  }
  else if (liste->sub ==NULL)
  {
    (pere->fils)->sub = f;

  }
  else
  {
    while(liste!=NULL)
    {
      prec = liste;
      liste = liste->suivant;

    }
    liste  = (struct subNode)malloc(sizeof(struct subNode)); // faire une vérif sur le malloc?
    liste->sub = f;
    liste->suivant = NULL;
    prec->suivant = liste;

  }
}

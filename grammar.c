#include "grammar.h"

void createNode(struct Node *noeud, char *tagName, char *value, int lg)
{
  if (noeud ==NULL)
  { // dans le cas d'un échec d'un malloc
    exit(-1);

  }

  struct subNode *f;
  f = (struct subNode*)malloc(sizeof(struct subNode));
  if (f ==NULL)
  {
    exit(-1); // dans le cas d'un échec du malloc

  }

  strcpy(noeud->tag, tagName);
  strcpy(noeud->buf, value);
  noeud->len = lg;
  noeud->fils = f;
}


void addSubNode(struct Node *pere, struct Node *f)
{
  struct subNode *liste = pere->fils;
  struct subNode *prec;

  if (liste==NULL)
  {
    liste = (struct subNode*)malloc(sizeof(struct subNode)); // faire une vérif sur le malloc?
    liste->sub = f;
    liste->suivant = NULL;
    pere->fils = liste;

  }
  else if (liste->sub ==NULL)
  {
    liste->sub = f;

  }
  else
  {
    while(liste!=NULL)
    {
      prec = liste;
      liste = liste->suivant;

    }
    liste  = (struct subNode*)malloc(sizeof(struct subNode)); // faire une vérif sur le malloc?
    liste->sub = f;
    liste->suivant = NULL;
    prec->suivant = liste;

  }
}


//aller voir string .h , un truc de type split
int findEndLine (char* buf, int len)
{
  int ind=0;
  int sauv = ind;

  // on incrémente i jusqu'à sortir de la chaine ou trouver la fin de ligne
  while (ind+1<len && (buf[ind]!='\r' || buf[ind+1]!='\n')) ind++;


  // si on sort de la chaine, on renvoie la longueur prise en entrée
  if (ind==len) return ind;

  // sinon on renvoie le caractère juste avant la fin de ligne
  else
  {
    return ind--;
  }
}



int findEndVerif(char* buf, int len, char separateur)
{
  int ind=0;
  int sauv = ind;

  // on incrémente i jusqu'à sortir de la chaine ou trouver le séparateur
  while (ind<len && buf[ind]!=separateur) ind++;


  // si on sort de la chaine, on renvoie la longueur prise en entrée
  if (ind==len) return ind;

  // sinon on revient en arrière jusqu'à trouver le premier caractère n'étant
  // pas un espace ou un HTAB, ou bien l'élément juste avant le séparateur
  // le cas échéant
  else
  {
    ind--; //élément avant le dernier séparateur
    sauv= ind; //sauvegarde de cet élément
    // 32 = HTAB et 9 = Space en ASCII
    while (ind>0 && ( buf[ind]==9 || buf[ind]==32)) ind--;

    if (ind==0) return sauv;
    else return ind;
  }
}

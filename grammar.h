#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Ce module s'occupera de traduire des requetes et reponses HTTP tel qu'il soit
   comprehensible par le parseur */

//---------------Definitions des structures---------------//

// structure des noeuds de l'arbre construit lors de la vérification
typedef struct Node
{
  char *tag;  // nom de la rulename
  char *buf;  // valeur de la rulename
  int len;  // Longeur
  void *fils; // pointeur sur la liste chainée des fils du noeud
} Node;

// Liste chainee de chaque noeud
typedef struct subNode
{
  struct Node *sub; // Pointeur vers la structure du noeud fils
  struct subNode *suivant; // Pointeur sur case suivante
}subNode;


// structure Erreur ? voir avec ZAWZ


//--------------Prototype des fonctions----------------//

/* on initialise les valeurs d'un noeud dont l'espace mémoire
a déjà été attribué dans la fonction appelante*/
void createNode(struct Node *noeud, char *tagName, char *value, int lg);

/* on ajoute le noeud fils initialisé dans la fonction appelée par
le père, dans les fils du père initialisé précédemment*/
void addSubNode(struct Node *pere, struct Node *f);

//renvoie un entier ind tel que buf+ind est le dernier élement de la ligne
int findEndLine (char* buf, int len);

//renvoie un entier ind tel que buf+ind est l'emplacement du
// dernier caractère non OWS avant le premier nouveau séparateur, sinon
// l'emplacement du dernier OWS.
int findEndVerif(char* buf, int len, char separateur);
}


#endif

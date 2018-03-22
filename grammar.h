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

void createNode(struct Node *noeud, char *tagName, char *value, int lg);

void addSubNode(struct Node *pere, struct Node *f);



#endif

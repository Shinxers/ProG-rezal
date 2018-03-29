#include "check.h"


/* Prototype des fonctions de vérification:

bool checkMachin( Node* balai , char * dansLe, int cul){

  balai = pointeur vers là où on fourre les valeurs du noeud
  dansLe = pointeur vers le premier caractère de la chaîne à vérifier
  cul = la taille de cette chaine de caractère


ok = true;
  1 - faire la vérfication des fils et des séparateurs grâce aux fonctions:
    Node* new_fils;
    if(checkFilsMachin(new_fils, là_où_on_en_est_dans_la_chaine, longueur_de_la_chaine )){
      (balai->fils)->sub = new_fils;
    }else{
      ok = false;
    }
    ceci est à adapter en fonction du format de la rule

  2 - retour:
    return ok;
}

Ne pas oublier d'adapter ou de reprendre les modèles (voir les automates)

par exemple :

bool checkToken(Node* node, char* buf, int len){
  bool ok = true;
  struct subNode* fils = struct

  for (int i=0; i<len ; i++){
    // struct Node* bleg = malloc(sizeof truc); pas besoin ici mais on le met pour qu'on comprenne
    if (!checkPchar(NULL, buf+i, 1)){
      ok=false;
      free(bleg); // remise en liberté, car animal en voie de disparition , toi même tu sais. il est mignon,genre bien trop. EUAAAAAAAArg *mibph*
    }else{// pas besoin non plus, mais same, etibamecus représente!
      parcours liste chainée new_fils et ajout de bleg
    }
  }

  if (ok==true){
    createNode(node,"Token", buf, len);
    return true;
  }else{
    node = &structerreur;
    return false;
  }// alé salu
} */

bool checkTchar( Node* node, char* buf, int len)
{
  bool ok = true;

}

bool checkHTTPMessage( Node* node, char* buf, int len)
{
  bool ok = true;

}

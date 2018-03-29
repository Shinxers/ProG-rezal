#include "check.h"


/* Prototype des fonctions de vérification:

bool checkMachin( Node* balai , char * dansLe, int cul){
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

Ne pas oublier d'adapter ou de reprendre les modèles (voir les automates)*/

bool checkHTTPMessage( Node* node, char* buf, int len)
{

}

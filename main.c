#include <stdio.h>
#include <stdlib.h>
#include "api.h"

/// Incluez ici les fichiers d'entête nécessaires pour l'execution de ce programme.
/// La fonction parseur doit être dans un autre fichier .c
/// N'ajouter aucun autre code dans ce fichier.

int main(int argc, char *argv[])
{
  char req[]="GET / HTTP/1.0\r\nHost: www.google.com\r\nTransfer-Encoding: gzip\r\n\r\n";
  if (argc != 2 ) { printf("usage: %s <rulename>\n",argv[0]); return 0; }
  if (parseur(req,strlen(req))) {
    _Token *r,*tok;
    r=searchTree(NULL,argv[1]);
    tok=r;
    while (tok) {
      int l;
      char *s;
      s=getElementValue(tok,&l);
      printf("FOUND [%.*s]\n",l,s);
      tok=tok->next;
    }
    purgeElement(&r);
  }
  else {
    return 0;
  }
  return 1;
}

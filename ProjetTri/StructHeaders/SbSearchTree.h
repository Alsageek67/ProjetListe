/*
 * SbSearchTree.h
 *
 *  Created on: Nov 10, 2015
 *      Author: kabbouh
 */

#ifndef STRUCTHEADERS_SBSEARCHTREE_H_
#define STRUCTHEADERS_SBSEARCHTREE_H_

typedef struct Arbin
{
	int val;
	struct Arbin* ad;
	struct Arbin* ag;
	int hd;
	int hg;
	int combien;
} Noeud,*Arbre;

//Arbre vide
Arbre initArbre();

//Libère
int FreeArbre();

//Renvoie le désequilibre de l'arbre : -2,-1, 0, 1, 2
int desec(Arbre a);


//Effectue les rotations à droites, rotations à gauches
Arbre rd(Arbre a);
Arbre rg(Arbre a);

//Insertion à la racine + réequilibrage
Arbre insert(int val, Arbre a);

#endif /* STRUCTHEADERS_SBSEARCHTREE_H_ */

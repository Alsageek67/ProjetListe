/*
 * SbSearchTree.c
 *
 *  Created on: Nov 10, 2015
 *      Author: kabbouh
 */

#include <stdio.h>
#include <stdlib.h>
#include <SbSearchTree.h>


typedef struct ancetre
{
	Noeud* ancetre;
	int direction; //Droite = 1, Gauche =-1
} Ancetre;

Arbre initArbre()
{
	return NULL;
}

int desec(Arbre a)
{
	return a->ag-a->ad;
}

Arbre rd(Arbre a)
{

}
Arbre rg(Arbre a)
{

}

//Sous fonction d'insert
Arbre alloc(int val)
{
	Arbre nouve_arbre=(Arbre) malloc(sizeof(Noeud));
	nouve_arbre->combien=1;
	nouve_arbre->ad=NULL;
	nouve_arbre->ag=NULL;
	nouve_arbre->val=val;
	nouve_arbre->hd=0;
	nouve_arbre->hg=0;
	return nouve_arbre;
}

Arbre insert(int val, Arbre a)
{
	//Insertion triviale
	if(a==NULL)
	{
		Arbre nouve=alloc(val);
		return nouve;
	}

	//Declaration du tab d'ancêtre
	Ancetre *tab;
	int taille;
	if(val>a->val)
	{
		Ancetre localtab[a->hd];
		taille=a->hd;
		tab=localtab;
	}
	else if(val<a->val)
	{
		Ancetre localtab[a->hg];
		taille=a->hg;
		tab=localtab;
	}

	//Parcours de l'arbre
	Arbre position=a,last=a;
	int hauteur_insertion=0;
	while(position!=NULL)
	{
		last=position;
		if(val==position->val)
		{
			position->combien++;
			return a;
		}

		else if(val>position->val)
		{
			tab[hauteur_insertion].ancetre=position;
			tab[hauteur_insertion].direction=1;
			position=position->ad;
			hauteur_insertion++;
		}
		else if(val<position->val)
		{
			tab[hauteur_insertion].ancetre=position;
			tab[hauteur_insertion].direction=-1;
			position=position->ag;
			hauteur_insertion++;
		}
	}
	Arbre nouve=alloc(val);
	if(val>last->val)
	{
		last->ad=nouve;
	}
	else if(val<last->val)
	{
		last->ag=nouve;
	}

	//Rééquilibrage
	int i=taille;
	for(i=taille-1;i>=0;i--)
	{
		//if(desec)... Reprendre le boulot ici
	}
	return a;
}

#include "collection.h"
#include <cstdio>
#include <iostream>

int main()
{
    Collection arbre;

    //arbre1 -- insertion des éléments de 0 à 19 (montre les fonctionnalité: MAJcouleur et les rotations) pour l'arbre rouge noir
    arbre.insererElement(0); 
    arbre.insererElement(1);
    arbre.insererElement(2);
    arbre.insererElement(3);
    arbre.insererElement(4);
    arbre.insererElement(5);
    arbre.insererElement(6);
    arbre.insererElement(7);
    arbre.insererElement(8);
    arbre.insererElement(9);
    arbre.insererElement(10);
    arbre.insererElement(11);
    arbre.insererElement(12);
    arbre.insererElement(13);
    arbre.insererElement(14);
    arbre.insererElement(15);
    arbre.insererElement(16);
    arbre.insererElement(17);
    arbre.insererElement(18);
    arbre.insererElement(19);

    Collection arbre2;
    
    //arbre2 -- montre l'affichage de la fonctionnalité double rotation droite + une rotation gauche pour l'arbre rouge noir
    arbre2.insererElement(500);
    arbre2.insererElement(250);
    arbre2.insererElement(350);
    arbre2.insererElement(600);
    arbre2.insererElement(700); 

    Collection arbre3;

    //arbre3 -- montre l'affichage et les fonctionnalités de l'ABR
    arbre3.insererElement(26);
    arbre3.insererElement(17);
    arbre3.insererElement(41);
    arbre3.insererElement(14);
    arbre3.insererElement(21);
    arbre3.insererElement(30);
    arbre3.insererElement(47);
    arbre3.insererElement(9);
    arbre3.insererElement(12);
    arbre3.insererElement(5);

    arbre.affichage();
    std::cout<<std::endl;
    arbre.recherche(5,true);
    arbre.recherche(28,true);
    std::cout<<std::endl;
    arbre2.affichage();
    std::cout<<std::endl;
    arbre3.affichage();
    std::cout<<std::endl;
    arbre3.recherche(47,true);
    arbre3.recherche(100,true);

}
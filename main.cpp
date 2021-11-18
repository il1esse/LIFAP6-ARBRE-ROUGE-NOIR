#include "element.h"
#include "anr.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    ANR arbre;
    arbre.insererElement(0);
    arbre.insererElement(1);
    arbre.insererElement(2);
    arbre.insererElement(3);
    arbre.insererElement(4);
    arbre.insererElement(5);
    arbre.insererElement(6);
    arbre.insererElement(7);
    arbre.insererElement(8);
    //arbre.insererElement(9);
    //arbre.insererElement(10);
    //arbre.insererElement(11);
    //arbre.insererElement(12);
    //arbre.insererElement(13);
    //arbre.insererElement(14);
    //arbre.insererElement(15);
    //arbre.insererElement(16);
    //arbre.insererElement(17);
    //arbre.insererElement(18);
    //arbre.insererElement(19);


    
    //arbre.insererElement(0);
    //arbre.insererElement(10);
    //arbre.insererElement(8);

    /*arbre.insererElement(4);
    arbre.insererElement(3);
    arbre.insererElement(1);
    arbre.insererElement(6);
    //arbre.insererElement(7);
    arbre.insererElement(5);
    //arbre.insererElement(2);

    //arbre.insererElement(6);*/


    arbre.affichage();
    return 0;
}
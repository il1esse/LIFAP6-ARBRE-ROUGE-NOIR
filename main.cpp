#include "element.h"
#include "anr.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    ANR arbre;
    arbre.insererElement(0);
    //arbre.insererElement(5);
    arbre.insererElement(10);
    arbre.insererElement(8);
    //arbre.insererElement(15);
    //arbre.insererElement(11);
    //arbre.insererElement(5);
    //arbre.insererElement(6);


    arbre.affichage();
    return 0;
}
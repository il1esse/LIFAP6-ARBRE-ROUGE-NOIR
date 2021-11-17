#include "element.h"
#include "anr.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    ANR arbre;
    arbre.insererElement(5);
    arbre.insererElement(6);
    //arbre.insererElement(4);
    arbre.insererElement(7);
    arbre.insererElement(8);
    //arbre.insererElement(3);
    arbre.affichage();
    return 0;
}
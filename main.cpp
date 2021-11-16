#include "element.h"
#include "abr.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    ABR arbre;
    arbre.insererElement(10);
    arbre.insererElement(7);
    arbre.insererElement(15);
    arbre.insererElement(3);
    arbre.insererElement(12);
    arbre.insererElement(24);
    arbre.insererElement(11);
    arbre.insererElement(13);
    arbre.affichage();
    arbre.recherche(24);
    return 0;
}
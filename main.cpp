#include "element.h"
#include "anr.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    ANR arbre;
    arbre.insererElement(10);
    arbre.insererElement(7);
    arbre.insererElement(15);
    arbre.insererElement(3);
    arbre.insererElement(12);
    arbre.insererElement(24);
    arbre.insererElement(11);
    arbre.insererElement(13);
    arbre.affichage();
    return 0;
}
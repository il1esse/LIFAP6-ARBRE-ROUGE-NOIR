#include "abr.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{

    ABR arbre1;

    arbre1.insererElement(1);
    
    arbre1.insererElement(3);
    arbre1.insererElement(6);
    arbre1.insererElement(7);
    arbre1.insererElement(5);
    arbre1.insererElement(2);

    arbre1.affichage();
    arbre1.recherche(6);
    arbre1.recherche(12);
    
}
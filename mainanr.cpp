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

    /*arbre.insererElement(690);
    arbre.insererElement(59);
    arbre.insererElement(926);
    arbre.insererElement(540);
    arbre.insererElement(426);*/
    //arbre.insererElement(172);

    /*arbre.insererElement(500);
    arbre.insererElement(400);
    arbre.insererElement(600);
    arbre.insererElement(550);
    arbre.insererElement(575);*/
    //arbre.insererElement(172);
   

    
    /*arbre.insererElement(0);
    arbre.insererElement(10);
    arbre.insererElement(8);*/

    /*arbre.insererElement(50);
    arbre.insererElement(30);    
    arbre.insererElement(20);
    arbre.insererElement(10);
    arbre.insererElement(60);
    arbre.insererElement(40); 
    arbre.insererElement(9);
    arbre.insererElement(61);  
    arbre.insererElement(58);*/
    //arbre.insererElement(63);
    //arbre.insererElement(62);

    //arbre.insererElement(59);              
    //arbre.insererElement(7);
    //arbre.insererElement(5);
    //arbre.insererElement(2);

    //arbre.insererElement(6);*/

    /*arbre.insererElement(10);
    arbre.insererElement(383);
    arbre.insererElement(886);
    arbre.insererElement(777);
    arbre.insererElement(800);
    arbre.insererElement(915);*/
    /*arbre.insererElement(793);
    arbre.insererElement(335);
    arbre.insererElement(386);*/

    arbre.affichage();
    arbre.recherche(5);
    arbre.recherche(12);
    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iostream>
#include "element.h"
#include<vector>
//#include "abr.h"
#include "anr.h"
#include "string.h"
#include <fstream> 



int perf(int nbinsertion)
{
    int nbarbre = 1, i, j;
    ANR arbre;
    ANR bonjour[nbarbre];
    //ABR * tab[nbSkipList];


    for (i = 0; i < nbarbre; i++)
    { 
        
        bonjour[i] = arbre;

    }

    std::chrono::time_point<std::chrono::system_clock> start, end;

    int tabmesure[nbarbre];
    for (int i =0; i<nbarbre;i++)
    { 
        start = std::chrono::system_clock::now();
        for (j = 0; j < nbinsertion; j++)
            arbre.insererElement(rand()%1000);
            
        end = std::chrono::system_clock::now();
        tabmesure[i] = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }
        
    int sommemesure =0;
    for (int i =0; i<nbarbre;i++)
    {
        sommemesure = sommemesure +tabmesure[i];
    }

    int moyennemesure = sommemesure / nbarbre;
    

    std::cout << "Temps d'insertion moyen : " << moyennemesure << "ms" << std::endl;
    return moyennemesure;
}

void ecrireFichierEntiers(const char * nomFichier,int nbinsertionmax)
//preconditions : nomFichier chaine de caracteres designant le nom du fichier a creer
//postcondition : le fichier nomFichier contient nb entiers separes par des espaces
{
std::ofstream ofs;
 ofs.open(nomFichier);
if(ofs.bad()) 
    {std::cout<<"Impossible d'ouvrir le fichier "<<nomFichier<<" en ecriture \n"; exit(1);}

else
{   
    //ofs<<"# nbinsertion"<<"  "<<"temps moyen"<<std::endl;
    for(int i=0; i<=10;i++)
    {
        int a = perf(nbinsertionmax/10 * i);
        ofs<<nbinsertionmax/10*i<<"  "<<a<<std::endl;
    }
}

ofs.close();
}





int main()
{
    int nbinsertionmax;
    std::cout<<"Cb d'insertion max voulez vous faire ?"<<std::endl;
    std::cin>>nbinsertionmax;

    //int moyennemesure = perf(i);
    ecrireFichierEntiers("performance",nbinsertionmax);

    return 0;
}
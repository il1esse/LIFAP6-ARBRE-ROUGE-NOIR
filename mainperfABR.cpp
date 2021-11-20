#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iostream>
#include "element.h"
#include<vector>
#include "abr.h"
//#include "anr.h"
#include "string.h"
#include <fstream> 



void perf(const char * nomFichier,int nbinsertion)
{
    std::ofstream ofs;
    ofs.open(nomFichier);
if(ofs.bad()) 
    {std::cout<<"Impossible d'ouvrir le fichier "<<nomFichier<<" en ecriture \n"; exit(1);}

else
{
    int nbarbre = 10;
    ABR arbre;
    //ABR bonjour[nbarbre];
    //ABR * tab[nbSkipList];

    std::chrono::time_point<std::chrono::system_clock> start, end;

    int tabmesure[nbarbre];
    for (int i =0; i<nbinsertion;i++)
    { 
        //ABR arbre;
        int sommemesure =0;
        for (int j = 1; j <= nbarbre; j++)
        {
            start = std::chrono::system_clock::now();
            int r=rand()%1000;
            std::cout<<r<<std::endl;
            arbre.insererElement(r);
            end = std::chrono::system_clock::now();
            tabmesure[j] = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
            sommemesure = sommemesure +tabmesure[j];
            
        }  
        
        int moyennemesure = sommemesure / nbarbre;
        
        //std::cout<<i<<tabmesure[i]<<std::endl;
        
        

    
        ofs<<i<<"  "<<moyennemesure<<std::endl;
    }
        
    
    

    //std::cout << "Temps d'insertion moyen : " << moyennemesure << "ms" << std::endl;
    
ofs.close();
}
    
}




int main()
{
    int nbinsertionmax;
    std::cout<<"Cb d'insertion max voulez vous faire ?"<<std::endl;
    std::cin>>nbinsertionmax;

    //int moyennemesure = perf(i);
    perf("performance",nbinsertionmax);

    return 0;
}
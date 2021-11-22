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



void perfinsertionANR(const char * nomFichier,int nbinsertion)
{
    std::ofstream ofs;
    ofs.open(nomFichier);
    if(ofs.bad()) 
        {std::cout<<"Impossible d'ouvrir le fichier "<<nomFichier<<" en ecriture \n"; exit(1);}

    else
    {
        int nbarbre = 1000;
        ANR arbreANR[nbarbre];

        std::chrono::time_point<std::chrono::system_clock> start, end;

        float mesure;
        for (int i =0; i<nbinsertion;i++)
        { 
            start = std::chrono::system_clock::now();
            for (int j = 0; j < nbarbre; j++)
            {
                
                int r=rand()%1000;
                //std::cout<<r<<std::endl;
                
                arbreANR[j].insererElement(r);
                //arbreANR[j].affichage();
            }  
            end = std::chrono::system_clock::now();
            mesure = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); 
            float moyennemesure = mesure / nbarbre;
            
            //std::cout<<i<<tabmesure[i]<<std::endl;

            ofs<<i<<"  "<<moyennemesure<<std::endl;
        }
        //std::cout << "Temps d'insertion moyen : " << moyennemesure << "ms" << std::endl;
        
    ofs.close();
    }
}

void perfrechercheANR(const char * nomFichier,int nbinsertion)
{
    std::ofstream ofs;
    ofs.open(nomFichier);
    if(ofs.bad()) 
        {std::cout<<"Impossible d'ouvrir le fichier "<<nomFichier<<" en ecriture \n"; exit(1);}

    else
    {
        int nbarbre = 1000;
        ANR arbreANR[nbarbre];

        std::chrono::time_point<std::chrono::system_clock> start, end;

        float mesure;
        for (int i =0; i<nbinsertion;i++)
        { 
           
            for (int j = 0; j < nbarbre; j++)
            {
                
                int r=rand()%1000;
                //std::cout<<r<<std::endl;
                
                arbreANR[j].insererElement(r);
                //arbreANR[j].affichage();
            }  
            
            start = std::chrono::system_clock::now();
            for(int k=0;k<nbarbre;k++)
            {
                int r2=rand()%1000;
                arbreANR[k].recherche(r2);
            }
            end = std::chrono::system_clock::now();
            mesure = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); 
            float moyennemesure = mesure / nbarbre;
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
    
    perfinsertionANR("performance_insertion_ANR",nbinsertionmax);
    perfrechercheANR("performance_recherche_ANR",nbinsertionmax);

    return 0;
}
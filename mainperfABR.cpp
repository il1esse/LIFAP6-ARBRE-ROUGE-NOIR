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



void perfinsertion(const char * nomFichier,int nbinsertion)
{
    std::ofstream ofs;
    ofs.open(nomFichier);
    if(ofs.bad()) 
        {std::cout<<"Impossible d'ouvrir le fichier "<<nomFichier<<" en ecriture \n"; exit(1);}

    else
    {
        int nbarbre = 1000;
        ABR bonjour[nbarbre];

        std::chrono::time_point<std::chrono::system_clock> start, end;

        float mesure;
        for (int i =0; i<nbinsertion;i++)
        { 
            start = std::chrono::system_clock::now();
            for (int j = 0; j < nbarbre; j++)
            {
                
                int r=rand()%1000;
                //std::cout<<r<<std::endl;
                
                bonjour[j].insererElement(r);
                /*bonjour[j].affichage();
                std::cout<<std::endl;
                std::cout<<std::endl;
                std::cout<<std::endl;*/
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

void perfrecherche(const char * nomFichier,int nbinsertion)
{
    std::ofstream ofs;
    ofs.open(nomFichier);
    if(ofs.bad()) 
        {std::cout<<"Impossible d'ouvrir le fichier "<<nomFichier<<" en ecriture \n"; exit(1);}

    else
    {
        int nbarbre = 1000;
        ABR bonjour[nbarbre];

        std::chrono::time_point<std::chrono::system_clock> start, end;

        float mesure;
        for (int i =0; i<nbinsertion;i++)
        { 
           
            for (int j = 0; j < nbarbre; j++)
            {
                
                int r=rand()%1000;
                //std::cout<<r<<std::endl;
                
                bonjour[j].insererElement(r);
                
                /*bonjour[j].affichage();
                std::cout<<std::endl;
                std::cout<<std::endl;
                std::cout<<std::endl;*/
            }  
            
            start = std::chrono::system_clock::now();
            for(int k=0;k<nbarbre;k++)
                {
                    int r2=rand()%1000;
                    bonjour[k].recherche(r2);
                }
            //std::cout<<i<<tabmesure[i]<<std::endl;
            end = std::chrono::system_clock::now();
            mesure = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); 
            float moyennemesure = mesure / nbarbre;
            ofs<<i<<"  "<<moyennemesure<<std::endl;
        }
        //std::cout << "Temps d'insertion moyen : " << moyennemesure << "ms" << std::endl;
        
    ofs.close();
    }
        
    }


int main()
{
    int nbinsertionmax;
    //std::cout<<"Cb d'insertion max voulez vous faire ?"<<std::endl;
    //std::cin>>nbinsertionmax;

    nbinsertionmax=4500;
    //int moyennemesure = perf(i);
    perfinsertion("performance_recherche_ABR",nbinsertionmax);

    return 0;
}
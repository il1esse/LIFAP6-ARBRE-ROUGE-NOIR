#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iostream>
#include "element.h"
#include "anr.h"
#include "string.h"
#include <fstream> 



void perfinsertionANR(const char * nomFichier,int nbinsertion) //procédure de calcul de la performance d'insertion pour les arbres rouges noirs
{
    std::ofstream ofs;
    ofs.open(nomFichier); //on ouvre le fichier précisé en paramètre
    if(ofs.bad())  //si on arrive pas à ouvrir le fichier on affiche impossible à ouvrir
    {
        std::cout<<"Impossible d'ouvrir le fichier "<<nomFichier<<" en ecriture \n"; exit(1);
    }
    else
    {
        int nbarbre = 1000; //on initialise le nombre d'arbre à 1000
        ANR arbreANR[nbarbre];//on crée un tableau d'arbre ANR

        std::chrono::time_point<std::chrono::system_clock> start, end;// on définit les variables de chrono start et end

        float mesure;
        for (int i =0; i<nbinsertion;i++)//boucle for pour chaque insertion d'élément
        { 
            start = std::chrono::system_clock::now();// on stocke dans start l'heure actuelle
            for (int j = 0; j < nbarbre; j++)//boucle for pour insérer un élément dans tous les arbres
            {
                
                int r=rand()%1000;//on stocke dans la variable r un entier aléatoire entre 0 et 1000
                arbreANR[j].insererElement(r);// puis on l'insère dans un arbre

            }  
            end = std::chrono::system_clock::now();// on stocke  dans end l'heure actuelle
            mesure = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();  // on stock dans mesure la différence de end et start en nanosecondes
            float moyennemesure = mesure / nbarbre; //on fait la moyenne du temps obtenu pour insérer les éléments dans chaque arbre 

            ofs<<i<<"  "<<moyennemesure<<std::endl; //puis on insère dans le fichier le nombre d'élément déjà insérer et le temps moyen qu'insérer un nouveau élément à pris
        }
    ofs.close();//et enfin on ferme le fichier
    }
}

void perfrechercheANR(const char * nomFichier,int nbinsertion) //procédure de calcul de la performance de recherche pour les arbres rouges noirs
{
    std::ofstream ofs;
    ofs.open(nomFichier);//on ouvre le fichier précisé en paramètre
    if(ofs.bad()) //si on arrive pas à ouvrir le fichier on affiche impossible à ouvrir
    {
        std::cout<<"Impossible d'ouvrir le fichier "<<nomFichier<<" en ecriture \n"; exit(1);
    }
    else
    {
        int nbarbre = 1000; //on initialise le nombre d'arbre à 1000
        ANR arbreANR[nbarbre]; //on crée un tableau d'arbre ANR

        std::chrono::time_point<std::chrono::system_clock> start, end; // on définit les variables de chrono start et end

        float mesure;
        for (int i =0; i<nbinsertion;i++) //boucle for pour chaque insertion d'élément
        { 
            for (int j = 0; j < nbarbre; j++)  //boucle for pour insérer un élément dans tous les arbres
            {
                int r=rand()%1000; //on stocke dans la variable r un entier aléatoire entre 0 et 1000
                arbreANR[j].insererElement(r); // puis on l'insère dans un arbre
            }  
            
            start = std::chrono::system_clock::now(); // on stocke dans start l'heure actuelle
            for(int k=0;k<nbarbre;k++) //boucle for pour passer d'arbre en arbre
            {
                int r2=rand()%1000; //on stocke dans la variable r2 un entier aléatoire entre 0 et 1000
                arbreANR[k].recherche(r2,false); //on cherche l'entier r2 dans l'abre k
            }
            end = std::chrono::system_clock::now(); // on stocke  dans end l'heure actuelle
            mesure = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();  // on stock dans mesure la différence de end et start en nanosecondes
            float moyennemesure = mesure / nbarbre; //on fait la moyenne du temps obtenu pour insérer les éléments dans chaque arbre 
            ofs<<i<<"  "<<moyennemesure<<std::endl; //puis on insère dans le fichier le nombre d'élément déjà insérer et le temps moyen qu'insérer un nouveau élément à pris
        }
    }     
    ofs.close(); //et enfin on ferme le fichier
}


int main()
{
    int nbinsertionmax=5000;

    perfinsertionANR("data/performance_insertion_ANR.txt",nbinsertionmax);
    perfrechercheANR("data/performance_recherche_ANR.txt",nbinsertionmax);

    return 0;
}
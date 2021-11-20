#include "abr.h"
#include <iostream>
#include <fstream> //ifstream, ofstream

Noeud::Noeud(Elem e)
{
    info = e;
    fg = nullptr;
    fd = nullptr;
}

Noeud::~Noeud(){
    if(fd != nullptr) delete fd;
    if(fg != nullptr) delete fg;
}

ABR::ABR()
{
    adracine = nullptr;
    nbelem = 0;
}

void ABR::insererElement(const Elem & e)
{
    inseressArbre(adracine, e);
    nbelem++;
}

void ABR::inseressArbre(Noeud* &a,const Elem & e)
{

    if(a == nullptr)
    {
        a = new Noeud(e);
    }
    else 
    if(a->info > e)
    {
        inseressArbre(a->fd , e);

    }
    else
    {
        inseressArbre(a->fg , e);
    }
}

void ABR::affichage()
{
    //RotationDroite(adracine,adracine->fd);
    //affichessArbre(adracine);
    AfficherInfixe(adracine,1);
}

void ABR::affichessArbre(Noeud* &a)
{   
    if(a != nullptr)
    {
        if(a->fg !=nullptr && a->fd !=nullptr)
        std::cout<<"    "<<a->fg->info<<"   "<<a->fd->info<<"   "<<std::endl;
        else if(a->fg !=nullptr)
        std::cout<<"    "<<a->fg->info<<"   ";
        else if(a->fd !=nullptr)
        std::cout<<"    "<<a->fd->info<<"   "<<std::endl;
        affichessArbre(a->fg);
        affichessArbre(a->fd);
    }
}

void ABR::AfficherInfixe (Noeud *n, int nbespace) const
{
    if(n != nullptr)
    {
        AfficherInfixe(n->fg, nbespace+5);
        std::cout<<std::endl;
        for(int i=0; i<nbespace;i++)
            std::cout<<" ";
        afficheElement(n->info);
        std::cout<<std::endl;
        AfficherInfixe(n->fd, nbespace+5);
    }
}



bool ABR::recherche(const Elem & e)
{
    bool a =recherchessarbre(adracine,e);
    //std::cout<<adracine->info<<std::endl;
    std::cout<<a<<std::endl;
    return a;
    
}

bool ABR::recherchessarbre(Noeud* &a, const Elem &e)
{
    /*if(a->info == e)
    {
        return true;
    }
    else 
    {
        recherchessarbre(a->fd,e);
        recherchessarbre(a->fg,e);
    }
    return false;*/

    if(a == nullptr)
    {
        return false;
    }
    else if (a->info == e)
    {
        return true;
    }
    else if(a->info > e)
    {
        recherchessarbre(a->fd,e);
        
    }
    else
    {
         recherchessarbre(a->fg,e);
    }
       
}

void ABR::creeFichierEntiers(const char * nomFichier, int nb)
//preconditions : nomFichier chaine de caracteres designant le nom du fichier a creer
//postcondition : le fichier nomFichier contient nb entiers separes par des espaces
{
std::ofstream ofs;
 ofs.open(nomFichier);
if(ofs.bad()) 
    {std::cout<<"Impossible d'ouvrir le fichier "<<nomFichier<<" en ecriture \n"; exit(1);}

for(int i=0;i<nb;i++)
 {
    int temp;
    std::cout << "Entier suivant : ";
    std::cin >> temp; //Ou utilisez la version robuste de saisie d'un int
     ofs << temp <<' ';//Remarquez que l'on separe les int par des espaces
    }
ofs.close();
}
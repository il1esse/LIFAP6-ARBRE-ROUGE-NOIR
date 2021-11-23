#include "abr.h"
#include <iostream>
#include <fstream> //ifstream, ofstream

Noeud::Noeud(Elem e) //constructeur noeud qui donne l'element e à l'info, initialise son fils droit et gauche à nullptr
{
    info = e;
    fg = nullptr;
    fd = nullptr;
}

Noeud::~Noeud() //destructeur de noeud
{
    if(fd != nullptr) delete fd;
    if(fg != nullptr) delete fg;
}

ABR::ABR() //constructeur arbre, initialise la racine à nullptr et le nombre d'élément à zéro
{
    adracine = nullptr;
    nbelem = 0;
}

void ABR::insererElement(const Elem & e) //procédure qui appelle insérerssarbre
{
    inseressArbre(adracine, e);
    nbelem++;
}

void ABR::inseressArbre(Noeud* &a,const Elem & e)
{

    if(a == nullptr) //si l'arbre est vide ou on se trouve en bout d'arbre alors on creer un nouveau noeud avec l'élément à insérer
    {
        a = new Noeud(e);
    }
    else if(a->info > e) //si l'info du noeud sur lequel on se trouve est plus grand que l'élément à insérer on relance la procédure sur son fils gauche
    {
        inseressArbre(a->fg , e);

    }
    else if(a->info < e) //si l'info du noeud sur lequel on se trouve est plus petit que l'élément à insérer on relance la procédure sur son fils droit
    {
        inseressArbre(a->fd , e);
    }
}

void ABR::affichage() //procédure d'affichage qui appelle la afficherinfixe
{
    AfficherInfixe(adracine,1);
}

void ABR::AfficherInfixe (Noeud *n, int nbespace) const
{
    if(n != nullptr)
    {
        AfficherInfixe(n->fd, nbespace+5);
        std::cout<<std::endl;
        for(int i=0; i<nbespace;i++)
            std::cout<<" ";
        afficheElement(n->info);
        std::cout<<std::endl;
        AfficherInfixe(n->fg, nbespace+5);
    }
}



bool ABR::recherche(const Elem & e,bool affichage) //procédure de recherche qui utilise recherchessarbre
{
    bool a =recherchessarbre(adracine,e);
    if(affichage == true)
    {
       if(a==true)
        {
            std::cout<<"élément : "<<e<<" trouvé"<<std::endl;
        }
        else
        {
            std::cout<<"élément : "<<e<<" introuvable"<<std::endl;
        } 
    }

    return a;
}

bool ABR::recherchessarbre(Noeud* &a, const Elem &e) //procédure de recherche
{
    if(a == nullptr) //si l'arbre est vide on retourne faux
    {
        return false;
    }
    else if (a->info == e) //si l'info du noeud sur lequel on se trouve est égal à l'élément recherché alors on retourne vrai
    {
        return true;
    }
    else if(a->info > e) //sinon si l'info est plus grande ou relance la fonction de recherche sur le fils gauche
    {
        
        return recherchessarbre(a->fg,e);
        
    }
    else//sinon on la relance sur le fils droit
    {
         return recherchessarbre(a->fd,e);
    }
}
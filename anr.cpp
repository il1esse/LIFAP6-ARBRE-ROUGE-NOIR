#include "abr.h"
#include <iostream>

Noeud::Noeud(Elem e)
{
    info = e;
    fg = nullptr;
    fd = nullptr;
    c = Rouge;
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

int ABR::inseressArbre(Noeud* &a,const Elem & e)
{

    int res;
    if(a == nullptr)
    {
        a = new Noeud(e);
        return 1;
    }
    else 
    if(a->info > e)
    {
        res = inseressArbre(a->fg , e);
        /*quand on insere on visite plein de pointeurs sur le chemin d'insertion
        a est le pointeur qui est situé un étage au dessus (dans le chemin) au dessus ce celui sur lequel on vient de faire un appel récursif

        si a pointe sur un Noeud qui est grand pere d'un cas pathologique?
        Si oui on fait ce quil y a à faire*/
        return res+1;

    }
    else
    {
        inseressArbre(a->fd , e);
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
        std::cout<<" C=";
        afficheElement(n->c);
        std::cout<<std::endl;
        AfficherInfixe(n->fd, nbespace+5);
    }
}

void ABR::RotationDroite(Noeud * & pn) // on travaille ici dans l'arbre *this
{
    //cout << nbelem // this->nbelm
    Noeud *pt;
    pt = pn -> fg;
    pn->fg = pt -> fd;
    pt -> fd = pn;
    pn = pt;
}

void ABR::MAJcouleur(Noeud &n)
{
}


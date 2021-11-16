#include "anr.h"
#include <iostream>

Noeud::Noeud(Elem e)
{
    info = e;
    fg = nullptr;
    fd = nullptr;
    c = 1;
}

ANR::ANR()
{
    adracine = nullptr;
    nbelem = 0;
}

void ANR::insererElement(const Elem & e)
{
    inseressArbre(adracine, e);
    nbelem++;
}

int ANR::inseressArbre(Noeud* &a,const Elem & e)
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
        
        if(res==1)
            if (a->c=1)
                return 2;
        if(res==2)
            if (a->fd->c=1)

                return 1;


    }
    else
    {
        inseressArbre(a->fd , e);
    }
}

void ANR::affichage()
{
    //RotationDroite(adracine,adracine->fd);
    //affichessArbre(adracine);
    AfficherInfixe(adracine,1);
}

void ANR::affichessArbre(Noeud* &a)
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

void ANR::AfficherInfixe (Noeud *n, int nbespace) const
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

void ANR::RotationDroite(Noeud * &a,Noeud * pn) // on travaille ici dans l'arbre *this
{
    //cout << nbelem // this->nbelm
    Noeud *pt;
    pt = pn -> fg;
    pn->fg = pt -> fd;
    pt -> fd = pn;
    pn = pt;
}

void ANR::MAJcouleur(Noeud &n)
{
}


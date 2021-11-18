#include "abr.h"
#include <iostream>

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
    std::cout<<adracine->info;
    std::cout<<a;
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
    else
    {
        recherchessarbre(a->fd,e);
        recherchessarbre(a->fg,e);
    }
}
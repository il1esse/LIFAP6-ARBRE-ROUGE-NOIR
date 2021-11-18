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
    int res=inseressArbre(adracine, e);
    
    if(res==3)
    {
        if (adracine->fg->fd != nullptr)
        {
            if(adracine->fg->fd->info == e)
            {
                RotationGauche(adracine->fg);
                RotationDroite(adracine);
            }
            
            
        }
        else
        RotationDroite(adracine);
    }

    if(res==4)
    {
        if (adracine->fd->fg != nullptr) //(adracine->fd->fg != nullptr) cas 0108 ---(en cours cas cours)
        {
            if(adracine->fd->fg->info == e)
            {
                RotationDroite(adracine->fd);
                RotationGauche(adracine);
                
            }
        }
        else
        {
            RotationGauche(adracine);
        }
            
    }
    nbelem++;
}

int ANR::inseressArbre(Noeud* &a,const Elem & e)
{
    int res;
    if(a == nullptr)  //INSERTION ELEMENT
    {
        a = new Noeud(e);
        if(nbelem == 0) 
        {
            a->c=0;
        }
        return 1;
    }
    
    else if(a->info > e) 
    {
        res = inseressArbre(a->fg , e);
        
        if(res==1 && (a->c)==1) //SI MON FILS EST ROUGE ET QUE JE SUIS ROUGE JE RETURN 2
        {
                return 2;
        }

        if(res==2) //SI MON FILS ET PETIT FILS SONT ROUGE ( COTE GAUCHE)
        {
            if(a->fd != nullptr) //SI MON FILS DROIT EXISTE
            {
                if((a->fd->c)==1) //ET IL EST ROUGE
                {
                        MAJcouleur(a); // ALORS MES 2 FILS DEVIENNENT NOIR MON PETIT FILS RESTE ROUGE ET JE DEVIENS ROUGE
                        return 1;
                }
            }
            if(a->fd == nullptr || (a->fd->c)==0) //SI MON FILS DROIT NEXISTE PAS OU QUIL EST DE COULEUR NOIR ALORS JE RETURN 3
            {
                return 3; 
                //RotationDroite(a->fg);
            }
        }

        if(res==3) //(ARRIERE GRAND PERE) SI MON FILS N'A PAS DE FILS DROIT OU QUIL EST NOIR ALORS JE TOURNE A GAUCHE AVEC MON PETIT FILS 
        //DROITE AVEC MON FILS
        {
            if(a->fg->fg->fd != nullptr)
                {
                    if(a->fg->fg->fd->info ==e) 
                    {
                        RotationGaucheDouble(a->fg->fg);
                        RotationDroite(a->fg);
                    }
                    
                }
            else
            {
                RotationDroite(a->fg);

            }
        }

    }
    else //si l'info du noeud est plus petit que l'element que l'on veut insérer
    {
        res = inseressArbre(a->fd , e);

        if(res==1 && (a->c)==1)
        {
                return 2;
        }

        if(res==2)
        {
            if(a->fg != nullptr)
            {
                if((a->fg->c)==1)
                {
                        MAJcouleur(a);
                        return 1;
                }
            }
            if(a->fg == nullptr || (a->fg->c)==0)
            {
                return 4; 
                //RotationGauche(a);  
            }
        }

        if(res==4)
        {
            if(a->fd->fd->fg != nullptr)
            {
                if(a->fd->fd->fg->info == e)
                {
                    RotationDroite(a->fd->fd);
                    RotationGauche(a->fd);
                }
            }
            else
            {
                RotationGauche(a->fd);
            }
        
        
             
    }
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
        AfficherInfixe(n->fd, nbespace+5);
        std::cout<<std::endl;
        for(int i=0; i<nbespace;i++)
            std::cout<<" ";
        afficheElement(n->info);
        std::cout<<" C=";
        afficheElement(n->c);
        std::cout<<std::endl;
        AfficherInfixe(n->fg, nbespace+5);
    }
}

void ANR::RotationDroite(Noeud * &pn) // on travaille ici dans l'arbre *this
{
    //cout << nbelem // this->nbelm
    Noeud *pt;
    pt = pn -> fg;
    pn->fg = pt -> fd;
    pt -> fd = pn;
    pn = pt;
    pn->c=0;
    pn->fd->c=1;
}

void ANR::RotationDroiteDouble(Noeud * &pn) // on travaille ici dans l'arbre *this
{
    //cout << nbelem // this->nbelm
    Noeud *pt;
    pt = pn -> fg;
    //pn->fg = pt -> fd;
    pt -> fd = pn;
    pn = pt;
    pn->c=0;
    pn->fd->c=1;
}

void ANR::RotationGauche(Noeud * &pn) // on travaille ici dans l'arbre *this
{
    //cout << nbelem // this->nbelm
    Noeud *pt;
    pt = pn -> fd;
    pn->fd = pt -> fg;
    pt -> fg = pn;
    pn = pt;
    pn->c=0;
    pn->fg->c=1;
}

void ANR::RotationGaucheDouble(Noeud * &pn) // on travaille ici dans l'arbre *this
{
    //cout << nbelem // this->nbelm
    Noeud *pt;
    pt = pn -> fd;
    //pn->fd = pt -> fg;
    pt -> fg = pn;
    pn = pt;
    pn->c=0;
    pn->fg->c=1;
}

void ANR::MAJcouleur(Noeud * &n)
{
    n->c=1;
    n->fd->c=0;
    n->fg->c=0;
}


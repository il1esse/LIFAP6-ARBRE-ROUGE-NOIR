#include "anr.h"
#include <iostream>

using namespace std;

Noeud::Noeud(Elem e)
{
    info = e;
    fg = nullptr;
    fd = nullptr;
    c = 1;
    diff = 0;
}

ANR::ANR()
{
    adracine = nullptr;
    nbelem = 0;

}

void ANR::insererElement(const Elem & e)
{
    int res=inseressArbre(adracine, e);

    if(res ==2)
        {
            if(adracine->info > e) 
            {
                if(adracine->fd != nullptr && adracine->fd->c == 1)//CAS 1
                {
                    MAJcouleur(adracine);
                }
                else if(adracine->fd == nullptr || (adracine->fd->c)==0) //CAS 2
                {
                    RotationDroite(adracine);
                }
                else if(adracine->fg->fd->info == e)
                {
                    RotationGauche(adracine->fg);
                    RotationDroite(adracine);
                }  
            }
            else if (adracine->info < e)
            {
                if(adracine->fg != nullptr && adracine->fg->c == 1)//CAS 3
                {
                    MAJcouleur(adracine);
                }
                else if(adracine->fg == nullptr || (adracine->fg->c)==0) //CAS 4
                {
                    RotationGauche(adracine);
                }
                else if(adracine->fd->fg->info == e)
                {
                    RotationDroite(adracine->fd);
                    RotationGauche(adracine);
                }
            }

        } 
        adracine->c=0;
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

        if(res ==2)
        {
            if(a->fd != nullptr && a->fd->c == 1)//CAS 1 a gauche
            {
                MAJcouleur(a);
                return 1;
            }
            else if((a->fd == nullptr || (a->fd->c)==0) && a->fg->fg !=nullptr) //CAS 2
            {
                RotationDroite(a);
            }
            else if((a->fd == nullptr || (a->fd->c)==0) && (a->fg->fd !=nullptr) && (a->fg->fd->info == e))//CAS3
            {
                RotationGauche(a->fg);
                RotationDroite(a);
            }
        }
    }
    else if (a->info < e)
    {
        res = inseressArbre(a->fd , e);
 
        if(res==1 && (a->c)==1) //SI MON FILS EST ROUGE ET QUE JE SUIS ROUGE JE RETURN 2
        {
                return 2;
        }

        if(res==2)
        {
            if(a->fg != nullptr && a->fg->c == 1)//CAS 1 a droite
            {
                MAJcouleur(a);
                return 1;
            }
            else if((a->fg == nullptr || (a->fg->c)==0) && (a->fd->fd !=nullptr) )//CAS 4
            {
                RotationGauche(a);
            }
            else if((a->fg == nullptr || (a->fg->c)==0) && (a->fd->fg !=nullptr) && (a->fd->fg->info == e))//CAS 5
            {
                RotationDroite(a->fd);
                RotationGauche(a);
            }
        }
    }
    
    
}

void ANR::affichage()
{
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
        //std::cout<<" diff=";
        //afficheElement(n->diff);
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

void ANR::MAJcouleur(Noeud * &n)
{
    n->c=1;
    n->fd->c=0;
    n->fg->c=0;
}

int ANR::Hauteurmin(Noeud *&n)
{
    int a;
    int b;
    int c;
    if(n != nullptr)
    {
        if(n->fg != nullptr)
        {
            if(n->fd == nullptr)
            {
                a = Hauteurmin(n->fg);
                return a + 1;
            }
            a = Hauteurmin(n->fg);
        }
        if(n->fd != nullptr)
        {
            if(n->fg == nullptr)
            {
                b = Hauteurmin(n->fd);
                return b + 1;
            }
            b = Hauteurmin(n->fd);
        }
        if((n->fg == nullptr) && (n->fd == nullptr))
        {
            return 1;
        }
        if(a>=b)
        {
            c = b;
        }
        else
        {
            c = a;
        }
        return 1 + c ;
    }
    else
    {
        return 0;
    }
}

void ANR::afficherhauteurmin(Noeud *&n)
{
    int b = Hauteurmin(n);
    std::cout<<"min : "<<b<<std::endl;;

}

int ANR::Hauteurmax(Noeud *&n)
{
    int a;
    int b;
    int c;
    if(n != nullptr)
    {
        if(n->fg != nullptr)
        {
            if(n->fd == nullptr)
            {
                a = Hauteurmax(n->fg);
                return a + 1;
            }
            a = Hauteurmax(n->fg);
        }
        if(n->fd != nullptr)
        {
            if(n->fg == nullptr)
            {
                b = Hauteurmax(n->fd);
                return b + 1;
            }
            b = Hauteurmax(n->fd);
        }
        if((n->fg == nullptr) && (n->fd == nullptr))
        {
            return 1;
        }
        if(a<=b)
        {
            c = b;
        }
        else
        {
            c = a;
        }
        return 1 + c ;
    }
    else
    {
        return 0;
    }
}

void ANR::afficherhauteurmax(Noeud *&n)
{
    int b = Hauteurmax(n);
    std::cout<<"max : "<<b<<std::endl;;
}

/*

int ANR::DiffHauteur(Noeud *&n)
{
    //std::cout<<Hauteurmax(adracine)<<std::endl;
    //std::cout<<Hauteurmin(adracine)<<std::endl;
    int h =Hauteurmax(adracine) - Hauteurmin(adracine);
    std::cout<<h<<std::endl;
    return h;
}

/*void ANR::Rotation_Double_Droite(Noeud *&pn)
{
    Noeud * pg;
    Noeud * pgd;

    pg = pn->fg;
    pgd = pn->fg->fd;
    pg->fd = pgd ->fg;
    pgd->fg = pg;
    pn->fg = pgd -> fd;
    pgd->fd = pn;
    pn = pgd;
}*/

/*
void ANR::equilibrer(Noeud *&pn)
{
    if(pn)
    {

    }
    if(pn->diff==2)
    {
        if(pn->fg->diff == 1)
        {
            RotationDroite(pn);
        }
        else
        {
            Rotation_Double_Droite(pn);
        }
    }
    else if(pn ->fd -> diff ==)
}
*/
/*
void ANR::DiffHauteur2(Noeud * &n)
{
    int h = Hauteurmax(adracine) - Hauteurmin(adracine);
    n->diff=h;

    if(n->fg != nullptr)
    {
        n->fg->diff=h;
        DiffHauteur2(n->fg);
    }
    if(n->fd != nullptr)
    {
        n->fd->diff=h;
        DiffHauteur2(n->fd);
    }
}

*/
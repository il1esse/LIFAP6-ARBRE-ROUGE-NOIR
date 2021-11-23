#include "anr.h"
#include <iostream>

using namespace std;

Noeud::Noeud(Elem e) //constructeur noeud qui donne l'element e à l'info, initialise son fils droit et gauche à nullptr et sa couleur à rouge
{
    info = e;
    fg = nullptr;
    fd = nullptr;
    c = 1;
}

ANR::ANR() //constructeur de arbre rouge noir, initialise la racine à nullptr et le nombre d'élément à zéro
{
    adracine = nullptr;
    nbelem = 0;

}

void ANR::insererElement(const Elem & e) //procédure d'insertion d'un élément dans un arbre, prend un élément en paramètre

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
    if(a == nullptr)  //insertion de l'element si on est en bout d'arbre ou si celui ci est vide
    {
        a = new Noeud(e);
        if(nbelem == 0) //si on se trouve à la racine, alors on met la couleur de l'élément inséré à noir
        {
            a->c=0;
        }
        return 1;
    }
    else if(a->info > e) //test pour savoir si l'élément à insérer est plus petit que l'info du noeud sur lequel on se trouve
    {
        res = inseressArbre(a->fg , e);//on rappelle la fonction insererssArbre sur le fils gauche car l'élément était plus petit que l'info du noeud
        //sur lequel on était
 
        if(res==1 && (a->c)==1) //Si mon fils est rouge et que je suis rouge je retourne 2
        {
                return 2;
        }

        if(res ==2) //Si mon fils est rouge et que je suis rouge
        {
            if(a->fd != nullptr && a->fd->c == 1) //CAS 1 (gauche), on regarde si l'élement insérer à un oncle et si celui ci est rouge
            {
                MAJcouleur(a); //si c'est le cas on fait simplement appel à la procédure MAJcouleur sur le grand père du cas pathologique
                //(grand père de l'element rouge qui a un père également rouge)
                return 1;
            }
            else if((a->fd == nullptr || (a->fd->c)==0) && a->fg->fg !=nullptr) //CAS 2 (gauche), si l'élément insérer n'a pas d'oncle ou que celui ci
            //est noir alors on fait une rotation à droite sur le grand père du cas pathologique 
            {
                RotationDroite(a);
            }
            else if((a->fd == nullptr || (a->fd->c)==0) && (a->fg->fd !=nullptr) && (a->fg->fd->info == e)) //CAS3, si l'élément insérer n'a pas d'oncle 
            // ou que celui ci est noir et qu'il se trouve à droite de la gauche alors on effectue une double rotation à droite
            //cad une rotation à gauche sur le père pathologique et une rotation à droite sur le grand père pathologique
            {
                RotationGauche(a->fg);
                RotationDroite(a);
            }
        }
    }
    else if (a->info < e) //test pour savoir si l'élément à insérer est plus grand que l'info du noeud sur lequel on se trouve
    {
        res = inseressArbre(a->fd , e); //on rappelle la fonction insererssArbre sur le fils droit car l'élément était plus grand que l'info du noeud
        //sur lequel on était
 
        if(res==1 && (a->c)==1) //Si mon fils est rouge et que je suis rouge je retourne 2
        {
                return 2;
        }

        if(res==2) //Si mon fils est rouge et que je suis rouge
        {
            if(a->fg != nullptr && a->fg->c == 1) //CAS 1 (droite), on regarde si l'élement insérer à un oncle et si celui ci est rouge
            {
                MAJcouleur(a); //si c'est le cas on fait simplement appel à la procédure MAJcouleur sur le grand père du cas pathologique
                //(grand père de l'element rouge qui a un père également rouge)
                return 1;
            }
            else if((a->fg == nullptr || (a->fg->c)==0) && (a->fd->fd !=nullptr) ) //CAS 4 (droite), si l'élément insérer n'a pas d'oncle ou que celui ci
            //est noir alors on fait une rotation à gauche sur le grand père du cas pathologique 
            {
                RotationGauche(a);
            }
            else if((a->fg == nullptr || (a->fg->c)==0) && (a->fd->fg !=nullptr) && (a->fd->fg->info == e)) //CAS 5, si l'élément insérer n'a pas d'oncle 
            // ou que celui ci est noir et qu'il se trouve à gauche de la droite alors on effectue une double rotation à gauche
            //cad une rotation à droite sur le père pathologique et une rotation à gauche sur le grand père pathologique
            {
                RotationDroite(a->fd);
                RotationGauche(a);
            }
        }
    }
    
    
}

void ANR::affichage() //procédure d'affichage qui fait appel à afficherinfixe
{
    AfficherInfixe(adracine,1);
}

void ANR::AfficherInfixe (Noeud *n, int nbespace) const //procédure d'affichage
{
    if(n != nullptr)
    {
        AfficherInfixe(n->fd, nbespace+5); //on appel la fonction afficherinfixe jusqu'à arriver sur le bout de l'arbre coté droit
        std::cout<<std::endl;
        for(int i=0; i<nbespace;i++)
            std::cout<<" ";
        afficheElement(n->info); //
        std::cout<<" C=";
        afficheElement(n->c);
        std::cout<<std::endl;
        AfficherInfixe(n->fg, nbespace+5);
    }
}

void ANR::RotationDroite(Noeud * &pn) //procédure de rotation droite
{
    Noeud *pt; //pointeur de travail pt
    pt = pn -> fg; //pt pointe sur le fils gauche du noeud
    pn->fg = pt -> fd; 
    pt -> fd = pn;
    pn = pt;
    pn->c=0;
    pn->fd->c=1;
}

void ANR::RotationGauche(Noeud * &pn)
{
    Noeud *pt; //pointeur de travail
    pt = pn -> fd;
    pn->fd = pt -> fg;
    pt -> fg = pn;
    pn = pt;
    pn->c=0;
    pn->fg->c=1;
}

void ANR::MAJcouleur(Noeud * &n) //procédure qui prend un noeud en paramètre
{
    n->c=1; //on change la couleur en rouge
    n->fd->c=0; //on met la couleur noir au fils droit du noeud en paramètre
    n->fg->c=0; // on met la couleur noir au fils gauche du noeud en paramètre
}

bool ANR::recherche(const Elem & e) //procédure qui appelle recherchessarbre
{
    bool a =recherchessarbre(adracine,e);
    return a;
}

bool ANR::recherchessarbre(Noeud* &a, const Elem &e) //procédure qui recherche l'élément e dans l'arbre en partant de la racine
{
    if(a == nullptr) //si l'arbre est vide alors on retourne faux car l'element n'est pas dans l'arbre
    {
        return false;
    }
    else if (a->info == e) //si l'info du noeud est égale à l'élément recherché alors on retourne vrai
    {
        return true;
    }
    else if(a->info > e) //si l'info du noeud est plus grande que l'élément recherché alors on appelle la procédure recherchessarbre sur le fils gauche
    {
        recherchessarbre(a->fg,e); 
    }
    else if(a->info < e) //si l'info du noeud est plus petite que l'élément recherché alors on appelle la procédure recherchessarbre sur le fils droit
    {
         recherchessarbre(a->fd,e);
    }
}

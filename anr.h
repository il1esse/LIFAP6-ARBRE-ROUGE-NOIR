#ifndef _ABR
#define _ABR

#include "element.h"

enum couleur{Rouge=0,Noir=1};

class Noeud
{
    friend class ABR;

    public :
    Noeud(Elem e);
    ~Noeud();
    

    private:
    Elem info;
    Noeud *fg;
    Noeud *fd;
    couleur c; 
};

class ABR
{
   
    public :
    ABR();
    //~ABR();
    
    void insererElement(const Elem & e);

    void affichage();

    void affichessArbre(Noeud* &a);

    private: 
    
    
    void inseressArbre(Noeud* &a,const Elem & e);

    void AfficherInfixe (Noeud *n, int nbespace) const;

    void RotationDroite(Noeud * &a,Noeud * p);

    void MAJcouleur();


    Noeud * adracine;
    
    int nbelem;
};
#endif
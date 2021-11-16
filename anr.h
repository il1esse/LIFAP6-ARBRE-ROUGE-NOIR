#ifndef _ANR
#define _ANR

#include "element.h"

enum couleur{Rouge=0,Noir=1};

class Noeud
{
    friend class ANR;

    public :
    Noeud(Elem e);
    ~Noeud();
    

    private:
    Elem info;
    Noeud *fg;
    Noeud *fd;
    int c; 
};

class ANR
{
   
    public :
    ANR();
    //~ANR();
    
    void insererElement(const Elem & e);

    void affichage();

    void affichessArbre(Noeud* &a);

    private: 
    
    
    int inseressArbre(Noeud* &a,const Elem & e);

    void AfficherInfixe (Noeud *n, int nbespace) const;

    void RotationDroite(Noeud * &a,Noeud * p);

    void MAJcouleur(Noeud &n);


    Noeud * adracine;
    
    int nbelem;
};
#endif
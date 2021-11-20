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
    int diff;
};

class ANR
{
   
    public :
    ANR();
    //~ANR();
    
    void insererElement(const Elem & e);

    void affichage();

    void affichessArbre(Noeud* &a);

    void afficherhauteurmin(Noeud *&n);
    void afficherhauteurmax(Noeud *&n);

    private: 
    
    
    int inseressArbre(Noeud* &a,const Elem & e);

    void AfficherInfixe (Noeud *n, int nbespace) const;

    void RotationDroite(Noeud* &pn);

    //void RotationDroiteDouble(Noeud * &pn);

    void RotationGauche(Noeud * &pn);

    //void RotationGaucheDouble(Noeud * &pn);

    void MAJcouleur(Noeud * &n);

    int Hauteurmin(Noeud *&n);
    int Hauteurmax(Noeud *&n);

/*
    int DiffHauteur(Noeud *&n);

    void equilibrer(Noeud *&pn);

    void Rotation_Double_Droite(Noeud *&pn);

    void DiffHauteur2(Noeud * &n); */

    Noeud * adracine;
    
    int nbelem;
};
#endif
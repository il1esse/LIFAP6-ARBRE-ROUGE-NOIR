#ifndef _ANR
#define _ANR

#include "element.h"

class NoeudANR
{
    friend class ANR;

    public :
    NoeudANR(Elem e);
    ~NoeudANR();
    

    private:
    Elem info;
    NoeudANR *fg;
    NoeudANR *fd;
    int c;
    int diff;
};

class ANR
{
    public :

    ANR();

    ~ANR();

    void insererElement(const Elem & e);

    void affichage();

    void affichessArbre(NoeudANR* &a);

    void detruire(NoeudANR* &a);

    bool recherche(const Elem & e,bool affichage);
    
    private: 
    
    int inseressArbre(NoeudANR* &a,const Elem & e);

    void AfficherInfixe (NoeudANR *n, int nbespace) const;

    void RotationDroite(NoeudANR* &pn);

    void RotationGauche(NoeudANR * &pn);

    void MAJcouleur(NoeudANR * &n);

    bool recherchessarbre(NoeudANR* &a, const Elem &e);

    NoeudANR * adracine;
    
    int nbelem;
};
#endif
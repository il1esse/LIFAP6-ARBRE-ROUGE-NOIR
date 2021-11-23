#ifndef _ABR
#define _ABR

#include "element.h"

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
};

class ABR
{
   
    public :
    ABR();
    
    ~ABR();
    
    void insererElement(const Elem & e);

    void affichage();

    void affichessArbre(Noeud* &a);

    bool recherche(const Elem & e,bool affichage); 

    bool recherchesansaffichage(const Elem & e);

    void creeFichierEntiers(const char * nomFichier, int nb);
    
    void detruire(Noeud* &a);
    private: 
    
    void inseressArbre(Noeud* &a,const Elem & e);

    void AfficherInfixe (Noeud *n, int nbespace) const;

    
    bool recherchessarbre(Noeud* &a, const Elem &e);

   

    Noeud * adracine;
    
    int nbelem;
};
#endif
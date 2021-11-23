# LIFAP6_ABR_ANR

(Ce fichier est en .md pour profiter des balises Markdown je vous conseille de l'ouvrir avec vscode et d'appuyer sur ctrl+shift+V) 

Dans ce projet nous avons crée 2 type d'arbres avec des règles de construction différente pour chacun d'eux : 

-Arbre binaire de recherche :
    
    -Chaque nœud d'un arbre est constitué d'une donnée (info) et peux avoir jusqu'a 2 fils (1 à droite 1 à gauche). Lors de l'ajout d'un élément dans un arbre on regarde les éléments déjà présent dans l'arbre à partir de la racine. Si l'élément que l'on ajoute est supérieurs à l'éléments à la racine on regarde son fils droit (inversement s’il est plus petit). Si le fils que l'on regarde n'existe pas (pas de fils) alors on ajoute l'élément a cette endroit dans l'arbre. Si le fils existe alors on fait la même manipulation que précédemment: on regarde si l'élément que l'on ajoute est plus grand ou plus petit que la donnée présent dans le nœud qu'on regarde. Ainsi de suite.


-Arbre rouge noir :
    
    -La méthode d'insertion d'élément est la même que pour l'arbre binaire de recherche (on regarde la donnée dans le nœud dans lequel on se trouve on l'a comparé avec l'élément que l'on veut ajouter puis on choisit vers quel fils aller ensuite).
    
    -Mais là où réside la grosse différence entre l'arbre rouge noir et l'arbre binaire de recherche est l'équilibrage global de l'arbre. Afin d'équilibrer l'arbre on ajoute des couleurs (rouge noir) a chaque nœud. Les 2 règles les plus importante sont lors de l'ajout d'un nœud sa couleur sera rouge, le nœud racine est toujours noir. Voici quelque autres règles indispensable pour l'équilibrage :
        
        --Mise à jour des couleurs : lorsque l'on ajoute un nœud et que son père et son oncle son rouge. On change la couleur de son père et son oncle en noir et le grand père en rouge.
        
        --Les rotations : Exemple pour la rotation à droite : Si le père est rouge et plus petit que le grand père et que le fils est rouge et plus petit que le père alors on échange la place du père avec le grand père et la place du fils avec le père. Puis le grand père devient le fils droit du père. Le père devient noir et le grand père devient rouge. Pour la rotation Gauche c'est la même chose mais dans l'autre sens (père plus grand que le grand père et rouge...).
        
        --Les doubles rotations : Exemple pour la double rotation droite : Si le père est rouge et plus petit que le grand père et que le fils est rouge mais plus grand que le père alors le fils échange sa place avec son père et son ancien père devient son fils gauche. Ensuite on se retrouve dans le cas d'une rotation simple à droite détaillé juste à dessus.
    
    -Contrainte : Il ne doit jamais y avoir 2 rouge de suite (père et fils rouge).


Mise à jour de couleur : 
 

            GP n                               GP r
        
        O r      P r            -->        O n      P n 

                    F r                                 F r


Rotation à droite : 

                GP n                            P n
            
            P r             -->             F r     GP r
        
        F r


Double Rotation à droite :


                GP n                            GP n                        F n
            
            P r             -->             F r             -->         P r     GP r

                F r                     P r



GP = Grand-Père     P = Père    F = Fils    r = rouge   n = noir



## Organisation des fichiers 



-**lifap6_abr_anr/bin** : répertoire où les exécutables seront compilés



-**lifap6_abr_anr/data** : répertoire où se trouveront les txt de performances et les courbes



-**lifap6_abr_anr/obj** : répertoire comportant les compilations intermédiaires (.o)



-**lifap6_abr_anr/src** : répertoire ou se trouvent les .cpp et les .h 



## Installation



Concernant l'installation il faut en premier lieu aller dans le répertoire global du programme et exécuter la commande :



```bash

make all

```  



Le fichier makefile va alors s'occuper des compilation et éditions de lien de tous les fichiers du programme. Elle va aussi créer dans le dossier bin/ les 3 exécutables dont on a besoin :

main.ex permet la création d'arbre rouge noir ou d'un arbre binaire de recherche selon ce qui est choisi dans le "collection.h". Dans le main : pour inserer des éléments on utilise la fonction insererElement(). On peut afficher l'arbre avec la fonction afficher(). On peut aussi rechercher un élément avec la fonction rechercher().  

mainperfANR.ex permet de connaitre les performances de l'arbre rouge noir pour l'insertion et pour la recherche. Le programme les écrit dans une fichier .txt. On peut faire une courbe (avec gnuplot par exemple) avec ces données pour voir les performances en fonction du nombre d’élément ajouté.

mainperfABR.ex permet de connaitre les performances de l'arbre binaire de recherche pour l'insertion et pour la recherche. Le programme les écrit dans une fichier .txt. On peut faire une courbe (avec gnuplot par exemple) avec ces données pour voir les performances en fonction du nombre d’élément ajouté.



## Exigences



Aucune exigence particulière.



## Usage



Pour utiliser les 3 exécutables après les avoir créés avec la fonction make on utilise

```c++

./bin/main.ex		//Pour construire les arbres rouge noir ou les arbres binaire de recherche.

./bin/mainperfABR.ex	//Pour calculer les performances des arbres binaire de recherche.

./bin/mainperfANR.ex	//Pour calculer les performances des arbres rouge noir.

```



## Auteurs



VINCENT/Yann/11906701



LARIBI/Iliesse/11911241



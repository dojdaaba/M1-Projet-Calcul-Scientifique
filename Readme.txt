
JAFUNO Douba 


4M053 : Calcul scientifique pour les grands systèmes linéaires
X.Claeys, G.Migliorati B.Thierry & P.-H.Tournier 






DESCRIPTIF D'INTRODUCTION

Après avoir créer et implémenter les 3 classes DenseMatrix, Block et BlockMatrix, le projet consistait à modéliser et à construire le Préconditionneur de Schwarz additif tout en utilisant une famille de vecteur de la méthode de Schwarz, le but final du projet étant de comparer cette méthode du gradient avec celle sans preconditionneur. 



CONTENU DES DIFFERENTS FICHIERS

Le projet est composé de 
- 3 fichiers cpp (src), 3 fichiers hpp constitutifs (include) des 3 classes DenseMatrix,Block,et BlockMatrix 
- 1 fichier Vecteur.cpp et 1 fichier Vecteur.hpp pour représenter les vecteur<double> le long du projet ainsi que les opérations comme le produit scalaire.
- d'un Makefile permettant de compiler le projet, 
- de plusieurs question.cpp contenant des tests. 
Enfin, il contient 
-les fichiers Matrix.txt j'ai renommé Matrix01.txt en Matrix1.txt jusqu'a la 9eme Matrice.



MISE EN MARCHE ET EXECUTION


1ERE PARTIE: Implémentation de la classe DenseMatrix
-Après avoir décompresser le fichier zip dans votre terminal, dirigez-vous vers le projet nommé Projet a l'aide de la commande "cd location/location/Jafuno/Projet"
-Exécutez à l'aide de la commande "make" qui permet de compiler 
-Effectuez ensuite "bin/question1" 
La question1.cpp va effectuer plusieurs teste sur la classe BlockMatrix:
     1) On test l'affichage d'une DenseMatrix 
     2) On teste la résolution de Ax = B par LuSolve et Cg
     3) On teste la fonction MvProd 

2E PARTIE: Implémentation de la classe Block
-Dans le terminal, exécutez à l'aide de la commande "make" 
-Afficher avec "bin/question2"
La question2.cpp vous montre la représentation d'un block et de la fonction MvProd.

3E PARTIE: Implémentation de la classe BlockMatrix
-Dans le terminal, exécutez à l'aide de la commande "make" 
-Afficher avec "bin/question3"
La question3.cpp va effectuer plusieurs teste sur la classe BlockMatrix:
     1) On test l'operateur += qui ajoute des Blocks à la liste val de notre BlockMatrix 
     2) On teste la fonction MvProd 
     3) On teste la résolution de Ax = B par l'algorithme MinRes


4E PARTIE: Familles de Vecteurs 
-Dans le terminal, exécutez à l'aide de la commande "make" 
-Afficher avec "bin/question4"
La question4.cpp teste et affiche la création d'une famille de Vecteur Iq avec un recouvrement de [[1...n]] à partir de la méthode de Schwartz. En respectant les standards du c++ (on a commencé par 0). 


5E PARTIE: Opérateur ( , )
-Dans le terminal, exécutez à l'aide de la commande "make" 
-Afficher avec "bin/question5"
La question5.cpp affiche un exemple d'appliaction de l'operateur (,) pour les DenseMatrix .


6E PARTIE: Routine Extract
-Dans le terminal, exécutez à l'aide de la commande "make" 
-Afficher avec "bin/question6"
La question6.cpp affiche un exemple d'appliaction de la routine Extract pour les BlockMatrix.


7E PARTIE: MvprodInv pour le préconditionneur P
-Dans le terminal, exécutez à l'aide de la commande "make" 
-Afficher avec "bin/question7"
La question7.cpp teste le bon fonctionnement des fonctions MvProdInv pour les Blocks et dons les BlockMatrix aussi. A noter que:  

     1 2 3	                −40  16  9
B =  2 5 3 a pour inverse B^-1 = 13  −5  −3
     1 0 8	                 5   −2  −1	 

     1 2 3	                −24  18  5 
B =  0 1 4 a pour inverse B^-1 = 20 −15 −4 
     5 6 0	                 −5   4  1	 
 

8E PARTIE: Avec Préconditionneur 
-Dans le terminal, exécutez à l'aide de la commande "make" 
-Afficher avec "bin/question8"
La question8.cpp teste le bon fonctionnement de la fonction Pcg et de son algorithme donné avec tol=1e-6 

9E PARTIE: Avec Préconditionneur
-Dans le terminal, exécutez à l'aide de la commande "make" 
-Afficher avec "bin/question9"
La question9.cpp teste la résolution du système Ax = B pour le Gradient Conjugué avec et sans préconditionnement avect un vecteur B choisi aléatoirement: 

     1) Entrer Un nombre entre 1 et 15 pour le choix de la Matrice 
     2) Entrer 2 nombres l et r pour la famille de vecteur de votre Preconditionneur (r<l=<N)
     3) Sur l'écran apparait le nombre d'itérration de ces 2 méthodes et laquelle est la plus
        rapide, le fichier courbe.txt est crée il contient 3 colonne le nombres d'iterations et
        chaque coefs du vecteur de résidu pour PCG et CG 
      
     4) -Dans le terminal, exécutez à l'aide de la commande "gnuplot" puis éxécuter succesivement 
        -set logscale y   pour l'échelle logarithme sur l'axe y pour les résidus
        -set title "Convergence pour N=.." pour mettre un titre au graphique 
evenuellement:
        -set xlabel "Niter"  nom de l'axe des x
        -set xlabel "log|r|"  nom de l'axe des y 

Puis si Pcg est plus rapide: 
        -plot "courbe.txt" using 1:2 with lines title "GC", "courbe.txt" using 1:3 with lines
         title "PGC"
Sinon:
        -plot "courbe.txt" using 1:2 with lines title "PGC", "courbe.txt" using 1:3 with lines
         title "GC"

        Et voila la courbe s'affiche !

      5) Dans le terminal, exécutez à l'aide de la commande "exit" pour quitter le graph.


10E PARTIE: Matrice creuse 
          Par manque de temps et de problème dans mes codes cette partie subsidiaire n'a pas été
          traité


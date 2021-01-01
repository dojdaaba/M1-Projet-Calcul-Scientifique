#include "include/BlockMatrix.hpp"

int main(){


Vecteur b(3); 
b(0)=1;
b(1)=1;
b(2)=1;

Vecteur d(b);
Vecteur x(3);
x(0)=1;
x(1)=2;
x(2)=3;
Vecteur c(b);
vector<int> B = {0,1,2}; 
vector<int> C = {1,2,3}; 

Block D(3,3,B,C);
D.Insert(0,0,1);
D.Insert(0,1,2);
D.Insert(0,2,3);
D.Insert(1,0,2);
D.Insert(1,1,5);
D.Insert(1,2,3);
D.Insert(2,0,1);
D.Insert(2,1,0);
D.Insert(2,2,8);
Block E(D); 
D.display();
cout<<endl; 
cout<<"Soit x un vecteur :";
cout<<x; 
cout<<"Soit b un vecteur :";
b.display();
D.MvProdInv(x,b);
cout<<D;
cout<<"Le produit de R(n,J)*B⁻1 *t(R(m,J)) par x stockée dans b est "<< "b' = ";
b.display();

Block A(3,3,B,C);
A.Insert(0,0,1);
A.Insert(0,1,2);
A.Insert(0,2,3);
A.Insert(1,0,0);
A.Insert(1,1,1);
A.Insert(1,2,4);
A.Insert(2,0,5);
A.Insert(2,1,6);
A.Insert(2,2,0);
A.display();
Block F(A); 

cout<<endl; 
cout<<"Soit x un vecteur :";
cout<<x; 
cout<<"Soit c un vecteur :";
c.display();
A.MvProdInv(x,c);
cout<<"Le produit de R(n,J)*B⁻1 *t(R(m,J)) par x stockée dans c est "<< "c' = ";
c.display();

BlockMatrix G(3,3); 
G+=E;
G+=F; 
cout<<"Soit x un vecteur :";
cout<<x; 
cout<<"Soit d un vecteur :";
d.display();
G.MvProdInv(x,d);
cout<<"Pour nos 2 Matrices précédente le produit de la somme R(n,J)*B⁻1 *t(R(m,J)) par x stockée dans d est "<< "d' = ";
d.display();


return 0; 
}

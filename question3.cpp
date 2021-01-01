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
x(2)=1;
Vecteur c(b);
vector<int> B = {0,1,2}; 
vector<int> C = {0,1}; 

cout<<"Pour I un vecteur "<< "I = ";
	afficheVector(B);
	cout<<"Soit J un vecteur "<< "J = ";
	afficheVector(C); 
cout<<endl;
Block D(3,3,B,C);
D.Insert(0,0,1);
D.Insert(0,1,2);
D.Insert(1,0,2);
D.Insert(1,1,5);
D.Insert(2,0,1);
D.Insert(2,1,0);

Block E(D); 
D.display();
cout<<endl;

vector<int> K = {0,1}; 
vector<int> L = {1,2};
cout<<"Pour I un vecteur "<< "I = ";
	afficheVector(K);
	cout<<"Soit J un vecteur "<< "J = ";
	afficheVector(L);
	cout<<endl;  
Block A(3,3,K,L);
A.Insert(0,0,1);
A.Insert(0,1,2);
A.Insert(1,0,0);
A.Insert(1,1,1);

A.display();
Block F(A); 


BlockMatrix G(3,3); 
G+=E;
G+=F; 
cout<<endl;
cout<<"On considere un BlockMatrix G dont la list<block> val contient les Densematrix précedentes, La matrice A(Somme des Blocks) formé par G est:\n"; 
cout<<G;

cout<<endl; 
cout<<"Soit x un vecteur :";
cout<<x; 
cout<<"Soit c un vecteur :";
c.display();
G.MvProd(x,c);
cout<<"Le produit de A par x stockée dans c est "<< "c' = ";
c.display();  
cout<<endl; 
cout<<"/------------------------------------------------------------/";
cout<<endl;
Vecteur r(5); 
r(0)=1;
r(1)=1;
r(2)=1;
r(3)=1;
r(4)=1;

Vecteur h(5); 

DenseMatrix M(5,5);
M.Laplace();
BlockMatrix P(5,5);
 vector<vector<int>>l;
 vector<int>Id{0,1,2,3,4};
 l.push_back(Id);
 P.Extract(Recouvrement(3,1,5),M);
 for(auto x : P.getval()){
	x.display(); 
	cout<<endl;
}
cout<<"On considere un BlockMatrix G dont la list<block> val contient la Densematrix précedentes, La matrice A(Somme des Blocks) formé par G ici est:\n"; 
cout<<P;
cout<<"Soit x un vecteur :";
cout<<h; 
cout<<"Soit b un vecteur :";
r.display();    	
P.MinRes(h,r);
cout<<"La solution du systeme Ax = b par MinRes est donnée par le vecteur suivant stockee dans x :";
h.display();
return 0; 
} 

#include "include/BlockMatrix.hpp"

int main(){
	
	


vector<int> Ir=Recouvrement(3,1,5)[0]; 

vector<int> Ic=Recouvrement(3,1,5)[1];


cout<<"Soit Ir un vecteur "<< "Ir = ";
	afficheVector(Ir);
	cout<<"Soit Ic un vecteur "<< "Ic = ";
	afficheVector(Ic); 

DenseMatrix A(5,5);
A.Laplace();


	cout<<"Soit A une matrice dense "<< "A = \n"<< A<<"\n"; 
	cout<<"Avec A(Ir,Ir)= \n"<< A(Ir,Ir)<<"\n"; 
	cout<<"Avec A(Ic,Ic)= \n"<< A(Ic,Ic)<<"\n"; 

	cout<<"Soit L vector<vector<int>> contenant Ir et Ic pour G une BlockMatrix\n";
	cout<<"L'appel G.Extract(L,A) nous donne les Block suivant: \n";
BlockMatrix G(5,5); 
G.Extract(Recouvrement(3,1,5),A);
for(auto x : G.getval()){
	x.display(); 
	cout<<endl;
}
cout<<"La matrice A(Somme des Blocks) formé par G ici est:\n"; 
cout<<G;
	

	return 0; 
}

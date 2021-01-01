#include "include/DenseMatrix.hpp"

int main(){
	
	
vector<int> Ir={0,1,2}; 

vector<int> Ic={1,2}; 

DenseMatrix A(3,3);

	A(0,0) = 1;
	A(0,1) = 2;
	A(0,2) = 3;
	A(1,0) = 4;
	A(1,1) = 5;
	A(1,2) = 6;
	A(2,0) = 7;
	A(2,1) = 8;
	A(2,2) = 9;

	cout<<"Soit A une matrice dense "<< "A = \n"<< A; 
	cout<<"Soit Ir un vecteur "<< "Ir = ";
	afficheVector(Ir);
	cout<<"Soit Ic un vecteur "<< "Ic = ";
	afficheVector(Ic); 

    cout<<"La Matrice  A' extraite de A grace à ces deux vecteur est  "<< "A' = \n";
    cout<< A(Ir,Ic); 
	return 0; 
}

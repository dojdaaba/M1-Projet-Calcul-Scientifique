#include "include/BlockMatrix.hpp"
#include "include/Block.hpp"
int main(){


	DenseMatrix A(2,2);
	DenseMatrix B(5,5);
	
	B(0,0)=1;
	B(0,1)=6;
	B(0,2)=1;
	B(0,3)=6;
	B(0,4)=5;
	B(1,0)=6;
	B(1,1)=1;
	B(1,2)=2;
	B(1,3)=1;
	B(1,4)=1;
	B(2,0)=1;
	B(2,1)=2;
	B(2,2)=6;
	B(2,3)=5;
	B(2,4)=2;
	B(3,0)=6;
	B(3,1)=1;
	B(3,2)=5;
	B(3,3)=1;
	B(3,4)=6;
	B(4,0)=5;
	B(4,1)=1;
	B(4,2)=2;
	B(4,3)=6;
	B(4,4)=1;

	DenseMatrix C(A);

  cout<<"Soit A une DenseMatrix \n"; 
  
  cout<<B<<endl;
  
cout <<"On construit la Matrice P du Preconditionneur de Schwartz à partir de cette Densematrix et de cette familles de 2 vecteurs:\n"; 
  for(auto x: Recouvrement(3,1,5)){
	afficheVector(x);
	cout<<endl; 
}

BlockMatrix D(5,5); 


   Vecteur z(5); 
    z(0)=19;
    z(1)=11;
    z(2)=16;
    z(3)=19;
    z(4)=15;
   Vecteur w(5); 
    Vecteur s(5);
    cout<<"Soit x un vecteur :";
    w.display(); 
    cout<<"Soit b un vecteur :";
    z.display();
    cout<<endl;
  
    cout<<"La solution du systeme Ax = b par Pcg est donnée par le vecteur suivant stockee dans x :";
    B.pcg(w,z,Recouvrement(3,1,5)); 
    w.display();
 

  return 0; 
}

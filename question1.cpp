#include "include/DenseMatrix.hpp"

int main(){
	
	DenseMatrix A(2,2);
	DenseMatrix B(5,5);
	DenseMatrix P(4,5);
	B.Laplace(); 
	DenseMatrix C(A);

  cout<<"Soit A une DenseMatrix \n"; 
  cout<<B<<endl;
  DenseMatrix D(B);

    Vecteur z(5); 
    for(int i=0; i<5 ; i++){
		z(i)=1;
	}

    Vecteur w(5); 
    Vecteur s(5);
    cout<<"Soit x un vecteur :";
    w.display(); 
    cout<<"Soit b un vecteur :";
    z.display(); 
    
    B.LuSolve(w,z);
    cout<<"La solution du systeme Ax = b par LU est donnée par le vecteur suivant stockee dans x :";
    w.display();  
    D.cg(s,z);  
    cout<<"On retrouve la meme solution par CG:"; 
    s.display();
	Vecteur x(2); 
	Vecteur b(2); 
	x(0)=1.;
	x(1)=2.;
	b(0)=2.;
	b(1)=5.; 
	A(0,0) = 1.;
	A(0,1) = 2.;
	A(1,0) = 3.;
	A(1,1) = 4.;
	cout<<"Soit A une DenseMatrix "<< "A = \n"<< A; 
	cout<<"Soit x un vecteur "<< "x = ";
	x.display();
	cout<<"Soit b un vecteur "<< "b = ";
	b.display(); 
    A.MvProd(x,b);
    cout<<"Le produit de A par x stockée dans b est "<< "b' = ";
    b.display();  
  
	return 0; 
}

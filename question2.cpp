#include "include/Block.hpp"

int main(){


Vecteur b(2); 
b(0)=1;
b(1)=1;
Vecteur x(3);
x(0)=1;
x(1)=2;
x(2)=3;
vector<int> B = {0,1}; 
vector<int> C = {1,2,3}; 
cout<<"Soit I: "; 
afficheVector(B);
cout<<"Soit J: ";   
afficheVector(C); 
  
Block A(2,3,B,C);
A.Insert(0,0,1);
A.Insert(0,1,2);
A.Insert(0,2,3);
A.Insert(1,0,4);
A.Insert(1,1,5);
A.Insert(1,2,6);
A.display();
cout<<endl;

cout<<"Soit x un vecteur :";
cout<<x; 
cout<<"Soit b un vecteur :";
b.display(); 
A.MvProd(x,b);
cout<<"Le produit de A par x stockée dans b est "<< "b' = ";
b.display();  
    


return 0; 
}
	

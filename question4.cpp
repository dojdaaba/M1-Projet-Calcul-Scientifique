
#include "include/BlockMatrix.hpp"



int main(){


cout<< "Pour l=3 , r=1 et n=7, on obtient la liste de vecteurs suivants : \n" ;
for (auto x : Recouvrement(3,1,57)){
	afficheVector(x); 
}
cout<<endl; 
cout<< "Pour l=5 , r=3 et n=8, on obtient la liste de vecteurs suivants : \n" ;
for (auto x : Recouvrement(5,3,8)){
	afficheVector(x); 
}
cout<<endl; 
cout<< "Pour l=7 , r=2 et n=25, on obtient la liste de vecteurs suivants : \n" ;
for (auto x : Recouvrement(7,2,25)){
	afficheVector(x); 
}
return 0; 
}


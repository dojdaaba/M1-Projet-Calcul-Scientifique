// CLASSE DENSEMATRIX: modélise les matrice pleines
#include <iostream>
#include "../include/DenseMatrix.hpp"
#include <vector>
#include <fstream>
#include <cmath>
#include "../include/BlockMatrix.hpp"
class BlockMatrix;
using namespace std;
Vecteur solve_triang_inf(const DenseMatrix& A, const Vecteur& b){

  Vecteur res(b);
  int i, j;

  for(i = 0;i<b.size();i++){
    for(j = 0;j<i;j++){
      res(i) -= A(i, j)*res(j);
    }
    res(i) /= A(i, i);
  }

  return res;
}


Vecteur solve_triang_sup(const DenseMatrix& A, const Vecteur& b){

  Vecteur res(b);
  int i, j;

  for(i = b.size()-1;i>=0;i--){
    for(j = i+1;j<b.size();j++){
      res(i) -= A(i, j)*res(j);
    }
    res(i) /= A(i, i);
  }

  return res;

}




DenseMatrix::DenseMatrix(){
    nc=0;
    nr=0;
    val.resize(0,0);
    
}
DenseMatrix::DenseMatrix(const int &Nr,const int &Nc){
    nr=Nr;
    nc=Nc;
    val.resize(Nc*Nr,0);
}
DenseMatrix::DenseMatrix(const DenseMatrix & M){
	nr=M.nr; 
	nc=M.nc; 
	val=M.val;
    
    for (unsigned int i=0;i<M.val.size();i++){
        val.push_back(M.val[i]);
    }
  
}

int DenseMatrix::getnc()const{ return nc;}
int DenseMatrix::getnr()const{ return nr;}
double DenseMatrix::temps()const{ return time;}
vector<double> DenseMatrix::getval(){ return val;}
vector<double> DenseMatrix::residu()const { return resvec;}

void afficheVector(vector<int> v){
	  cout<< "( ";
  if(v.size()){
    cout<< v[0];
  }
  for(unsigned int i=1;i<v.size();i++){
    cout << ", " << v[i];
  }
  cout << " )\n\n";
}
void AfficheVector(vector<double> v){
	  cout<< "( ";
  if(v.size()){
    cout<< v[0];
  }
  for(unsigned int i=1;i<v.size();i++){
    cout << ", " << v[i];
  }
  cout << " )\n\n";
}	

void DenseMatrix::display() const{
	for (int i=0;i<nr;i++){
        for (int j=0;j<nc;j++){
            cout<<val[i+j*nr]<<"\t";
        }
        cout<<endl;
    }
 
}

ostream& operator <<(ostream& f, const DenseMatrix & M ){
    for (int i=0;i<M.nr;i++){
        for (int j=0;j<M.nc;j++){
            f<<M(i,j)<<"\t";
        }
        f<<endl;
    }
    return f;
}


double & DenseMatrix::operator () (int i, int j){
    return val[i+j*nr];
}
double DenseMatrix::operator () ( int i, int j) const{
    return val[i+j*nr];
}

void DenseMatrix::operator=(const DenseMatrix &M){
	nr=M.nr;
	nc=M.nc;
	val.resize((M.val).size()) ;
  for (unsigned int j=0;j<val.size();j++){
            val[j]=M.val[j];
}
}
  
 

DenseMatrix DenseMatrix::operator+( const DenseMatrix &M){
    DenseMatrix P(nr,nc);
    
    for(int i=0;i<nr*nc;i++){
        P.val[i]=val[i]+M.val[i];}
    return P;
}
DenseMatrix DenseMatrix::operator-( const DenseMatrix &M){
    DenseMatrix P(nr,nc);
    
    for(int i=0;i<nr*nc;i++){
        P.val[i]=val[i]-M.val[i];}
    return P;
}

DenseMatrix operator*(const DenseMatrix& A, const DenseMatrix& B){

 
  int i, j, k;
 DenseMatrix P(A.nr,B.nc);

  for(i=0;i<A.nr;i++){
    for(j=0;j<B.nc;j++){
      for(k=0;k<A.nc;k++){
	 P.val[i+P.nr*j] +=  A.val[i+A.nr*k]*B.val[k+B.nr*j];
      }
    }
  }

  return P;
}

DenseMatrix DenseMatrix::operator*( const double &a)const{
    DenseMatrix P(nr,nc);
    
    for(int i=0;i<nr*nc;i++){
        P.val[i]=a*val[i];}
    return P;
}
Vecteur operator*(const DenseMatrix& A, const Vecteur& v){



  int i, j;
  Vecteur res(A.nr);

  for(i=0;i<A.nr;i++){
    res(i) = 0;
    for(j=0;j<A.nc;j++){
      res(i) += A.val[i+A.nr*j] * v(j);
    }
  }
  return res; 
}
void DenseMatrix::MvProd( const Vecteur& x, Vecteur& b){
	DenseMatrix K(*this);
	 if(x.size()!= nc && b.size()!= nr){
    cout<<"DenseMatrix Mvprod(const vector<double> & x,const vector<double> & b) : Les Vecteurs x et b doivent avoir une taille nc et nr respectivement"<<endl;
  } 
  b.resize(nr);
   b.mise_a_zero();
    for(int i=0;i<nr;i++){
		for(int j=0;j<nc;j++){
			b(i) = b(i) + K(i,j)* x(j);
    }
  }
}


void DenseMatrix::Laplace(){
DenseMatrix w(nr,nc);
   for(int i=0;i<nr;i++){
     for(int j=0;j<nc;j++){
       if(i==j){
		   w(i,j)=2;
	   }
       if(j==i-1 || j==i+1){
       w(i,j)=-1;
   }
     }
   }
   *this=w;
}

void DenseMatrix::LuSolve( Vecteur& x, const Vecteur& b)const{
DenseMatrix A(*this);
DenseMatrix U(nr,nc);
DenseMatrix L(nr,nc); 


double pivot;

	for(int k=0; k<nc;k++){
	    pivot = A(k,k);
		L(k,k)=1;
		for(int i=k+1; i<nc;i++){
		 L(i,k)=A(i,k)/pivot;	
		 }
		 U(k,k)=A(k,k);
		  
		for(int j=k+1; j<nc; j++){
			  U(k,j)=A(k,j);
		}
		for(int i=k+1;i<nc;i++){
			for(int j=k+1; j<nc; j++){
			  A(i,j) -=  L(i,k)*U(k,j);
			}
		
		}
	
	}
	
	Vecteur y(solve_triang_inf(L, b));
	Vecteur w(solve_triang_sup(U, y));
	x.mise_a_zero(); 
	
	for(int i=0;i<x.size();i++){
		x(i)=w(i);
	} 
	
	
	}

void DenseMatrix::cg(Vecteur& x,const Vecteur& b){
clock_t start,end;
start=clock();
	DenseMatrix A(*this); 
Vecteur c(b.size()); 
Vecteur p(b.size()) ;
	double aux; 
	double alpha; 
	Vecteur r; 
	int niter = 0;
	int n_max= 10000;
  x.resize(b.size());
  resvec.clear();
  x.mise_a_zero();
  r =  b; 
  p=b;
 while((r.norm()/b.norm() > 1e-6) && (niter <n_max)){
   aux = (r, r);
   A.MvProd(p,c);
  alpha= aux/(c, p);
  x += alpha*p;
  r -= alpha*(c);
  aux = (r, r)/aux;
   p= r + aux*p;
    resvec.push_back(r.norm()/b.norm());
   niter++;
  }
  end=clock();
  cout<<"CG avec un nombre d'iterrations de "<<niter<<endl;
  time=static_cast<double>(end - start) / CLOCKS_PER_SEC ;
}
  DenseMatrix DenseMatrix::operator()(vector<int> Ir, vector<int>Ic)const{
	  DenseMatrix K(*this);
	  int ir= Ir.size();
	  int ic= Ic.size();
	   DenseMatrix A(ir,ic); 
	  for(int i=0;i<ir;i++){
		for(int j=0;j<ic;j++){
			A(i,j) = K(Ir[i],Ic[j]);
			}
	  
	  }
	  return A; 
}
void DenseMatrix::pcg(Vecteur &x,const Vecteur &b,const vector<vector<int> > & k){
clock_t start,end;
start=clock();
	
double gamma; 
double alpha; 
double beta; 
int niter=0;
int n_max= 10000;
DenseMatrix D(*this);
BlockMatrix A(D.nr,D.nc);
 A.Extract(k,D);
  x.resize(D.nr);
  x.mise_a_zero();
  Vecteur r(b);
 Vecteur z(D.nr);
 A.MvProdInv(r,z);
  Vecteur p(z);
  resvec.clear();
while((r.norm()/b.norm()> 1e-6)&&(niter <n_max)){
    gamma= (r,z);
    Vecteur v(D.nr);
    D.MvProd(p,v);
    alpha=gamma/(p,v);
    x += alpha*p;
    r -= alpha*v;
    A.MvProdInv(r,z);
   beta=(r,z)/gamma;
    p=z+(beta*p); 
    resvec.push_back(r.norm()/b.norm());
    niter++;
    }
    end=clock();
 cout<<"PCG Avec un nombre d'iterrations de "<<niter<<endl;
  time=static_cast<double>(end - start) / CLOCKS_PER_SEC ;
}

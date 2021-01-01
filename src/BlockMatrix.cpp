#include "../include/BlockMatrix.hpp"

BlockMatrix::BlockMatrix(int Nr,int Nc): nr(Nr), nc(Nc){
		val.clear(); 
		}
	
   BlockMatrix::BlockMatrix(const BlockMatrix& B): nr(B.nr), nc(B.nc), val(B.val){}   

void BlockMatrix::operator=(const BlockMatrix &B){
	
	nc=B.nc;
	nr=B.nr;
	val=B.val;

	
}

void BlockMatrix::operator+=( const Block& B){
	
	val.push_back(B);

	
}

//Acces à la case (i,j) de la matrice A pour pouvoir afficher la matrice A somme des blocks
double BlockMatrix::operator () ( int i, int j) const{
 
   double k = 0;
    for(auto it=val.begin(); it != val.end(); it++){
		k+=(*it)(i,j); 
	}
	
   return k;
}

list<Block>& BlockMatrix::getval(){return val;}

//Affichage de la Matrice A
ostream& operator<<(ostream& f, const BlockMatrix& B){
	for (int i=0;i<B.nr;i++){
        for (int j=0;j<B.nc;j++){
          
            f<<B(i,j)<<"\t";
        }
       f<<endl;
    
    
}
  return f;
}
	

	//Question 6
void BlockMatrix::Extract( const vector<vector<int>>& v,const DenseMatrix& A ){

  int n=v.size();
for(int i=0;i<n;i++){
    Block B(A.getnr(),A.getnc(),v[i],v[i]);
    B.getmat()=A(v[i],v[i]);
    *this+=B;
  }
}

void BlockMatrix::MvProd( const Vecteur& x, Vecteur& b){
Vecteur c(b);
	b.mise_a_zero();
	for(auto s: val){
	s.MvProd(x,c);
	  b=b+c; 
	 
	}
}

//Question 3
void BlockMatrix::MinRes( Vecteur& x,const Vecteur& b){
  BlockMatrix B(*this);
  int n_max= 100000;
  int N=b.size();
  x.resize(N);
  x.mise_a_zero();
  Vecteur r(b);
  Vecteur b1(b);
  Vecteur w(N);
  int niter=0;
 while((r.norm()/b.norm() > 1e-6) && (niter <n_max)){
  B.MvProd(r,w);
 double alpha= (r,w)/(w,w);
  x +=alpha*r;
  B.MvProd(x,w);
  r = b-w;
  niter++;
  }
  }

void BlockMatrix::MvProdInv(const Vecteur& x, Vecteur& b){
	Vecteur c(b);
	b.mise_a_zero();
	for(auto s: val){
	s.MvProdInv(x,c);
	  b=b+c; 
	 
	}
	
	
}


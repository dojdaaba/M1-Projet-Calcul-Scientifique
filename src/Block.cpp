#include "../include/Block.hpp"


double Block::operator () ( int i, int j) const{

   return MatA(*this)(i,j);
   //Pour MVPROD
}

void Block::Insert(int i,int j,double v){
   mat(i,j)=v;

}
void Block::operator=(const Block &B){
	
	nc=B.nc;
	nr=B.nr;
	Ir.resize((B.Ir).size());
	Ic.resize((B.Ic).size()); 
for (unsigned int j=0;j<Ir.size();j++){
            Ir[j]=B.Ir[j];
}
for (unsigned int j=0;j<Ic.size();j++){
            Ic[j]=B.Ic[j];
}
	mat=B.mat;
	
}
int Block::getnc()const{ return nc;}
int Block::getnr()const{ return nr;}
vector<int> Block::getIr() const{ return Ir;}
vector<int> Block::getIc()const{ return Ic;}
DenseMatrix Block::getmat() const{return mat;}
DenseMatrix& Block::getmat() {return mat;}	

//Matrice A pour l'affichage et quelque opération
DenseMatrix MatA(const Block& B){
	DenseMatrix Rn(B.getnr(),B.getIr().size());
	DenseMatrix Rm(B.getIc().size(),B.getnc());

	
	int cpt(0);
	int cpt1(0);
	for(auto x: B.getIr()){
		for(int j=0; j<B.getnr(); j++){
			if (x==j){
				Rn(j,cpt)=1;
				}
		}
		cpt++;
	}
	
    for(auto x: B.getIc()){
		for(int j=0; j<B.getnc(); j++){
			if (x==j){
				Rm(cpt1,j)=1;
			}
		}
		cpt1++;
	}

	return Rn*B.getmat()*Rm; 

}
void Block::display() const {
	
		const Block& B = *this;
		DenseMatrix Rn(B.nr,B.Ir.size());
	DenseMatrix Rm(B.Ic.size(),B.nc);

	
	int cpt(0);
	int cpt1(0);
	for(auto x: B.Ir){
		for(int j=0; j<B.nr; j++){
			if (x==j){
				Rn(j,cpt)=1;
				}		}
		cpt++;
	}
	
    for(auto x: B.Ic){
		for(int j=0; j<B.nc; j++){
			if (x==j){
				Rm(cpt1,j)=1;
			}
		}
		cpt1++;
	}
	DenseMatrix A(MatA(B));
	
	
	cout<<"Soit une Matrice de la forme A= R(n,I)*B*t(R(m,J)) avec :\n";
	cout<<"Matrice R(n,I): \n";
    for (int i=0;i<Rn.getnr();i++){
        for (int j=0;j<Rn.getnc();j++){
            cout<<Rn(i,j)<<"\t";
        }
        cout<<endl;
    }
    
    cout<<"Matrice B: \n";
     cout<<mat;
        cout<<endl;
    
    
    cout<<"Matrice t R(m,J): \n";
    for (int i=0;i<Rm.getnr();i++){
        for (int j=0;j<Rm.getnc();j++){
            cout<<Rm(i,j)<<"\t";
        }
        cout<<endl;
    }
    cout<<"et tel que A= :\n";
    
    cout<<A;
	}


//Affichage de la Matrice A 
ostream& operator <<(ostream& f, const Block & B ){
	
	DenseMatrix A;
	A= MatA(B);
    for(int i=0;i<A.getnr();i++){
		for(int j=0;j<A.getnc();j++){
			 f<<A(i,j)<<"\t";
        }
        f<<endl;
    }
    
    return f;
}
void Block::MvProd( const Vecteur& x, Vecteur& b){

	 
	DenseMatrix A;
	A=MatA(*this);

   b.mise_a_zero();
    for(int i=0;i<A.getnr();i++){
		for(int j=0;j<A.getnc();j++){
			b(i) = b(i) + A(i,j)* x(j);
    }
  }
  /*
  int ic=Ic.size();
  int ir=Ir.size();
   Vecteur w(ic);
  for(int i=0;i<ic;i++){
	  w(i)=x(Ic[i]);
       }
   Vecteur z(ir);
   mat.MvProd(w,z);
   for(int i=0;i<ir;i++){
	   b(Ir[i])=z(i)
	   };
	 */
}

void Block::MvProdInv(const Vecteur& x, Vecteur& b){

	Vecteur y(Ic.size()); 
	DenseMatrix Rn(nr,Ir.size());
    DenseMatrix Rm(Ic.size(),nc);
    int cpt(0);
	int cpt1(0);
	for(auto x: Ir){
		for(int j=0; j<nr; j++){
			if (x==j){
				Rn(j,cpt)=1;
				}
		}
		cpt++;
	}

	
	for(auto x: Ic){
		for(int j=0; j<nc; j++){
			if (x==j){
				Rm(cpt1,j)=1;
			}
		}
		cpt1++;
	}
	Rm.MvProd(x,y);
	Vecteur z(Ic.size());
	mat.LuSolve(z,y);
	Rn.MvProd(z,b);;
	/*
	
  int ic=Ic.size();
  int ir=Ir.size();
  Vecteur y(ic);
  for(int i=0;i<ic;i++){
   y(i)=x(Ic[i]);
   }
 
  Vecteur z(ic);
  mat.LuSolve(z,y);

 for(int i=0;i<ir;i++){
  b(Ir[i])=z(i);
    }

 */
	}; 
vector<vector<int>> Recouvrement(int l,int r,int n){

vector<vector<int>> L ; 

     vector<int> I1(l+r,0);
     for( int i=0; i<l+r; i++){
		 I1[i]= i; 
	 }
	 L.push_back(I1);
	for (int q=2; q<floor(n/l); q++){ 
	 vector<int> Iq(2*r+l+1,0);
	  for( int i=0; i<2*r+l+1; i++){
		  Iq[i]= l*(q-1)-r +i-1; 
	 }
	  L.push_back(Iq);
	}
	 vector<int> Iqs;
	 for( int i=l*(floor(n/l)-1); i<n;i++){
		  Iqs.push_back(i);
	 }
	  L.push_back(Iqs);

 return L;
}

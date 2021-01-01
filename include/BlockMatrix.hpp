
#ifndef BLOCKMATRIX_hpp
#define BLOCKMATRIX_hpp
#include "DenseMatrix.hpp"
#include "Block.hpp"
#include <list> 

#include <fstream>

using namespace std;
class BlockMatrix{
	private:
    
    int nr,nc;
    list<Block> val;
  
     
    public: 
    
    BlockMatrix(int Nr,int Nc);
    BlockMatrix(const BlockMatrix& B);  
    double operator () ( int i, int j) const;
	void operator=(const BlockMatrix &B);
	void operator+=(const Block& B);
	int size() const{return val.size();}; 
	list<Block>& getval(); // POUR EXTRACT
	int getnr()const{return nr;}
	int getnc() const{return nc;}
	friend ostream& operator<<(ostream& , const BlockMatrix& B);
	friend istream & operator>>(std::istream &, BlockMatrix& B);
	void MvProd(const Vecteur&,Vecteur& ); 
	void MinRes(Vecteur&,const Vecteur& ) ;
	void MvProdInv(const Vecteur&, Vecteur&); 
    void Extract( const vector<vector<int>>&,const DenseMatrix& );
};

#endif



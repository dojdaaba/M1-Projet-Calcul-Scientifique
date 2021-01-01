#ifndef Block_hpp
#define Block_hpp
#include "DenseMatrix.hpp"
#include <iostream>
#include <vector>
#include <fstream>



using namespace std;
class Block{
	private:
    
    int nr,nc;
    vector<int> Ir,Ic;
    DenseMatrix mat;
     
    public: 
  
    Block(int Nr,int Nc,vector<int> R, vector<int> C): nr(Nr), nc(Nc),Ir(R),Ic(C),mat(Ir.size(),Ic.size()){}
    Block(const Block& B): nr(B.nr), nc(B.nc),Ir(B.Ir),Ic(B.Ic),mat(B.mat){};  
    double operator () ( int i, int j) const; //On l'utilisera pour l'afffichage des Blockmatrix
    void Insert(int ,int ,double ); // Remplir mat
    friend ostream& operator <<(ostream& f, const Block &);
    void display() const;
	void operator=(const Block &B);
	int getnr()const ;
    int getnc()const ;
    vector<int> getIr() const;
    vector<int> getIc() const;
    DenseMatrix& getmat();
    DenseMatrix getmat()const;     
	void MvProd(const Vecteur&,Vecteur& );
	void MvProdInv(const Vecteur&, Vecteur&); 
	
};
vector<vector<int>> Recouvrement(int l,int r,int n);//FAMILLE DE VECTEUR
DenseMatrix MatA(const Block& B); // Retoune la Matrice formée par le block RiBRj

#endif

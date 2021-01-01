#ifndef DenseMatrix_hpp
#define DenseMatrix_hpp
#include <iostream>
#include <vector>
#include <fstream>
#include <list> 
#include <cmath> 
#include <algorithm>
#include <iterator>
#include <ctime>

#include "Vecteur.hpp"

using namespace std;
class DenseMatrix{
    
private:
    
    int nc,nr;
    vector<double> val;
    vector<double> resvec;   
    double time;          
    
public:
    DenseMatrix();
    DenseMatrix(const int &Nr,const int &Nc);
    DenseMatrix(const DenseMatrix & M);
    int getnr()const ;
    int getnc()const ;
    double temps()const;
    void display() const;
    vector<double> getval();
    vector<double> residu()const ; 
    double & operator () (int i, int j);
    double operator () ( int i, int j) const; 
    friend ostream& operator <<(ostream& f, const DenseMatrix & M );
    void operator=(const DenseMatrix &);
    DenseMatrix operator+(const DenseMatrix &);
    DenseMatrix operator-(const DenseMatrix &);
    friend DenseMatrix operator*(const DenseMatrix&, const DenseMatrix&);
    DenseMatrix operator*(const double &)const;
    friend Vecteur operator*(const DenseMatrix&, const Vecteur&);
    void Laplace(); //MATRICE DE lAPLACE 
    DenseMatrix operator()(vector<int>,vector<int>)const; 
    void MvProd(const Vecteur&,Vecteur& );
    void LuSolve(Vecteur&,const Vecteur& ) const;
    void cg(Vecteur&,const Vecteur& ) ;
    void pcg(Vecteur &,const Vecteur &,const vector<vector<int> > &);
 
   
    
};

void afficheVector(vector<int>); //Affiche vecteur<int>
void AfficheVector(vector<double>); 
Vecteur solve_triang_inf(const DenseMatrix&, const Vecteur&); //Ax=B pour Matrice triangulaire inferieure
Vecteur solve_triang_sup(const DenseMatrix&, const Vecteur&);

#endif 

#include <cmath>
#include "../include/Vecteur.hpp"

using namespace std;

Vecteur::Vecteur() : N_(0), coef_(0,0){}

Vecteur::Vecteur(int N) : N_(N), coef_(N){}



int Vecteur::size() const{
  return N_;
}

void Vecteur::display() const{
  cout<< "( ";
  if(coef_.size()){
    cout<< coef_[0];
  }
  for(unsigned int i=1;i<coef_.size();i++){
    cout << ", " << coef_[i];
  }
  cout << " )\n\n";
}

void Vecteur::resize(int NN_){
  N_ = NN_;
  coef_.resize(NN_);
}

void Vecteur::mise_a_zero(){
  for(unsigned int i=0;i<coef_.size();i++){
    coef_[i] = 0.0;
  }
}



double Vecteur::norm()const{
  double n=0;
 for(int i=0;i<N_;i++){
	 n+=(coef_[i]*coef_[i]);
 }
 return sqrt(n);
}
double& Vecteur::operator()(int i){
  return coef_[i];
}

double Vecteur::operator()(int i) const{
  return coef_[i];
}


ostream& operator<<(ostream& o, const Vecteur& v){
  o << "( ";
  if(v.coef_.size()){
    o << v.coef_[0];
  }
  for(unsigned int i=1;i<v.coef_.size();i++){
    o << ", " << v.coef_[i];
  }
  o << " )\n\n";

  return o;
}
const Vecteur& Vecteur::operator+=(const Vecteur& v){
  for(int i=0;i<N_;i++){
    coef_[i] += v.coef_[i];
  }
  return *this;
}
const Vecteur& Vecteur::operator-=(const Vecteur& v){
  for(int i=0;i<N_;i++){
    coef_[i] -= v.coef_[i];
  }
  return *this;
}
const Vecteur& Vecteur::operator*=(double alpha){
  for(int i=0;i<N_;i++){
    coef_[i] *= alpha;
  }
  return *this;
}


Vecteur operator+(const Vecteur& a, const Vecteur& b){

  Vecteur sum(a.N_);
  for(int i=0;i<a.N_;i++){
    sum.coef_[i] = a.coef_[i] + b.coef_[i];
  }
  return sum;

}

Vecteur operator-(const Vecteur& a, const Vecteur& b){

  Vecteur sum(a.N_);
  for(int i=0;i<a.N_;i++){
    sum.coef_[i] = a.coef_[i] - b.coef_[i];
  }
  return sum;

}

Vecteur operator*(double alpha, const Vecteur& v){
  Vecteur res(v.N_);
  for(unsigned int i=0;i<v.coef_.size();i++){
    res.coef_[i] = alpha*v.coef_[i];
  }
  return res;
}
double operator,(const Vecteur& a, const Vecteur& b){
  double r = 0.0;
  for(int i=0;i<a.N_;i++){
    r += a.coef_[i] * b.coef_[i];
  }
  return r;
}


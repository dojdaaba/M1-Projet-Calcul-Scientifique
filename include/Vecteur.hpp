#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include <vector>
#include <iostream>



class Vecteur{
private:
  int N_;
  std::vector<double> coef_;
public:
  Vecteur();
  Vecteur(int N);
  Vecteur(const Vecteur& v) = default;
  Vecteur(Vecteur&& v) = default;

  ~Vecteur() = default;

  int size() const;
  void display() const;

  void resize(int);
  void mise_a_zero();

  double norm() const;
  const Vecteur& operator+=(const Vecteur&);
  const Vecteur& operator-=(const Vecteur&);
  const Vecteur& operator*=(double);
  const Vecteur& operator=(Vecteur&);

  Vecteur& operator=(const Vecteur& f) = default;
  Vecteur& operator=(Vecteur&& v) = default;
  double& operator()(int i);
  double operator()(int i) const;



  friend std::ostream& operator<<(std::ostream&, const Vecteur&);
  friend Vecteur operator+(const Vecteur&, const Vecteur&);
  friend Vecteur operator-(const Vecteur&, const Vecteur&);
  friend Vecteur operator*(double, const Vecteur&);
  friend double operator,(const Vecteur&, const Vecteur&);
};




#endif

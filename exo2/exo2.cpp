
#include <iostream>
using namespace std;

class Fraction {
private:
  int numerateur;
  int denominateur;

public:
  /* ==================== */
  /*       Constructors   */
  /* ==================== */

  Fraction() : numerateur(1), denominateur(1) {}
  Fraction(int n, int d) : numerateur(n), denominateur(d) {}
  /* ==================== */
  /*       Setters        */
  /* ==================== */
  void setNumerateur(int n) {
    this->numerateur = n;
  }
  void setDenominateur(int d) {
    this->denominateur = d;
  }
  /* ==================== */
  /*       Getters        */
  /* ==================== */
  int getNumerateur()
  {
    return this->numerateur;
  }
  int getDenominateur() {
    return this->denominateur;
  }
  /* ==================== */
  /*       Methods        */
  /* ==================== */
  Fraction add(Fraction f) {
    Fraction result;
    result.setNumerateur(this->numerateur * f.denominateur + f.numerateur * this->denominateur);
    result.setDenominateur(this->denominateur * f.denominateur);
    return result;
  }
  Fraction minus(Fraction f) {
    Fraction result;
    result.setNumerateur(this->numerateur * f.denominateur - f.numerateur * this->denominateur);
    result.setDenominateur(this->denominateur * f.denominateur);
    return result;
  }
  Fraction multiply(Fraction f) {
    Fraction result;
    result.setNumerateur(this->numerateur * f.numerateur);
    result.setDenominateur(this->denominateur * f.denominateur);
    return result;
  }
  Fraction multiply(int n) {
    Fraction result;
    result.setNumerateur(this->numerateur * n);
    result.setDenominateur(this->denominateur);
    return result;
  }
  Fraction divide(Fraction f) {
    Fraction result;
    result.setNumerateur(this->numerateur * f.denominateur);
    result.setDenominateur(this->denominateur * f.numerateur);
    return result;
  }
  void simplify() {
    int a = this->numerateur;
    int b = this->denominateur;
    while (b != 0) {
      int t = b;
      b = a % b;
      a = t;
    }
    this->numerateur /= a;
    this->denominateur /= a;
    if (this->denominateur < 0) {
      this->denominateur = -this->denominateur;
      this->numerateur = -this->numerateur;
    }
  }
};
/*
You can write your class Fraction here
*/
int main() {
  /* Test constructors */
  Fraction f0;
  if (f0.getNumerateur() == 1 && f0.getDenominateur() == 1) {
    cout << "[OK] Default constructor works" << endl;
  } else {
    cout << "[FAILURE] Default constructor doesn't work" << endl;
  }
  Fraction f1(1, 2);
  if (f1.getNumerateur() == 1 && f1.getDenominateur() == 2) {
    cout << "[OK] Constructor with parameters works" << endl;
  } else {
    cout << "[FAILURE] Constructor with parameters doesn't work" << endl;
  }
  Fraction f2(3, 4);
  /* Test add */
  Fraction f3 = f1.add(f2);

  if (f3.getNumerateur() == 10 && f3.getDenominateur() == 8) {
    cout << "[OK] Add method works" << endl;
  } else {
    cout << "[FAILURE] Add method doesn't work" << endl;
  }
  /* Test minus */
  f3 = f1.minus(f2);
  if (f3.getNumerateur() == -2 && f3.getDenominateur() == 8) {
    cout << "[OK] Minus method works" << endl;
  } else {
    cout << "[FAILURE] Minus method doesn't work" << endl;
  }
  /* Test multiply */
  f3 = f1.multiply(f2);
  if (f3.getNumerateur() == 3 && f3.getDenominateur() == 8) {
    cout << "[OK] Multiply method works" << endl;
  } else {
    cout << "[FAILURE] Multiply method doesn't work" << endl;
  }
  /* Test divide */
  f3 = f1.divide(f2);
  if (f3.getNumerateur() == 4 && f3.getDenominateur() == 6) {
    cout << "[OK] Divide method works" << endl;
  } else{
    cout << "[FAILURE] Divide method doesn't work" << endl;
  }
  return 0;
}
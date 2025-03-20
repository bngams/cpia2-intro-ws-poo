#include <iostream>
using namespace std;

class Creature
{
private:
  int pv;
  int pa;
  int niveau;

public:
  Creature() : pv(5), pa(1), niveau(1) {}

  Creature(int pv, int pa, int niveau) : pv(pv), pa(pa), niveau(niveau) {}

  ~Creature() {}

  void affiche()
  {
    cout << "CREATURE PV: " << pv << " PA: " << pa << " Niveau: " << niveau << endl;
  }

  int attaque()
  {
    int facteurAleatoire = rand() % 10 + 1;
    int degats = (this->pa * this->niveau * facteurAleatoire) / 10;
    cout << "CREATURE attaque et inflige " << degats << " degats" << endl;
    return degats;
  }

  void subitDegats(int degats)
  {
    this->pv -= degats;
    cout << "CREATURE subit " << degats << " degats" << endl;
  }

  bool estVivant()
  {
    return this->pv > 0;
  }
};

class Heros
{

private:
  int pv;
  int pa;
  int niveau;
  string nom;

public:
  Heros() : pv(5), pa(1), niveau(1), nom("Hrun") {}

  Heros(int pv, int pa, int niveau, string nom) : pv(pv), pa(pa), niveau(niveau), nom(nom) {}

  ~Heros() {}

  void affiche()
  {
    cout << "HEROS " << nom << " PV: " << pv << " PA: " << pa << " Niveau: " << niveau << endl;
  }

  int attaque()
  {
    int facteurAleatoire = rand() % 10 + 1;
    int degats = (this->pa * this->niveau * facteurAleatoire) / 10;
    cout << "HEROS " << nom << " attaque et inflige " << degats << " degats" << endl;
    return degats;
  }

  void subitDegats(int degats)
  {
    this->pv -= degats;
    cout << "HEROS " << nom << " subit " << degats << " degats" << endl;
  }

  bool estVivant()
  {
    return this->pv > 0;
  }
};

int main()
{
  Heros heros{10, 10, 8, "Hrun"};
  Creature creature{10, 10, 5};

  heros.affiche();
  creature.affiche();

  int degats = heros.attaque();
  creature.subitDegats(degats);

  degats = creature.attaque();
  heros.subitDegats(degats);

  heros.affiche();
  creature.affiche();
  return 0;
}
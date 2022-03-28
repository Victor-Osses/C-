#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  class Pessoa{
    private:
        string nome;
    public:
        Pessoa(){}

        Pessoa(string nome){
            this->setNome("Victor");
        }

        string getNome(){
            return this->nome;
        }

        setNome(string nome){
            this->nome = nome;
        }
  };

  Pessoa p0;
  p0.setNome("Maria");
  cout << p0.getNome() << endl;

  Pessoa * p1 = new Pessoa("Victor Osses");
  cout << p1->getNome() << endl;
}

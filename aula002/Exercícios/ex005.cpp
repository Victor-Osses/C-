#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
    class Universidade{
        private:
            string nome;
        public:
            Universidade(string nome = "Unicamp"){
                this->setNome(nome);
            }
            setNome(string nome){
                this->nome = nome;
            }
            string getNome(){
                return this->nome;
            }
    };

    Universidade * unicamp = new Universidade();
    cout << unicamp->getNome() << endl;

    unicamp->setNome("Universidade Estadual de Campinas");
    cout << unicamp->getNome() << endl;

    delete unicamp;
}

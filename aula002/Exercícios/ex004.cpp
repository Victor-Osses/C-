#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
    setlocale(LC_ALL, "");

    class Pessoa{
        private:
            int idade;
        public:
            Pessoa(){}

            Pessoa(int idade){
                this->setIdade(idade);
            }

            setIdade(int idade){
                this->idade = idade;
            }

            int getIdade(){
                return this->idade;
            }
    };

    /*
    NEW: Tenta alocar e inicializar um objeto ou matriz de objetos de um tipo de espaço reservado ou especificado e retorna um
    ponteiro não zero para o objeto (ou para o objeto inicial da matriz).

    Quando new é usado para alocar memória para um objeto de classe C++, o construtor do objeto é chamado depois que a memória é
    alocada.

    Use o operador delete para desalocar a memória alocada pelo new operador
    */
    Pessoa * p1 = new Pessoa();
    p1->setIdade(19);

    cout << p1 << endl;
    cout << "Sua idade: " << p1->getIdade() << " anos" << endl;

    delete p1;;
}

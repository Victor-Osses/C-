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
    NEW: Tenta alocar e inicializar um objeto ou matriz de objetos de um tipo de espa�o reservado ou especificado e retorna um
    ponteiro n�o zero para o objeto (ou para o objeto inicial da matriz).

    Quando new � usado para alocar mem�ria para um objeto de classe C++, o construtor do objeto � chamado depois que a mem�ria �
    alocada.

    Use o operador delete para desalocar a mem�ria alocada pelo new operador
    */
    Pessoa * p1 = new Pessoa();
    p1->setIdade(19);

    cout << p1 << endl;
    cout << "Sua idade: " << p1->getIdade() << " anos" << endl;

    delete p1;;
}

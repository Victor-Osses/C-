#include <iostream>
#include <string>

using namespace std;

int main(int argc, char * argv[]){
    setlocale(LC_ALL, "");

    class Tabuada2{
        private:
            int number;
            string operacao;

            void soma(int number){
                for(int x = 1; x <= 10; x++){
                    cout << x << " + " << number << " = " << x + number << endl;
                }
            }

            void subtracao(int number){
                for(int x = 1; x <= 10; x++){
                    cout << x << " - " << number << " = " << x - number << endl;
                }
            }

            void multiplicacao(int number){
                for(int x = 1; x <= 10; x++){
                    cout << x << " * " << number << " = " << x * number << endl;
                }
            }

            void divisao(int number){
                if(number != 0){
                    for(int x = 1; x <= 10; x++){
                        cout << x << " / " << this->getNumber() << " = " << x / this->getNumber() << endl;
                    }
                }
                else {
                    cout << "Não é possível realizar divisões por 0! " << endl;
                }
            }

        public:
            Tabuada2 (int number = 1, string operacao = "SOMA"){
                this->setNumber(number);
                this->setOperacao(operacao);
            }

            setNumber(int number){
                this->number = number;
            }

            int getNumber(){
                return this->number;
            }

            setOperacao(string operacao){
                this->operacao = operacao;
            }

            string getOperacao(){
                return this->operacao;
            }

            void imprimirTabuada(){
                if(this->getOperacao() == "SOMA"){
                    this->soma(this->getNumber());
                }else if(this->getOperacao() == "SUBTRACAO"){
                    this->subtracao(this->getNumber());
                }else if(this->getOperacao() == "MULTIPLICACAO"){
                    this->multiplicacao(this->getNumber());
                }else{
                    this->divisao(this->getNumber());
                }
            }
    };

    Tabuada2 * tab = new Tabuada2(8, "MULTIPLICACAO");
    tab->imprimirTabuada();
    delete tab;
}

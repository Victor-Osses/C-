#include <iostream>

using namespace std;


int main(int argc, char * argv[]){
    setlocale(LC_ALL, "");
    class Tabuada1{
        private:
            int number;
        public:
            Tabuada1 (int number){
                this->setNumber(number);
            }

            setNumber(int number){
                this->number = number;
            }

            int getNumber(){
                return this->number;
            }

            void soma(){
                for(int x = 1; x <= 10; x++){
                    cout << x << " + " << this->getNumber() << " = " << x + this->getNumber()  << endl;
                }
            }

            void subtracao(){
                for(int x = 1; x <= 10; x++){
                    cout << x << " - " << this->getNumber() << " = " << x - this->getNumber() << endl;
                }
            }

            void multiplicacao(){
                for(int x = 1; x <= 10; x++){
                    cout << x << " x " << this->getNumber() << " = " << x * this->getNumber() << endl;
                }
            }

            void divisao(){
                if(this->getNumber() != 0 ) {
                    for(int x = 1; x <= 10; x++){
                        cout << x << " / " << this->getNumber() << " = " << x / this->getNumber() << endl;
                    }
                } else {
                    cout << "Não é possível realizar divisões por 0! " << endl;
                }
            }
    };

    Tabuada1 * tab = new Tabuada1(8);

    cout << "Tabuada da soma do " << tab->getNumber() << ":" << endl;
    tab->soma();

    cout << "\nTabuada da subtração do " << tab->getNumber() << ":" << endl;
    tab->subtracao();

    cout << "\nTabuada da multiplicação do " << tab->getNumber() << ":" << endl;
    tab->multiplicacao();

    cout << "\nTabuada da divisão do " << tab->getNumber() << ":" << endl;
    tab->divisao();
}

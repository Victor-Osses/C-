#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char * argv[]){

    class Potencia{
        private:
            double resultado;
        public:
            Potencia(){}

            setResultado(double resultado){
                this->resultado = resultado;
            }

            getResultado(){
                return this->resultado;
            }

            double calcula(int base, int expoente){
                this->setResultado(pow(base, expoente));
                cout << "Método de assinatura (int base, int expoente): " << this->getResultado() << endl;
            }

            double calcula(int base, double expoente){
                this->setResultado(pow(base, expoente));
                cout << "Método de assinatura (int base, double expoente): " << this->getResultado()  << endl;
            }

            double calcula(double base, double expoente){
                this->setResultado(pow(base, expoente));
                cout << "Método de assinatura (double base, double expoente): " << this->getResultado() << endl;
            }
    };

    Potencia * potencia = new Potencia();
    potencia->calcula(2, 2);
    potencia->calcula(2, 2.0);
    potencia->calcula(2.0, 2.0);
    delete potencia;

    return 0;
}

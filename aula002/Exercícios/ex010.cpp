#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
    setlocale(LC_ALL, "");

    class HotDog{
        private:
             string molho, batata, maionese, mostarda, picles, pimenta;
        public:
            HotDog(){}

            HotDog(bool molho = false, bool mostarda = false, bool batata = false, bool maionese = false, bool picles = false, bool pimenta = false){
                this->molho = molho ? ", molho" : "";
                this->batata = batata ? ", batata" : "";
                this->maionese = maionese ? ", maionese" : "";
                this->mostarda = mostarda ? ", mostarda" : "";
                this->picles = picles ? ", picles" : "";
                this->pimenta = pimenta ? " e pimenta" : "";
            }

            void deliveryHotDog(){
                cout
                << "Esse sanduíche possuí: pão, salsicha"
                << this->molho
                << this->mostarda
                << this->batata
                << this->maionese
                << this->picles
                << this->pimenta
                << endl;
            }
    };

    HotDog * sanduiche = new HotDog(true, true, false, true, true, true);
    sanduiche->deliveryHotDog();
    delete sanduiche;

    return 0;
}

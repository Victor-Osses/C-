#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
    setlocale(LC_ALL, "");

    class Forno{
        private:
            float temperatura;
        public:
            Forno(float temperatura = 0.0){
                this->setTemperatura(temperatura);
            }

            setTemperatura(float temperatura){
                if(temperatura < 0) temperatura = 0.0;
                else if(temperatura > 280) temperatura = 280;

                this->temperatura = temperatura;
            }

            float getTemperatura(){
                return this->temperatura;
            }

            void getStatus(){
                cout << "Forno cozinhando a " << this->getTemperatura() << " graus ";
            }
    };


    class FornoEletrico : public Forno{
        private:
            int voltagem;

        public:
            FornoEletrico(int voltagem = 110){
                this->setVoltagem(voltagem);
            }

            setVoltagem(float voltagem){
                this->voltagem = voltagem;
            }

            float getVoltagem(){
                return this->voltagem;
            }

            void getStatus(){
                cout << "\nForno elétrico: ";
                Forno::getStatus();
                cout << "com uma voltagem de " << this->getVoltagem() << "V" << endl;
            }
    };

     class FornoGas : public Forno{
        private:
            string gas;

        public:
            FornoGas(string gas = "GLP"){
                this->setGas(gas);
            }

            setGas(string gas){
                this->gas = gas;
            }

            string getGas(){
                return this->gas;
            }

            void getStatus(){
                cout << "Forno a gás: ";
                Forno::getStatus();
                cout << "utilizando gás " << this->getGas() << endl;
            }
    };

    class FornoLenha : public Forno{
        private:
            string tipoLenha;

        public:
            FornoLenha(string tipoLenha = "lenha macia"){
                this->setTipoLenha(tipoLenha);
            }

            setTipoLenha(string tipoLenha){
                this->tipoLenha = tipoLenha;
            }

            string getTipoLenha(){
                return this->tipoLenha;
            }

            void getStatus(){
                cout << "Forno à lenha: ";
                Forno::getStatus();
                cout << "utilizando " << this->getTipoLenha() << endl;
            }
    };

    Forno * forno = new Forno(60);
    forno->getStatus();

    FornoEletrico * fornoEletrico = new FornoEletrico(220);
    fornoEletrico->setTemperatura(45);
    fornoEletrico->getStatus();

    FornoGas * fornoGas = new FornoGas();
    fornoGas->setTemperatura(89);
    fornoGas->getStatus();

    FornoLenha * fornoLenha = new FornoLenha();
    fornoLenha->setTemperatura(187);
    fornoLenha->getStatus();

    delete forno;
    delete fornoEletrico;
    delete fornoGas;
    delete fornoLenha;
}

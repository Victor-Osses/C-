#include <iostream>
#include <cstdlib>

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
                cout << "\nForno el?trico: ";
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
                cout << "Forno a g?s: ";
                Forno::getStatus();
                cout << "utilizando g?s " << this->getGas() << endl;
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
                cout << "Forno ? lenha: ";
                Forno::getStatus();
                cout << "utilizando " << this->getTipoLenha() << endl;
            }
    };

    int * teste = (int *) malloc(4 * sizeof(int));
    teste[0] = 1.2;
    teste[1] = 2.2;
    cout << teste[1] << endl;

    Forno ** fornos = (Forno **) malloc(4 * sizeof(Forno *));

    Forno * forno = new Forno(60);
    fornos[0] = forno;

    FornoEletrico * fornoEletrico = new FornoEletrico(220);
    fornoEletrico->setTemperatura(45);
    fornos[1] = fornoEletrico;

    FornoGas * fornoGas = new FornoGas();
    fornoGas->setTemperatura(89);
    fornos[2] = fornoGas;

    FornoLenha * fornoLenha = new FornoLenha();
    fornoLenha->setTemperatura(187);
    fornos[3] = fornoLenha;

    for(int x = 0; x < 4; x++){
        fornos[x]->getStatus();
        cout << "\n" << endl;
    }

    delete forno;
    delete fornoEletrico;
    delete fornoGas;
    delete fornoLenha;
}

#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
    setlocale( LC_ALL, "" );

    int number1;
    float number2;
    string text;

    cout << "Informe um n�mero inteiro: ";
    cin >> number1;

    cout <<"\nInforme um n�mero real: ";
    cin >> number2;

    cout <<"\nInforme uma string: ";
    cin.ignore(); // A fun��o std::getline() � capaz de ler o dado de entrada at� que uma nova linha seja detectada
    getline(cin, text); // A fun��o std::ignore() limpa o caracter de nova linha \n do buffer de entrada std::cin.

    cout << "\nInteiro: " << number1 << "\nFloat: " << number2 << "\nString: " << text << endl;
}

#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
    setlocale( LC_ALL, "" );

    int number1;
    float number2;
    string text;

    cout << "Informe um número inteiro: ";
    cin >> number1;

    cout <<"\nInforme um número real: ";
    cin >> number2;

    cout <<"\nInforme uma string: ";
    cin.ignore(); // A função std::getline() é capaz de ler o dado de entrada até que uma nova linha seja detectada
    getline(cin, text); // A função std::ignore() limpa o caracter de nova linha \n do buffer de entrada std::cin.

    cout << "\nInteiro: " << number1 << "\nFloat: " << number2 << "\nString: " << text << endl;
}

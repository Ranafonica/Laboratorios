#include <iostream>
using namespace std;

int main(){

    int edad;

    cout << "Ingrese su edad: " << endl;
    cin >> edad;

    if (edad>=18 && edad<=25){
        cout << "Su edad se encuentra entre el rango solicitado" << endl;
    }
    else {
        cout << "Su edad no se encuentra entre el rango solicitado" << endl;
    }

    return 0;
}

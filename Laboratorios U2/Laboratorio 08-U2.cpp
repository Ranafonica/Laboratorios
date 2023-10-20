#include <iostream>
using namespace std;

bool Login (string user, string pass){

    int contador=0;
    bool comparacion;

    if (user=="user123"){
        contador++;
    }
    if (pass == "1234"){
        contador++;
    }
    if (contador == 2){
        comparacion = true;
    }

    return comparacion;
}
int main (){

	int intentosmax=3;
    bool acceso= false;
    
    while (intentosmax>0){
    	
    	string usuario;
    	string contra;
    	
    	cout << "Ingrese nombre de usuario: " << endl;
		cin >> usuario;

	    cout << "Ingrese contraseña: " << endl;
	    cin >> contra;
	
	    if (Login(usuario, contra)) {
	        acceso = true;
	        break;
	        
	    } else {
	    	intentosmax--;
	        cout << "Acceso denegado" << endl;
	        cout << "Intentos restantes: " << intentosmax << endl;
	    }
	    cout << "" << endl;   
	}
	 
    if (acceso){
    	cout << "!Acceso Exitoso!...Bienvenido user123" << endl;
	}
	else{
		cout << "Se han acabado los intentos. !Acceso denegado!" << endl;
	}
	
    return 0;
}

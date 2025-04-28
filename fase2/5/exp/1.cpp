#include <iostream>
#include <string>

using namespace std;

class CuentaBancaria{
    protected:
    string numero;
    string titular;
    double saldo;
//bob el constructor
    public:
    CuentaBancaria(string numero, string titular, double saldo){
        this-> numero=numero;
        this->titular=titular;
        this->saldo=saldo;
    }
//metodos
    CuentaBancaria& depositar(double montoD){
        if(montoD<0){
            cout<<"no se puede cpp es negativo tu webada"<<endl;
        }else{
            this->saldo+=montoD;
            cout<<"Monto exitante. Saldo actual: "<<saldo<<endl;
        }
        return *this;//retornda la referencia actual
    }

    CuentaBancaria& retirar(double montoR){
        if (montoR>0){
            this-> saldo-=montoR;
            cout<<"Retiro realizado correctamente. \nRetiraste: "<<montoR<<" MILLONES DE INTIS"<<endl;
        }else{
            cout<<"No tienes ni un sol cpp no te alcansa pi pi pi"<<endl;
        }
        return *this;
    }

    void mostrarSaldo(){
        cout<<"Saldo actual ("<<this->titular<<"): $"<<this->saldo<<" millones de intis."<<endl;
    }
};

int main() {
    // Crear una cuenta bancaria
    CuentaBancaria cuenta("123456", "Juan Perez", 500);

    // Encadenamiento: depositar -> retirar -> mostrarSaldo
    cuenta.depositar(1000).retirar(200).mostrarSaldo();

    return 0;
}
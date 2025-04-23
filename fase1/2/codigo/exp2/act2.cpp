#include <iostream>

using namespace std;

class CuentaBancaria{
    private:
    string numeroCuenta;
    double saldo;

    public:
    string titular;

    //bob
    CuentaBancaria(string NC, double s, string t)
    :numeroCuenta(NC),saldo(s),titular(t){}

    void depositar(double monto){
        if(monto>0){     
           saldo += monto;
           cout<<"Saldo deposita con exito.\nSaldo actual: "<<saldo<<endl;
        }else{
            cout<<"El monto debe ser positivo."<<endl;
        }
    }

    void retirar(double monto){
        if(monto>saldo){
            cout<<"no puedes hacer un retiro mayor a tu saldo.\nSaldo actual: "<<saldo<<endl;
        }else if(monto>0){
            saldo -= monto;
            cout<<"el retiro fue exitoso!\nSaldo actual: "<<saldo<<endl;
        }else{
            cout<<"El retiro debe ser positivo."<<endl;
        }
    }
//GET Y SET
    string getNumeroCuenta(){
        return numeroCuenta;
    }

    double getSaldo(){
        return saldo;
    }

    void setNumeroCuenta(string nuevoNumero){
        numeroCuenta=nuevoNumero;
    }
};

int main(){
    CuentaBancaria c1("987654 321 02", 500.0,"venito camelo");

    cout<<"Cuenta creada para: "<<c1.titular<<"\nSaldo: "<<c1.getSaldo()<<endl;
    
    c1.getNumeroCuenta();
    c1.depositar(30.0);
    c1.retirar(204.60);
    
    return 0;
};
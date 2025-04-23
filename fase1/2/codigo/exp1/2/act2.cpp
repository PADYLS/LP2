#include <iostream>

using namespace std;

class Carro {
    string modelo;
    int anio, velocidad;
//bob el constructor
    public:
    Carro(string m, int a): modelo(m),anio(a),velocidad(0) {};

    void acelerar(int incremento){
        velocidad += incremento;
        cout<<modelo<<"("<<anio<<") acelera a "<<velocidad<<" km/h."<<endl;
    }

    void frenar(int freno){
        velocidad -= freno;
        if(velocidad<0) velocidad=0;
        cout<<modelo<<"("<<anio<<") reduce la velocidad a "<<velocidad<<" km/h."<<endl;
    }
};

int main(){
    Carro c1("Bochito",1890);
    Carro c2("Ferrari",2025);

    c1.acelerar(90);
    c2.acelerar(80);

    c1.frenar(50);
    c2.frenar(80);
    return 0;
}
#include <iostream>

using namespace std;

class Animal {
    string especie, tipo;
    string nombre;
    int edad;

    //constructor
    public:
    Animal(string t,string e, string n, int ed) {
        tipo=t;
        especie = e;
        nombre = n;
        edad = ed;
    }
    void alimentar(){
        cout<< nombre <<" ha sido alimentado."<<endl;
    };

    void sonido(){
        if (tipo=="perro"){
            cout<<nombre <<" ta ladrando."<<endl;
        } else if (tipo=="gato"){
            cout<<nombre<<" ta maullando."<<endl;
        }else if(tipo == "hamster"){
            cout<<nombre<<" lo que haga esta cosa."<<endl;
        }
    }
};

int main(){
    Animal perro("perro","especie 1","firulais",4);
    Animal gato("gato","especie 1","michifu xd",1);
    Animal hamster("hamster","especie 2","rata",1);

    //probando metodos
    perro.alimentar();
    hamster.sonido();

    return 0;
}
#include <iostream>

using namespace std;

class zzz{
    private:
    string nombre;

    public:
    zzz(string n):nombre(n){};

    string getnombre(){
        return nombre;
    }; 

    void setnombre(string nuevo_nombre){
        nombre=nuevo_nombre;
        cout<<"Se cambio el nombre con exito!"<<endl;
    };
};

int main(){
    zzz h1("roberto");

    cout<<"nombre actual: "<<h1.getnombre()<<endl;
    h1.setnombre("spectro");
    cout<<"nuevo nombre: "<<h1.getnombre()<<endl;
}

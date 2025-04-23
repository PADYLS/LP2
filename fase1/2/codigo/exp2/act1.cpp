#include <iostream>

using namespace std;

class Persona{
    private:
    int DNI;

    public:
    string nombre;
    int edad;

    //constructor
    Persona(int dni, string n, int e):DNI(dni), nombre(n),edad(e){}

    //set y get
    int getDNI(){
        return DNI;
    }

    void setDNI(int nuevoDNI){
        DNI=nuevoDNI;
        cout<<"DNI modificado a: "<<DNI<<endl;
    }

    int getedad(){
        return edad;
    }

    void setedad(int nuevaEdad){
        if (nuevaEdad>0){
            edad=nuevaEdad;
        }else{
            cout<<"La edad no puede ser negativa."<<endl;
        }
    }
};

int main(){
    Persona p1(1234567,"Jorge",18);

    cout<<"DNI: "<<p1.getDNI()<<endl;
    cout<<"EDAD: "<<p1.getedad()<<endl;

    p1.setDNI(7878789);
    p1.setedad(-1);

    cout<<"nuevo DNI: "<<p1.getDNI()<<endl;
    cout<<"nueva EDAD: "<<p1.getedad()<<endl;

    return 0;
}
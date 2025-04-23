#include <iostream>
using namespace std;

class Estudiante{
    string nombre;
    int codigo,edad, grado;
    //contructor
    public:
    Estudiante(string n,int cod, int e, int g):nombre(n),codigo(cod),edad(e),grado(g){}

    void TomarExamen(){
        cout<<nombre<<" ha ralizado examen en el "<<grado<<endl;
    };

    void RecibirNota(float nota){
        cout<<nombre<<" ha recibido una calificacion de "<<nota<<endl;
        if(nota>11)
            cout<<"APROBADO"<<endl;
        else
            cout<<"DESAPROBADO"<<endl;
    };
};
int main(){
    Estudiante e1("Jose",332,12,3);
    Estudiante e2("Fatima",333,12,3);

    //tomar examen
    e1.TomarExamen();
    e2.TomarExamen();

    //recibir nota
    e1.RecibirNota(15.3);
    e2.RecibirNota(9.1);

    return 0;
};

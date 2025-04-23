#include <iostream>

using namespace std;

class Libro{
    private:
    string titulo, autor, genero;
    int codigo;
    
    public:
    string biblioteca;
//bob
    Libro(string t, string a, string g, int c, string b)
    :titulo(t),autor(a),genero(g),codigo(c),biblioteca(b){}

//set y gets
    string getTitulo(){
        return titulo;
    };

    string getAutor(){
        return autor;
    };

    string getgenero(){
        return genero;
    };

    int getCoidgo(){
        return codigo;
    }

    void setGenero(string nuevoG){
        genero=nuevoG;
        cout<<"Genero cambiado con exito ahora es: "<<genero<<endl;
    };

    void cambiarCodigo(int nuevoCodigo){
        cout<<"Error: No se puede cambiar el codigo."<<endl;
    }
};

int main(){
    Libro l1("Game of Throns","nose","terror",654,"UCSM");
    cout<<"Libro agregado con exito!\nCodigo: "<<l1.getCoidgo()<<"\nTitulo: "<<l1.getTitulo()<<"\nAutor: "<<l1.getAutor()<<"\nGenero: "<<l1.getgenero()
    <<"\nBiblioteca: "<<l1.biblioteca<<endl;

    l1.setGenero("aventura");
    
    l1.cambiarCodigo(54212);
    
    return 0;
}
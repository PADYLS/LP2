#include <iostream>
#include <string>

using namespace std;

class Hijo {
private:
    string nombre;

public:
    Hijo(string nombre) : nombre(nombre) {}

    string getNombre() const {
        return nombre;
    }

    void setNombre(string nuevoNombre) {
        nombre = nuevoNombre;
    }
};

class Padre {
private:
    string nombre;
    Hijo* hijos[10];  // Arreglo de punteros a Hijo (tamaño máximo 10)
    int numHijos;

public:
    Padre(string nombre) : nombre(nombre), numHijos(0) {
        // Inicializar el arreglo de punteros a nullptr
        for (int i = 0; i < 10; ++i) {
            hijos[i] = nullptr;
        }
    }

    string getNombre() const {
        return nombre;
    }

    void setNombre(string nuevoNombre) {
        nombre = nuevoNombre;
    }

    void agregarHijo(Hijo* hijo) {
        if (numHijos < 2) {
            hijos[numHijos] = hijo;
            numHijos++;
        } else {
            cout << "No se pueden agregar mas hijos, se alcanzo el límite." << endl;
        }
    }

    void imprimirInfo() const {
        cout << "Padre: " << nombre << endl;
        cout << "Cantidad de hijos: " << numHijos << endl;
        cout << "Hijos:" << endl;
        for (int i = 0; i < numHijos; ++i) {
            if (hijos[i] != nullptr) {
                cout << " - " << hijos[i]->getNombre() << endl;
            }
        }
    }
};

int main() {
    Padre padre("Juan Perez");
    
    Hijo hijo1("Carlos Perez");
    Hijo hijo2("Maria Perez");
    Hijo hijo3("Luis Perez");
    
    padre.agregarHijo(&hijo1);
    padre.agregarHijo(&hijo2);
    padre.agregarHijo(&hijo3);
    
    padre.imprimirInfo();

    return 0;
}
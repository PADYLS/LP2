#include <iostream>
#include <string>
using namespace std;

class Dispositivo {
private:
    string marca;
    string modelo;
    int anioFabricacion;

public:
    // 1. Constructor predeterminado (por defecto)
    Dispositivo() {
        marca = "Sin marca";
        modelo = "Sin modelo";
        anioFabricacion = 0;
        cout << "Constructor predeterminado -> " << modelo << endl;
    }

    // 2. Constructor parametrizado
    Dispositivo(string marca, string modelo, int anio) {
        this->marca = marca;
        this->modelo = modelo;
        this->anioFabricacion = anio;
        cout << "Constructor parametrizado -> " << modelo << endl;
    }

    // 3. Constructor de copia
    Dispositivo(const Dispositivo &otro) {
        this->marca = otro.marca;
        this->modelo = otro.modelo + " (copia)";
        this->anioFabricacion = otro.anioFabricacion;
        cout << "Constructor de copia -> " << modelo << endl;
    }

    // 4. Destructor (se ejecuta al destruir el objeto)
    ~Dispositivo() {
        cout << "Destructor -> Dispositivo " << modelo << " destruido." << endl;
    }

    // Método para mostrar datos (opcional)
    void mostrarDatos() {
        cout << marca << " " << modelo << " (" << anioFabricacion << ")" << endl;
    }
};

int main() {
    cout << "\n--- Creacion de dispositivos individuales ---" << endl;
    Dispositivo d1; // Constructor predeterminado
    Dispositivo d2("Samsung", "Galaxy S23", 2023); // Constructor parametrizado
    Dispositivo d3 = d2; // Constructor de copia

    cout << "\n--- Creacion de un arreglo de dispositivos ---" << endl;
    Dispositivo dispositivos[3] = {
        Dispositivo(), // Predeterminado
        Dispositivo("Apple", "iPhone 15", 2023), // Parametrizado
        d2 // Copia
    };

    cout << "\n--- Mostrando datos del arreglo ---" << endl;
    for (int i = 0; i < 3; i++) {
        dispositivos[i].mostrarDatos();
    }

    cout << "\n--- Fin del main() (los destructores se llamarán automaticamente) ---" << endl;
    return 0;
}
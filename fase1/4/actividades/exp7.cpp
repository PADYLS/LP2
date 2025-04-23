#include <iostream>
#include <string>

using namespace std;

// Clase base (superclase)
class Vehiculo {
protected:
    string marca;
    string modelo;
    int anio;
    double precio;

public:
    // Constructor de la clase base
    Vehiculo(string marca, string modelo, int anio, double precio)
        : marca(marca), modelo(modelo), anio(anio), precio(precio) {
        cout << "Constructor de Vehiculo llamado" << endl;
    }

    // Destructor virtual para permitir polimorfismo
    virtual ~Vehiculo() {
        cout << "Destructor de Vehiculo llamado" << endl;
    }

    // Métodos comunes
    void mostrarInformacion() const {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "anio: " << anio << endl;
        cout << "Precio: $" << precio << endl;
    }

    void setPrecio(double nuevoPrecio) {
        precio = nuevoPrecio;
        cout << "Precio actualizado a $" << precio << endl;
    }
};

// Clase derivada (subclase)
class Automovil : public Vehiculo {
private:
    int numPuertas;
    string tipoCombustible;
    bool aireAcondicionado;

public:
    // Constructor que llama al constructor de la clase base
    Automovil(string marca, string modelo, int anio, double precio,
              int numPuertas, string tipoCombustible, bool aireAcondicionado)
        : Vehiculo(marca, modelo, anio, precio), 
          numPuertas(numPuertas), 
          tipoCombustible(tipoCombustible),
          aireAcondicionado(aireAcondicionado) {
        cout << "Constructor de Automovil llamado" << endl;
    }

    // Destructor
    ~Automovil() {
        cout << "Destructor de Automovil llamado" << endl;
    }

    // Métodos específicos de Automovil
    void mostrarDetalles() const {
        mostrarInformacion(); // Llamada al método heredado
        cout << "Numero de puertas: " << numPuertas << endl;
        cout << "Tipo de combustible: " << tipoCombustible << endl;
        cout << "Aire acondicionado: " << (aireAcondicionado ? "Si" : "No") << endl;
    }

    void encenderAireAcondicionado() {
        if (aireAcondicionado) {
            cout << "Aire acondicionado encendido" << endl;
        } else {
            cout << "Este automovil no tiene aire acondicionado" << endl;
        }
    }

    void setNumPuertas(int puertas) {
        numPuertas = puertas;
        cout << "Numero de puertas actualizado a " << numPuertas << endl;
    }
};

int main() {
    // Crear objeto de la clase derivada
    cout << "=== CREANDO AUTOMOVIL ===" << endl;
    Automovil miAuto("Toyota", "Corolla", 2023, 25000.50, 4, "Gasolina", true);
    
    cout << "\n=== ACCEDIENDO A MIEMBROS HEREDADOS ===" << endl;
    // Acceder a métodos heredados
    miAuto.mostrarInformacion();
    miAuto.setPrecio(24500.75);
    
    cout << "\n=== ACCEDIENDO A MIEMBROS PROPIOS ===" << endl;
    // Acceder a métodos propios
    miAuto.mostrarDetalles();
    miAuto.encenderAireAcondicionado();
    miAuto.setNumPuertas(5);
    
    cout << "\n=== MODIFICANDO ATRIBUTOS ===" << endl;
    // Modificar atributos
    miAuto.setPrecio(24000.00);
    miAuto.setNumPuertas(4);
    
    cout << "\n=== INFORMACION FINAL ===" << endl;
    miAuto.mostrarDetalles();
    
    cout << "\n=== FINALIZANDO ===" << endl;
    // El destructor se llama automáticamente al salir del ámbito
    return 0;
}
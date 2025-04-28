#include <iostream>
#include <string>

using namespace std;

class Fecha {
    private:
        int dia, mes, anio;
    public:
        Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}
        void mostrar() const {
            cout << dia << "/" << mes << "/" << anio << endl;
        }
};

class Contrato {
private:
    string codigo;
    string descripcion;
    Fecha fechaInicio;
public:
    // Constructor con lista de inicialización
    Contrato(const string& cod, const string& desc, const Fecha& fecha)
        : codigo(cod), descripcion(desc), fechaInicio(fecha) {}

    // Método para mostrar los datos del contrato
    void mostrar() const {
        cout << "Código: " << codigo << endl
             << "Descripción: " << descripcion << endl
             << "Fecha de inicio: ";
        fechaInicio.mostrar();
    }
};

class Empleado {
    private:
        string nombre;
        Contrato contrato;
    public:
        // Constructor con lista de inicialización
        Empleado(const string& nom, const Contrato& cont)
            : nombre(nom), contrato(cont) {}
    
        // Método para mostrar toda la información
        void mostrar() const {
            cout << "=== Datos del Empleado ===" << endl
                 << "Nombre: " << nombre << endl
                 << "--- Detalles del Contrato ---" << endl;
            contrato.mostrar();
        }
};

int main() {
    // Crear una fecha para el contrato (usando tu clase Fecha)
    Fecha fechaContrato(15, 6, 2023);

    // Crear un contrato
    Contrato contratoEmp("CTR-2023-001", "Contrato indefinido", fechaContrato);

    // Crear un empleado con ese contrato
    Empleado empleado("Carlos Méndez", contratoEmp);

    // Mostrar toda la información
    empleado.mostrar();

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

const int MAX_TRABAJADORES = 10; // Tamaño máximo del arreglo

class Trabajador {
protected:
    string nombre;
    string id;
    Trabajador* companeros[MAX_TRABAJADORES];
    int numCompaneros;

public:
    Trabajador(string nombre, string id) : nombre(nombre), id(id), numCompaneros(0) {
        for (int i = 0; i < MAX_TRABAJADORES; ++i) {
            companeros[i] = nullptr;
        }
    }

    string getNombre() const { return nombre; }
    string getId() const { return id; }

    void agregarCompanero(Trabajador* companero) {
        if (numCompaneros < MAX_TRABAJADORES && companero != this) {
            // Verificar que no sea el mismo trabajador y que no esté ya agregado
            bool existe = false;
            for (int i = 0; i < numCompaneros; ++i) {
                if (companeros[i] == companero) {
                    existe = true;
                    break;
                }
            }
            
            if (!existe) {
                companeros[numCompaneros] = companero;
                numCompaneros++;
                // Relación bidireccional
                companero->agregarCompanero(this);
            }
        }
    }

    void imprimirCompaneros() const {
        cout << "Companeros de " << nombre << " (" << id << "):" << endl;
        for (int i = 0; i < numCompaneros; ++i) {
            if (companeros[i] != nullptr) {
                cout << "- " << companeros[i]->getNombre() 
                     << " (" << companeros[i]->getId() << ")" << endl;
            }
        }
        cout << endl;
    }
};

class Gerente : public Trabajador {
private:
    Trabajador* equipo[MAX_TRABAJADORES];
    int numEquipo;

public:
    Gerente(string nombre, string id) : Trabajador(nombre, id), numEquipo(0) {
        for (int i = 0; i < MAX_TRABAJADORES; ++i) {
            equipo[i] = nullptr;
        }
    }

    void agregarAlEquipo(Trabajador* trabajador) {
        if (numEquipo < MAX_TRABAJADORES && trabajador != this) {
            // Verificar que no sea el mismo gerente y que no esté ya en el equipo
            bool existe = false;
            for (int i = 0; i < numEquipo; ++i) {
                if (equipo[i] == trabajador) {
                    existe = true;
                    break;
                }
            }
            
            if (!existe) {
                equipo[numEquipo] = trabajador;
                numEquipo++;
                
                // Establecer relación entre compañeros de equipo
                for (int i = 0; i < numEquipo - 1; ++i) {
                    equipo[i]->agregarCompanero(trabajador);
                }
            }
        }
    }

    void imprimirEquipo() const {
        cout << "Equipo del gerente " << nombre << " (" << id << "):" << endl;
        for (int i = 0; i < numEquipo; ++i) {
            if (equipo[i] != nullptr) {
                cout << "- " << equipo[i]->getNombre() 
                     << " (" << equipo[i]->getId() << ")" << endl;
            }
        }
        cout << endl;
    }
};

int main() {
    // Crear trabajadores
    Trabajador t1("Juan Perez", "T1001");
    Trabajador t2("Maria Gomez", "T1002");
    Trabajador t3("Carlos Lopez", "T1003");
    Trabajador t4("Ana Martinez", "T1004");

    // Crear gerentes
    Gerente g1("Pedro Ramirez", "G2001");
    Gerente g2("Laura Jimenez", "G2002");

    // Asignar trabajadores a equipos de gerentes
    g1.agregarAlEquipo(&t1);
    g1.agregarAlEquipo(&t2);
    g2.agregarAlEquipo(&t3);
    g2.agregarAlEquipo(&t4);

    // También podemos agregar relaciones directas entre trabajadores
    t1.agregarCompanero(&t3);

    // Imprimir información
    cout << "=== Relaciones de companerismo ===" << endl;
    t1.imprimirCompaneros();
    t2.imprimirCompaneros();
    t3.imprimirCompaneros();
    t4.imprimirCompaneros();

    cout << "=== Equipos de gerentes ===" << endl;
    g1.imprimirEquipo();
    g2.imprimirEquipo();

    return 0;
}
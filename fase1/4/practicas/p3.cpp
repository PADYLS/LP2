#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Clase Profesor
class Profesor {
private:
    string nombre;
    string direccion;
    string telefono;
    vector<string> asignaturasImpartidas;

public:
    Profesor(string nombre, string direccion, string telefono)
        : nombre(nombre), direccion(direccion), telefono(telefono) {}

    void agregarAsignatura(string codigoAsignatura) {
        asignaturasImpartidas.push_back(codigoAsignatura);
    }

    string getNombre() const { return nombre; }
    vector<string> getAsignaturas() const { return asignaturasImpartidas; }
};

// Clase Asignatura
class Asignatura {
private:
    string codigo;
    string nombre;
    string descripcion;
    Profesor* profesor;

public:
    Asignatura(string codigo, string nombre, string descripcion, Profesor* prof)
        : codigo(codigo), nombre(nombre), descripcion(descripcion), profesor(prof) {
        profesor->agregarAsignatura(codigo);
    }

    string getCodigo() const { return codigo; }
    string getNombre() const { return nombre; }
    Profesor* getProfesor() const { return profesor; }
};

// Clase Estudiante
class Estudiante {
private:
    string nombre;
    string direccion;
    string matricula;
    vector<Asignatura*> asignaturasMatriculadas;
    map<string, double> notas;
    map<string, int> faltas;

public:
    Estudiante(string nombre, string direccion, string matricula)
        : nombre(nombre), direccion(direccion), matricula(matricula) {}

    void matricularAsignatura(Asignatura* asignatura) {
        asignaturasMatriculadas.push_back(asignatura);
        notas[asignatura->getCodigo()] = 0.0;
        faltas[asignatura->getCodigo()] = 0;
    }

    void registrarNota(string codigoAsignatura, double nota) {
        notas[codigoAsignatura] = nota;
    }

    void registrarFalta(string codigoAsignatura) {
        faltas[codigoAsignatura]++;
    }

    void mostrarInformacion() const {
        cout << "\nEstudiante: " << nombre << " (" << matricula << ")\n";
        cout << "Asignaturas matriculadas:\n";
        for (const auto& asignatura : asignaturasMatriculadas) {
            cout << "- " << asignatura->getNombre() << " (" << asignatura->getCodigo() << ")\n";
            cout << "  Nota: " << notas.at(asignatura->getCodigo()) << endl;
            cout << "  Faltas: " << faltas.at(asignatura->getCodigo()) << endl;
        }
    }
};

// Función principal
int main() {
    // Crear profesor
    Profesor profesor("Dr. Rodriguez", "Calle Universidad", "555-9012");
    
    // Crear asignaturas
    Asignatura matematicas("MAT-101", "Matematicas I", "Algebra lineal", &profesor);
    Asignatura programacion("PROG-102", "Programacion I", "Fundamentos de C++", &profesor);
    
    // Crear estudiantes
    Estudiante estudiante1("Carlos Lopez", "Residencia Universitaria", "20230001");
    Estudiante estudiante2("Maria Garcia", "Av. Central 123", "20230002");
    
    // Matricular estudiantes
    estudiante1.matricularAsignatura(&matematicas);
    estudiante1.matricularAsignatura(&programacion);
    estudiante2.matricularAsignatura(&programacion);
    
    // Registrar notas y faltas
    estudiante1.registrarNota("MAT-101", 8.5);
    estudiante1.registrarFalta("MAT-101");
    estudiante1.registrarNota("PROG-102", 7.0);
    
    estudiante2.registrarNota("PROG-102", 9.0);
    estudiante2.registrarFalta("PROG-102");
    estudiante2.registrarFalta("PROG-102");
    
    // Mostrar información
    cout << "=== SISTEMA UNIVERSITARIO ===" << endl;
    estudiante1.mostrarInformacion();
    estudiante2.mostrarInformacion();
    
    cout << "\nAsignaturas impartidas por " << profesor.getNombre() << ":\n";
    for (const auto& codigo : profesor.getAsignaturas()) {
        cout << "- " << codigo << endl;
    }
    
    return 0;
}
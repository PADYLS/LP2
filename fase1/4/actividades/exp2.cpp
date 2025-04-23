#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Declaracion anticipada
class Estudiante;

class Curso {
private:
    string nombre;
    string codigo;
    string descripcion;
    string fechaInicio;
    string fechaFinalizacion;
    vector<Estudiante*> estudiantes;

public:
    Curso(string nombre, string codigo, string descripcion, string fechaInicio, string fechaFinalizacion)
        : nombre(nombre), codigo(codigo), descripcion(descripcion),
          fechaInicio(fechaInicio), fechaFinalizacion(fechaFinalizacion) {}

    string getNombre() const { return nombre; }
    string getCodigo() const { return codigo; }

    void agregarEstudiante(Estudiante* estudiante);
    void eliminarEstudiante(Estudiante* estudiante);
    void imprimirEstudiantes() const;
};

class Estudiante {
private:
    string nombre;
    string apellido;
    string identificacion;
    string email;
    vector<Curso*> cursos;

public:
    Estudiante(string nombre, string apellido, string identificacion, string email)
        : nombre(nombre), apellido(apellido), identificacion(identificacion), email(email) {}

    string getNombreCompleto() const {
        return nombre + " " + apellido;
    }
    string getIdentificacion() const { return identificacion; }

    void agregarCurso(Curso* curso) {
        if (find(cursos.begin(), cursos.end(), curso) == cursos.end()) {
            cursos.push_back(curso);
            curso->agregarEstudiante(this);
        }
    }

    void eliminarCurso(Curso* curso) {
        auto it = find(cursos.begin(), cursos.end(), curso);
        if (it != cursos.end()) {
            cursos.erase(it);
            curso->eliminarEstudiante(this);
        }
    }

    void imprimirCursos() const {
        cout << "Cursos del estudiante " << getNombreCompleto() << " (" << identificacion << "):" << endl;
        for (const auto& cur : cursos) {
            if (cur != nullptr) {
                cout << "- " << cur->getNombre() << " (" << cur->getCodigo() << ")" << endl;
            }
        }
        cout << endl;
    }
};

// Implementacion de metodos de Curso
void Curso::agregarEstudiante(Estudiante* estudiante) {
    if (find(estudiantes.begin(), estudiantes.end(), estudiante) == estudiantes.end()) {
        estudiantes.push_back(estudiante);
    }
}

void Curso::eliminarEstudiante(Estudiante* estudiante) {
    auto it = find(estudiantes.begin(), estudiantes.end(), estudiante);
    if (it != estudiantes.end()) {
        estudiantes.erase(it);
    }
}

void Curso::imprimirEstudiantes() const {
    cout << "Estudiantes del curso " << nombre << " (" << codigo << "):" << endl;
    for (const auto& est : estudiantes) {
        if (est != nullptr) {
            cout << "- " << est->getNombreCompleto() << endl;
        }
    }
    cout << endl;
}

// Programa principal de prueba
int main() {
    // Crear cursos
    Curso curso1("Programacion I", "PROG101", "Introduccion a la programacion", "2023-03-01", "2023-06-30");
    Curso curso2("Base de Datos", "BD202", "Fundamentos de bases de datos", "2023-03-15", "2023-07-15");
    Curso curso3("Redes", "RED301", "Redes de computadoras", "2023-04-01", "2023-08-01");

    // Crear estudiantes
    Estudiante est1("Juan", "Perez", "E1001", "juan.perez@email.com");
    Estudiante est2("Maria", "Gomez", "E1002", "maria.gomez@email.com");
    Estudiante est3("Carlos", "Lopez", "E1003", "carlos.lopez@email.com");

    // Establecer relaciones bidireccionales
    cout << "=== Agregando relaciones ===\n";
    est1.agregarCurso(&curso1);
    est1.agregarCurso(&curso2);
    est2.agregarCurso(&curso1);
    est2.agregarCurso(&curso3);
    est3.agregarCurso(&curso2);
    est3.agregarCurso(&curso3);

    // Imprimir estado inicial
    curso1.imprimirEstudiantes();
    curso2.imprimirEstudiantes();
    curso3.imprimirEstudiantes();

    est1.imprimirCursos();
    est2.imprimirCursos();
    est3.imprimirCursos();

    // Eliminar algunas relaciones
    cout << "=== Eliminando algunas relaciones ===\n";
    est1.eliminarCurso(&curso2);
    curso1.eliminarEstudiante(&est2);

    // Imprimir estado despues de eliminar
    curso1.imprimirEstudiantes();
    curso2.imprimirEstudiantes();
    curso3.imprimirEstudiantes();

    est1.imprimirCursos();
    est2.imprimirCursos();
    est3.imprimirCursos();

    return 0;
}
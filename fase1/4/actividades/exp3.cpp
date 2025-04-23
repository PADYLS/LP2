#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Declaraciones anticipadas
class Estudiante;
class Docente;
class Curso;

// Clase Asociacion
class Asociacion {
private:
    Estudiante* estudiante;
    Docente* docente;
    Curso* curso;

public:
    Asociacion(Estudiante* est, Docente* doc, Curso* cur);
    
    Estudiante* getEstudiante() const { return estudiante; }
    Docente* getDocente() const { return docente; }
    Curso* getCurso() const { return curso; }
    
    void imprimirInfo() const;
};

// Clase Estudiante
class Estudiante {
private:
    string nombre;
    string codigo;
    vector<Asociacion*> asociaciones;

public:
    Estudiante(string nombre, string codigo);
    
    string getNombre() const { return nombre; }
    string getCodigo() const { return codigo; }
    
    void agregarAsociacion(Asociacion* asociacion);
    void imprimirCursosYDocentes() const;
};

// Clase Docente
class Docente {
private:
    string nombre;
    string especialidad;
    vector<Asociacion*> asociaciones;

public:
    Docente(string nombre, string especialidad);
    
    string getNombre() const { return nombre; }
    string getEspecialidad() const { return especialidad; }
    
    void agregarAsociacion(Asociacion* asociacion);
    void imprimirEstudiantesYCursos() const;
};

// Clase Curso
class Curso {
private:
    string nombre;
    string codigo;
    vector<Asociacion*> asociaciones;

public:
    Curso(string nombre, string codigo);
    
    string getNombre() const { return nombre; }
    string getCodigo() const { return codigo; }
    
    void agregarAsociacion(Asociacion* asociacion);
    void imprimirEstudiantesYDocentes() const;
};

// Implementación de métodos después de todas las definiciones de clase

// Asociacion
Asociacion::Asociacion(Estudiante* est, Docente* doc, Curso* cur) 
    : estudiante(est), docente(doc), curso(cur) {}

void Asociacion::imprimirInfo() const {
    if (estudiante && docente && curso) {
        cout << "Asociacion: " << endl
             << "- Estudiante: " << estudiante->getNombre() << endl
             << "- Docente: " << docente->getNombre() << endl
             << "- Curso: " << curso->getNombre() << endl << endl;
    }
}

// Estudiante
Estudiante::Estudiante(string nombre, string codigo) 
    : nombre(nombre), codigo(codigo) {}

void Estudiante::agregarAsociacion(Asociacion* asociacion) {
    if (asociacion) {
        asociaciones.push_back(asociacion);
    }
}

void Estudiante::imprimirCursosYDocentes() const {
    cout << "Cursos y docentes del estudiante " << nombre << " (" << codigo << "):" << endl;
    vector<string> relacionesMostradas;
    
    for (const auto& asoc : asociaciones) {
        if (asoc && asoc->getCurso() && asoc->getDocente()) {
            string relacion = "- Curso: " + asoc->getCurso()->getNombre() + 
                           " | Docente: " + asoc->getDocente()->getNombre();
            
            if (find(relacionesMostradas.begin(), relacionesMostradas.end(), relacion) == relacionesMostradas.end()) {
                cout << relacion << endl;
                relacionesMostradas.push_back(relacion);
            }
        }
    }
    cout << endl;
}

// Docente
Docente::Docente(string nombre, string especialidad) 
    : nombre(nombre), especialidad(especialidad) {}

void Docente::agregarAsociacion(Asociacion* asociacion) {
    if (asociacion) {
        asociaciones.push_back(asociacion);
    }
}

void Docente::imprimirEstudiantesYCursos() const {
    cout << "Estudiantes y cursos del docente " << nombre << " (" << especialidad << "):" << endl;
    vector<string> relacionesMostradas;
    
    for (const auto& asoc : asociaciones) {
        if (asoc && asoc->getEstudiante() && asoc->getCurso()) {
            string relacion = "- Estudiante: " + asoc->getEstudiante()->getNombre() + 
                            " | Curso: " + asoc->getCurso()->getNombre();
            
            if (find(relacionesMostradas.begin(), relacionesMostradas.end(), relacion) == relacionesMostradas.end()) {
                cout << relacion << endl;
                relacionesMostradas.push_back(relacion);
            }
        }
    }
    cout << endl;
}

// Curso
Curso::Curso(string nombre, string codigo) 
    : nombre(nombre), codigo(codigo) {}

void Curso::agregarAsociacion(Asociacion* asociacion) {
    if (asociacion) {
        asociaciones.push_back(asociacion);
    }
}

void Curso::imprimirEstudiantesYDocentes() const {
    cout << "Estudiantes y docentes del curso " << nombre << " (" << codigo << "):" << endl;
    vector<string> relacionesMostradas;
    
    for (const auto& asoc : asociaciones) {
        if (asoc && asoc->getEstudiante() && asoc->getDocente()) {
            string relacion = "- Estudiante: " + asoc->getEstudiante()->getNombre() + 
                           " | Docente: " + asoc->getDocente()->getNombre();
            
            if (find(relacionesMostradas.begin(), relacionesMostradas.end(), relacion) == relacionesMostradas.end()) {
                cout << relacion << endl;
                relacionesMostradas.push_back(relacion);
            }
        }
    }
    cout << endl;
}

// Programa principal
int main() {
    // Crear instancias
    Estudiante* est1 = new Estudiante("Juan Perez", "E1001");
    Estudiante* est2 = new Estudiante("Maria Gomez", "E1002");
    
    Docente* doc1 = new Docente("Carlos Lopez", "Informatica");
    Docente* doc2 = new Docente("Ana Martinez", "Bases de Datos");
    
    Curso* curso1 = new Curso("Programacion I", "PROG101");
    Curso* curso2 = new Curso("Base de Datos", "BD202");

    // Crear asociaciones
    Asociacion* asoc1 = new Asociacion(est1, doc1, curso1);
    Asociacion* asoc2 = new Asociacion(est1, doc2, curso2);
    Asociacion* asoc3 = new Asociacion(est2, doc1, curso1);
    Asociacion* asoc4 = new Asociacion(est2, doc2, curso2);

    // Establecer relaciones
    est1->agregarAsociacion(asoc1);
    est1->agregarAsociacion(asoc2);
    est2->agregarAsociacion(asoc3);
    est2->agregarAsociacion(asoc4);
    
    doc1->agregarAsociacion(asoc1);
    doc1->agregarAsociacion(asoc3);
    doc2->agregarAsociacion(asoc2);
    doc2->agregarAsociacion(asoc4);
    
    curso1->agregarAsociacion(asoc1);
    curso1->agregarAsociacion(asoc3);
    curso2->agregarAsociacion(asoc2);
    curso2->agregarAsociacion(asoc4);

    // Imprimir información
    cout << "=== Informacion de las asociaciones ===" << endl;
    asoc1->imprimirInfo();
    asoc2->imprimirInfo();
    asoc3->imprimirInfo();
    asoc4->imprimirInfo();

    cout << "=== Vista desde los estudiantes ===" << endl;
    est1->imprimirCursosYDocentes();
    est2->imprimirCursosYDocentes();

    cout << "=== Vista desde los docentes ===" << endl;
    doc1->imprimirEstudiantesYCursos();
    doc2->imprimirEstudiantesYCursos();

    cout << "=== Vista desde los cursos ===" << endl;
    curso1->imprimirEstudiantesYDocentes();
    curso2->imprimirEstudiantesYDocentes();

    // Liberar memoria
    delete asoc1;
    delete asoc2;
    delete asoc3;
    delete asoc4;
    
    delete est1;
    delete est2;
    delete doc1;
    delete doc2;
    delete curso1;
    delete curso2;

    return 0;
}
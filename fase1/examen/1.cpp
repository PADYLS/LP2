#include <iostream>
#include <string>

using namespace std;


class Autor {
private:  // 2 atributos privados
    string nombre;
    string nacionalidad;

public:
    // Constructor
    Autor(string nombre, string nacionalidad) : nombre(nombre), nacionalidad(nacionalidad) {}

    // Getters y setters
    string getNombre() const { return nombre; }
    void setNombre(string nombre) { this->nombre = nombre; }

    string getNacionalidad() const { return nacionalidad; }
    void setNacionalidad(string nacionalidad) { this->nacionalidad = nacionalidad; }


    string obtenerInfoAutor() const {
        return "Autor: " + nombre + " (" + nacionalidad + ")";
    }
};

class Libro {
private:  // 2 atributos privados + instancia de Autor
    string titulo;
    int anio;
    Autor autor;

public:
    // Constructor
    Libro(string titulo, int anio, Autor autor) : titulo(titulo), anio(anio), autor(autor) {}

    // Getters y setters
    string getTitulo() const { return titulo; }
    void setTitulo(string titulo) { this->titulo = titulo; }

    int getAnio() const { return anio; }
    void setAnio(int anio) { this->anio = anio; }

    Autor getAutor() const { return autor; }
    void setAutor(Autor autor) { this->autor = autor; }

    string obtenerInfoLibro() const {
        return titulo + " (" + to_string(anio) + ") - " + autor.getNombre();
    }
};


// Separamos la responsabilidad de mostrar información en una clase aparte
class PresentadorLibros {
public:
    void mostrarInfoCompleta(const Libro& libro) const {
        cout << "Informacion completa:" << endl;
        cout << "- Titulo: " << libro.getTitulo() << endl;
        cout << "- Anio: " << libro.getAnio() << endl;
        cout << "- " << libro.getAutor().obtenerInfoAutor() << endl;
    }
};


int main() {
    // Crear autor
    Autor autor("Mario Vargas Llosa", "Peruano");
    cout << "Probando clase Autor:" << endl;
    cout << autor.obtenerInfoAutor() << endl << endl;

    // Crear libro
    Libro libro("La ciudad y los perros", 1963, autor);
    cout << "Probando clase Libro (sin SRP):" << endl;
    cout << libro.obtenerInfoLibro() << endl << endl;

    // Probando con SRP
    PresentadorLibros presentador;
    cout << "Probando con SRP aplicado:" << endl;
    presentador.mostrarInfoCompleta(libro);

    return 0;
}
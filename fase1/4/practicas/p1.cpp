#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <map>
#include <iomanip>

using namespace std;

// Clase Autor
class Autor {
private:
    string nombre;
    string nacionalidad;
    vector<string> librosEscritos;

public:
    Autor(string nombre, string nacionalidad) : nombre(nombre), nacionalidad(nacionalidad) {}

    void agregarLibro(string isbn) {
        librosEscritos.push_back(isbn);
    }

    string getNombre() const { return nombre; }
    string getNacionalidad() const { return nacionalidad; }
    vector<string> getLibrosEscritos() const { return librosEscritos; }

    void mostrarInformacion() const {
        cout << "Autor: " << nombre << " (" << nacionalidad << ")\n";
        cout << "Libros escritos (" << librosEscritos.size() << "):\n";
        for (const auto& isbn : librosEscritos) {
            cout << "- ISBN: " << isbn << endl;
        }
    }
};

// Clase Libro
class Libro {
private:
    string isbn;
    string titulo;
    int anioPublicacion;
    int cantidadEjemplares;
    int ejemplaresDisponibles;
    Autor* autor;

public:
    Libro(string isbn, string titulo, int anio, int cantidad, Autor* autor)
        : isbn(isbn), titulo(titulo), anioPublicacion(anio), 
          cantidadEjemplares(cantidad), ejemplaresDisponibles(cantidad), autor(autor) {
        autor->agregarLibro(isbn);
    }

    string getISBN() const { return isbn; }
    string getTitulo() const { return titulo; }
    int getAnioPublicacion() const { return anioPublicacion; }
    int getEjemplaresDisponibles() const { return ejemplaresDisponibles; }
    Autor* getAutor() const { return autor; }

    bool prestarEjemplar() {
        if (ejemplaresDisponibles > 0) {
            ejemplaresDisponibles--;
            return true;
        }
        return false;
    }

    void devolverEjemplar() {
        if (ejemplaresDisponibles < cantidadEjemplares) {
            ejemplaresDisponibles++;
        }
    }

    void mostrarInformacion() const {
        cout << "Libro: " << titulo << "\n";
        cout << "ISBN: " << isbn << "\n";
        cout << "Anio: " << anioPublicacion << "\n";
        cout << "Ejemplares: " << ejemplaresDisponibles << "/" << cantidadEjemplares << "\n";
        cout << "Autor: " << autor->getNombre() << endl;
    }
};

// Clase Usuario
class Usuario {
private:
    string nombre;
    string direccion;
    string telefono;
    map<string, pair<Libro*, time_t>> librosPrestados;
    map<string, time_t> librosDevueltos;

public:
    Usuario(string nombre, string direccion, string telefono)
        : nombre(nombre), direccion(direccion), telefono(telefono) {}

    string getNombre() const { return nombre; }
    string getDireccion() const { return direccion; }
    string getTelefono() const { return telefono; }

    bool prestarLibro(Libro* libro) {
        if (libro == nullptr) return false;
        
        string isbn = libro->getISBN();
        if (librosPrestados.find(isbn) != librosPrestados.end()) {
            cout << "El usuario ya tiene prestado este libro.\n";
            return false;
        }

        if (libro->prestarEjemplar()) {
            time_t ahora = time(nullptr);
            librosPrestados[isbn] = make_pair(libro, ahora);
            cout << "Prestamo registrado correctamente.\n";
            return true;
        } else {
            cout << "No hay ejemplares disponibles de este libro.\n";
            return false;
        }
    }

    bool devolverLibro(string isbn) {
        auto it = librosPrestados.find(isbn);
        if (it != librosPrestados.end()) {
            time_t ahora = time(nullptr);
            it->second.first->devolverEjemplar();
            librosDevueltos[isbn] = ahora;
            librosPrestados.erase(it);
            cout << "Devolucion registrada correctamente.\n";
            return true;
        }
        cout << "El usuario no tiene prestado este libro.\n";
        return false;
    }

    void mostrarHistorial() const {
        cout << "\nUsuario: " << nombre << "\n";
        cout << "Direccion: " << direccion << "\n";
        cout << "Telefono: " << telefono << "\n";

        cout << "\nLibros actualmente prestados:\n";
        if (librosPrestados.empty()) {
            cout << "No tiene libros prestados actualmente.\n";
        } else {
            for (const auto& prestamo : librosPrestados) {
                cout << "- " << prestamo.second.first->getTitulo() << " (ISBN: " << prestamo.first << ")\n";
                cout << "  Fecha prestamo: " << ctime(&prestamo.second.second);
            }
        }

        cout << "\nLibros devueltos:\n";
        if (librosDevueltos.empty()) {
            cout << "No ha devuelto ningun libro.\n";
        } else {
            for (const auto& devolucion : librosDevueltos) {
                cout << "- ISBN: " << devolucion.first << "\n";
                cout << "  Fecha devolucion: " << ctime(&devolucion.second);
            }
        }
    }
};

// Clase Biblioteca
class Biblioteca {
private:
    vector<Autor*> autores;
    vector<Libro*> libros;
    vector<Usuario*> usuarios;

public:
    ~Biblioteca() {
        for (auto autor : autores) delete autor;
        for (auto libro : libros) delete libro;
        for (auto usuario : usuarios) delete usuario;
    }

    Autor* crearAutor(string nombre, string nacionalidad) {
        Autor* nuevoAutor = new Autor(nombre, nacionalidad);
        autores.push_back(nuevoAutor);
        return nuevoAutor;
    }

    Libro* crearLibro(string isbn, string titulo, int anio, int cantidad, Autor* autor) {
        Libro* nuevoLibro = new Libro(isbn, titulo, anio, cantidad, autor);
        libros.push_back(nuevoLibro);
        return nuevoLibro;
    }

    Usuario* crearUsuario(string nombre, string direccion, string telefono) {
        Usuario* nuevoUsuario = new Usuario(nombre, direccion, telefono);
        usuarios.push_back(nuevoUsuario);
        return nuevoUsuario;
    }

    void mostrarCatalogo() const {
        cout << "\n=== CATALOGO DE LIBROS ===\n";
        for (const auto& libro : libros) {
            libro->mostrarInformacion();
            cout << "-----------------------\n";
        }
    }

    void mostrarAutores() const {
        cout << "\n=== LISTA DE AUTORES ===\n";
        for (const auto& autor : autores) {
            autor->mostrarInformacion();
            cout << "-----------------------\n";
        }
    }

    void mostrarUsuarios() const {
        cout << "\n=== LISTA DE USUARIOS ===\n";
        for (const auto& usuario : usuarios) {
            usuario->mostrarHistorial();
            cout << "-----------------------\n";
        }
    }
};

// Funcion principal
int main() {
    Biblioteca biblioteca;

    cout << "=== SISTEMA DE GESTION DE BIBLIOTECA ===\n";

    // Crear autores
    Autor* autor1 = biblioteca.crearAutor("Gabriel Garcia Marquez", "Colombiano");
    Autor* autor2 = biblioteca.crearAutor("Mario Vargas Llosa", "Peruano");
    Autor* autor3 = biblioteca.crearAutor("Isabel Allende", "Chilena");

    // Crear libros
    Libro* libro1 = biblioteca.crearLibro("978-0307", "Cien anios de soledad", 1967, 5, autor1);
    Libro* libro2 = biblioteca.crearLibro("978-8466", "La ciudad y los perros", 1963, 3, autor2);
    Libro* libro3 = biblioteca.crearLibro("978-8408", "El amor en los tiempos del colera", 1985, 4, autor1);
    Libro* libro4 = biblioteca.crearLibro("978-9500", "La casa de los espiritus", 1982, 6, autor3);

    // Crear usuarios
    Usuario* usuario1 = biblioteca.crearUsuario("Juan Perez", "Calle Falsa 123", "555-1234");
    Usuario* usuario2 = biblioteca.crearUsuario("Maria Gomez", "Avenida Siempreviva 742", "555-5678");

    // Realizar prestamos
    cout << "\n=== REGISTRANDO PRESTAMOS ===\n";
    usuario1->prestarLibro(libro1);
    usuario1->prestarLibro(libro3);
    usuario2->prestarLibro(libro2);
    usuario2->prestarLibro(libro4);

    // Realizar devoluciones
    cout << "\n=== REGISTRANDO DEVOLUCIONES ===\n";
    usuario1->devolverLibro(libro1->getISBN());
    usuario2->devolverLibro(libro4->getISBN());

    // Mostrar informacion
    biblioteca.mostrarAutores();
    biblioteca.mostrarCatalogo();
    biblioteca.mostrarUsuarios();

    cout << "\n=== FIN DEL PROGRAMA ===\n";
    return 0;
}
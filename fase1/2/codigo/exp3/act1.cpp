#include <iostream>
#include <vector>

using namespace std;

// Clase Factura
class Factura {
private:
    int numero;
    string cliente;
    double monto;

public:
    Factura(int num, string cli, double mon) : numero(num), cliente(cli), monto(mon) {}

    // Getters
    int getNumero() { return numero; }
    string getCliente() { return cliente; }
    double getMonto() { return monto; }

    // Setters
    void setCliente(string nuevoCliente) { cliente = nuevoCliente; }
    void setMonto(double nuevoMonto) {
        if (nuevoMonto >= 0) {
            monto = nuevoMonto;
        } else {
            cout << "Error: El monto no puede ser negativo." << endl;
        }
    }

    // Método para mostrar factura
    void mostrarFactura() {
        cout << "Factura N°: " << numero << " | Cliente: " << cliente << " | Monto: $" << monto << endl;
    }
};

// Clase Libro
class Libro {
private:
    string titulo, autor, genero;
    int codigo;

public:
    Libro(string t, string a, string g, int c) : titulo(t), autor(a), genero(g), codigo(c) {}

    // Getters
    string getTitulo() { return titulo; }
    string getAutor() { return autor; }
    string getGenero() { return genero; }
    int getCodigo() { return codigo; }

    // Setters
    void setGenero(string nuevoGenero) { genero = nuevoGenero; }

    // Método para mostrar información del libro
    void mostrarLibro() {
        cout << "Libro: " << titulo << " | Autor: " << autor << " | Género: " << genero << " | Código: " << codigo << endl;
    }
};

int main() {
    // Arreglo de objetos de Factura
    vector<Factura> facturas;
    facturas.push_back(Factura(101, "Juan Pérez", 250.75));
    facturas.push_back(Factura(102, "María López", 130.50));
    facturas.push_back(Factura(103, "Carlos Díaz", 180.25));

    // Mostrar todas las facturas
    cout << "---- Lista de Facturas ----" << endl;
    for (Factura &f : facturas) {
        f.mostrarFactura();
    }

    // Modificar una factura
    facturas[1].setMonto(200.00);
    facturas[1].setCliente("Ana Torres");

    cout << "\nFactura modificada:" << endl;
    facturas[1].mostrarFactura();

    // Arreglo de objetos de Libro
    vector<Libro> libros;
    libros.push_back(Libro("El Quijote", "Miguel de Cervantes", "Novela", 1234));
    libros.push_back(Libro("Cien años de soledad", "Gabriel García Márquez", "Realismo mágico", 5678));
    libros.push_back(Libro("1984", "George Orwell", "Ciencia Ficción", 9101));

    // Mostrar todos los libros
    cout << "\n---- Lista de Libros ----" << endl;
    for (Libro &l : libros) {
        l.mostrarLibro();
    }

    // Modificar el género de un libro
    libros[2].setGenero("Distopía");
    cout << "\nLibro modificado:" << endl;
    libros[2].mostrarLibro();

    return 0;
}
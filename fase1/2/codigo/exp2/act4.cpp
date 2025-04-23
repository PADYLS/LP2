#include <iostream>

using namespace std;

class Factura {
private:
    int numero;
    string cliente;
    double monto;

public:
    // Constructor
    Factura(int num, string cli, double mon) : numero(num), cliente(cli), monto(mon) {}

    // Getters
    int getNumero() {
        return numero;
    }

    string getCliente() {
        return cliente;
    }

    double getMonto() {
        return monto;
    }

    // Setters
    void setCliente(string nuevoCliente) {
        cliente = nuevoCliente;
    }

    void setMonto(double nuevoMonto) {
        if (nuevoMonto >= 0) {
            monto = nuevoMonto;
        } else {
            cout << "Error: El monto no puede ser negativo." << endl;
        }
    }

    // Método para mostrar la factura
    void mostrarFactura() {
        cout << "-----------------------------------" << endl;
        cout << "Factura N°: " << numero << endl;
        cout << "Cliente: " << cliente << endl;
        cout << "Monto total: $" << monto << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    // Crear facturas
    Factura f1(101, "Juan Pérez", 250.75);
    Factura f2(102, "María López", 130.50);

    // Mostrar facturas
    f1.mostrarFactura();
    f2.mostrarFactura();

    // Modificar datos de una factura
    f1.setMonto(300.00);
    f1.setCliente("Carlos Díaz");

    // Mostrar factura actualizada
    f1.mostrarFactura();

    return 0;
}

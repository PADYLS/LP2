#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

// Clase Proveedor
class Proveedor {
private:
    string nombre;
    string contacto;

public:
    Proveedor(string nombre, string contacto) : nombre(nombre), contacto(contacto) {}
};

// Clase Producto
class Producto {
private:
    string codigo;
    string descripcion;
    double precio;
    Proveedor* proveedor;

public:
    Producto(string codigo, string descripcion, double precio, Proveedor* prov)
        : codigo(codigo), descripcion(descripcion), precio(precio), proveedor(prov) {}
};

// Clase Cliente
class Cliente {
private:
    string nombre;
    string direccion;
    string telefono;
    vector<pair<Producto*, int>> historialCompras; // Producto y cantidad

public:
    Cliente(string nombre, string direccion, string telefono)
        : nombre(nombre), direccion(direccion), telefono(telefono) {}

    void realizarCompra(Producto* producto, int cantidad) {
        historialCompras.push_back(make_pair(producto, cantidad));
    }
};

// Clase Venta
class Venta {
private:
    string numeroFactura;
    time_t fecha;
    Cliente* cliente;
    vector<pair<Producto*, int>> productosVendidos;

public:
    Venta(string numFactura, Cliente* cli) : numeroFactura(numFactura), cliente(cli) {
        fecha = time(0);
    }

    void agregarProducto(Producto* producto, int cantidad) {
        productosVendidos.push_back(make_pair(producto, cantidad));
        cliente->realizarCompra(producto, cantidad);
    }
};

// Implementación del sistema de tienda
void sistemaTienda() {
    Proveedor prov1("Textiles S.A.", "contacto@textiles.com");
    Producto camisa("CAM-001", "Camisa manga larga", 29.99, &prov1);
    
    Cliente cliente1("Maria Gomez", "Avenida 456", "555-5678");
    Venta venta1("FAC-0001", &cliente1);
    venta1.agregarProducto(&camisa, 2);
}

// Función principal main()
int main() {
    sistemaTienda(); // Llamar a tu función principal
    
    // Opcional: agregar código para mostrar resultados
    cout << "Sistema de tienda ejecutado correctamente." << endl;
    
    return 0;
}
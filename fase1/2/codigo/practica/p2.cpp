#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Producto {
public:
    string nombre;
    int stock;
    double precio;
//constructor
    Producto(string n, int s, double p) : nombre(n), stock(s), precio(p) {}

    void mostrarInfo() {
        cout << "Producto: " << nombre << " | Stock: " << stock << " | Precio: " << precio << endl;
    }
};

class Factura {
public:
    string cliente;
    string producto;
    int cantidad;
    double total;

    Factura(string c, string p, int cant, double t) : cliente(c), producto(p), cantidad(cant), total(t) {}

    void mostrarFactura() {
        cout << "Cliente: " << cliente << " | Producto: " << producto
             << " | Cantidad: " << cantidad << " | Total: $" << total << endl;
    }
};

class Inventario {
private:
    vector<Producto> disponibles;
    vector<Producto> agotados;
    vector<Factura> facturas;

public:
    // Agregar productos
    void agregarProducto(string nombre, int stock, double precio) {
        Producto nuevo(nombre, stock, precio);
        if (stock > 0)
            disponibles.push_back(nuevo);
        else
            agotados.push_back(nuevo);
    }

    // Mostrar productos disponibles
    void mostrarProductos() {
        cout << "\nProductos Disponibles\n";
        for (Producto &p : disponibles) {
            p.mostrarInfo();
        }
    }

    void realizarPedido(string cliente, string nombreProducto, int cantidad) {
        for (Producto &p : disponibles) {
            if (p.nombre == nombreProducto) {
                if (p.stock >= cantidad) {
                    double total = cantidad * p.precio;
                    facturas.push_back(Factura(cliente, nombreProducto, cantidad, total));
                    p.stock -= cantidad;
                    cout << "\nPedido realizado con exito!" << endl;
    
                    if (p.stock == 0) {
                        agotados.push_back(p);
                        // Buscar y eliminar de disponibles
                        auto it = find_if(disponibles.begin(), disponibles.end(), [&](const Producto &prod) {
                            return prod.nombre == p.nombre;
                        });
                        if (it != disponibles.end()) {
                            disponibles.erase(it);
                        }
                    }
                    return;
                } else {
                    cout << "\nNo hay suficiente stock para este pedido.\n";
                    return;
                }
            }
        }
        cout << "\nProducto no encontrado en inventario.\n";
    }

    // Mostrar facturas
    void mostrarFacturas() {
        cout << "\nFacturas de Clientes\n";
        for (Factura &f : facturas) {
            f.mostrarFactura();
        }
    }
};

int main() {
    Inventario tienda;

    // Agregar productos
    tienda.agregarProducto("Laptop", 5, 1500);
    tienda.agregarProducto("Celular", 10, 800);
    tienda.agregarProducto("Auriculares", 1, 50); // Producto agotado

    tienda.mostrarProductos();

    // Realizar pedidos
    tienda.realizarPedido("Juan", "Laptop", 2);
    tienda.realizarPedido("Maria", "Celular", 5);
    tienda.realizarPedido("Carlos", "Laptop", 3);
    tienda.realizarPedido("Ana", "Auriculares", 6); // Producto agotado

    tienda.mostrarFacturas();
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Clase Producto (objeto a agregar)
class Producto {
private:
    string id;
    string nombre;
    double precio;

public:
    Producto(string id, string nombre, double precio) 
        : id(id), nombre(nombre), precio(precio) {}

    string getId() const { return id; }
    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }

    void setPrecio(double nuevoPrecio) { precio = nuevoPrecio; }

    void mostrarInfo() const {
        cout << "Producto ID: " << id 
             << " | Nombre: " << nombre 
             << " | Precio: $" << precio << endl;
    }
};

// Clase Inventario (clase base que contiene la agregación)
class Inventario {
private:
    vector<Producto*> productos;

public:
    // Agregar producto al inventario
    void agregarProducto(Producto* producto) {
        if (producto != nullptr) {
            // Verificar si el producto ya existe
            auto it = find_if(productos.begin(), productos.end(), 
                [&](Producto* p) { return p->getId() == producto->getId(); });
            
            if (it == productos.end()) {
                productos.push_back(producto);
                cout << "Producto agregado: " << producto->getNombre() << endl;
            } else {
                cout << "Error: Producto con ID " << producto->getId() << " ya existe" << endl;
            }
        }
    }

    // Eliminar producto del inventario
    bool eliminarProducto(string id) {
        auto it = find_if(productos.begin(), productos.end(), 
            [&](Producto* p) { return p->getId() == id; });
        
        if (it != productos.end()) {
            cout << "Producto eliminado: " << (*it)->getNombre() << endl;
            productos.erase(it);
            return true;
        }
        cout << "Error: Producto con ID " << id << " no encontrado" << endl;
        return false;
    }

    // Obtener producto por ID
    Producto* obtenerProducto(string id) {
        auto it = find_if(productos.begin(), productos.end(), 
            [&](Producto* p) { return p->getId() == id; });
        
        if (it != productos.end()) {
            return *it;
        }
        return nullptr;
    }

    // Mostrar todos los productos
    void listarProductos() const {
        cout << "\n=== INVENTARIO ACTUAL ===" << endl;
        if (productos.empty()) {
            cout << "El inventario esta vacio" << endl;
        } else {
            for (const auto& producto : productos) {
                producto->mostrarInfo();
            }
        }
        cout << "=======================\n" << endl;
    }
};

int main() {
    // Crear inventario (objeto principal)
    Inventario inventario;

    // Crear productos (objetos a agregar)
    Producto p1("P001", "Laptop", 1200.50);
    Producto p2("P002", "Mouse", 25.99);
    Producto p3("P003", "Teclado", 45.75);
    Producto p4("P004", "Monitor", 350.00);

    // Agregar productos al inventario
    cout << "=== AGREGANDO PRODUCTOS ===" << endl;
    inventario.agregarProducto(&p1);
    inventario.agregarProducto(&p2);
    inventario.agregarProducto(&p3);
    inventario.agregarProducto(&p4);
    inventario.agregarProducto(&p1); // Intento de agregar duplicado

    // Mostrar inventario
    inventario.listarProductos();

    // Acceder y modificar un producto
    cout << "=== MODIFICANDO PRODUCTO ===" << endl;
    Producto* producto = inventario.obtenerProducto("P002");
    if (producto != nullptr) {
        cout << "Precio actual del mouse: $" << producto->getPrecio() << endl;
        producto->setPrecio(29.99);
        cout << "Nuevo precio del mouse: $" << producto->getPrecio() << endl;
    }

    // Mostrar inventario actualizado
    inventario.listarProductos();

    // Eliminar un producto
    cout << "=== ELIMINANDO PRODUCTO ===" << endl;
    inventario.eliminarProducto("P003");
    inventario.eliminarProducto("P999"); // Producto que no existe

    // Mostrar inventario final
    inventario.listarProductos();

    return 0;
}
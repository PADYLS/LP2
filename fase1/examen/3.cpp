#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// Interfaz base para productos
class IProducto {
    public:
        virtual ~IProducto() = default;
        virtual double getPrecio() const = 0;
        virtual string obtenerDescripcion() const = 0;
    };
    
    // Producto base que implementa la interfaz
    class Producto : public IProducto {
    protected:
        string nombre;
        double precio;
    
    public:
        Producto(string nombre, double precio) : nombre(nombre), precio(precio) {}
    
        string getNombre() const { return nombre; }
        void setNombre(string nombre) { this->nombre = nombre; }
    
        double getPrecio() const override { return precio; }
        virtual void setPrecio(double precio) { this->precio = precio; }
    
        string obtenerDescripcion() const override {
            return nombre + " ($" + to_string(precio) + ")";
        }
    };
    
    // Producto con descuento (extiende Producto manteniendo el contrato)
    class ProductoDescuento : public Producto {
    private:
        double descuento;
    
    public:
        ProductoDescuento(string nombre, double precio, double descuento) 
            : Producto(nombre, precio), descuento(descuento) {}
    
        double getPrecio() const override {
            return precio * (1 - descuento);
        }
    
        string obtenerDescripcion() const override {
            return nombre + " [DESCUENTO] ($" + to_string(getPrecio()) + ")";
        }
    };
    
    // Pedido modificado para usar la interfaz
    class Pedido {
    private:
        string codigoPedido;
        string fecha;
        vector<shared_ptr<IProducto>> productos;
    
    public:
        Pedido(string codigo, string fecha) : codigoPedido(codigo), fecha(fecha) {}
    
        // Getters y setters se mantienen iguales
    
        void agregarProducto(shared_ptr<IProducto> producto) {
            productos.push_back(producto);
        }
    
        double calcularTotal() const {
            double total = 0.0;
            for (const auto& producto : productos) {
                total += producto->getPrecio();
            }
            return total;
        }
    
        void mostrarDetalles() const {
            cout << "Pedido #" << codigoPedido << " - Fecha: " << fecha << endl;
            cout << "Productos:" << endl;
            for (const auto& producto : productos) {
                cout << "- " << producto->obtenerDescripcion() << endl;
            }
            cout << "Total: $" << calcularTotal() << endl;
        }
    };

    int main() {
        // Crear productos normales y con descuento
        auto producto1 = make_shared<Producto>("Laptop", 1200.0);
        auto producto2 = make_shared<Producto>("Mouse", 25.99);
        auto producto3 = make_shared<ProductoDescuento>("Teclado", 59.99, 0.15); // 15% descuento
    
        // Crear un pedido
        Pedido pedido("PED-2023-001", "2023-05-20");
        
        // Agregar productos al pedido
        pedido.agregarProducto(producto1);
        pedido.agregarProducto(producto2);
        pedido.agregarProducto(producto3);
    
        // Mostrar detalles del pedido
        pedido.mostrarDetalles();
    
        // Demostración de LSP - podemos sustituir Producto por ProductoDescuento
        vector<shared_ptr<IProducto>> productos;
        productos.push_back(producto1);
        productos.push_back(producto3); // ProductoDescuento se comporta como IProducto
    
        cout << "\nLista de productos (mezclados):" << endl;
        for (const auto& prod : productos) {
            cout << "- " << prod->obtenerDescripcion() << endl;
        }
    
        return 0;
    }
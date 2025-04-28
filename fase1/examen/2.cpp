#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Interfaz abstracta para el cliente
class ICliente {
    public:
        virtual ~ICliente() = default;
        virtual string getNombre() const = 0;
        virtual string getDireccion() const = 0;
        virtual string obtenerInfoCliente() const = 0;
    };
    
    // Implementación concreta de Cliente
    class Cliente : public ICliente {
    private:
        string nombre;
        string direccion;
    
    public:
        Cliente(string nombre, string direccion) : nombre(nombre), direccion(direccion) {}
    
        string getNombre() const override { return nombre; }
        void setNombre(string nombre) { this->nombre = nombre; }
    
        string getDireccion() const override { return direccion; }
        void setDireccion(string direccion) { this->direccion = direccion; }
    
        string obtenerInfoCliente() const override {
            return nombre + " - " + direccion;
        }
    };
    
    // Factura ahora depende de la abstracción ICliente
    class Factura {
    private:
        string numero;
        double monto;
        shared_ptr<ICliente> cliente;
    
    public:
        Factura(string numero, double monto, shared_ptr<ICliente> cliente) 
            : numero(numero), monto(monto), cliente(cliente) {}
    
        string getNumero() const { return numero; }
        void setNumero(string numero) { this->numero = numero; }
    
        double getMonto() const { return monto; }
        void setMonto(double monto) { this->monto = monto; }
    
        shared_ptr<ICliente> getCliente() const { return cliente; }
        void setCliente(shared_ptr<ICliente> cliente) { this->cliente = cliente; }
    
        string generarFactura() const {
            return "Factura #" + numero + "\nCliente: " + cliente->obtenerInfoCliente() + 
                   "\nMonto: $" + to_string(monto);
        }
    };

    int main() {
        // Crear un cliente
        auto cliente = make_shared<Cliente>("Juan Perez", "Calle Principal 123");
        
        // Mostrar info del cliente
        cout << "Informacion del cliente:" << endl;
        cout << cliente->obtenerInfoCliente() << endl << endl;
        
        // Crear una factura asociada al cliente
        Factura factura("FAC-001", 199.99, cliente);
        
        // Mostrar la factura
        cout << "Detalles de la factura:" << endl;
        cout << factura.generarFactura() << endl << endl;
        
        // Modificar el cliente
        cliente->setDireccion("Avenida Central 456");
        cout << "Factura actualizada:" << endl;
        cout << factura.generarFactura() << endl;
        
        return 0;
    }
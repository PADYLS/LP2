#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// Interfaz base para empleados
class IEmpleado {
    public:
        virtual ~IEmpleado() = default;
        virtual string obtenerInfo() const = 0;
        virtual string getNombre() const = 0;
    };
    
// Implementación base de Empleado
class Empleado : public IEmpleado {
    protected:
        string nombre;
        string puesto;
    
    public:
        Empleado(string nombre, string puesto) : nombre(nombre), puesto(puesto) {}
    
        string getNombre() const override { 
            return nombre; }

        void setNombre(string nombre) { 
            this->nombre = nombre; }
    
        string getPuesto() const { 
            return puesto; }

        void setPuesto(string puesto) { 
            this->puesto = puesto; }
    
        string obtenerInfo() const override {
            return nombre + " - " + puesto;
        }
    };
    
// Nuevo tipo de empleado sin modificar la clase base
class EmpleadoTemporal : public IEmpleado {
    private:
        string nombre;
        string proyecto;
        int duracionMeses;
    
    public:
        EmpleadoTemporal(string nombre, string proyecto, int duracion) 
            : nombre(nombre), proyecto(proyecto), duracionMeses(duracion) {}
    
        string getNombre() const override { return nombre; }
        string getProyecto() const { return proyecto; }
        int getDuracion() const { return duracionMeses; }
    
        string obtenerInfo() const override {
            return nombre + " [Temporal] - Proyecto: " + proyecto + " (" + to_string(duracionMeses) + " meses)";
        }
    };
    
// Departamento modificado para usar la interfaz
class Departamento {
    private:
        string nombre;
        string ubicacion;
        vector<shared_ptr<IEmpleado>> empleados;
    
    public:
        Departamento(string nombre, string ubicacion) : nombre(nombre), ubicacion(ubicacion) {}
    
        string getNombre() const { return nombre; }
        void setNombre(string nombre) { this->nombre = nombre; }
    
        string getUbicacion() const { return ubicacion; }
        void setUbicacion(string ubicacion) { this->ubicacion = ubicacion; }
    
        void agregarEmpleado(shared_ptr<IEmpleado> empleado) {
            empleados.push_back(empleado);
        }
    
        void listarEmpleados() const {
            cout << "Empleados del departamento " << nombre << " (" << ubicacion << "):" << endl;
            for (const auto& empleado : empleados) {
                cout << "- " << empleado->obtenerInfo() << endl;
            }
        }
    
        int contarEmpleados() const {
            return empleados.size();
        }
    };

int main() {
        // Crear departamento
        Departamento desarrollo("Desarrollo", "Piso 600000");
    
        // Crear empleados normales
        auto emp1 = make_shared<Empleado>("Ana Lopez", "Desarrollador Senior");
        auto emp2 = make_shared<Empleado>("Carlos Ruiz", "Desarrollador Junior");
    
        // Crear empleado temporal (nuevo tipo sin modificar las clases existentes)
        auto empTemp = make_shared<EmpleadoTemporal>("Luisa Perez", "Sistema de Pagos", 6);
    
        // Agregar empleados al departamento
        desarrollo.agregarEmpleado(emp1);
        desarrollo.agregarEmpleado(emp2);
        desarrollo.agregarEmpleado(empTemp);
    
        // Mostrar información
        desarrollo.listarEmpleados();
        cout << "\nTotal empleados: " << desarrollo.contarEmpleados() << endl;
    
        return 0;
    }
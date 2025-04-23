#include <iostream>
#include <string>

using namespace std;

// Clase Motor (objeto compuesto)
class Motor {
private:
    string tipo;
    int caballosFuerza;
    bool encendido;

public:
    Motor(string tipo, int caballos) 
        : tipo(tipo), caballosFuerza(caballos), encendido(false) {
        cout << "Motor " << tipo << " de " << caballos << " HP construido" << endl;
    }

    ~Motor() {
        cout << "Motor " << tipo << " destruido" << endl;
    }

    void encender() {
        if (!encendido) {
            encendido = true;
            cout << "Motor encendido (" << tipo << ")" << endl;
        } else {
            cout << "El motor ya estaba encendido" << endl;
        }
    }

    void apagar() {
        if (encendido) {
            encendido = false;
            cout << "Motor apagado (" << tipo << ")" << endl;
        } else {
            cout << "El motor ya estaba apagado" << endl;
        }
    }

    void mostrarEspecificaciones() const {
        cout << "Tipo: " << tipo << ", HP: " << caballosFuerza 
             << ", Estado: " << (encendido ? "Encendido" : "Apagado") << endl;
    }

    void setCaballosFuerza(int nuevosHP) {
        caballosFuerza = nuevosHP;
        cout << "Motor modificado: ahora tiene " << nuevosHP << " HP" << endl;
    }
};

// Clase Automovil (clase principal que contiene la composición)
class Automovil {
private:
    string modelo;
    int anio;
    Motor* motor;  // Relación de composición

public:
    // Constructor que inicializa el motor (composición)
    Automovil(string modelo, int anio, string tipoMotor, int hpMotor) 
        : modelo(modelo), anio(anio) {
        motor = new Motor(tipoMotor, hpMotor);  // Creación del objeto compuesto
        cout << "Automovil " << modelo << " construido" << endl;
    }

    // Destructor que libera el motor
    ~Automovil() {
        delete motor;  // Destrucción del objeto compuesto
        cout << "Automovil " << modelo << " destruido" << endl;
    }

    // Método para acceder al motor
    Motor& getMotor() {
        return *motor;
    }

    void mostrarInfo() const {
        cout << "\n=== Informacion del Automovil ===" << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "anio: " << anio << endl;
        cout << "Motor: ";
        motor->mostrarEspecificaciones();
        cout << "==============================\n" << endl;
    }
};

int main() {
    // Crear automóvil (esto crea automáticamente su motor por composición)
    cout << "=== CREANDO AUTOMOVIL ===" << endl;
    Automovil miAuto("Toyota Corolla", 2023, "4 cilindros", 169);
    miAuto.mostrarInfo();

    // Acceder al motor compuesto y operar con él
    cout << "=== OPERANDO CON EL MOTOR ===" << endl;
    Motor& motor = miAuto.getMotor();
    motor.encender();
    motor.mostrarEspecificaciones();

    // Modificar el motor
    cout << "\n=== MODIFICANDO EL MOTOR ===" << endl;
    motor.setCaballosFuerza(180);
    motor.apagar();
    miAuto.mostrarInfo();

    // El motor se destruye automáticamente cuando el automóvil se destruye
    cout << "=== FINALIZANDO ===" << endl;
    return 0;
}
package modelo;

import java.time.LocalDate;

// Archivo: TareaPrioritaria.java

public class TareaPrioritaria extends Tarea {
    private int nivelPrioridad;

    public TareaPrioritaria(String id, String t,String d,LocalDate f, String a, int n) {
        super(id, t, d, f, a);
        this.nivelPrioridad = n;
        this.setEstado("Alta Prioridad");
    }

    public int getNivelPrioridad() {
        return nivelPrioridad;
    }

    // No sobrescribimos métodos de manera que cambie el comportamiento esperado
    // Solo extendemos funcionalidad
}
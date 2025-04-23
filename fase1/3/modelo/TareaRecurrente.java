package modelo;
import java.time.LocalDate;

// Archivo: TareaRecurrente.java
public class TareaRecurrente extends Tarea {
    private String frecuencia;

    public TareaRecurrente(String id, String t,String d,LocalDate f, String a, int n,String frecuencia) {
        super(id, t, d, f, a);
        this.frecuencia = frecuencia;
    }

    public String getFrecuencia() {
        return frecuencia;
    }

    // Comportamiento base de Tarea se mantiene igual
}
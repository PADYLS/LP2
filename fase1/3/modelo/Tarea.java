package modelo;

//import javax.print.DocFlavor.STRING;
import java.time.LocalDate;

public class Tarea {
    private String id;
    private String titulo;
    private String descripcion;
    private LocalDate fechaLimite;
    private String estado;
    private String asignadoA;

    //constructor
    public Tarea(String id, String t,String d,LocalDate f, String a) {
        this.id=id;
        this.titulo=t;
        this.descripcion=d;
        this.fechaLimite=f;
        this.estado="Pendiente";
        this.asignadoA=a;
    }
    // Getters
    public String getId() { return id; }
    public String getTitulo() { return titulo; }
    public String getDescripcion() { return descripcion; }
    public LocalDate getFechaLimite() { return fechaLimite; }
    public String getEstado() { return estado; }
    public String getAsignadoA() { return asignadoA; }

    // Setters (solo para campos modificables)
    public void setEstado(String estado) {
        this.estado = estado;
    }

    // Método que usa las variables
    public String toString() {
        return String.format(
            "Tarea %s: %s (Estado: %s)", 
            id, titulo, estado
        );
    }
}

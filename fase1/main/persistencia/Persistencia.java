package persistencia;
import modelo.Tarea;

// Archivo: Persistencia.java
public interface Persistencia {
    void guardar(Tarea tarea);
    Tarea cargar(String id);
}

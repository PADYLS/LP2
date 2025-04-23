package servicios;
import java.util.List;

import persistencia.Persistencia;
import notificaciones.Notificador;
import modelo.Tarea;
import persistencia.BuscadorTareas;
// Archivo: ServicioTareas.java
public class ServicioTareas {
    private final Persistencia persistencia;
    private final Notificador notificador;

    // Inyección de dependencias en el constructor
    public ServicioTareas(Persistencia persistencia, Notificador notificador) {
        this.persistencia = persistencia;
        this.notificador = notificador;
    }

    public void crearYNotificarTarea(Tarea tarea) {
        persistencia.guardar(tarea);
        notificador.enviarNotificacion(
            "Nueva tarea asignada: " + tarea.getTitulo(), 
            tarea.getAsignadoA()
        );
    }

    public List<Tarea> obtenerTareasPendientes() {
        // Dependemos de la interfaz, no de la implementación concreta
        return ((BuscadorTareas)persistencia).buscarPorEstado("Pendiente");
    }
}
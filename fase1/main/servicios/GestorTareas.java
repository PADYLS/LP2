package servicios;
//import modelo.Tarea;
import java.util.List; // Para la interfaz List
import java.util.ArrayList; // Para la implementación concreta

import modelo.Tarea;

public class GestorTareas {
    private List<Tarea> tareas;

    public GestorTareas() {
        this.tareas = new ArrayList<>();
    }

    // Responsabilidad única: gestionar el CRUD de tareas
    public void crearTarea(Tarea tarea) {
        tareas.add(tarea);
    }

    public Tarea obtenerTarea(String id) {
        return tareas.stream()
                .filter(t -> t.getId().equals(id))
                .findFirst()
                .orElse(null);
    }

    public void actualizarEstadoTarea(String id, String nuevoEstado) {
        Tarea tarea = obtenerTarea(id);
        if (tarea != null) {
            tarea.setEstado(nuevoEstado);
        }
    }

    public List<Tarea> listarTareas() {
        return new ArrayList<>(tareas);
    }
}
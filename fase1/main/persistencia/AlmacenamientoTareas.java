package persistencia;
import modelo.Tarea;  // Import para la clase Tarea
import java.util.List;  // Para usar List<>
import java.util.HashMap;  // Para el Map de almacenamiento
import java.util.Map;  // Para la interfaz Map
import java.util.stream.Collectors;  // Para Streams (búsquedas)


// Archivo: AlmacenamientoTareas.java (implementa múltiples interfaces específicas)
public class AlmacenamientoTareas implements Persistencia, BuscadorTareas {
    private Map<String, Tarea> tareas = new HashMap<>();

    @Override
    public void guardar(Tarea tarea) {
        tareas.put(tarea.getId(), tarea);
    }

    @Override
    public Tarea cargar(String id) {
        return tareas.get(id);
    }

    @Override
    public List<Tarea> buscarPorTitulo(String titulo) {
        return tareas.values().stream()
                .filter(t -> t.getTitulo().contains(titulo))
                .collect(Collectors.toList());
    }

    @Override
    public List<Tarea> buscarPorAsignado(String asignadoA) {
        return tareas.values().stream()
                .filter(t -> t.getAsignadoA().equals(asignadoA))
                .collect(Collectors.toList());
    }

    @Override
    public List<Tarea> buscarPorEstado(String estado) {
        return tareas.values().stream()
                .filter(t -> t.getEstado().equals(estado))
                .collect(Collectors.toList());
    }
}
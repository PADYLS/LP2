package persistencia;

import modelo.Tarea;
import java.util.List;

public interface BuscadorTareas {
    List<Tarea> buscarPorTitulo(String titulo);
    List<Tarea> buscarPorEstado(String estado);
    List<Tarea> buscarPorAsignado(String asignadoA);
}
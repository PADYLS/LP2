package servicios;

import modelo.Tarea;
import java.util.List;

public class ReporteTareas {
    public void generarReporte(List<Tarea> tareas) {
        System.out.println("=== REPORTE DE TAREAS ===");
        tareas.forEach(tarea -> 
            System.out.println(
                String.format("[%s] %s - %s (Asignada a: %s)", 
                tarea.getEstado(), 
                tarea.getTitulo(), 
                tarea.getFechaLimite(), 
                tarea.getAsignadoA()))
        );
    }
}
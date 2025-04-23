package Main;

import modelo.Tarea;
import modelo.TareaPrioritaria;
import persistencia.AlmacenamientoTareas;
import notificaciones.NotificadorEmail;
import servicios.ServicioTareas;
import servicios.ReporteTareas;
import java.time.LocalDate;

public class Main {
    public static void main(String[] args) {
        System.out.println("Iniciando Gestor de Tareas SOLID");

        // 1. Configuración inicial
        AlmacenamientoTareas almacenamiento = new AlmacenamientoTareas();
        NotificadorEmail notificador = new NotificadorEmail();
        
        // 2. Inicializar servicios
        ServicioTareas servicio = new ServicioTareas(almacenamiento, notificador);
        ReporteTareas reporte = new ReporteTareas();

        // 3. Crear tareas de ejemplo
        Tarea tareaNormal = new Tarea(
            "T-001", 
            "Revisar código", 
            "Revisar implementación SOLID", 
            LocalDate.now().plusDays(7), 
            "dev@empresa.com"
        );

        TareaPrioritaria tareaUrgente = new TareaPrioritaria(
            "T-002", 
            "Corregir bug crítico", 
            "Bug en módulo de pagos", 
            LocalDate.now().plusDays(1), 
            "urgente@empresa.com", 
            1
        );

        // 4. Procesar tareas
        servicio.crearYNotificarTarea(tareaNormal);
        servicio.crearYNotificarTarea(tareaUrgente);

        // 5. Cambiar estado de una tarea
        servicio.actualizarEstadoTarea("T-001", "En progreso");

        // 6. Generar reportes
        System.out.println("\n📊 REPORTES:");
        reporte.generarReporteGeneral(almacenamiento.buscarPorEstado("Todos"));
        reporte.generarReportePorEstado(almacenamiento.buscarPorEstado("Pendiente"), "Pendiente");
    }
}
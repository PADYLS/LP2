package main;

import modelo.Tarea;
import servicios.ServicioTareas;
import persistencia.AlmacenamientoTareas;
import notificaciones.NotificadorEmail;

public class Main {
    public static void main(String[] args) {
        // Configuración adaptada para VS
        System.out.println("Iniciando Gestor de Tareas SOLID");
        
        AlmacenamientoTareas almacenamiento = new AlmacenamientoTareas();
        NotificadorEmail notificador = new NotificadorEmail();
        
        ServicioTareas servicio = new ServicioTareas(almacenamiento, notificador);
        
        Tarea tarea = new Tarea("1", "Revisar código", 
                "Revisar implementación SOLID", 
                new java.util.Date(), 
                "dev@example.com");
        
        servicio.crearYNotificarTarea(tarea);
    }
}
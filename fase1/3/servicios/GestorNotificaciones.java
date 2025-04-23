package servicios;
import notificaciones.Notificador;//** */
import modelo.Tarea;//***** */

// Archivo: GestorNotificaciones.java
public class GestorNotificaciones {
    private Notificador notificador;

    public GestorNotificaciones(Notificador notificador) {
        this.notificador = notificador;
    }

    public void notificarVencimientoTarea(Tarea tarea) {
        String mensaje = "La tarea '" + tarea.getTitulo() + "' vence el " + tarea.getFechaLimite();
        notificador.enviarNotificacion(mensaje, tarea.getAsignadoA());
    }
}
package notificaciones;

public class NotificadorEmail implements Notificador {
    @Override
    public void enviarNotificacion(String mensaje, String destinatario) {
        System.out.println("Enviando email a " + destinatario + ": " + mensaje);
    }
}

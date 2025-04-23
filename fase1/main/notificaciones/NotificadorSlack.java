package notificaciones;

public class NotificadorSlack implements Notificador {
    @Override
    public void enviarNotificacion(String mensaje, String destinatario) {
        System.out.println("Enviando mensaje por Slack a " + destinatario + ": " + mensaje);
    }
}
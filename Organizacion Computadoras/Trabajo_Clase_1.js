import java.util.regex.*;

public class EjemploMetacaracteres {

    public static void main(String[] args) {
        String texto = "Esta es una frase con muchas palabras.";
        String patron = "^a.*e$";

        Pattern pattern = Pattern.compile(patron);
        Matcher matcher = pattern.matcher(texto);

        while (matcher.find()) {
            System.out.println(matcher.group());
        }
    }
}

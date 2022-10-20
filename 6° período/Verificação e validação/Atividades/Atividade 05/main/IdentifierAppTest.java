import static org.junit.Assert.*;

import java.beans.Transient;

import org.junit.Test;

public class IdentifierAppTest{

    // Caso de teste válido
    @Test
    public void teste01(){
        Identifier id = new Identifier();
        boolean valorPassado;

        valorPassado = id.validateIdentifier("r1");
        assertEquals(true, valorPassado);
    }

    // Caso de teste inválido
    @Test
    public void teste02(){
        Identifier id = new Identifier();
        boolean valorPassado;

        valorPassado = id.validateIdentifier(s: "ka123")
        assertEquals(false, valorPassado);
    }
}
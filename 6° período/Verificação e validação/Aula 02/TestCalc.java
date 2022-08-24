import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class TestCalc {
    Calc c = new Calc();

    @Test
    public void teste01(){
        assertEquals(2, c.soma(1, 1));
    }
}

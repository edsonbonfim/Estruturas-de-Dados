package backtrack;

import java.util.Vector;

public class Caminho {

    private double custo;
    private Vector<Integer> vet;

    Caminho() {
        this.vet = new Vector<>();
    }

    @Override
    public String toString() {

        String string = "[Custo: " + this.custo + "]";

        for (Integer i : this.vet)
            string = string.concat(" " + i);

        return string;
    }

    public void setCusto(double custo) {
        this.custo = custo;
    }

    public double getCusto() {
        return custo;
    }

    public Vector<Integer> getVet() {
        return vet;
    }
}

package grafo;

public class Aresta {

    private int dest;
    private double custo;
    Vertice vertice;

    public Aresta(int dest, double custo, Vertice vertice) {
        this.dest = dest;
        this.custo = custo;
        this.vertice = vertice;
        this.vertice.arestas.add(this);
    }

    @Override
    public String toString() {
        return "["+this.getDest()+"|"+this.getCusto()+"]";
    }

    public int getDest() {
        return this.dest;
    }

    public double getCusto() {
        return this.custo;
    }

    public void remove() {
        this.vertice.arestas.remove(this);
    }
}

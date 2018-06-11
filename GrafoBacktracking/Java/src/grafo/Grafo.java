package grafo;

import java.util.NoSuchElementException;

public class Grafo {

    private int size;
    Vertice[] vertices;

    public Grafo (int n) {
        this.size = n;
        this.vertices = new Vertice[n+1];
    }

    @Override
    public String toString() {

        String string = "";

        for (Vertice vertice : this.vertices) {

            if (vertice == null)
                continue;

            string = string.concat(vertice.toString() + "\n");
        }

        return string;
    }

    public void add(int orig, int dest, double custo) {

        if (this.vertices[orig] == null)
            new Vertice(this, orig);

        this.vertices[orig].add(dest, custo);
    }

    public void remove(int orig, int dest) throws NoSuchElementException {

        if (this.vertices[orig] == null)
            throw new NoSuchElementException("O grafo nao possui o vertice '"+orig+"'.");

        this.vertices[orig].remove(dest);
    }

    public int size() {
        return this.size;
    }

    public int numArestas() {

        int cont = 0;

        for (Vertice vertice : this.vertices) {

            if (vertice == null)
                continue;

            cont += vertice.getArestas().size();
        }

        return cont;
    }

    public boolean isEsparco() {
        int n = this.size();
        return this.numArestas() <= n * 0.3;
    }

    public Vertice getVertice(int orig) {
        return this.vertices[orig];
    }
}

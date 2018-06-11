package grafo;

import java.util.ArrayList;
import java.util.NoSuchElementException;

public class Vertice {

    private int orig;
    Grafo grafo;
    ArrayList<Aresta> arestas;

    public Vertice(Grafo grafo, int orig) {

        this.grafo = grafo;
        this.orig = orig;
        this.arestas = new ArrayList<>();
        this.grafo.vertices[orig] = this;
    }

    @Override
    public String toString() {

        String string = "|"+this.orig+"|";

        for (Aresta aresta : this.arestas)
            string = string.concat("-" + aresta.toString());

        return string;
    }

    public void add(int dest, double custo) throws ArrayStoreException {

        for (Aresta aresta : this.arestas)
            if (aresta.getDest() == dest)
                throw new ArrayStoreException("O vertice '"+this.orig+"' ja possui o destino '"+dest+"'.");

        new Aresta(dest, custo, this);
    }

    public void remove(int dest) throws NoSuchElementException {

        for (Aresta aresta : this.arestas) {
            if (aresta.getDest() == dest) {
                aresta.remove();
                return;
            }
        }

        throw new NoSuchElementException("O vertice '"+this.orig+"' nao possiu o destino '"+dest+"'.");
    }

    public ArrayList<Aresta> getArestas()
    {
        return this.arestas;
    }

    public int grau() {
        return this.grauEntrada() + this.grauSaida();
    }

    public int grauEntrada() {

        int cont = 0;

        for (Vertice vertice : this.grafo.vertices) {

            if (vertice == null)
                continue;

            for (Aresta aresta : vertice.arestas)
                if (aresta.getDest() == this.orig)
                    cont++;
        }

        return cont;
    }

    public int grauSaida() {
        return this.arestas.size();
    }
}

package backtrack;

import grafo.Aresta;
import grafo.Grafo;
import java.util.ArrayList;

public class Backtrack {

    private Grafo grafo;
    private int[] vet;
    private BacktrackReal backtrackReal;

    public Backtrack(Grafo grafo) {
        this.grafo = grafo;
        this.vet = new int[grafo.size()];
        this.backtrackReal = new BacktrackReal(grafo);
    }

    public ArrayList<Caminho> getCaminhos(int orig, int dest) {

        ArrayList<Caminho> caminhos = new ArrayList<>();

        this.vet[0] = orig;
        backtrackReal.getCaminhos(caminhos, vet, 1, 0, dest, orig);

        return caminhos;
    }

    public ArrayList<Caminho> getCaminhos(int orig, int dest, int intermed) {

        ArrayList<Caminho> caminhos = new ArrayList<>();

        this.vet[0] = orig;
        backtrackReal.getCaminhos(caminhos, vet, 1, 0, dest, intermed);

        return caminhos;
    }

    public ArrayList<Caminho> getCaminhosHamiltonianos(int orig) {

        ArrayList<Caminho> caminhos = new ArrayList<>();

        for (Caminho caminho : this.getCaminhos(orig,0)) {

            int vertice = caminho.getVet().get(caminho.getVet().size()-1);

            for (Aresta aresta : this.grafo.getVertice(vertice).getArestas()) {

                if (aresta.getDest() == orig)
                    caminhos.add(caminho);
            }
        }

        return caminhos;
    }

    public Caminho getCaminhoMenorCusto(int orig, int dest) {

        double menor = Double.MAX_VALUE;

        Caminho caminho = null;

        for (Caminho c : this.getCaminhos(orig, dest))
        {
            if (c.getCusto() < menor) {
                menor = c.getCusto();
                caminho = c;
            }
        }

        return caminho;
    }
}

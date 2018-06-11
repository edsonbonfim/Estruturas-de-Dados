package backtrack;

import grafo.Aresta;
import grafo.Grafo;
import java.util.ArrayList;
import java.util.List;

public class Backtrack {

    private Grafo grafo;
    private int[] vet;

    public Backtrack(Grafo grafo) {
        this.grafo = grafo;
        this.vet = new int[grafo.size()];
    }

    public List<Caminho> getCaminhos(int orig, int dest) {

        List<Caminho> caminhos = new ArrayList<>();

        this.vet[0] = orig;
        this.backtracking(caminhos, vet, 1, 0, dest, orig);

        return caminhos;
    }

    public List<Caminho> getCaminhos(int orig, int dest, int intermed) {

        List<Caminho> caminhos = new ArrayList<>();

        this.vet[0] = orig;
        this.backtracking(caminhos, vet, 1, 0, dest, intermed);

        return caminhos;
    }

    public List<Caminho> getCaminhosHamiltonianos(int orig) {

        List<Caminho> caminhos = new ArrayList<>();

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

    private boolean existeVet(int[] vet, int pos, int elem) {

        for (int i = 0; i < pos; i++)
            if (vet[i] == elem)
                return true;

        return false;
    }

    private void backtracking(List<Caminho> caminhos, int[] vet, int pos, double custo, int dest, int intermed) {

        if (dest == 0 && this.grafo.size() == pos) {

            Caminho caminho = new Caminho();
            caminho.setCusto(custo);

            for (int i = 0; i < pos; i++)
                caminho.getVet().add(vet[i]);

            caminhos.add(caminho);
        } else if (vet[pos-1] == dest && existeVet(vet, pos, intermed)) {

            Caminho caminho = new Caminho();
            caminho.setCusto(custo);

            for (int i = 0; i < pos; i++)
                caminho.getVet().add(vet[i]);

            caminhos.add(caminho);
        } else {

            for (Aresta aresta : this.grafo.getVertice(vet[pos-1]).getArestas()) {

                if (!this.existeVet(vet, pos, aresta.getDest())) {

                    vet[pos] = aresta.getDest();
                    this.backtracking(caminhos, vet, pos+1, custo + aresta.getCusto(), dest, intermed);
                }
            }
        }
    }
}

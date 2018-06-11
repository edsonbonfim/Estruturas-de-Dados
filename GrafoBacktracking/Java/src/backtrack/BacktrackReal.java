package backtrack;

import grafo.*;
import java.util.ArrayList;

class BacktrackReal {

    private Grafo grafo;

    BacktrackReal(Grafo grafo) {
        this.grafo = grafo;
    }

    private boolean existeVet(int[] vet, int pos, int elem) {

        for (int i = 0; i < pos; i++)
            if (vet[i] == elem)
                return true;

        return false;
    }

    public void getCaminhos(ArrayList<Caminho> caminhos, int[] vet, int pos, double custo, int dest, int intermed) {

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
                    this.getCaminhos(caminhos, vet, pos+1, custo + aresta.getCusto(), dest, intermed);
                }
            }
        }
    }
}

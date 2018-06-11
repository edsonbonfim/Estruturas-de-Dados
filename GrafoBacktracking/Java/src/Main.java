import grafo.*;
import backtrack.*;

import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {

    public static void main(String args[]) {

        int n, orig, dest;

        Scanner s = new Scanner(System.in);
        System.out.println("INFORME O TAMANHO DO GRAFO: ");
        n = s.nextInt();

        Grafo grafo = new Grafo(n);

        while (true) {

            System.out.println("\n1. INSERIR UMA ARESTA");
            System.out.println("2. REMOVER UMA ARESTA");
            System.out.println("3. IMPRIMIR O GRAFO");
            System.out.println("4. GRAU DE UM VERTICE");
            System.out.println("5. VERIFICAR SE EH ESPARCO");
            System.out.println("6. IMPRIMIR CAMINHOS QUE PASSAM POR UM VERTICE INTERMEDIARIO");
            System.out.println("7. IMPRIMIR O CAMINHO DE MENOR CUSTO");
            System.out.println("8. IMPRIMIR CICLOS HAMILTONIANOS");
            System.out.println("9. SAIR");

            System.out.println("\nOPCAO: ");
            n = s.nextInt();

            Backtrack bt = new Backtrack(grafo);

            switch (n) {

                case 1:
                    System.out.print("ORIGEM: ");
                    orig = s.nextInt();

                    System.out.print("DESTINO: ");
                    dest = s.nextInt();

                    System.out.print("CUSTO: ");
                    double custo = s.nextDouble();

                    try {
                        grafo.add(orig, dest, custo);
                    } catch (ArrayStoreException e) {
                        System.out.println(e.getMessage());
                    }
                    break;

                case 2:
                    System.out.print("ORIGEM: ");
                    orig = s.nextInt();

                    System.out.print("DESTINO: ");
                    dest = s.nextInt();

                    try {
                        grafo.remove(orig, dest);
                    } catch (NoSuchElementException e) {
                        System.out.println(e.getMessage());
                    }
                    break;

                case 3:
                    System.out.println(grafo);
                    break;

                case 4:
                    System.out.print("ORIGEM: ");
                    orig = s.nextInt();

                    System.out.println("GRAU: " + grafo.getVertice(orig).grau());
                    break;

                case 5:
                    if (grafo.isEsparco())
                        System.out.println("\nEH ESPARCO");
                    else
                        System.out.println("\nNAO EH ESPARCO");
                    break;

                case 6:
                    System.out.print("ORIGEM: ");
                    orig = s.nextInt();

                    System.out.print("DESTINO: ");
                    dest = s.nextInt();

                    System.out.print("NO INTERMEDIARIO: ");
                    n = s.nextInt();

                    System.out.println(bt.getCaminhos(orig, dest, n));
                    break;

                case 7:
                    System.out.print("ORIGEM: ");
                    orig = s.nextInt();

                    System.out.print("DESTINO: ");
                    dest = s.nextInt();

                    System.out.println(bt.getCaminhoMenorCusto(orig, dest));
                    break;

                case 8:
                    System.out.print("ORIGEM: ");
                    orig = s.nextInt();

                    System.out.println(bt.getCaminhosHamiltonianos(orig));
                    break;

                default:
                    System.exit(0);
            }
        }
    }
}

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// função para medir o tempo de execução
double medirTempo(void (*funcao)(int *, int), int *vet, int quantidade)
{
    // criação de um vetor temporário para copiar os dados
    int *vetTemp = malloc(quantidade * sizeof(int)); // aloca memória para o vetor temporário
    for (int i = 0; i < quantidade; i++) {
        vetTemp[i] = vet[i]; // cópia do vetor original
    }

    clock_t inicio, fim;
    inicio = clock(); // guarda o tempo de início
    funcao(vetTemp, quantidade); // chama a função de ordenação
    fim = clock(); // guarda o tempo após ordenação

    /*
    printf("Vetor ordenado:\n");
    printf("{");
    for (int i = 0; i < quantidade; i++)
    {
        if(i!=quantidade-1)
            printf("%d, ", vetTemp[i]);
        else
            printf("%d}\n", vetTemp[i]);
    }
    printf("\n");
    */
    
    free(vetTemp); // libera a memória alocada para o vetor temporário
    return ((double) (fim - inicio)) / CLOCKS_PER_SEC; // retorna o tempo de execução em segundos
}


void selectionSort (int *vet, int quantidade) // função declarando um vetor de inteiros e quantidade 
{

    for(int indiceUm = 0; indiceUm < quantidade-1 ; indiceUm++) // loop externo para definir o numero de passagens no vetor
    {
        int menorIndice = indiceUm; // inicializa menorIndice com a posição atual
        for(int indiceDois = indiceUm + 1; indiceDois < quantidade ; indiceDois++) // loop interno para encontrar o menor elemnto
        {
            if(vet[indiceDois] < vet[menorIndice]) // verifica se o que estiver no vetor na posição indiceDois é menor que o que estiver no vetor na posição menorIndice
            {
                menorIndice = indiceDois; // guarda a posição indiceDois como a posição que détem o menor valor
            }
        }

        int temp = vet[indiceUm]; // variável para armazenar temporariamente o valor que estiver em posição indiceUm do vetor
        vet[indiceUm] = vet[menorIndice]; // o valor do vetor na posição indiceUm passa a ser o valor que se encontra no vetor na posição menorIndice
        vet[menorIndice] = temp; // o valor do vetor na posicao de menorIndice passa a ser o valor que estava na varíavel temporária
    }
}

void insertionSort (int *vet, int quantidade) // função declarando um vetor de inteiros e quantidade 
{
    
   for(int indiceUm = 1; indiceUm < quantidade; indiceUm++) // loop externo começando do segundo elemento assumindo que o primeiro está ordenado
   {
       int valorAtual = vet[indiceUm]; // armazena o elemento da posicao indiceUm na variavel valorAtual
       int indiceDois; // cria váriavel indiceDois fora do loop interno para uso posterior
       
       for(indiceDois = indiceUm-1; indiceDois >=0 && vet[indiceDois] > valorAtual; indiceDois--) // loop interno para deslocar os elementos maiores que valorAtual uma posição à direita, até encontrar a posição correta para inseri-lo.
       {
           vet[indiceDois + 1] = vet[indiceDois]; // desloca o elemento para direita
       }
       
       vet[indiceDois + 1] = valorAtual; // insere valor atual na posição correta
   }
}


void bubbleSort (int *vet, int quantidade) // função declarando um vetor de inteiros e quantidade 
{
    for(int indiceUm = 0; indiceUm < quantidade-1 ; indiceUm++) // loop externo para definir o numero de passagens no vetor
    {
        for(int indiceDois = 0; indiceDois < quantidade-1 ; indiceDois++) // loop interno para comparar os elementos adjacentes
        {
            if(vet[indiceDois] > vet[indiceDois + 1]) // verifica se o valor na posição atual é maior que o da posição seguinte
            {
                int temp = vet[indiceDois]; // guarda o valor da posição atual
                vet[indiceDois] = vet[indiceDois + 1]; // troca o valor da posição atual pelo valor da posição seguinte
                vet[indiceDois + 1] = temp; // define o valor da posição seguinte como o valor da anterior
            }
        }
    }
}

void mesclar(int vet[], int esquerda, int meio, int direita)
{
 
    int tamanhoEsquerda = meio - esquerda + 1;  // subvetor esquerdo vai de esquerda até meio
    int tamanhoDireita = direita - meio; // subvetor direito vai de meio + 1 até direita
  
    int vetEsquerda[tamanhoEsquerda], vetDireita[tamanhoDireita]; // cria dois vetores temporários para guardar os elementos dos subvetores

    for (int indiceEsquerda = 0; indiceEsquerda < tamanhoEsquerda; indiceEsquerda++) // copia os elementos do subvetor esquerdo para vetEsquerda
        vetEsquerda[indiceEsquerda] = vet[esquerda + indiceEsquerda]; // copia os valores do vetor original

    for (int indiceDireita = 0; indiceDireita < tamanhoDireita; indiceDireita++) // copia os elementos do subvetor direito para vetDireita
        vetDireita[indiceDireita] = vet[meio + 1 + indiceDireita]; // copia os valores do vetor original
        
    int indiceEsquerda = 0, indiceDireita = 0, indiceMesclagem = esquerda;  // inicializa os índices para percorrer os vetores temporários e o vetor original e indica onde esta em cada vetor

    
    while (indiceEsquerda < tamanhoEsquerda && indiceDireita < tamanhoDireita) // mescla os dois subvetores no vetor original
    {  
        if (vetEsquerda[indiceEsquerda] <= vetDireita[indiceDireita]) // compara os dois valores
        {  
            vet[indiceMesclagem] = vetEsquerda[indiceEsquerda]; // coloca o valor menor no vetor original
            indiceEsquerda++; // muda para o próximo elemento no subvetor esquerdo
        }
        else
        {
            vet[indiceMesclagem] = vetDireita[indiceDireita]; // coloca o valor menor no vetor original
            indiceDireita++; // muda para o próximo elemento no subvetor direito
        }
        indiceMesclagem++; // muda para o próximo espaço no vetor original
    }

    
    while (indiceEsquerda < tamanhoEsquerda) // se ainda houver elementos no subvetor esquerdo, coloca eles no vetor original
    {  
        vet[indiceMesclagem] = vetEsquerda[indiceEsquerda]; // coloca os elementos restantes do lado esquerdo
        indiceEsquerda++; // muda para o próximo elemento no subvetor esquerdo
        indiceMesclagem++; // muda para o próximo espaço no vetor original
    }

  
    while (indiceDireita < tamanhoDireita) // se ainda houver elementos no subvetor direito, coloca eles no vetor original
    {  
        vet[indiceMesclagem] = vetDireita[indiceDireita];  // coloca os elementos restantes do lado direito
        indiceDireita++; // muda para o próximo elemento no subvetor direito
        indiceMesclagem++; // muda para o próximo espaço no vetor original
    }
}

void mergeSort(int vet[], int esquerda, int direita) // função de ordenação merge sort
{
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        mergeSort(vet, esquerda, meio);
        mergeSort(vet, meio + 1, direita);
        mesclar(vet, esquerda, meio, direita);
    }
}


void mergeSortWrapper(int *vet, int quantidade) // empacotador para mergeSort para funcionar com medirTempo
{
    mergeSort(vet, 0, quantidade - 1);
}



int particionar(int vetor[], int inicio, int fim) // função para particionar o vetor (dividir o vetor em subvetores)
{
    int pivo = vetor[fim]; // escolhe o pivô como o último elemento do vetor (ou subvetor)
  
   
    int indiceMenor = inicio - 1;  // indice do último elemento menor que o pivô (inicia antes do primeiro índice)

    
    for (int indiceAtual = inicio; indiceAtual <= fim - 1; indiceAtual++) // percorre o vetor (do início ao penúltimo elemento) para organizar em torno do pivô
    {
        
        if (vetor[indiceAtual] < pivo) // se o elemento atual for menor que o pivô, movemos ele para a esquerda
        {
            indiceMenor++;  // avança o índice do menor elemento
            // troca os elementos na posição de indiceMenor e indiceAtual
            int temp = vetor[indiceMenor];
            vetor[indiceMenor] = vetor[indiceAtual];
            vetor[indiceAtual] = temp;
        }
    }
    
    // coloca o pivô na posição correta, trocando-o com o elemento na posição indiceMenor + 1
    int temp = vetor[indiceMenor + 1];
    vetor[indiceMenor + 1] = vetor[fim];
    vetor[fim] = temp;
    
    
    return indiceMenor + 1; // retorna a posição final do pivô no vetor (onde ele ficou após o particionamento)
}


void quickSort(int vetor[], int inicio, int fim) // função principal do QuickSort
{
    if (inicio < fim) // se há mais de um elemento a ser ordenado
    { 
        int indicePivo = particionar(vetor, inicio, fim); // chama a função particionar para dividir o vetor, retorna a posição do pivô
        quickSort(vetor, inicio, indicePivo - 1); // ordena recursivamente a parte do vetor à esquerda do pivô
        quickSort(vetor, indicePivo + 1, fim); // ordena recursivamente a parte do vetor à direita do pivô
    }
}


void quickSortWrapper(int *vet, int quantidade)
{
    quickSort(vet, 0, quantidade - 1);
}


// função para organizar o vetor para manter a propriedade do heap (arvore inicial)
void heapify(int vetor[], int tamanho, int indiceRaiz)
{
    int maior = indiceRaiz;  //  assumir que o maior elemento está na raiz
    int esquerdo = 2 * indiceRaiz + 1;  // indice do filho a esquerda
    int direito = 2 * indiceRaiz + 2;   // indice do filho a direita

    // verifica se o filho a esquerda existe e é maior que a raiz
    if (esquerdo < tamanho && vetor[esquerdo] > vetor[maior]) {
        maior = esquerdo;
    }

    // verifica se o filho a direita existe e é maior que o maior entre raiz e filho a esquerda
    if (direito < tamanho && vetor[direito] > vetor[maior]) {
        maior = direito;
    }

    // se algum dos filhos for maior que a raiz, trocas e continua com a verificação
    if (maior != indiceRaiz) {
        int temp = vetor[indiceRaiz];  // armazena o valor da raiz
        vetor[indiceRaiz] = vetor[maior];  // troca o valor da raiz com o maior filho
        vetor[maior] = temp;  // coloca o valor da raiz no lugar do maior filho

        // chama recursivamente heapify na subárvore que foi modificada
        heapify(vetor, tamanho, maior);
    }
}

// função principal do HeapSort
void heapSort(int vetor[], int tamanho)
{
    // constrói o heap máximo (organiza o vetor como um heap)
    // começa do meio do vetor e vai ajustando os elementos para manter a propriedade do heap
    for (int i = tamanho / 2 - 1; i >= 0; i--)
    {
        heapify(vetor, tamanho, i);
    }

    // extrair o maior elemento (que está na raiz do heap) e colocá-lo no final do vetor
    // ajustar o heap novamente para garantir que a propriedade de heap seja mantida (arvore inicial)
    for (int i = tamanho - 1; i > 0; i--) {
        int temp = vetor[0];  // armazena o valor da raiz
        vetor[0] = vetor[i];   // coloca o último elemento no lugar da raiz
        vetor[i] = temp;       // coloca o valor da raiz na posição final

        // reduz o tamanho do heap e chama heapify para restaurar a propriedade do heap (// ajustar o heap novamente para garantir que a propriedade de heap seja mantida (arvore inicial))
        heapify(vetor, i, 0);
    }
}

void heapSortWrapper(int *vet, int quantidade)
{
    heapSort(vet, quantidade);
}



int main()
{
    printf("\n------------------------------------------\nPROGRAMA PARA ORDENACAO DE VETOR\n------------------------------------------\n");
    // vetores de diferentes tamanhos
    int tamanhos[] = {100, 1000, 10000, 50000, 100000};
    //int tamanhos[] = {10}; // teste singular
    int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    // teste para cada tamanho de vetor
    for (int i = 0; i < numTamanhos; i++)
    {
        int n = tamanhos[i];  // tamanho atual do vetor
        int *Vetor = malloc(n * sizeof(int)); // aloca memória dinamicamente para o vetor

        srand(time(NULL)); // inicializa o gerador de números aleatórios

        for (int j = 0; j < n; j++) {
            Vetor[j] = rand(); // preenche o vetor com números aleatórios
        }

        printf("\nTamanho do vetor: %d\n", n);
        
        // medir e exibir o tempo de execução para cada algoritmo de ordenação
        double tempo_cpuSelectionSort = medirTempo(selectionSort, Vetor, n);
        double tempo_cpuInsertionSort = medirTempo(insertionSort, Vetor, n);
        double tempo_cpuBubbleSort = medirTempo(bubbleSort, Vetor, n);
        double tempo_cpuMergeSort = medirTempo(mergeSortWrapper, Vetor, n);
        double tempo_cpuQuickSort = medirTempo(quickSortWrapper, Vetor, n);
        double tempo_cpuHeapSort = medirTempo(heapSortWrapper, Vetor, n);
       
        printf("\nTempo de execução: \nSelection: %f segundos\nInsertion: %f segundos\nBubble: %f segundos\nMerge: %f segundos\nQuick: %f segundos\nHeap: %f segundos\n", 
                tempo_cpuSelectionSort, tempo_cpuInsertionSort, tempo_cpuBubbleSort, tempo_cpuMergeSort, tempo_cpuQuickSort, tempo_cpuHeapSort);
        printf("------------------------------------------");
        free(Vetor); // libera a memória do vetor
    }
    
    return 0; // retorna o valor 0 caso o programa seja executado com sucesso
}

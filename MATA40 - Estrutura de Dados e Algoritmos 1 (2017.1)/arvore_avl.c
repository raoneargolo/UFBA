#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 5

// estrutura autoreferenciada
struct nodo_arvore {
    struct nodo_arvore *ponteiro_esquerda; // ponteiro para  a subarvore a esquerda
    int dado; // valor contido no nodo
    struct nodo_arvore *ponteiro_direita; // ponteiro para a subarvore a direita
}; // fim da estrutura nodo da arvore

typedef struct nodo_arvore nodo_arvore; // sinonimo para a estrutura de nodo da arvore
typedef nodo_arvore *nodo_arvore_ponteiro; // sinonimo para o ponteiro de estrutura de nodo da arvore

// prototipos de função
void inserir_na_arvore(nodo_arvore_ponteiro *ponteiro_arvore, int valor, int *quantidade_nodos);
void percurso_em_ordem(nodo_arvore_ponteiro ponteiro_arvore);
void impressao_formato_arvore(nodo_arvore_ponteiro ponteiro_arvore, int espaco);
nodo_arvore_ponteiro busca_nodo(nodo_arvore_ponteiro ponteiro_arvore, int valor);
nodo_arvore_ponteiro remove_nodo(nodo_arvore_ponteiro arvore, int valor, int quantidade_nodos);

// função main inicia execução do programa
int main( int argc, char **argv )
{
    unsigned int i; // contador de loop de 1-10
    int item; // variável para armazenar os valores randômicos criados
    nodo_arvore_ponteiro ponteiro_raiz = NULL; // inicializando a árvore como nula
    //nodo_arvore_ponteiro nodo_busca = NULL;
    srand(time(NULL));
    puts("Os numeros a serem inseridos na arvore sao:");

    int quantidade_nodos = 0; //variavel para controlar quantidade de nodos na arvore

    // inserindo valores randômicos entre 0 e 14 na árvore
    for (i = 1; i <= 20; ++i)
    {
        item = rand() % 100;
        printf("%3d", item);
        inserir_na_arvore(&ponteiro_raiz, item, &quantidade_nodos); //insere valores aleatorios no nodo
    } // fim do laço for
    
    //printf("\n\nQuantidade de nodos na arvore: %d",quantidade_nodos);
    
    // percorrendo percurso em ordem
    puts("\n\nO percuro em-ordem:");
    percurso_em_ordem(ponteiro_raiz);

    printf("\n\n");
	
	printf("\n\t\t\tArvore impressa em 2D\n");
    impressao_formato_arvore(ponteiro_raiz,0);

    int valor_busca;

    char opcao;
    
    printf("\nDeseja remover algum valor da arvore? Digite 'S' para sim ou 'N' para nao para sair do programa: ");
    fflush(stdin);
    scanf("%c",&opcao);
    while(opcao == 'S' || opcao == 's')
    {
        printf("\nDigite um valor para remover da arvore: ");
        scanf("%d",&valor_busca);

        if (busca_nodo(ponteiro_raiz,valor_busca)!=NULL)
        {
            printf("\nO valor foi encontrado na arvore binaria! Procedendo remocao.\n");
            
            ponteiro_raiz = remove_nodo(ponteiro_raiz,valor_busca,quantidade_nodos);

            quantidade_nodos--;
            
            //printf("\nQuantidade de nodos na arvore: %d\n",quantidade_nodos);

            printf("\nArvore apos a remocao de %d:\n",valor_busca);

            impressao_formato_arvore(ponteiro_raiz,0);
        }
        else
        {
            printf("\nO valor nao existe na arvore binaria! Por favor, escolha outro.\n");
        }

        if(quantidade_nodos < 1)
        {
            printf("\n\t\tARVORE VAZIA\n");
            break;
        }
        else
        {
            printf("\nDeseja remover algum valor da arvore? Digite 'S' para sim ou 'N' para nao: ");
            fflush(stdin);
            scanf("%c",&opcao);
        }
    }
    
    printf("\nSaindo da aplicacao.");

    exit(0);
} // fim da função principal

// inserindo nodo na árvore
void inserir_na_arvore(nodo_arvore_ponteiro *ponteiro_arvore, int valor, int *quantidade_nodos)
{
    // se a árvore estiver vazia
    if (*ponteiro_arvore == NULL)
    {
        *ponteiro_arvore = malloc(sizeof(nodo_arvore));

        // se um espaço de memória foi alocado, então o nodo recebe o dado
        if (*ponteiro_arvore != NULL)
        {
            (*ponteiro_arvore)->dado = valor;
            (*ponteiro_arvore)->ponteiro_esquerda = NULL;
            (*ponteiro_arvore)->ponteiro_direita = NULL;
            (*quantidade_nodos)++;
        } // fim do condicional if
        else
        {
            printf( "%d nao inserido. Sem memoria disponivel.\n", valor );
        } // fim do condicional else
    } // fim do condional if
    else // a árvore não está vazia
    {
        // valor a ser inserido na árvore é menor que o valor presente no nodo atual
        if (valor < (*ponteiro_arvore)->dado)
        {
            inserir_na_arvore(&((*ponteiro_arvore)->ponteiro_esquerda),valor,&(*quantidade_nodos));
        } // fim do condicional if
        
        // valor a ser inserido na árvore é maior que o valor presente no nodo atual
        else if (valor > (*ponteiro_arvore)->dado)
        {
            inserir_na_arvore(&((*ponteiro_arvore)->ponteiro_direita),valor,&(*quantidade_nodos));
        } // fim do condicional else if
        else// ignorar valor dentro nó duplicado
        { 
            printf("%s", " (valor duplicado)");
        } // fim do condicional else
    } // fim do condicional else
} // fim da função inserir_na_arvore

// inicia percurso em ordem da árvore
void percurso_em_ordem(nodo_arvore_ponteiro ponteiro_arvore)
{
    // se a árvore não está vazia, então percorre a mesma
    if (ponteiro_arvore != NULL)
    {
        percurso_em_ordem(ponteiro_arvore->ponteiro_esquerda);
        printf("%3d", ponteiro_arvore->dado);
        percurso_em_ordem(ponteiro_arvore->ponteiro_direita);
    } // fim do condicional if
}// fim da função percurso_em_ordem

// Função para imprimir árvore binária de busca
void impressao_formato_arvore(nodo_arvore_ponteiro ponteiro_arvore, int espaco)
{
    // Caso base
    if (ponteiro_arvore == NULL)
        return;
 
    // Incrementa a distância entre níveis
    espaco += COUNT;
 
    // Processa nó a direita primeiro
    impressao_formato_arvore(ponteiro_arvore->ponteiro_direita, espaco);
 
    // Imprime nó atual depois de dar o número de espaços
    // contador
    printf("\n");
    int i;
    for (i = COUNT; i < espaco; i++)
    {
        printf(" ");
    }
    
    printf("%d\n", ponteiro_arvore->dado);
 
    // Processa nós a esquerda
    impressao_formato_arvore(ponteiro_arvore->ponteiro_esquerda, espaco);
}

//A função abaixo busca o nó da árvore que possui um valor específico
//A função retorna o nó onde está o valor buscado ou NULL caso o valor não seja encontrado na árvore
nodo_arvore_ponteiro busca_nodo(nodo_arvore_ponteiro arvore, int valor)
{
    if(arvore == NULL) //se a árvore estiver vazia ou o valor não for encontrado
    {
        return NULL;
    }
    else if(arvore->dado > valor) //quando o valor buscado é menor que o valor presente no nó atual
    {
        return busca_nodo(arvore->ponteiro_esquerda, valor);//busca na árvore continua pelo nó filho a esquerda do nó atual
    }
    else if(arvore->dado < valor) //quando o valor buscado é maior que o valor presente no nó atual
    {
        return busca_nodo(arvore->ponteiro_direita , valor);//busca na árvore continua pelo nó filho a direita do nó atual
    }
    else
    {
        return arvore; //quando o nó com o valor buscado é encontrado
    }
}

nodo_arvore_ponteiro remove_nodo(nodo_arvore_ponteiro arvore, int valor, int quantidade_nodos)
{
    if(arvore == NULL || quantidade_nodos < 1)
    {
        printf("\n\t\tARVORE VAZIA\n");
        return NULL;
    }
    else if(arvore->dado > valor)
    {
        arvore->ponteiro_esquerda = remove_nodo(arvore->ponteiro_esquerda,valor,quantidade_nodos);
    }
    else if(arvore->dado < valor)
    {
        arvore->ponteiro_direita = remove_nodo(arvore->ponteiro_direita,valor,quantidade_nodos);
    }
    else
    {   
        if(arvore->ponteiro_esquerda == NULL && arvore->ponteiro_direita == NULL)
        {
            arvore = NULL;
            free(arvore);
        }
        else if(arvore->ponteiro_esquerda == NULL)
        {
    		nodo_arvore_ponteiro auxiliar_2 = arvore->ponteiro_direita;
            while(auxiliar_2->ponteiro_esquerda != NULL)
            {
                auxiliar_2 = auxiliar_2->ponteiro_esquerda;
            }
            arvore->dado = auxiliar_2->dado;
            auxiliar_2->dado = valor;
            arvore->ponteiro_direita = remove_nodo(arvore->ponteiro_direita,valor,quantidade_nodos);
        }
        else if(arvore->ponteiro_direita == NULL)
        {
            nodo_arvore_ponteiro auxiliar_2 = arvore->ponteiro_esquerda;
            while(auxiliar_2->ponteiro_direita != NULL)
            {
                auxiliar_2 = auxiliar_2->ponteiro_direita;
            }
            arvore->dado = auxiliar_2->dado;
            auxiliar_2->dado = valor;
            arvore->ponteiro_esquerda = remove_nodo(arvore->ponteiro_esquerda,valor,quantidade_nodos);
        }
        else
        {

            nodo_arvore_ponteiro auxiliar_2 = arvore->ponteiro_esquerda;
            while(auxiliar_2->ponteiro_direita != NULL)
            {
                auxiliar_2 = auxiliar_2->ponteiro_direita;
            }
            arvore->dado = auxiliar_2->dado;
            auxiliar_2->dado = valor;
            arvore->ponteiro_esquerda = remove_nodo(arvore->ponteiro_esquerda,valor,quantidade_nodos);
            free(auxiliar_2);
        }
    }
    return arvore;
}
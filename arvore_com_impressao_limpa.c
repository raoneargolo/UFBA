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
void inserir_na_arvore(nodo_arvore_ponteiro *ponteiro_arvore, int valor);
void percurso_em_ordem(nodo_arvore_ponteiro ponteiro_arvore);
void impressao_formato_arvore(nodo_arvore_ponteiro ponteiro_raiz, int espaco);

// função main inicia execução do programa
int main( int argc, char **argv )
{
    unsigned int i; // contador de loop de 1-10
    int item; // variável para armazenar os valores randômicos criados
    nodo_arvore_ponteiro ponteiro_raiz = NULL; // inicializando a árvore como nula

    srand( time( NULL ) );
    puts( "Os numeros a serem inseridos na arvore sao:" );

    // inserindo valores randômicos entre 0 e 14 na árvore
    for ( i = 1; i <= 20; ++i )
    {
        item = rand() % 100;
        printf( "%3d", item );
        inserir_na_arvore( &ponteiro_raiz, item); //insere valores aleatorios no nodo
    } // fim do laço for
    
    // percorrendo percurso em ordem
    puts( "\n\nO percuro em-ordem:" );
    percurso_em_ordem( ponteiro_raiz );

    printf("\n");

    print2D(ponteiro_raiz);

    exit(0);
} // fim da função principal

// inserindo nodo na árvore
void inserir_na_arvore( nodo_arvore_ponteiro *ponteiro_arvore, int valor )
{
    // se a árvore estiver vazia
    if ( *ponteiro_arvore == NULL ) {
        *ponteiro_arvore = malloc( sizeof( nodo_arvore ) );

        // se um espaço de memória foi alocado, então o nodo recebe o dado
        if ( *ponteiro_arvore != NULL ) {
            ( *ponteiro_arvore )->dado = valor;
            ( *ponteiro_arvore )->ponteiro_esquerda = NULL;
            ( *ponteiro_arvore )->ponteiro_direita = NULL;
        } // fim do condicional if
        else {
            printf( "%d nao inserido. Sem memoria disponivel.\n", valor );
        } // fim do condicional else
    } // fim do condional if
    else { // a árvore não está vazia
        // valor a ser inserido na árvore é menor que o valor presente no nodo atual
        if ( valor < ( *ponteiro_arvore )->dado ) {
            inserir_na_arvore( &( ( *ponteiro_arvore )->ponteiro_esquerda ), valor );
        } // fim do condicional if
        
        // valor a ser inserido na árvore é maior que o valor presente no nodo atual
        else if ( valor > ( *ponteiro_arvore )->dado ) {
            inserir_na_arvore( &( ( *ponteiro_arvore )->ponteiro_direita ), valor );
        } // fim do condicional else if
        else { // ignorar valor dentro nó duplicado
            printf( "%s", " (valor duplicado)" );
        } // fim do condicional else
    } // fim do condicional else
} // fim da função inserir_na_arvore

// inicia percurso em ordem da árvore
void percurso_em_ordem( nodo_arvore_ponteiro ponteiro_arvore )
{
    // se a árvore não está vazia, então percorre a mesma
    if ( ponteiro_arvore != NULL ) {
        percurso_em_ordem( ponteiro_arvore->ponteiro_esquerda );
        printf( "%3d", ponteiro_arvore->dado );
        percurso_em_ordem( ponteiro_arvore->ponteiro_direita );
    } // fim do condicional if
}// fim da função percurso_em_ordem

// Função para imprimir árvore binária de busca
void impressao_formato_arvore(nodo_arvore_ponteiro ponteiro_raiz, int espaco)
{
    // Caso base
    if (ponteiro_raiz == NULL)
        return;
 
    // Incrementa a distância entre níveis
    espaco += COUNT;
 
    // Processa nó a direita primeiro
    impressao_formato_arvore(ponteiro_raiz->ponteiro_direita, espaco);
 
    // Imprime nó atual depois de dar o número de espaços
    // contador
    printf("\n");
    int i;
    for (i = COUNT; i < espaco; i++)
        printf(" ");
    printf("%d\n", ponteiro_raiz->dado);
 
    // Processa nós a esquerda
    impressao_formato_arvore(ponteiro_raiz->ponteiro_esquerda, espaco);
}
 
// Wrapper over impressao_formato_arvore()
void print2D(nodo_arvore_ponteiro ponteiro_raiz)
{
   // Pass initial space count as 0
   impressao_formato_arvore(ponteiro_raiz, 0);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 5

// self-referential structure
struct nodo_arvore {
    struct nodo_arvore *ponteiro_esquerda; // pointer to left subtree
    int dado; // node valor
    struct nodo_arvore *ponteiro_direita; // pointer to right subtree
}; // end structure nodo_arvore789

typedef struct nodo_arvore nodo_arvore; // synonym for struct nodo_arvore
typedef nodo_arvore *nodo_arvore_ponteiro; // synonym for nodo_arvore*

// prototypes
void insertNode( nodo_arvore_ponteiro *ponteiro_arvore, int valor );
void inOrder( nodo_arvore_ponteiro ponteiro_arvore );
void print2D(nodo_arvore_ponteiro ponteiro_raiz);
void print2DUtil(nodo_arvore_ponteiro ponteiro_raiz, int espaco);

// function main begins program execution
int main( int argc, char **argv )
{
    unsigned int i; // counter to loop from 1-10
    int item; // variable to hold random valors
    nodo_arvore_ponteiro ponteiro_raiz = NULL; // tree initially empty

    srand( time( NULL ) );
    puts( "Os numeros a serem inseridos na arvore sao:" );

    // insert random valors between 0 and 14 in the tree
    for ( i = 1; i <= 20; ++i )
    {
        item = rand() % 100;
        printf( "%3d", item );
        insertNode( &ponteiro_raiz, item); //insere valores aleatorios no nodo
    } // end for
    
    // traverse the tree inOrder
    puts( "\n\nO percuro em-ordem:" );
    inOrder( ponteiro_raiz );

    printf("\n");

    print2D(ponteiro_raiz);

    exit(0);
} // end main

// insert node into tree
void insertNode( nodo_arvore_ponteiro *ponteiro_arvore, int valor )
{
    // if tree is empty
    if ( *ponteiro_arvore == NULL ) {
        *ponteiro_arvore = malloc( sizeof( nodo_arvore ) );

        // if memory was allocated, then assign dado
        if ( *ponteiro_arvore != NULL ) {
            ( *ponteiro_arvore )->dado = valor;
            ( *ponteiro_arvore )->ponteiro_esquerda = NULL;
            ( *ponteiro_arvore )->ponteiro_direita = NULL;
        } // end if
        else {
        printf( "%d nao inserido. Sem memoria disponivel.\n", valor );
        } // end else
    } // end if
    else { // tree is not empty
        // dado to insert is less than dado in current node
        if ( valor < ( *ponteiro_arvore )->dado ) {
            insertNode( &( ( *ponteiro_arvore )->ponteiro_esquerda ), valor );
        } // end if
        
        // dado to insert is greater than dado in current node
        else if ( valor > ( *ponteiro_arvore )->dado ) {
            insertNode( &( ( *ponteiro_arvore )->ponteiro_direita ), valor );
        } // end else if
        else { // duplicate dado valor ignored
            printf( "%s", " (valor duplicado)" );
        } // end else
    } // end else
} // end function insertNode

// begin inorder traversal of tree
void inOrder( nodo_arvore_ponteiro ponteiro_arvore )
{
    // if tree is not empty, then traverse
    if ( ponteiro_arvore != NULL ) {
        inOrder( ponteiro_arvore->ponteiro_esquerda );
        printf( "%3d", ponteiro_arvore->dado );
        inOrder( ponteiro_arvore->ponteiro_direita );
    } // end if
}// end function inOrder

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(nodo_arvore_ponteiro ponteiro_raiz, int espaco)
{
    // Base case
    if (ponteiro_raiz == NULL)
        return;
 
    // Increase distance between levels
    espaco += COUNT;
 
    // Process right child first
    print2DUtil(ponteiro_raiz->ponteiro_direita, espaco);
 
    // Print current node after space
    // count
    printf("\n");
    int i;
    for (i = COUNT; i < espaco; i++)
        printf(" ");
    printf("%d\n", ponteiro_raiz->dado);
 
    // Process left child
    print2DUtil(ponteiro_raiz->ponteiro_esquerda, espaco);
}
 
// Wrapper over print2DUtil()
void print2D(nodo_arvore_ponteiro ponteiro_raiz)
{
   // Pass initial space count as 0
   print2DUtil(ponteiro_raiz, 0);
}

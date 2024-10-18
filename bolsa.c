#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "itens.h"

S_Prod *add_item(S_Prod *sentinel, int id_count);
S_List *add_to_list(S_Prod *sentinel, S_List *sentry, int id_count);
S_List *null_ht(S_List *sentry);
S_Prod *null_fl(S_Prod *sentry);
void print_produtos(S_Prod *sentinel);
void print_inventory(S_List *sentinela);
void fechamento();
void abertura();
void menu_produtos(S_Prod *produto, int id);
void menu_inventory(S_Prod *produto, S_List *lista, int id);
bool menu(S_List *lista, S_Prod *produto);

int main(){
    bool executando = true;
    S_List lista;
    S_Prod produto;

    null_ht(&lista);
    null_fl(&produto);
    abertura();

    while(executando){
        executando = menu(&lista, &produto);
    }
    return 0;
}

S_Prod *add_item(S_Prod *sentinel, int id_count){
    Produto *novo;

    novo = (Produto *)malloc(sizeof(Produto));

    getchar();
    novo->id = id_count;
    printf("Nome o produto: ");
    scanf("%[^\n]", novo->nome); // %[^\n] -> Lê a string até a quebra de linha (Enter), trazendo espaços para o vetor de char
    getchar(); // "Coleta" um enter/espaço para não dar como entrada do próximo scanf
    printf("Descrição do produto: ");
    scanf("%[^\n]", novo->descricao);
    getchar();
    printf("Peso do produto: ");
    scanf("%lf", &novo->peso);
    sprintf(novo->status, "Ativo");
    novo->prox = NULL;
    if(sentinel->first==NULL){
        sentinel->first = novo;
        sentinel->last = novo;
    }else{
        sentinel->last->prox = novo;
        sentinel->last = novo;
    }
    return sentinel;
}
S_List *add_to_list(S_Prod *sentinel, S_List *sentry, int id_count){
    Inventory *atual;
    Produto *aux_prod;
    int sel;

    printf("Qual produto deseja adicionar ao inventário? (Selecione pelo ID)\n");
    print_produtos(sentinel);
    scanf("%d", &sel);

    for(aux_prod=sentinel->first; aux_prod!=NULL; aux_prod=aux_prod->prox){
        if(aux_prod->id==sel){
            break;
        }
    }

    atual = (Inventory *)malloc(sizeof(Inventory));
    atual->id = id_count;
    atual->item = aux_prod;
    printf("Quantidade do produto a ser adicionado ao inventário?\n");
    scanf("%d", &atual->quantidade);
    atual->peso_lista = atual->quantidade * atual->item->peso;
    atual->next = NULL;
    atual->prev = NULL;
    if(sentry->head==NULL){
        sentry->head = atual;
        sentry->tail = atual;
    }else{
        atual->prev = sentry->tail;
        sentry->tail->next = atual;
        sentry->tail = atual;
    }
    
    print_inventory(sentry);

    return sentry;
}
S_List *null_ht(S_List *sentry){
    sentry->head = NULL;
    sentry->tail = NULL;

    return sentry;
}
S_Prod *null_fl(S_Prod *sentry){
    sentry->first = NULL;
    sentry->last = NULL;
    
    return sentry;
}
void print_produtos(S_Prod *sentinel){
    Produto *aux;
    printf("\nTodos os Produtos:\n");
    for(aux=sentinel->first; aux!=NULL; aux=aux->prox){
        printf("\tID: %d\n", aux->id);
        printf("\tNome: %s\n", aux->nome);
        printf("\tDescrição: %s\n", aux->descricao);
        printf("\tPeso: %.2f\n", aux->peso);
        printf("\tStatus: %s\n", aux->status);
    }
}
void print_inventory(S_List *sentinela){
    Inventory *aux;

    printf("Inventário:\n");
    for(aux=sentinela->head; aux!=NULL; aux=aux->next){
        printf("\tID: %d\n", aux->id);
        printf("\tProduto ID: %d\n", aux->item->id);
        printf("\tQuantidade: %d\n", aux->quantidade);
        printf("\tPeso total: %.2lf\n", aux->peso_lista);
    }
}
void fechamento(){
    printf("Execução finalizada!\n");
}
void abertura(){
    printf("******************************************\n");
    printf("* Sistema de Gerenciamento de Inventário *\n");
    printf("******************************************\n");
}
void menu_produtos(S_Prod *produto, int id){
    int option;

    printf("Produtos:\n");
    printf("\t1 - Adicionar Produto\n\t2 - Visualizar Produtos\n");
    scanf("%d", &option);

    switch (option) {
    case 1:
        add_item(produto, id);
        break;
    case 2:
        print_produtos(produto);
        break;
    default:
        return;
    }
}
void menu_inventory(S_Prod *produto, S_List *lista, int id){
    int option;

    printf("Inventário:\n");
    printf("\t1 - Adicionar ao Inventário\n\t2 - Visualizar Inventário\n");
    scanf("%d", &option);

    switch (option) {
    case 1:
        add_to_list(produto, lista, id);
        break;
    case 2:
        print_inventory(lista);
        break;
    default:
        return;
    }
}
bool menu(S_List *lista, S_Prod *produto){
    int option, id_prod = 1, id_invetory = 1;

    for(;;){
        printf("\nSitema de Gerenciamento de Inventário\n");
        printf("\t1 - Produtos\n\t2 - Inventário\n");
        scanf("%d", &option);

        switch (option){
        case 1:
            menu_produtos(produto, id_prod);
            id_prod++;
            break;
        case 2:
            menu_inventory(produto, lista, id_invetory);
            id_invetory++;
            break;
        default:
            return false;
        }
    }
}
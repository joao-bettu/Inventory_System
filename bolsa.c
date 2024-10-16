#include <stdio.h>
#include <stdlib.h>
#include "itens.h"
#include <stdbool.h>

void print_produtos(Produto *primeiro);
Produto *add_item(Produto *primeiro, int id_count);
Inventory *add_to_list(Produto *item, Sentinela *sentry, int id_count);
void null_sentry(Sentinela *sentry);
void print_inventory(Sentinela *sentinela);

int main(){
    int option, id_prod=1, id_list = 1;
    Produto *p_prod = NULL;
    bool executando = true;
    Sentinela lista;

    null_sentry(&lista);

    while(executando){
        printf("Sitema de Gerenciamento de Inventário\n");
        printf("\t1 - cadastrar produto\n\t2 - Adicionar ao inventário\n");
        scanf("%d", &option);
        
        switch (option){
        case 1:
            p_prod = add_item(p_prod, id_prod);
            id_prod++;
            break;
        case 2:
            add_to_list(p_prod, &lista, id_list);
            id_list++;
            break;
        default:
            executando = false;
        }
    }
    return 0;
}
Produto *add_item(Produto *primeiro, int id_count){
    Produto *novo, *auxiliar;

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
    novo->prox = NULL;
    if(primeiro==NULL){
        primeiro = novo;
        auxiliar = novo;
    }else{
        auxiliar->prox = novo;
        auxiliar = novo;
    }
    return primeiro;
}
Inventory *add_to_list(Produto *primeiro, Sentinela *sentry, int id_count){
    Inventory *atual;
    Produto *aux_prod;
    int sel;

    printf("Qual produto deseja adicionar ao inventário? (Selecione pelo ID)\n");
    print_produtos(primeiro);
    scanf("%d", &sel);

    for(aux_prod=primeiro; aux_prod!=NULL; aux_prod=aux_prod->prox){
        if(aux_prod->id==sel){
            break;
        }
    }

    atual = (Inventory *)malloc(sizeof(Inventory));
    atual->id = id_count;
    atual->item = aux_prod;
    printf("Quantidade do produto a ser adicionado ao inventário?\n");
    scanf("%d", &atual->quantidade);
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

    return sentry->head;
}
void null_sentry(Sentinela *sentry){
    sentry->head = NULL;
    sentry->tail = NULL;
}
void print_produtos(Produto *primeiro){
    Produto *aux;
    printf("\nTodos os Produtos:\n");
    for(aux=primeiro; aux!=NULL; aux=aux->prox){
        printf("\tID: %d\n", aux->id);
        printf("\tNome: %s\n", aux->nome);
        printf("\tDescrição: %s\n", aux->descricao);
        printf("\tPeso: %f\n", aux->peso);
    }
}
void print_inventory(Sentinela *sentinela){
    Inventory *aux;

    printf("Lista:\n");
    for(aux=sentinela->head; aux!=NULL; aux=aux->next){
        printf("\tID: %d\n", aux->id);
        printf("\tProduto ID: %d\n", aux->item->id);
        printf("\tQuantidade: %d\n", aux->quantidade);
    }
}
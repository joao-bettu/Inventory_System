#include <stdio.h>
#include <stdlib.h>
#include "itens.h"
#include <stdbool.h>

void print_produtos(Produto *primeiro);
Produto *add_item(Produto *primeiro, int id_count);
Inventory *add_to_list(Produto *item, Sentinela *sentry, int id_count);
void null_sentry(Sentinela *sentry);
int main(){
    int option, id_prod=1;
    Produto *p_prod = NULL;
    bool executando = true;

    while(executando){
        printf("Sitema de Gerenciamento de Inventário\n");
        printf("\t1 - cadastrar produto\n\t2 - Adicionar ao inventário\n");
        scanf("%d", &option);
        
        switch (option){
        case 1:
            add_item(p_prod, id_prod);
            id_prod++;
            break;
        case 2:
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

    novo->id = id_count;
    printf("Nome o produto: ");
    scanf("%s", novo->nome);
    printf("Descrição do produto: ");
    scanf("%s", novo->descricao);
    printf("Peso do produto: ");
    scanf("%f", &novo->peso);
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
    Inventory *atual, *aux_list;
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
    
    return sentry->head;
}
void null_sentry(Sentinela *sentry){
    sentry->head = NULL;
    sentry->tail = NULL;
}
void print_produtos(Produto *primeiro){
    Produto *aux;
    printf("Todos os Produtos:\n");
    for(aux=primeiro; aux!=NULL; aux=aux->prox){
        printf("\n\tID: %d\n", aux->id);
        printf("\tNome: %s\n", aux->nome);
        printf("\tDescrição: %s\n", aux->descricao);
        printf("\tPeso: %f\n", aux->peso);
    }
}
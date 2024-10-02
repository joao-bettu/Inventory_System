#include <stdio.h>
#include <stdlib.h>
#include "itens.h"

Produto add_item(int id_count);
Inventory add_to_list(Produto item, Sentinela sentry);
void null_sentry(Sentinela sentry);
int main(){
    int option;

    for(;;){
        printf("Sitema de Gerenciamento de Inventário\n");
        printf("\t1 - cadastrar produto\n\t2 - Adicionar ao inventário\n");
        scanf("%d", &option);
        
        switch (option){
        case 1:
            break;
        case 2:
            break;
        default:
            return 0;
        }
    }
    
    return 0;
}
Produto add_item(int id_count){
    Produto novo;

    novo.id = id_count;
    printf("Nome o produto: ");
    scanf("%s", novo.nome);
    printf("Descrição do produto: ");
    scanf("%s", novo.descricao);
    printf("Peso do produto: ");
    scanf("%f", &novo.peso);
}
Inventory add_to_list(Produto item, Sentinela sentry){
    Inventory *atual, *aux;

    atual = (Inventory *)malloc(sizeof(Inventory));
    for(aux=sentry.head;aux!=NULL;aux=aux->next){
        
    }
}
void null_sentry(Sentinela sentry){

}
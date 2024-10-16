typedef struct prod{
    int id;
    char nome[30];
    char descricao[50];
    double peso;
    struct prod *prox;
}Produto;

typedef struct list{
    int id;
    Produto *item;
    int quantidade;
    struct list *next, *prev;
}Inventory;

typedef struct sent{
    Inventory *head, *tail;
}Sentinela;
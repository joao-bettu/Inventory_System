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
    double peso_lista;
    struct list *next, *prev;
}Inventory;

typedef struct sent{
    Inventory *head, *tail;
}S_List;

typedef struct sentry{
    Produto *first, *last;
}S_Prod;
typedef struct prod{
    int id;
    char nome[15];
    char descricao[30];
    float peso;
}Produto;

typedef struct list{
    int id;
    Produto item;
    int quantidade;
    struct list *next, *prev;
}Inventory;

typedef struct sent{
    Inventory *head, *tail;
}Sentinela;
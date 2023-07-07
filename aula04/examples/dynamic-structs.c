#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

// Define um item do cardapio.
// Um item do cardapio precisa ter
// um nome e um preço.
struct s_item {
    float price;
    char *name;
};

typedef struct s_item Item;

// Define o que é um cardapio.
// O cardápio é um vetor de
// itens e também a quantidade
// de itens que o cardápio possui.
struct s_menu {
    int nItems;
    Item items[MAX_ITEMS];
};

typedef struct s_menu Menu;

// Define o que é um loja.
// Uma loja precisa de um nome,
// do numero de funcionários e
// de um cardápio.
struct s_store {
    char *name;
    int nWorkers;
    Menu menu;   
};

typedef struct s_store Store;

// Cria uma nova loja a partir do nome e do
// número de funcionários. Note que o cardápio
// inicialmente possui 0 itens.
Store createStore(char *name, int nWorkers){
    Store store;

    store.name = name;
    store.nWorkers = nWorkers;

    store.menu.nItems = 0;

    return store;
}

// Imprime as informações de uma loja no terminal.
void printStore(Store store){
    printf("=================\n");
    printf("Store name: %s\n", store.name);
    printf("Store nWorkers: %d\n\n", store.nWorkers);
    
    printf("Store Menu: \n");
    for(int i = 0; i < store.menu.nItems; i++){
        printf("%s: %.2f\n", store.menu.items[i].name, store.menu.items[i].price);
    }
}

// Adiciona um novo item no cardapio de uma loja.
// Note que o número de itens só é acrescido no final.
void addItem(Store *store, char *name, float price){
    
    int actualItemsNumber = store->menu.nItems;

    store->menu.items[ actualItemsNumber ].name = name;
    store->menu.items[ actualItemsNumber ].price = price;

    store->menu.nItems++;
}

// Lógica de negócio para adicionar
// um funcionário em uma loja.
void addWorker(Store *store){
    store->nWorkers++;
}

int main(){

    char *name = "Coffee Shop";
    char nWorkers = 0;

    Store firstStore = createStore(name, nWorkers);

    addItem(&firstStore, "Coffee", 2);
    addItem(&firstStore, "Express", 4);

    addWorker(&firstStore);

    printStore(firstStore);

    Store secondStore = createStore("Second Coffee Store", 5);

    addItem(&secondStore, "Hamburguer", 17);

    printStore(secondStore);

    return 0;
}
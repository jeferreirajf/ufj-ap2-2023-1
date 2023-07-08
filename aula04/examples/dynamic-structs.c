#include <stdio.h>
#include <stdlib.h>

// Define um item do cardapio.
// Um item do cardapio precisa ter
// um nome e um preço.
struct s_item
{
    float price;
    char *name;
};

typedef struct s_item Item;

// Define o que é um cardapio.
// O cardápio é um vetor de
// itens e também a quantidade
// de itens que o cardápio possui.
struct s_menu
{
    int nItems;
    Item *items;
};

typedef struct s_menu Menu;

// Define o que é um loja.
// Uma loja precisa de um nome,
// do numero de funcionários e
// de um cardápio.
struct s_store
{
    char *name;
    int nWorkers;
    Menu menu;
};

typedef struct s_store Store;

// Cria uma nova loja a partir do nome e do
// número de funcionários. Note que o cardápio
// inicialmente possui 0 itens.
Store createStore(char *name, int nWorkers)
{
    Store store;

    store.name = name;
    store.nWorkers = nWorkers;

    store.menu.nItems = 0;

    // Faz o ponteiro guardar um endereço
    // que significa "lugar nenhum".
    // Quer dizer, o valor "NULL" significa
    // "lugar nenhum" na linguagem C.
    // Pode ser muito útil para verificar se
    // O ponteiro está guardando um endereço
    // válido ou ainda não está guardando
    // um endereço válido.
    store.menu.items = NULL;

    return store;
}

// Imprime as informações de uma loja no terminal.
void printStore(Store store)
{
    printf("=================\n");
    printf("Store name: %s\n", store.name);
    printf("Store nWorkers: %d\n\n", store.nWorkers);

    printf("Store Menu: \n");
    for (int i = 0; i < store.menu.nItems; i++)
    {
        printf("%s: %.2f\n", store.menu.items[i].name, store.menu.items[i].price);
    }
}

// Adiciona um novo item no cardapio de uma loja.
// Note que o número de itens só é acrescido no final.
// Em Estruturas de Dados vocês irão conhecer uma estrutura
// Que resolveria esse problema de adicionar itens
// muito melhor do que essa solução apresentada aqui.
void addItem(Store *store, char *name, float price)
{

    // Representa a quantidade de itens atuais no cardápio
    int actualItemsNumber = store->menu.nItems;

    // Instância um novo vetor de itens com n+1 itens.
    Item *newItemsArray = (Item *)malloc(sizeof(Item) * (actualItemsNumber + 1));

    // Faz a cópia de cada item que já existia no menu
    // para o novo vetor de itens (n primeiros itens)
    for (int i = 0; i < actualItemsNumber; i++)
    {
        newItemsArray[i] = store->menu.items[i];
    }

    // Adiciona o novo item no novo vetor
    newItemsArray[actualItemsNumber].name = name;
    newItemsArray[actualItemsNumber].price = price;

    // Libero o espaço de memória do vetor
    // que representa o cardápio
    // REGRA DO 1 PRA 1
    free(store->menu.items);

    // Agora o ponteiro da loja deve guardar
    // o endereço que estava sendo guardado
    // no novo vetor de itens
    store->menu.items = newItemsArray;

    // O número de itens do cardápio é acrescido
    // em um.
    store->menu.nItems++;
}

// Lógica de negócio para adicionar
// um funcionário em uma loja.
void addWorker(Store *store)
{
    store->nWorkers++;
}

// Libera o espaço de memória
// ocupado pelo cardápio da loja
// REGRA DO 1 PRA 1
void destroyStore(Store *store)
{
    free(store->menu.items);
}

int main()
{
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

    destroyStore(&firstStore);
    destroyStore(&secondStore);

    return 0;
}
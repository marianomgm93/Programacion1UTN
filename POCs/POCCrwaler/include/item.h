#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#define DIM 30

struct Item {
    char nombre[DIM];
    int cantidad;
};

int buscarItem(struct Item items[], char nombreItem[]);
int eliminarItem(struct Item items[], char nombreItem[]);
void usarItem(struct Item items[], char nombreItem[]);
void agregarItem(struct Item items[], char nombreItem[], int cantidad);

#endif // ITEM_H_INCLUDED

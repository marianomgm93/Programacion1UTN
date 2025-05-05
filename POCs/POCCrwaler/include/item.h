#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#define DIM 30

typedef struct  {
    char nombre[DIM];
    int cantidad;
}Item;

int buscarItem( Item items[], char nombreItem[]);
int eliminarItem( Item items[], char nombreItem[]);
void usarItem( Item items[], char nombreItem[]);
void agregarItem( Item items[], char nombreItem[], int cantidad);

#endif // ITEM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define OUT 0
#define IN 1
float calcularPrecio(int cantidad,float precio);
void compra(int* cantidad,float* precio);
void calcularDescuento(float* montoTotal,int cantidadProducto,float* totalConDescuento);
void facturar(int cantidad,float precio,float total,float totalConDescuento);
void vender(int* cantidad,float* precio,float* total,float* totalConDescuento,int* sumatoriaVendidos,float* totalDiario);
void iniciarVendedor(int* cantidad,float* precio,float* total,float* totalConDescuento,int* sumatoriaVendidos,float* totalDiario);
int negocio();
int main()
{
    negocio();
    return 0;
}
int negocio()
{
    int sumatoriaVendidos,cantidad,option,status=IN;
    float precio,total,totalConDescuento,totalDiario;
    while(status)
    {
        printf("0\tSalir\n1\tCompra\n2\tPrecio carrito\n3\tFacturar\n4\tRealizar venta\n5\tArqueo diario\n6\tIniciar vendedor\n");
        scanf("%i",&option);
        switch(option)
        {
        case 0:
            printf("Esta seguro de que desea cerrar la sesion?\n1\tSi\n2\tNo\n");
            scanf("%i",&option);
            switch(option)
            {
            case 1:
                status=OUT;
            case 2:
                break;
            default:
                printf("El caracter ingresado no corresponde a ninguna opcion, intentelo nuevamente");
                break;
            }
            break;
        case 1:
            compra(&cantidad,&precio);
            break;
        case 2:
            total=calcularPrecio(cantidad,precio);
            calcularDescuento(&total,cantidad,&totalConDescuento);
            printf("total:%f\ncantidad:%i\ntotal con descuento:%f\n",total,cantidad,totalConDescuento);
            break;
        case 3:
            facturar(cantidad,precio,total,totalConDescuento);
            break;
        case 4:
            vender(&cantidad,&precio,&total,&totalConDescuento,&sumatoriaVendidos,&totalDiario);
            break;
        case 5:
            printf("Total diario actual:%.2f\nVentas totales:%i\n",totalDiario,sumatoriaVendidos);
            break;
        case 6:
            iniciarVendedor(&cantidad,&precio,&total,&totalConDescuento,&sumatoriaVendidos,&totalDiario);
            break;
        default:
            printf("El caracter ingresado no corresponde a ninguna opcion, intentelo nuevamente");
            break;
        }
    }
}
/**A_Hacer una función que pida la cantidad de productos comprados por el cliente y el
precio de por unidad y retorne ambos. (Ojo, solo puede haber un return y sólo puede retornar un valor, pensar bien).
*/
void compra(int* cantidad,float* precio)
{
    printf("Ingrese la cantidad de productos\n");
    scanf("%i",cantidad);
    printf("Ingrese el valor del producto\n");
    scanf("%f",precio);
}
/**
*B_Hacer una función que reciba como parámetro, la cantidad de productos y el precio y retorne el
*monto total de la venta.
*/
float calcularPrecio(int cantidad,float precio)
{
    float total=(float)cantidad*precio;
    return total;
}
/**
*C_Una función para determinar el descuento aplicado (si es que tiene). Por parámetro pasa, el monto
*total de la compra y la cantidad de producto comprado. Si el monto de la compra supera los 1000$ y
*son más de 10 productos, tiene un descuento del 15%, si la compra supera los 2000$ y la cantidad de
*productos es 25 o más, tiene un descuento del 20%, si no cumple ninguno de los requisitos no se le
*aplica descuento alguno.
*/
void calcularDescuento(float* montoTotal,int cantidadProducto,float* totalConDescuento)
{
    if(*montoTotal>2000 && cantidadProducto>25)
    {
        *totalConDescuento=(*montoTotal)*0.8;
    }
    else if(*montoTotal>1000&&cantidadProducto>10)
    {
        *totalConDescuento=(*montoTotal)*0.85;
    }
}
/**
*D_Hacer una función que muestre por pantalla la factura de compra. Ejemplo:
*		Empresa “pirulo”
*		Cantidad de productos …………………….. 12 u.
*		Precio por producto ………………………… $ 200
*Total parcial …………………………………. $ 2400
*Descuento aplicado ……………………….... -$ 360
*Monto a pagar ……………………………….. $ 2040
*/
void facturar(int cantidad,float precio,float total,float totalConDescuento)
{

    printf("Empresa \"nombreEmpresa\"\n"
           "Cantidad de productos.....%i u\n"
           "Precio por producto.......$%.2f\n"
           "Total parcial.............$%.2f\n"
           "Descuento aplicado........-$%.2f\n"
           "Total a pagar.............$%.2f\n",cantidad,precio,total,total-totalConDescuento,totalConDescuento);
}
/**
*E_Una función que realice una venta (tiene que llamar a todas las anteriores
*/
void vender(int* cantidad,float* precio,float* total,float* totalConDescuento,int* sumatoriaVendidos,float* totalDiario)
{
    compra(cantidad,precio);
    *total=calcularPrecio(*cantidad,*precio);
    calcularDescuento(total,*cantidad,totalConDescuento);
    facturar(*cantidad,*precio,*total,*totalConDescuento);
    *totalDiario+=*totalConDescuento;
    *sumatoriaVendidos+=*cantidad;
}
/**
*F_El usuario puede realizar todas las ventas que desee, una vez que ya no tiene más ventas, el programa
*debe mostrar el monto total y la cantidad de producto vendido a lo largo del día.
*/
void iniciarVendedor(int* cantidad,float* precio,float* total,float* totalConDescuento,int* sumatoriaVendidos,float* totalDiario)
{
    int status=IN,option;
    while(status)
    {
        printf("1\tNueva venta\n0\tSalir\n");
        scanf("%i",&option);
        switch(option)
        {
        case 0:
            status=OUT;
            break;
        case 1:
            vender(cantidad,precio,total,totalConDescuento,sumatoriaVendidos,totalDiario);
            break;
        default:
            printf("El caracter ingresado no corresponde a ninguna opcion, intentelo nuevamente");
            break;
        }

    }
}
/**Ejercicios propuestos

Un negocio desea un sistema que le permita llevar las ventas de su negocio.
Nos contrata a nosotros para la realización del programa. Hemos determinado que
el sistema necesita lo siguiente (Suponemos que solo vende un producto):

A_Hacer una función que pida la cantidad de productos comprados por el cliente y el
precio de por unidad y retorne ambos. (Ojo, solo puede haber un return y sólo puede retornar un valor, pensar bien).

B_Hacer una función que reciba como parámetro, la cantidad de productos y el precio y retorne el
monto total de la venta.

C_Una función para determinar el descuento aplicado (si es que tiene). Por parámetro pasa, el monto
total de la compra y la cantidad de producto comprado. Si el monto de la compra supera los 1000$ y
son más de 10 productos, tiene un descuento del 15%, si la compra supera los 2000$ y la cantidad de
productos es 25 o más, tiene un descuento del 20%, si no cumple ninguno de los requisitos no se le
aplica descuento alguno.

D_Hacer una función que muestre por pantalla la factura de compra. Ejemplo:
		Empresa “pirulo”
		Cantidad de productos …………………….. 12 u.
		Precio por producto ………………………… $ 200
Total parcial …………………………………. $ 2400
Descuento aplicado ……………………….... -$ 360
Monto a pagar ……………………………….. $ 2040

E_Una función que realice una venta (tiene que llamar a todas las anteriores)

F_El usuario puede realizar todas las ventas que desee, una vez que ya no tiene más ventas, el programa
debe mostrar el monto total y la cantidad de producto vendido a lo largo del día.
*/

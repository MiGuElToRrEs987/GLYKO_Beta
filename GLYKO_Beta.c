#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTOS 5

typedef struct {
    char nombre[50];
    float precio;
    int inventario;
} Producto;

Producto inventario[MAX_PRODUCTOS];

void inicializarInventario() {
    // Configura los productos iniciales y su inventario
    strcpy(inventario[0].nombre, "Dulce 1");
    inventario[0].precio = 10.0;
    inventario[0].inventario = 5;

    strcpy(inventario[1].nombre, "Dulce 2");
    inventario[1].precio = 15.0;
    inventario[1].inventario = 3;

    strcpy(inventario[2].nombre, "Dulce 3");
    inventario[2].precio = 12.0;
    inventario[2].inventario = 7;

    strcpy(inventario[3].nombre, "Dulce 4");
    inventario[3].precio = 8.0;
    inventario[3].inventario = 10;

    strcpy(inventario[4].nombre, "Dulce 5");
    inventario[4].precio = 20.0;
    inventario[4].inventario = 2;
}

void mostrarProductos() {
    printf("Productos disponibles:\n");
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        printf("%d. %s - Precio: %.2f - Inventario: %d\n", i + 1, inventario[i].nombre, inventario[i].precio,
               inventario[i].inventario);
    }
}

void comprarProducto(int producto) {
    if (producto < 1 || producto > MAX_PRODUCTOS) {
        printf("Opción inválida. Por favor, seleccione un producto válido.\n");
        return;
    }

    int cantidad;
    printf("Ingrese la cantidad de %s a comprar: ", inventario[producto - 1].nombre);
    scanf("%d", &cantidad);

    if (cantidad > inventario[producto - 1].inventario) {
        printf("No hay suficiente inventario. Por favor, elija una cantidad menor.\n");
        return;
    }

    float total = inventario[producto - 1].precio * cantidad;
    printf("El total a pagar es: %.2f\n", total);

    float pago;
    printf("Ingrese el monto de pago: ");
    scanf("%f", &pago);

    if (pago < total) {
        printf("El pago es insuficiente. No se puede completar la compra.\n");
        return;
    }

    float cambio = pago - total;
    printf("Su cambio es: %.2f\n", cambio);

    // Lógica para despachar el producto
    printf("Despachando %d %s...\n", cantidad, inventario[producto - 1].nombre);
    inventario[producto - 1].inventario -= cantidad;
}

void resurtirMaquina() {
    printf("Resurtir la máquina:\n");
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        int cantidad;
        printf("Ingrese la cantidad de %s a resurtir: ", inventario[i].nombre);
        scanf("%d", &cantidad);
        inventario[i].inventario += cantidad;
    }
}

void mostrarInformacionAdmin() {
    printf("Información del administrador:\n");
    // Lógica para mostrar saldo, número de ventas, etc.
    // ...
}

int main() {
    int opcion;
    int modoAdmin = 0;
    char password[20];

    inicializarInventario();

    printf("¡Bienvenido a GLYKO!\n");

    do {
        if (!modoAdmin) {
            printf("\nMÁQUINA EXPENDEDORA\n");
            printf("1. Mostrar productos disponibles\n");
            printf("2. Comprar producto\n");
            printf("3. Ingresar al modo administrador\n");
            printf("0. Salir\n");
            printf("Ingrese una opción: ");
            scanf("%d", &opcion);

            switch (opcion) {
                case 1:
                    mostrarProductos();
                    break;
                case 2:
                    mostrarProductos();
                    printf("Seleccione el número de producto a comprar: ");
                    scanf("%d", &opcion);
                    comprarProducto(opcion);
                    break;
                case 3:
                    printf("Ingrese la contraseña del modo administrador: ");
                    scanf("%s", password);
                    if (strcmp(password, "admin123") == 0) {
                        modoAdmin = 1;
                    } else {
                        printf("Contraseña incorrecta. Vuelva a intentarlo.\n");
                    }
                    break;
                case 0:
                    printf("Saliendo del programa...\n");
                    break;
                default:
                    printf("Opción inválida. Por favor, intente de nuevo.\n");
                    break;
            }
        } else {
            printf("\nMODO ADMINISTRADOR\n");
            printf("1. Mostrar inventario completo\n");
            printf("2. Resurtir máquina\n");
            printf("3. Mostrar información del administrador\n");
            printf("4. Salir del modo administrador\n");
            printf("Ingrese una opción: ");
            scanf("%d", &opcion);

            switch (opcion) {
                case 1:
                    mostrarProductos();
                    break;
                case 2:
                    resurtirMaquina();
                    break;
                case 3:
                    mostrarInformacionAdmin();
                    break;
                case 4:
                    modoAdmin = 0;
                    break;
                default:
                    printf("Opción inválida. Por favor, intente de nuevo.\n");
                    break;
            }
        }
    } while (opcion != 0);

    return 0;
}

#include "punto1.h"
#include <iostream>

void mostrarMenuPrincipal() {
    std::cout << "************************************\n";
    std::cout << "* Por favor, elige una opcion: *\n";
    std::cout << "* 1. Ejercicio 1 *\n";
    std::cout << "* 2. Salir *\n";
    std::cout << "************************************\n";
}

void mostrarMenuEjercicio1() {
    std::cout << "************************************\n";
    std::cout << "* Estas en el Ejercicio 1 *\n";
    std::cout << "BIENVENIDO A MI TIENDA,EN QUE TE PUEDO COLABORAR? *\n";
    std::cout << "* Por favor, elige una opcion: *\n";
    std::cout << "* 1. Agregar productos *\n";
    std::cout << "* 2. Modificar productos *\n";
    std::cout << "* 3. Realizar compra *\n";
    std::cout << "* 4. Regresar al menu principal *\n";
    std::cout << "************************************\n";
}

int main() {
    Punto1 punto1;

    while (true) {
        mostrarMenuPrincipal();

        int opcion;
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            while (true) {
                mostrarMenuEjercicio1();

                int opcionEjercicio1;
                std::cin >> opcionEjercicio1;

                switch (opcionEjercicio1) {
                case 1: {
                    std::string nombre, marca, tipo;
                    int precio, descuento, cantidad;
                    std::cout << "Introduce el nombre del producto: ";
                    std::cin >> nombre;
                    std::cout << "Introduce la marca del producto: ";
                    std::cin >> marca;
                    std::cout << "Introduce el precio del producto: ";
                    std::cin >> precio;
                    std::cout << "Introduce el descuento del producto: ";
                    std::cin >> descuento;
                    std::cout << "Introduce la cantidad del producto: ";
                    std::cin >> cantidad;
                    std::cout << "Introduce el tipo de producto (Comestible, Electronico, Aseo): ";
                    std::cin >> tipo;
                    if (tipo == "Comestible") {
                        std::string fechaVencimiento;
                        std::cout << "Introduce la fecha de vencimiento del producto (MM-YYYY): ";
                        std::cin >> fechaVencimiento;
                        Comestible* producto = new Comestible(nombre, marca, precio, descuento, cantidad, fechaVencimiento);
                        punto1.agregarProducto(producto);
                    } else if (tipo == "Electronico") {
                        int garantia;
                        std::cout << "Introduce la garantia del producto (en meses): ";
                        std::cin >> garantia;
                        Electronico* producto = new Electronico(nombre, marca, precio, descuento, cantidad, garantia);
                        punto1.agregarProducto(producto);
                    } else if (tipo == "Aseo") {
                        std::string material;
                        std::cout << "Introduce el material del producto: ";
                        std::cin >> material;
                        Aseo* producto = new Aseo(nombre, marca, precio, descuento, cantidad, material);
                        punto1.agregarProducto(producto);
                    }
                    break;
                }
                case 2: {
                    std::string nombre;
                    int nuevoPrecio, nuevoDescuento;
                    std::cout << "Introduce el nombre del producto a modificar: ";
                    std::cin >> nombre;
                    std::cout << "Introduce el nuevo precio del producto: ";
                    std::cin >> nuevoPrecio;
                    std::cout << "Introduce el nuevo descuento del producto: ";
                    std::cin >> nuevoDescuento;
                    punto1.modificarProducto(nombre, nuevoPrecio, nuevoDescuento);
                    break;
                }
                case 3: {
                    std::string nombre;
                    int cantidad;
                    std::cout << "Introduce el nombre del producto a comprar: ";
                    std::cin >> nombre;
                    std::cout << "Introduce la cantidad del producto a comprar: ";
                    std::cin >> cantidad;
                    punto1.realizarCompra(nombre, cantidad);
                    break;
                }
                case 4:
                    break;
                default:
                    std::cout << "Opcion no válida. Por favor, elige una opción del menu.\n";
                }

                if (opcionEjercicio1 == 4) {
                    break;
                }
            }
            break;
        }
        case 2:
            std::cout << "Gracias por usar nuestra aplicacion. Hasta luego!!\n";
            return 0;
        default:
            std::cout << "Opción no valida. Por favor, elige una opción del menu.\n";
        }
    }
}

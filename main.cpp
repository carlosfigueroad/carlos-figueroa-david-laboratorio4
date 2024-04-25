#include "punto1.h"
#include <iostream>

void mostrarMenu() {
    std::cout << "************************************\n";
    std::cout << "* Bienvenido a la tienda Punto1! *\n";
    std::cout << "* Por favor, elige una opción: *\n";
    std::cout << "* 1. Agregar productos *\n";
    std::cout << "* 2. Modificar productos *\n";
    std::cout << "* 3. Realizar compra *\n";
    std::cout << "* 4. Salir *\n";
    std::cout << "************************************\n";
}

int main() {
    Punto1 punto1;

    Comestible* pan = new Comestible("Pan", "Bimbo", 2000, 10, 50, "12-2024");
    punto1.agregarProducto(pan);

    Comestible* leche = new Comestible("Leche", "Alpina", 3000, 5, 30, "01-2025");
    punto1.agregarProducto(leche);

    Electronico* televisor = new Electronico("Televisor", "Samsung", 2000000, 15, 10, 24);
    punto1.agregarProducto(televisor);

    Electronico* celular = new Electronico("Celular", "Apple", 3000000, 20, 15, 12);
    punto1.agregarProducto(celular);

    Aseo* jabon = new Aseo("Jabón", "Protex", 1500, 5, 100, "Glicerina");
    punto1.agregarProducto(jabon);

    Aseo* shampoo = new Aseo("Shampoo", "Head & Shoulders", 8000, 10, 70, "Anticaspa");
    punto1.agregarProducto(shampoo);

    while (true) {
        mostrarMenu();

        int opcion;
        std::cin >> opcion;

        switch (opcion) {
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
                std::cout << "Introduce la garantía del producto (en meses): ";
                std::cin >> garantia;
                Electronico* producto = new Electronico(nombre, marca, precio, descuento, cantidad, garantia);
                punto1.agregarProducto(producto);
            } else if (tipo == "Aseo") {
                std::string material;
                std::cout << "Introduce el material del producto: ";
                std::cin >> material;
                Aseo* producto = new Aseo(nombre, marca, precio, descuento, cantidad, material);
                punto



#include <iostream>
#include <vector>
#include <sstream>
#include "CuentaCorriente.h"
#include "punto1.h"

// Función para dividir una cadena por un delimitador
std::vector<std::string> split(const std::string& str, char delim) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Función para encontrar una cuenta por ID
CuentaCorriente* encontrarCuentaPorId(std::vector<CuentaCorriente>& cuentas, const std::string& id) {
    for (auto& cuenta : cuentas) {
        if (cuenta.getId() == id) {
            return &cuenta;
        }
    }
    return nullptr;
}

// Función para cambiar la contraseña de una cuenta
void cambiarContrasenaCuenta(CuentaCorriente& cuenta, const std::string& nuevaContrasena) {
    cuenta.setPassword(nuevaContrasena);
}

void mostrarCategorias() {
    std::cout << "************************************\n";
    std::cout << "* Por favor, elige una categoria:  *\n";
    std::cout << "* 1. Comestibles                   *\n";
    std::cout << "* 2. Electronicos                  *\n";
    std::cout << "* 3. Aseo                          *\n";
    std::cout << "************************************\n";
}

int main() {
    // Crear un vector para almacenar cuentas
    std::vector<CuentaCorriente> cuentas;


    cuentas.push_back(CuentaCorriente("12345", "Toby123"));
    cuentas.push_back(CuentaCorriente("67890", "Bella456"));
    cuentas.push_back(CuentaCorriente("11121", "Max789"));
    cuentas.push_back(CuentaCorriente("31415", "Lucy159"));
    cuentas.push_back(CuentaCorriente("92653", "Charlie265"));
    cuentas.push_back(CuentaCorriente("58979", "Daisy358"));
    cuentas.push_back(CuentaCorriente("32384", "Buddy979"));
    cuentas.push_back(CuentaCorriente("62643", "Molly323"));
    cuentas.push_back(CuentaCorriente("38327", "Rocky626"));
    cuentas.push_back(CuentaCorriente("95028", "Zoe383"));
    cuentas.push_back(CuentaCorriente("84197", "Cooper950"));
    cuentas.push_back(CuentaCorriente("16939", "Lola841"));
    cuentas.push_back(CuentaCorriente("93751", "Bear169"));
    cuentas.push_back(CuentaCorriente("58209", "Oliver937"));
    cuentas.push_back(CuentaCorriente("74944", "Chloe582"));
    cuentas.push_back(CuentaCorriente("59230", "Winston749"));
    cuentas.push_back(CuentaCorriente("78164", "Lily592"));
    cuentas.push_back(CuentaCorriente("06286", "Ziggy781"));
    cuentas.push_back(CuentaCorriente("20899", "Milo062"));
    cuentas.push_back(CuentaCorriente("86280", "Daisy208"));

    Punto1 punto1;

    punto1.agregarProducto(new Comestible("Pan", "Bimbo", 2500, 10, 50, "12-2024"));
    punto1.agregarProducto(new Comestible("Leche", "Alpina", 2800, 15, 30, "01-2025"));
    punto1.agregarProducto(new Comestible("Queso", "Alpina", 3200, 10, 40, "01-2025"));
    punto1.agregarProducto(new Comestible("Yogurt", "Danone", 3500, 15, 60, "02-2025"));
    punto1.agregarProducto(new Comestible("Cereal", "Kellogg's", 6300, 20, 30, "03-2025"));
    punto1.agregarProducto(new Comestible("Galletas", "Nabisco", 3000, 10, 50, "04-2025"));
    punto1.agregarProducto(new Comestible("Jugo", "Del Valle", 2500, 15, 40, "05-2025"));

    punto1.agregarProducto(new Electronico("Laptop", "Dell", 1890000, 20, 10, 24));
    punto1.agregarProducto(new Electronico("Camara", "Canon", 6350000, 25, 15, 12));
    punto1.agregarProducto(new Electronico("Impresora", "HP", 1100000, 20, 10, 24));
    punto1.agregarProducto(new Electronico("Monitor", "LG", 2000000, 25, 15, 12));
    punto1.agregarProducto(new Electronico("Audifonos", "Sony", 300000, 20, 10, 24));
    punto1.agregarProducto(new Electronico("Televisor", "Samsung", 46000000, 20, 10, 24));
    punto1.agregarProducto(new Electronico("Celular", "Apple", 4800000, 25, 15, 12));

    punto1.agregarProducto(new Aseo("Shampoo", "Head & Shoulders", 14000, 5, 100, "Plastico"));
    punto1.agregarProducto(new Aseo("Jabon liquido", "Dove", 8400, 5, 100, "Plastico"));
    punto1.agregarProducto(new Aseo("Pasta dental", "Colgate", 2500, 5, 100, "Plastico"));
    punto1.agregarProducto(new Aseo("Desodorante", "Rexona", 3500, 5, 100, "Metal"));
    punto1.agregarProducto(new Aseo("Cepillo dental", "Oral-B", 4000, 5, 100, "Plastico"));
    punto1.agregarProducto(new Aseo("Jabon", "Protex", 3300, 5, 100, "Glicerina"));



    int opcion = 0;
    do {
        std::cout << "************************************\n";
        std::cout << "* Por favor, elige una opcion:     *\n";
        std::cout << "* 1. Agregar productos             *\n";
        std::cout << "* 2. Modificar productos           *\n";
        std::cout << "* 3. Realizar compra               *\n";
        std::cout << "* 4. Cambiar contrasena            *\n";
        std::cout << "* 5. Salir                         *\n";
        std::cout << "************************************\n";
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
                std::cout << "Producto agregado exitosamente. Informacion del producto: " << punto1.getProducto(punto1.getNumProductos() - 1)->getDetalles() << "\n";
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
                for (int i = 0; i < punto1.getNumProductos(); i++) {
                    if (punto1.getProducto(i)->getNombre() == nombre) {
                        std::cout << "Informacion anterior del producto: " << punto1.getProducto(i)->getDetalles() << "\n";
                        punto1.modificarProducto(nombre, nuevoPrecio, nuevoDescuento);
                        std::cout << "Informacion actualizada del producto: " << punto1.getProducto(i)->getDetalles() << "\n";
                        break;
                    }
                }
                break;
            }
            case 3: {
                std::string id, password;
                std::cout << "Introduce tu numero de identificacion: ";
                std::cin >> id;
                std::cout << "Introduce tu contraseña: ";
                std::cin >> password;
                CuentaCorriente* cuenta = encontrarCuentaPorId(cuentas, id);
                if (cuenta && cuenta->validarCuenta(id, password)) {
                    mostrarCategorias();
                    int categoria;
                    std::cin >> categoria;
                    std::cout << "Estos son los productos disponibles en la categoria seleccionada:\n";
                    for (int i = 0; i < punto1.getNumProductos(); i++) {
                        if ((categoria == 1 && dynamic_cast<Comestible*>(punto1.getProducto(i))) ||
                            (categoria == 2 && dynamic_cast<Electronico*>(punto1.getProducto(i))) ||
                            (categoria == 3 && dynamic_cast<Aseo*>(punto1.getProducto(i)))) {
                                std::cout << punto1.getProducto(i)->getNombre() << ": " << punto1.getProducto(i)->getPrecio() << "\n";
                            }
                    }
                        std::string nombre;
                        int cantidad;
                        std::cout << "Introduce el nombre del producto a comprar: ";
                        std::cin >> nombre;
                        std::cout << "Introduce la cantidad del producto a comprar: ";
                        std::cin >> cantidad;
                        punto1.realizarCompra(nombre, cantidad);
                    } else {
                        std::cout << "No se pudo validar la cuenta. Por favor, intenta de nuevo.\n";
                    }
                    break;
                }
                case 4: {
                    std::string id, oldPassword, newPassword;
                    std::cout << "Introduce tu numero de identificacion: ";
                    std::cin >> id;
                    CuentaCorriente* cuenta = encontrarCuentaPorId(cuentas, id);
                    if (cuenta) {
                        std::cout << "Introduce tu contraseña actual: ";
                        std::cin >> oldPassword;
                        if (cuenta->validarCuenta(id, oldPassword)) {
                            std::cout << "Introduce tu nueva contraseña: ";
                            std::cin >> newPassword;
                            cambiarContrasenaCuenta(*cuenta, newPassword);
                            std::cout << "Contraseña cambiada exitosamente.\n";
                        } else {
                            std::cout << "Contraseña incorrecta.\n";
                        }
                    } else {
                        std::cout << "No se encontro una cuenta con ese número de identificacion.\n";
                    }
                    break;
                }
            }
        } while (opcion != 5);

        std::cout << "Gracias por usar mi programa. ¡Hasta luego!\n";
        return 0;
    }


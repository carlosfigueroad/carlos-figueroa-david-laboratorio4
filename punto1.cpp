#include "punto1.h"

Producto::Producto(std::string nombre, std::string marca, int precio, int descuento, int cantidad)
    : nombre(nombre), marca(marca), precio(precio), descuento(descuento), cantidad(cantidad) {}

std::string Producto::getNombre() { return nombre; }
std::string Producto::getMarca() { return marca; }
int Producto::getPrecio() { return precio; }
int Producto::getDescuento() { return descuento; }
int Producto::getCantidad() { return cantidad; }

Comestible::Comestible(std::string nombre, std::string marca, int precio, int descuento, int cantidad, std::string fechaVencimiento)
    : Producto(nombre, marca, precio, descuento, cantidad), fechaVencimiento(fechaVencimiento) {}

std::string Comestible::getDetalles() { return "Comestible: " + getNombre() + ", " + getMarca() + ", " + std::to_string(getPrecio()) + ", " + std::to_string(getDescuento()) + ", " + std::to_string(getCantidad()) + ", " + fechaVencimiento; }

Electronico::Electronico(std::string nombre, std::string marca, int precio, int descuento, int cantidad, int garantia)
    : Producto(nombre, marca, precio, descuento, cantidad), garantia(garantia) {}

std::string Electronico::getDetalles() { return "Electronico: " + getNombre() + ", " + getMarca() + ", " + std::to_string(getPrecio()) + ", " + std::to_string(getDescuento()) + ", " + std::to_string(getCantidad()) + ", " + std::to_string(garantia); }

Aseo::Aseo(std::string nombre, std::string marca, int precio, int descuento, int cantidad, std::string material)
    : Producto(nombre, marca, precio, descuento, cantidad), material(material) {}

std::string Aseo::getDetalles() { return "Aseo: " + getNombre() + ", " + getMarca() + ", " + std::to_string(getPrecio()) + ", " + std::to_string(getDescuento()) + ", " + std::to_string(getCantidad()) + ", " + material; }

Punto1::Punto1() {}
Punto1::~Punto1() {}

void Punto1::agregarProducto(Producto* producto) { inventario.push_back(producto); }
void Punto1::modificarProducto(std::string nombre, int nuevoPrecio, int nuevoDescuento) {
    for (Producto* producto : inventario) {
        if (producto->getNombre() == nombre) {
            producto->setPrecio(nuevoPrecio);
            producto->setDescuento(nuevoDescuento);
            break;
        }
    }
}
void Punto1::realizarCompra(std::string nombre, int cantidad) {
    for (Producto* producto : inventario) {
        if (producto->getNombre() == nombre) {
            if (producto->getCantidad() >= cantidad) {
                producto->setCantidad(producto->getCantidad() - cantidad);
                std::cout << "Compra realizada con éxito!\n";
            } else {
                std::cout << "No hay suficiente cantidad en el inventario.\n";
            }
            break;
        }
    }
}

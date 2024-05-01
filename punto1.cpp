#include "punto1.h"
#include<iostream>

Producto::Producto(std::string nombre, std::string marca, int precio, int descuento, int cantidad)
    : nombre(nombre), marca(marca), precio(precio), descuento(descuento), cantidad(cantidad) {}

std::string Producto::getNombre() { return nombre; }
std::string Producto::getMarca() { return marca; }
int Producto::getPrecio() { return precio; }
int Producto::getDescuento() { return descuento; }
int Producto::getCantidad() { return cantidad; }

void Producto::setPrecio(int precio) {
    this->precio = precio;
}

void Producto::setDescuento(int descuento) {
    this->descuento = descuento;
}

void Producto::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}

Comestible::Comestible(std::string nombre, std::string marca, int precio, int descuento, int cantidad, std::string fechaVencimiento)
    : Producto(nombre, marca, precio, descuento, cantidad), fechaVencimiento(fechaVencimiento) {}

std::string Comestible::getDetalles() { return "Comestible: " + getNombre() + ", " + getMarca() + ", " + std::to_string(getPrecio()) + ", " + std::to_string(getDescuento()) + ", " + std::to_string(getCantidad()) + ", " + fechaVencimiento; }

Electronico::Electronico(std::string nombre, std::string marca, int precio, int descuento, int cantidad, int garantia)
    : Producto(nombre, marca, precio, descuento, cantidad), garantia(garantia) {}

std::string Electronico::getDetalles() {
    return "Electronico: " + getNombre() + ", " + getMarca() + ", " + std::to_string(getPrecio()) + ", " + std::to_string(getDescuento()) + ", " + std::to_string(getCantidad()) + ", " + std::to_string(garantia);
}

Aseo::Aseo(std::string nombre, std::string marca, int precio, int descuento, int cantidad, std::string material)
    : Producto(nombre, marca, precio, descuento, cantidad), material(material) {}

std::string Aseo::getDetalles() { return "Aseo: " + getNombre() + ", " + getMarca() + ", " + std::to_string(getPrecio()) + ", " + std::to_string(getDescuento()) + ", " + std::to_string(getCantidad()) + ", " + material; }

Punto1::Punto1() : numProductos(0) {}
Punto1::~Punto1() {}

void Punto1::agregarProducto(Producto* producto) {
    if (numProductos < MAX_PRODUCTOS) {
        inventario[numProductos++] = producto;
    } else {
        std::cout << "Inventario lleno. No se puede agregar más productos.\n";
    }
}

void Punto1::modificarProducto(std::string nombre, int nuevoPrecio, int nuevoDescuento) {
    for (int i = 0; i < numProductos; i++) {
        if (inventario[i]->getNombre() == nombre) {
            std::cout << "Informacion anterior del producto: " << inventario[i]->getDetalles() << "\n";
            inventario[i]->setPrecio(nuevoPrecio);
            inventario[i]->setDescuento(nuevoDescuento);
            std::cout << "Informacion actualizada del producto: " << inventario[i]->getDetalles() << "\n";
            break;
        }
    }
}

void Punto1::realizarCompra(std::string nombre, int cantidad) {
    for (int i = 0; i < numProductos; i++) {
        if (inventario[i]->getNombre() == nombre) {
            if (inventario[i]->getCantidad() >= cantidad) {
                inventario[i]->setCantidad(inventario[i]->getCantidad() - cantidad);
                std::cout << "Compra realizada con éxito!\n";
                std::cout << "Factura: \n";
                std::cout << "Producto: " << nombre << "\n";
                std::cout << "Cantidad: " << cantidad << "\n";
                std::cout << "Precio: " << inventario[i]->getPrecio() << "\n";
                std::cout << "Descuento: " << inventario[i]->getDescuento() << "%\n";
                std::cout << "Total: " << (inventario[i]->getPrecio() * cantidad * (100 - inventario[i]->getDescuento())) / 100 << "\n";
            } else {
                std::cout << "No hay suficiente cantidad en el inventario.\n";
            }
            break;
        }
    }
}

Producto* Punto1::getProducto(int index) {
    if (index >= 0 && index < numProductos) {
        return inventario[index];
    }
    return nullptr;
}

int Punto1::getNumProductos() {
    return numProductos;
}

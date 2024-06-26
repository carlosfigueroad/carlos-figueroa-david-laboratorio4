#ifndef PUNTO1_H
#define PUNTO1_H

#include <string>

#define MAX_PRODUCTOS 100

class Producto {
public:
    Producto(std::string nombre, std::string marca, int precio, int descuento, int cantidad);
    virtual ~Producto() {}

    std::string getNombre();
    std::string getMarca();
    int getPrecio();
    int getDescuento();
    int getCantidad();
    void setPrecio(int precio);
    void setDescuento(int descuento);
    void setCantidad(int cantidad);

    virtual std::string getDetalles() = 0;

protected:
    std::string nombre;
    std::string marca;
    int precio;
    int descuento;
    int cantidad;
};

class Comestible : public Producto {
public:
    Comestible(std::string nombre, std::string marca, int precio, int descuento, int cantidad, std::string fechaVencimiento);
    std::string getDetalles() override;
private:
    std::string fechaVencimiento;
};

class Electronico : public Producto {
public:
    Electronico(std::string nombre, std::string marca, int precio, int descuento, int cantidad, int garantia);
    std::string getDetalles() override;

private:
    int garantia;
};

class Aseo : public Producto {
public:
    Aseo(std::string nombre, std::string marca, int precio, int descuento, int cantidad, std::string material);
    std::string getDetalles() override;

private:
    std::string material;
};

class Punto1 {
public:
    Punto1();
    ~Punto1();

    void agregarProducto(Producto* producto);
    void modificarProducto(std::string nombre, int nuevoPrecio, int nuevoDescuento);
    void realizarCompra(std::string nombre, int cantidad);
    Producto* getProducto(int index);
    int getNumProductos();

private:
    Producto* inventario[MAX_PRODUCTOS];
    int numProductos;
};

#endif // PUNTO1_H

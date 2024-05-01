#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H

#include <string>

class CuentaCorriente {
public:
    CuentaCorriente(std::string id, std::string password);
    std::string getId() const;
    std::string getPassword() const;
    void setPassword(std::string newPassword);
    bool validarCuenta(std::string id, std::string password);

private:
    std::string id;
    std::string password;
};

#endif // CUENTACORRIENTE_H

#include "CuentaCorriente.h"

CuentaCorriente::CuentaCorriente(std::string id, std::string password)
    : id(id), password(password.empty() ? "12345" : password) {}

std::string CuentaCorriente::getId() const {
    return id;
}

std::string CuentaCorriente::getPassword() const {
    return password;
}

void CuentaCorriente::setPassword(std::string newPassword) {
    password = newPassword;
}

bool CuentaCorriente::validarCuenta(std::string id, std::string password) {
    return this->id == id && this->password == password;
}

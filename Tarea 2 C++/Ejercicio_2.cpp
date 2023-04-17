#include <iostream>

/**
 * @brief Recibe un puntero a un vector de enteros y su longitud. Recorre el vector y modifica 
 *        los enteros negativos cambiándoles de signo.
 * 
 * @param ptr Puntero al vector de enteros
 * @param longitud Longitud del vector
 */
void modificarNegativos(int* ptr, int longitud) {
    // Si la longitud es 0, se termina la función recursiva
    if (longitud == 0) {
        return;
    }

    // Si el entero apuntado por el puntero es negativo, se cambia de signo
    if (*ptr < 0) {
        *ptr *= -1;
    }

    // Se llama a la función recursivamente con el puntero apuntando al siguiente entero del vector
    // y disminuyendo en 1 la longitud
    modificarNegativos(ptr + 1, longitud - 1);
}

int main() {
    // Se declara el vector de enteros y se inicializa
    int numeros[10] = {5, -7, 10, -3, 0, -2, 4, -8, 1, -6};

    // antes de modificar
    std::cout << "Vector antes de modificar: ";
    for (int i = 0; i < 10; i++) {
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;

    // Se llama a la función para modificar los enteros negativos del vector
    modificarNegativos(numeros, 10);

    // después de modificar
    std::cout << "Vector después de modificar: ";
    for (int i = 0; i < 10; i++) {
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
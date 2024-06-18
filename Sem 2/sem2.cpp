#include <iostream>
#include <string>
using namespace std;

// Clase base Material
class Material {
protected:
    string titulo;  // Título del material
    string autor;   // Autor o director del material
    int codigo;     // Código identificador del material
public:
    // Constructor de Material
    Material(string t, string a, int c) : titulo(t), autor(a), codigo(c) {}

    // Función virtual pura para mostrar detalles del material
    virtual void mostrarDetalles() const = 0;

    // Destructor virtual
    virtual ~Material() {}

    // Método para obtener el código del material
    int getCodigo() const {
        return codigo;
    }
};

// Clase derivada para Libros
class Libro : public Material {
public:
    // Constructor de Libro que inicializa la clase base Material
    Libro(string t, string a, int c) : Material(t, a, c) {}

    // Implementación de la función mostrarDetalles para libros
    void mostrarDetalles() const override {
        cout << "\tLibro - Título: " << titulo << endl;
        cout << "\tAutor: " << autor << endl;
        cout << "\tCódigo: " << getCodigo() << endl;
        cout << "______________________________" << endl;
    }
};

// Clase derivada para Revistas
class Revista : public Material {
public:
    // Constructor de Revista que inicializa la clase base Material
    Revista(string t, string a, int c) : Material(t, a, c) {}

    // Implementación de la función mostrarDetalles para revistas
    void mostrarDetalles() const override {
        cout << "\tRevista - Título: " << titulo << endl;
        cout << "\tAutor: " << autor << endl;
        cout << "\tCódigo: " << getCodigo() << endl;
        cout << "______________________________" << endl;
    }
};

// Clase derivada para DVDs
class DVD : public Material {
public:
    // Constructor de DVD que inicializa la clase base Material
    DVD(string t, string a, int c) : Material(t, a, c) {}

    // Implementación de la función mostrarDetalles para DVDs
    void mostrarDetalles() const override {
        cout << "\tDVD - Título: " << titulo << endl;
        cout << "\tAutor: " << autor << endl;
        cout << "\tCódigo: " << getCodigo() << endl;
        cout << "______________________________" << endl;
    }
};

// Plantilla de clase Coleccion<T>
template <typename T>
class Coleccion {
private:
    static const int MAX_ELEMENTOS = 100; // Tamaño máximo de la colección
    T* elementos[MAX_ELEMENTOS]; // Arreglo de punteros a elementos
    int numElementos; // Número actual de elementos en la colección

public:
    // Constructor
    Coleccion() : numElementos(0) {}

    // Destructor
    ~Coleccion() {
        // Liberar la memoria de todos los elementos almacenados
        for (int i = 0; i < numElementos; ++i) {
            delete elementos[i];
        }
    }

    // Método para agregar un nuevo material a la colección
    void agregarMaterial(T* material) {
        if (numElementos < MAX_ELEMENTOS) {
            elementos[numElementos++] = material; // Agregar el material al arreglo
        } else {
            cout << "Error: La colección está llena, no se puede agregar más materiales." << endl;
        }
    }

    // Método para eliminar un material por su código
    void eliminarMaterial(int codigo) {
        int indice = -1;
        // Buscar el material por su código
        for (int i = 0; i < numElementos; ++i) {
            if (elementos[i]->getCodigo() == codigo) {
                indice = i;
                break;
            }
        }

        if (indice != -1) {
            // Eliminar el material encontrado
            delete elementos[indice];
            // Desplazar los elementos restantes en el arreglo
            for (int i = indice; i < numElementos - 1; ++i) {
                elementos[i] = elementos[i + 1];
            }
            numElementos--; // Decrementar el contador de elementos
        } else {
            cout << "Error: Material no encontrado en la colección." << endl;
        }
    }

    // Método para buscar un material por su código y devolver un puntero al mismo
    T* buscarMaterial(int codigo) {
        for (int i = 0; i < numElementos; ++i) {
            if (elementos[i]->getCodigo() == codigo) {
                return elementos[i];
            }
        }
        return nullptr; // Retornar nullptr si el material no se encuentra
    }

    // Método para mostrar los detalles de todos los materiales en la colección
    void listarMateriales() const {
        for (int i = 0; i < numElementos; ++i) {
            elementos[i]->mostrarDetalles(); // Llamar a la función mostrarDetalles del material
        }
    }
};

// Función principal
int main() {
    // Ejemplo de uso de la plantilla Coleccion<T>
    Coleccion<Material> coleccion;

    // Agregar diferentes tipos de materiales a la colección
    coleccion.agregarMaterial(new Libro("Cien años de soledad", "Gabriel García Márquez", 1001));
    coleccion.agregarMaterial(new Revista("National Geographic", "Varios", 2001));
    coleccion.agregarMaterial(new DVD("El Señor de los Anillos", "Peter Jackson", 3001));

    cout << "Lista de materiales:" << endl;
    coleccion.listarMateriales(); // Mostrar los detalles de todos los materiales

    // Ejemplo de eliminación de un material por su código
    coleccion.eliminarMaterial(2001);

    cout << "Lista de materiales después de eliminar:" << endl;
    coleccion.listarMateriales(); // Mostrar la lista actualizada de materiales

    return 0;
}

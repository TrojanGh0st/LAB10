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
    // Constructor de la clase base Material
    Material(string t, string a, int c) : titulo(t), autor(a), codigo(c) {}

    // Función virtual pura para mostrar detalles del material
    virtual void mostrarDetalles() const = 0;

    // Función para obtener el código del material
    int obtenerCodigo() const {
        return codigo;
    }

    // Función para obtener el título del material
    string obtenerTitulo() const {
        return titulo;
    }

    // Función para obtener el autor del material
    string obtenerAutor() const {
        return autor;
    }

    // Destructor virtual para la clase base Material
    virtual ~Material() {}
};

// Clase derivada para Libros
class Libro : public Material {
public:
    // Constructor de la clase Libro que llama al constructor de Material
    Libro(string t, string a, int c) : Material(t, a, c) {}

    // Implementación de la función mostrarDetalles para libros
    void mostrarDetalles() const override {
        cout << "Libro - Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Codigo: " << codigo << endl;
        cout << "______________________________" << endl;
    }
};

// Clase derivada para Revistas
class Revista : public Material {
public:
    // Constructor de la clase Revista que llama al constructor de Material
    Revista(string t, string a, int c) : Material(t, a, c) {}

    // Implementación de la función mostrarDetalles para revistas
    void mostrarDetalles() const override {
        cout << "Revista - Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Codigo: " << codigo << endl;
        cout << "______________________________" << endl;
    }
};

// Clase derivada para DVDs
class DVD : public Material {
public:
    // Constructor de la clase DVD que llama al constructor de Material
    DVD(string t, string a, int c) : Material(t, a, c) {}

    // Implementación de la función mostrarDetalles para DVDs
    void mostrarDetalles() const override {
        cout << "DVD - Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Codigo: " << codigo << endl;
        cout << "______________________________" << endl;
    }
};

// Función para convertir una cadena a mayúsculas
string convertirMayusculas(const string& cadena) {
    string resultado;
    for (char c : cadena) {
        if (c >= 'a' && c <= 'z') {
            resultado += c - ('a' - 'A');
        } else {
            resultado += c;
        }
    }
    return resultado;
}

// Plantilla de clase para colecciones
template <typename T>
class Coleccion {
private:
    T* elementos[100];
    int cantidad;
public:
    // Constructor
    Coleccion() : cantidad(0) {}

    // Método para agregar un elemento
    bool agregar(T* elemento) {
        if (cantidad >= 100) {
            cout << "La coleccion esta llena." << endl;
            return false;
        }

        // Convertir el título a mayúsculas
        string tituloMayusculas = convertirMayusculas(elemento->obtenerTitulo());

        // Verificar unicidad del código y autor
        for (int i = 0; i < cantidad; ++i) {
            if (elementos[i]->obtenerCodigo() == elemento->obtenerCodigo() ||
                (convertirMayusculas(elementos[i]->obtenerTitulo()) == tituloMayusculas &&
                 elementos[i]->obtenerAutor() == elemento->obtenerAutor())) {
                cout << "Elemento con el mismo codigo o titulo y autor ya existe." << endl;
                return false;
            }
        }

        elementos[cantidad++] = elemento;
        return true;
    }

    // Método para eliminar un elemento por código
    void eliminar(int codigo) {
        for (int i = 0; i < cantidad; ++i) {
            if (elementos[i]->obtenerCodigo() == codigo) {
                delete elementos[i];
                for (int j = i; j < cantidad - 1; ++j) {
                    elementos[j] = elementos[j + 1];
                }
                --cantidad;
                cout << "Elemento eliminado." << endl;
                return;
            }
        }
        cout << "Elemento no encontrado." << endl;
    }

    // Método para buscar un elemento por código
    T* buscar(int codigo) const {
        for (int i = 0; i < cantidad; ++i) {
            if (elementos[i]->obtenerCodigo() == codigo) {
                return elementos[i];
            }
        }
        return nullptr;
    }

    // Método para listar todos los elementos
    void listar() const {
        for (int i = 0; i < cantidad; ++i) {
            elementos[i]->mostrarDetalles();
        }
    }

    // Destructor para liberar memoria
    ~Coleccion() {
        for (int i = 0; i < cantidad; ++i) {
            delete elementos[i];
        }
    }
};

// Función para obtener un entero con validación
int obtenerEntero(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail() || valor < 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Por favor, ingrese un numero entero positivo." << endl;
        } else {
            cin.ignore(10000, '\n');
            return valor;
        }
    }
}

// Función para obtener una cadena
string obtenerCadena(const string& mensaje) {
    string valor;
    cout << mensaje;
    getline(cin, valor);
    return valor;
}

// Función para mostrar el menú
void mostrarMenu() {
    cout << "1. Crear Libro" << endl;
    cout << "2. Crear Revista" << endl;
    cout << "3. Crear DVD" << endl;
    cout << "4. Mostrar materiales creados" << endl;
    cout << "5. Eliminar material" << endl;
    cout << "6. Buscar material" << endl;
    cout << "7. Salir" << endl;
    cout << "Seleccione una opción: ";
}

int main() {

    // Crear colecciones para diferentes tipos de materiales
    Coleccion<Material> coleccion;

    int opcion;
    do {
        mostrarMenu();
        opcion = obtenerEntero("");
       
        if (opcion >= 1 && opcion <= 3) {
            string titulo = obtenerCadena("Titulo: ");
            string autor = obtenerCadena("Autor: ");
            int codigo = obtenerEntero("Codigo: ");
           
            switch (opcion) {
                case 1: {
                    Libro* nuevoLibro = new Libro(titulo, autor, codigo);
                    if (!coleccion.agregar(nuevoLibro)) {
                        delete nuevoLibro;
                    }
                    break;
                }
                case 2: {
                    Revista* nuevaRevista = new Revista(titulo, autor, codigo);
                    if (!coleccion.agregar(nuevaRevista)) {
                        delete nuevaRevista;
                    }
                    break;
                }
                case 3: {
                    DVD* nuevoDVD = new DVD(titulo, autor, codigo);
                    if (!coleccion.agregar(nuevoDVD)) {
                        delete nuevoDVD;
                    }
                    break;
                }
            }
        } else if (opcion == 4) {
            coleccion.listar();
        } else if (opcion == 5) {
            int codigo = obtenerEntero("Ingrese el codigo del material a eliminar: ");
            coleccion.eliminar(codigo);
        } else if (opcion == 6) {
            int codigo = obtenerEntero("Ingrese el codigo del material a buscar: ");
            Material* encontrado = coleccion.buscar(codigo);
            if (encontrado) {
                encontrado->mostrarDetalles();
            } else {
                cout << "Material no encontrado." << endl;
            }
        } else if (opcion != 7) {
            cout << "Opción invalida." << endl;
        }
    } while (opcion != 7);

    cout << "Gracias por usar Diego's Library. ¡Adios!" << endl;
    return 0;
}

#include <iostream>

using namespace std;

// Definición de la clase Ruta para gestionar las rutas de entrega
template<typename T>
class Ruta {
private:
    T distancia;        // Distancia de la ruta
    T tiempoEstimado;   // Tiempo estimado de la ruta

public:
    // Constructor por defecto
    Ruta() : distancia(T()), tiempoEstimado(T()) {}

    // Constructor con parámetros
    Ruta(T dist, T tiempo) : distancia(dist), tiempoEstimado(tiempo) {}

    // Métodos para obtener la distancia y el tiempo estimado de la ruta
    T obtenerDistancia() const {
        return distancia;
    }

    T obtenerTiempoEstimado() const {
        return tiempoEstimado();
    }

    // Sobrecarga del operador de inserción para imprimir la ruta
    friend ostream& operator<<(ostream& os, const Ruta& ruta) {
        os << "Distancia: " << ruta.distancia << ", Tiempo Estimado: " << ruta.tiempoEstimado;
        return os;
    }
};

// Clase Recipiente para manejar un arreglo de cualquier tipo de dato
template<typename T, int MaxElementos>
class Recipiente {
private:
    T elementos[MaxElementos]; // Arreglo para almacenar los elementos
    int contador;              // Contador de elementos en el recipiente

public:
    // Constructor por defecto
    Recipiente() : contador(0) {}

    // Método para añadir un elemento al recipiente
    void agregarElemento(const T& elemento) {
        if (contador < MaxElementos) {
            elementos[contador] = elemento;
            contador++;
            cout << "Elemento agregado al recipiente." << endl;
        } else {
            cout << "No se puede agregar más elementos. Capacidad máxima alcanzada." << endl;
        }
    }

    // Método para obtener la cantidad de elementos en el recipiente
    int contarElementos() const {
        return contador;
    }

    // Método para imprimir todos los elementos en el recipiente
    void imprimirElementos() const {
        cout << "Listado de Elementos:" << endl;
        for (int i = 0; i < contador; ++i) {
            cout << "Elemento " << i + 1 << ": " << elementos[i] << endl;
        }
    }

    // Plantilla de método para ordenar los elementos
    template<typename Comparator>
    void ordenarElementos(Comparator comp) {
        for (int i = 0; i < contador - 1; ++i) {
            for (int j = 0; j < contador - i - 1; ++j) {
                if (comp(elementos[j], elementos[j + 1])) {
                    swap(elementos[j], elementos[j + 1]);
                }
            }
        }
        cout << "Elementos ordenados." << endl;
    }

    // Plantilla de método para imprimir elementos ordenados según un criterio
    template<typename Comparator>
    void imprimirElementosOrdenados(Comparator comp) {
        ordenarElementos(comp);
        imprimirElementos();
    }
};

// Funciones de comparación para ordenar rutas por distancia y por tiempo estimado
template<typename T>
bool compararPorDistancia(const Ruta<T>& a, const Ruta<T>& b) {
    return a.obtenerDistancia() > b.obtenerDistancia();
}

template<typename T>
bool compararPorTiempo(const Ruta<T>& a, const Ruta<T>& b) {
    return a.obtenerTiempoEstimado() > b.obtenerTiempoEstimado();
}

int main() {
    // Crear un recipiente para rutas de tipo double con capacidad para 5 rutas
    Recipiente<Ruta<double>, 5> recipienteRutasDouble;

    // Crear un recipiente para rutas de tipo int con capacidad para 3 rutas
    Recipiente<Ruta<int>, 3> recipienteRutasInt;

    // Agregar algunas rutas manualmente
    Ruta<double> ruta1(100.5, 2.5);
    Ruta<double> ruta2(75.2, 1.8);
    Ruta<int> ruta3(50, 3);
    Ruta<int> ruta4(30, 2);

    // Agregar las rutas al recipiente
    recipienteRutasDouble.agregarElemento(ruta1);
    recipienteRutasDouble.agregarElemento(ruta2);
    recipienteRutasInt.agregarElemento(ruta3);
    recipienteRutasInt.agregarElemento(ruta4);

    // Imprimir las rutas antes de ordenar
    cout << "Rutas antes de ordenar:" << endl;
    recipienteRutasDouble.imprimirElementos();
    recipienteRutasInt.imprimirElementos();

    // Ordenar y imprimir las rutas por distancia
    cout << "\nRutas ordenadas por distancia:" << endl;
    recipienteRutasDouble.imprimirElementosOrdenados(compararPorDistancia<Ruta<double>>);
    recipienteRutasInt.imprimirElementosOrdenados(compararPorDistancia<Ruta<int>>);

    // Ordenar y imprimir las rutas por tiempo estimado
    cout << "\nRutas ordenadas por tiempo estimado:" << endl;
    recipienteRutasDouble.imprimirElementosOrdenados(compararPorTiempo<Ruta<double>>);
    recipienteRutasInt.imprimirElementosOrdenados(compararPorTiempo<Ruta<int>>);

    return 0;
}

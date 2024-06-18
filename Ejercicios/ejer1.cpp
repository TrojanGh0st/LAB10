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
        return tiempoEstimado;
    }

    // Sobrecarga del operador de inserción para imprimir la ruta
    friend ostream& operator<<(ostream& os, const Ruta& ruta) {
        os << "Distancia: " << ruta.distancia << ", Tiempo Estimado: " << ruta.tiempoEstimado;
        return os;
    }
};

// Clase principal que representa el sistema de gestión de rutas de entrega
template<typename T, int MaxRutas>
class SistemaGestionRutas {
private:
    Ruta<T> rutas[MaxRutas]; // Arreglo para almacenar las rutas
    int contador;            // Contador de rutas en el sistema

public:
    // Constructor por defecto
    SistemaGestionRutas() : contador(0) {
        // Inicializar cada elemento del arreglo de rutas
        for (int i = 0; i < MaxRutas; ++i) {
            rutas[i] = Ruta<T>();  // Llama al constructor por defecto de Ruta<T>
        }
    }

    // Método para añadir una ruta al sistema
    void agregarRuta(const Ruta<T>& ruta) {
        if (contador < MaxRutas) {
            rutas[contador] = ruta;
            contador++;
            cout << "Ruta agregada al sistema." << endl;
        } else {
            cout << "No se puede agregar más rutas. Capacidad máxima alcanzada." << endl;
        }
    }

    // Método para eliminar una ruta del sistema por su índice
    void eliminarRuta(int indice) {
        if (indice < 0 || indice >= contador) {
            cout << "Índice de ruta inválido." << endl;
            return;
        }
        for (int i = indice; i < contador - 1; ++i) {
            rutas[i] = rutas[i + 1];
        }
        contador--;
        cout << "Ruta eliminada del sistema." << endl;
    }

    // Método para obtener la cantidad de rutas en el sistema
    int contarRutas() const {
        return contador;
    }

    // Método para imprimir todas las rutas en el sistema
    void imprimirRutas() const {
        cout << "Listado de Rutas:" << endl;
        for (int i = 0; i < contador; ++i) {
            cout << "Ruta " << i + 1 << ": " << rutas[i] << endl;
        }
    }

    // Método para generar un informe del sistema (ejemplo de implementación)
    void generarInforme() const {
        cout << "Informe del Sistema de Gestión de Rutas:" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Total de Rutas Registradas: " << contador << endl;
        cout << "Detalles de las Rutas:" << endl;
        for (int i = 0; i < contador; ++i) {
            cout << "Ruta " << i + 1 << ": Distancia - " << rutas[i].obtenerDistancia()
                 << ", Tiempo Estimado - " << rutas[i].obtenerTiempoEstimado() << endl;
        }
    }

    // Plantilla de función para ordenar el arreglo de rutas
    template<typename Comparator>
    void ordenarRutas(Comparator comp) {
        for (int i = 0; i < contador - 1; ++i) {
            for (int j = 0; j < contador - i - 1; ++j) {
                if (comp(rutas[j], rutas[j + 1])) {
                    swap(rutas[j], rutas[j + 1]);
                }
            }
        }
        cout << "Rutas ordenadas." << endl;
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
    // sistema de gestión de rutas con tipo double y capacidad para 5 rutas
    SistemaGestionRutas<double, 5> sistemaRutasDouble;

    // sistema de gestión de rutas con tipo int y capacidad para 3 rutas
    SistemaGestionRutas<int, 3> sistemaRutasInt;

    // Agregar algunas rutas manualmente
    Ruta<double> ruta1(100.5, 2.5);
    Ruta<double> ruta2(75.2, 1.8);
    Ruta<int> ruta3(50, 3);
    Ruta<int> ruta4(30, 2);

    // Agregar las rutas al sistema
    sistemaRutasDouble.agregarRuta(ruta1);
    sistemaRutasDouble.agregarRuta(ruta2);
    sistemaRutasInt.agregarRuta(ruta3);
    sistemaRutasInt.agregarRuta(ruta4);

    // Imprimir las rutas almacenadas en el sistema
    cout << "Rutas antes de ordenar:" << endl;
    sistemaRutasDouble.imprimirRutas();
    sistemaRutasInt.imprimirRutas();

    // Ordenar las rutas por distancia
    sistemaRutasDouble.ordenarRutas(compararPorDistancia<double>);
    sistemaRutasInt.ordenarRutas(compararPorDistancia<int>);

    // Imprimir las rutas ordenadas
    cout << "Rutas ordenadas por distancia:" << endl;
    sistemaRutasDouble.imprimirRutas();
    sistemaRutasInt.imprimirRutas();

    // Ordenar las rutas por tiempo estimado
    sistemaRutasDouble.ordenarRutas(compararPorTiempo<double>);
    sistemaRutasInt.ordenarRutas(compararPorTiempo<int>);

    // Imprimir las rutas ordenadas
    cout << "Rutas ordenadas por tiempo estimado:" << endl;
    sistemaRutasDouble.imprimirRutas();
    sistemaRutasInt.imprimirRutas();

    // Generar informe del sistema
    sistemaRutasDouble.generarInforme();
    sistemaRutasInt.generarInforme();

    return 0;
}

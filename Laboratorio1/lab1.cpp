///
/// lab1.cpp
///

#include <cstdio>
#include <cmath>
#include <utility> // Necesario para std::swap en sort_AI

// vector de origen en 4 dimensiones
double o[] = { 0.0, 0.0, 0.0, 0.0 };

double a[] = { 1.0, 1.0, 1.0, 1.0 };
double b[] = { 2.2, 0.0, 1.1, 3.3 };

double x[] = { 1.0, 2.1, 3.0, 5.1, 2.0, 0.0, 6.2, 7.3 };

const int No = sizeof(o) / sizeof(o[0]);
const int Nx = sizeof(x) / sizeof(x[0]);

// La distancia euclidiana entre dos puntos, en un espacio de 'n' dimensiones,
// es la raiz cuadrada de la suma de los cuadrados de las 'n' diferencias
// de las coordenadas correspondientes de esos puntos
// https://es.wikipedia.org/wiki/Distancia_euclidiana

// 'distance': computa la distancia euclidiana de dos vectores de 'n' dimensiones
double distance(int n, double v[], double w[]) {
    double suma_cuadrados = 0.0;
    for (int i = 0; i < n; ++i) {
        double diff = v[i] - w[i];
        suma_cuadrados += diff * diff;
    }
    return std::sqrt(suma_cuadrados);
}

// 'vec_sum': calcula la suma de dos vectores de 'n' dimensiones
void vec_sum(int n, double v[], double w[], double r[]) {
    for (int i = 0; i < n; ++i) {
        r[i] = v[i] + w[i];
    }
}

// 'show' muestra un vector 'v', de 'n' dimensiones, en la pantalla
// ESTA FUNCION NO SE TOCA (Original del profesor)
void show(int n, double v[], const char *sep) {
    fprintf(stdout, "[ ");
    for (int i = 0; i < n; ++i) {
        fprintf(stdout, "%f%s", v[i], sep);
    }
    fprintf(stdout, " ]\n");
}

// 'min' retorna el índice del menor valor en un subrango de un arreglo
int min(int i, int n, double a[]) {
    int indice_min = i;
    for (int j = i + 1; j < n; ++j) {
        if (a[j] < a[indice_min]) {
            indice_min = j;
        }
    }
    return indice_min;
}

// 'copy_array': copia un arreglo a otro
void copy_array(int n, double a[], double r[]) {
    for (int i = 0; i < n; ++i) {
        r[i] = a[i];
    }
}

// 'sort': ordena un arreglo 'a', de tamaño 'n' dejando el resultado en otro arreglo
void sort(const int n, double a[], double r[]) {
    // Copiamos los datos originales a 'r'
    copy_array(n, a, r);

    // Algoritmo de Selection Sort según instrucciones
    for (int l = 0; l < n - 1; ++l) {
        // 1. Conseguir el índice del valor mínimo en el rango [l, n)
        int k = min(l, n, r);

        // 2. Intercambiar r[l] con r[k]
        double temp = r[l];
        r[l] = r[k];
        r[k] = temp;
    }
}

// Lo mismo que `sort`, solo que usando inteligencia artificial.
void sort_AI(const int n, double a[], double r[]) {
    // Inteligencia Artificial: Gemini
    // Insight: Para producción, usar std::sort es más eficiente O(n log n).
    // Aquí usamos Selection Sort optimizado con std::swap para claridad.
    
    copy_array(n, a, r);

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (r[j] < r[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(r[i], r[min_idx]);
        }
    }
}

// Pruebas
void test_distance() {
    fprintf(stdout, "test_distance\n");

    double ao = distance(No, a, o);
    fprintf(stdout, "a <-> o ==> %f\n", ao);

    double bo = distance(No, b, o);
    fprintf(stdout, "b <-> o ==> %f\n", bo);

    double ab = distance(No, a, b);
    fprintf(stdout, "a <-> b ==> %f\n", ab);

    double ba = distance(No, b, a);
    fprintf(stdout, "b <-> a ==> %f\n", ba);
}

void test_vec_sum() {
    fprintf(stdout, "test_vec_sum\n");
    double r[No];

    vec_sum(No, a, b, r); show(No, r, " ");
    vec_sum(No, a, o, r); show(No, r, " ");
    vec_sum(No, o, b, r); show(No, r, " ");
    vec_sum(No, b, a, r); show(No, r, " ");
}

void test_sort() {
    fprintf(stdout, "test_sort\n");
    // aqui reservamos memoria para almacenar el resultado de ordenar a x
    double r[Nx];
    sort(Nx, x, r);
    show(Nx, x, " ");
    show(Nx, r, " ");
}

int main(int argc, const char *argv[]) {
    test_distance();
    test_vec_sum();
    test_sort();
    return 0;
}

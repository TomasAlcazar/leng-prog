#include <stdio.h> <stdlib.h>

#define C_MIN   0 // #define no ocupan memoria como las variables y si no se usan a la larga se hace ilegible el código
#define C_MAX   300
#define STEPS   20

void celcius_to_fahrenheit(void) {
    int celsius;

    printf("Celsius to Fahrenheit conversion table:\n");
    printf("Celsius\tFahrenheit\n");
    printf("---------------------\n");

    for (celsius = C_MIN; celsius <= C_MAX; celsius += STEPS) {
        float fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
        printf("%d\t%.1f\n", celsius, fahrenheit);
    }
}

void odd_or_even(void) {
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    if (num % 2 == 0) {
        printf("%d is even.\n", num);
    } else {
        printf("%d is odd.\n", num);
    }
}


void show_file_lines(const char *path) {
    FILE *fp = fopen(path, "r");
    if (!fp) return;
    
    char line[4096]; // Los arrays no usan variables para definir su tamaño sino ocuparian mucha memoria

    while (fgets(line, sizeof line, fp)) printf("%s", line); // while no puede recibir una asignación porque no es una expresión
    fclose(fp);
}

void count_file_whitespaces(const char *path) {
    FILE *fp = fopen(path, "r");
    if (!fp) return;
    
    unsigned long long newlines = 0, spaces = 0, tabs = 0;
    int c;

    while ((c = fgetc(fp)) != EOF) {
        if (c == ' ') spaces++;
        else if (c == '\n') newlines++;
        else if (c == '\t') tabs++;
    }
    fclose(fp);
    printf("newlines: %llu\nspaces: %llu\ntabs: %llu\n", newlines, spaces, tabs);
}

void print_evens(void) {
    long long n;
    if (scanf("%lld", &n) != 1 || n <= 0) return;

    int *a = malloc((size_t)n * sizeof *a);
    if (!a) return;

    for (long long i = 0; i < n; ++i) a[i] = (int)(2 * i);
    for (long long i = 0; i < n; ++i) printf("%d%s", a[i], (i + 1 == n) ? "\n" : " ");

    free(a);
}

int binary_search(const int *a, int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == key) {
            printf("Found %d at index %d\n", key, mid);
            return mid;
        } else if (a[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("%d not found in the array\n", key);
    return -1;
}

int main(void) {
    //celcius_to_fahrenheit();
    //odd_or_even();
    //show_file_lines("C:\\Users\\zartf\\projects\\leng-prog\\Practice\\guide-1\\guide-1.md");
    //count_file_whitespaces("C:\\Users\\zartf\\projects\\leng-prog\\Practice\\guide-1\\guide-1.md");
    //print_evens();
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof arr / sizeof *arr;
    binary_search(arr, size, 7);
    return 0;
}


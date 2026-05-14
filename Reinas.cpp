#include <stdio.h>
#include <graphics.h>

// Declaración de funciones
void reinas(int[], int[], int[], int[], int, int);
void tablero(int, int[]);
void dibujaReina(int, int);
void guardaArch(const char*, int, int[]);

// Declaración de variables globales
int s = 0; 
int c = 0;
int aux = 0;
int i;
int x, y, z;
int centro_x;
int centro_y;  
int x_inicial; 
int y_inicial; 
int clibre[8], diagarri[16], diagbaj[15], columna[8], fila = 0, col, m;

int main() {
    // Inicializar ventana gráfica
    int gd = DETECT, gm;
initgraph(&gd, &gm, (char *)"");
    if (graphresult() != 0) { // Verifica si los gráficos se inicializaron correctamente
        printf("Error al inicializar gráficos: %s\n", grapherrormsg(graphresult()));
        return 1;
    }

    tablero(-1, columna); // Dibujar el tablero inicial
    getch();

    // Llenar arreglos en ceros
    for (m = 0; m < 8; m++) { // Columnas
        clibre[m] = 0;
    }
    for (m = 0; m < 16; m++) { // Diagonal ascendente
        diagarri[m] = 0;
    }
    for (m = 0; m < 15; m++) { // Diagonal descendente
        diagbaj[m] = 0;
    }

    // Llamar al algoritmo de las reinas
    reinas(clibre, diagarri, diagbaj, columna, fila, col);
    getch();
    closegraph();

    return 0;
}

// Algoritmo de las reinas
void reinas(int clibre[], int diagarri[], int diagbaj[], int columna[], int fila, int col) {
    fila = fila + 1;

    for (col = 1; col < 9; col++) {
        // Evaluar para la colocación de reinas, verifica si está vacía o ocupada
        if (clibre[col - 1] == 0 && diagarri[fila + col - 2] == 0 && diagbaj[fila + 7 - col] == 0) {
            // Ocupar lugares para reinas
            columna[fila - 1] = col;
            clibre[col - 1] = 1;
            diagarri[fila + col - 2] = 1;
            diagbaj[fila + 7 - col] = 1;

            // Cuando haya solución, imprime el tablero y guarda en archivo
            if (fila == 8) {
                for (aux = 0; aux < 8; aux++) {
                    printf("fila: %d columna: %d\n", aux + 1, columna[aux]);
                    tablero(aux, columna); // Dibujar el tablero con las reinas
                    dibujaReina(aux, columna[aux]); // Dibuja una reina en la posición
                }
                guardaArch("soluciones.txt", 8, columna); // Guardar en archivo
                getch();
                cleardevice();
                tablero(-1, columna); // Dibujar el tablero inicial
                printf("\n");
            } else { // Buscar otra solución (recursividad)
                reinas(clibre, diagarri, diagbaj, columna, fila, col);
            }

            // Aplicación de backtracking para buscar otras soluciones
            clibre[col - 1] = 0;
            diagarri[fila + col - 2] = 0;
            diagbaj[fila + 7 - col] = 0;
        }
    }
    fila = fila - 1;
}

// Dibuja el tablero
void tablero(int i, int columna[8]) {
    char s[33];
    setbkcolor(BLACK);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    settextstyle(3, 0, 4);
    outtextxy(130, 50, (char*)"REINAS QUE NO SE ATACAN");

    rectangle(700, 50, 980, 200);
    settextstyle(8, 0, 1);
    outtextxy(710, 75, (char*)"Castañeda Noguerón Gael");
    outtextxy(710, 500, (char*)"Presiona enter para");
    outtextxy(710, 517, (char*)"ver la siguiente solucion");

    if (i < 0) {
        for (x = 0; x < 8; x++) {
            itoa(x + 1, s, 10);
            outtextxy(50, 150 + 70 * x, s);
            outtextxy(70 + 70 * x, 120, s);
        }
        for (x = 0; x < 8; x++) {
            for (y = 0; y < 8; y++) {
                if ((x + y) % 2 == 0) {
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(70 + 70 * x, 150 + 70 * y, 140 + 70 * x, 220 + 70 * y);
                } else {
                    setfillstyle(SOLID_FILL, LIGHTGRAY);
                    bar(70 + 70 * x, 150 + 70 * y, 140 + 70 * x, 220 + 70 * y);
                }
            }
        }
    }
}

// Dibuja una imagen para representar la reina
void dibujaReina(int fila, int columna) {
    x_inicial = 70 + columna * 70 - 70; // Coordenada x inicial
    y_inicial = 150 + 70 * fila;       // Coordenada y inicial

    // Cargar la imagen
    readimagefile("C://Users//gaelc//Downloads//reina.jpg", x_inicial, y_inicial, x_inicial + 70, y_inicial + 70);

    // Verificar si se cargó correctamente
    if (graphresult() != 0) {
        printf("No se pudo cargar la imagen de la reina. Verifica la ruta y el archivo.\n");
    }
}

// Guarda la solución en un archivo .txt
void guardaArch(const char* nomArch, int n, int columna[]) {
    FILE* archivo = fopen(nomArch, "a"); // Abre el archivo en modo de agregar
    if (archivo != NULL) {
        fprintf(archivo, "Solucion: %d\n", ++c);
        for (i = 0; i < n; i++) {
            fprintf(archivo, "fila: %d columna: %d\n", i + 1, columna[i]);
        }
        fprintf(archivo, "\n");
        fclose(archivo);
    } else {
        fprintf(stderr, "Error al abrir el archivo.\n");
    }
}


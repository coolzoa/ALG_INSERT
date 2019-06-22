#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int comparar(int a, int b);
int numeroAleatorio(int minimo, int maximo);
int* llenarLista(int elementos);
void printlista(int* lista, int elementos);
void insercion(int* lista, int elementos);
void inserciontiempo(int* lista, int elementos);
void alreves(int* lista, int elementos);
void btnInAl(GtkWidget* w, gpointer datos);
void btnInOr(GtkWidget* w, gpointer datos);
void btnInRe(GtkWidget* w, gpointer datos);




int main (int argc, char *argv[])
{
  srand(time(NULL));
  GtkWidget* ventana;
  GtkWidget* boton_insercion_aleatorio;
  GtkWidget* boton_insercion_ordenado;
  GtkWidget* boton_insercion_reves;
  GtkWidget* grid;
  GtkWidget* lblTexto;
  GtkWidget* entrada;
  GtkWidget* lblTextoS;
  GtkWidget* lblTiempo;


  gtk_init(&argc, &argv);

  ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  boton_insercion_aleatorio = gtk_button_new_with_label("Insercion con vector aleatorio");
  boton_insercion_ordenado = gtk_button_new_with_label("Insercion con vector ordenado");
  boton_insercion_reves = gtk_button_new_with_label(("Insercion con vector ordenado al reves"));

  grid = gtk_grid_new();

  lblTexto = gtk_label_new("Ingrese la cantidad de elementos para el algoritmo");
  lblTextoS = gtk_label_new("tiempo:");
  lblTiempo = gtk_label_new("");

  entrada = gtk_entry_new();

  gtk_container_add(GTK_CONTAINER(ventana),grid);
  gtk_grid_attach(GTK_GRID(grid),lblTexto,0,0,1,1);
  gtk_grid_attach(GTK_GRID(grid),entrada,1,0,1,1);
  gtk_grid_attach(GTK_GRID(grid),boton_insercion_aleatorio,0,1,1,1);
  gtk_grid_attach(GTK_GRID(grid),boton_insercion_ordenado, 1,1,1,1);
  gtk_grid_attach(GTK_GRID(grid),boton_insercion_reves, 2,1,1,1);
  gtk_grid_attach(GTK_GRID(grid),lblTextoS,0,3,1,1);
  gtk_grid_attach(GTK_GRID(grid),lblTiempo,1,3,1,1);


  g_signal_connect(G_OBJECT(boton_insercion_aleatorio),"clicked",G_CALLBACK(btnInAl),entrada);
  g_signal_connect(G_OBJECT(boton_insercion_ordenado),"clicked",G_CALLBACK(btnInOr),entrada);
  g_signal_connect(G_OBJECT(boton_insercion_reves),"clicked",G_CALLBACK(btnInRe),entrada);
  g_signal_connect(ventana, "destroy",G_CALLBACK(gtk_main_quit), NULL);
gtk_widget_show_all(ventana);
    gtk_main();

  return 0;
}

int comparar(int a, int b){
    return (a > b) - (a < b);
}

int numeroAleatorio(int minimo, int maximo){
    return (rand() % (maximo + 1 - minimo)) + minimo;
}


int* llenarLista(int elementos){
    int* lista= malloc(elementos*4);
    int i;
    for(i = 0; i < elementos; i++){
        lista[i] = numeroAleatorio(1,elementos);
    }
    return lista;
}

void printlista(int* lista, int elementos){
    int j;
    for (j = 0; j < elementos; j++){
        printf("%d",lista[j]);
        printf(",");
    }
}

void insercion(int* lista, int elementos){
    int i,j,k;
    for (j = 1; j < elementos; j++){
            k = lista[j];
            i = j - 1;
        while(i >= 0 && lista[i] > k){
            lista[i+1] = lista[i];
            i = i - 1;
        }
        lista[i + 1] = k;
    }
}

void inserciontiempo(int* lista, int elementos){
    clock_t tiempo;
    tiempo = clock();
    int i,j,k;
    for (j = 1; j < elementos; j++){
            k = lista[j];
            i = j - 1;
        while(i >= 0 && lista[i] > k){
            lista[i+1] = lista[i];
            i = i - 1;
        }
        lista[i + 1] = k;
    }
    tiempo = clock() - tiempo;
    double total = ((double)tiempo) / CLOCKS_PER_SEC;
    printf("Tiempo total %f\n",total);
}



void alreves(int* lista, int maximo){
    int temp;
    int inicio = 0;
    maximo--;
    while (inicio < maximo){
        temp = lista[inicio];
        lista[inicio] = lista[maximo];
        lista[maximo] = temp;
        inicio++;
        maximo--;
    }
}

void btnInAl(GtkWidget* w, gpointer datos){
    gchar* e;
    e = gtk_entry_get_text(GTK_ENTRY(datos));
    char* ch = (char*)(e);
    int elementos = atoi(ch);
    if (elementos >= 2){
        int * lista = llenarLista(elementos);
        inserciontiempo(lista,elementos);
        free(lista);
    }
}

void btnInOr(GtkWidget* w, gpointer datos){
    gchar* e;
    e = gtk_entry_get_text(GTK_ENTRY(datos));
    char* ch = (char*)(e);
    int elementos = atoi(ch);
    if (elementos >= 2){
        int* lista = llenarLista(elementos);
        insercion(lista,elementos);
        inserciontiempo(lista,elementos);
        free(lista);
    }

}

void btnInRe(GtkWidget* w, gpointer datos){
    gchar* e;
    e = gtk_entry_get_text(GTK_ENTRY(datos));
    char* ch = (char*)(e);
    int numero = atoi(ch);
    if (numero >= 2){
        int* lista = llenarLista(numero);
        insercion(lista,numero);
        alreves(lista,numero);
        inserciontiempo(lista,numero);
        free(lista);
    }

}




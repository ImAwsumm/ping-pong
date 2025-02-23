#include <gtk/gtk.h>

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *label;

    // Create a new window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Ping Pong");
    gtk_window_set_default_size(GTK_WINDOW(window), 1920, 1080);
    label = gtk_label_new("Ping Pong");

    // Add the text label to the window
    gtk_container_add(GTK_CONTAINER(window), label);
    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;
    app = gtk_application_new("org.example.PingPong", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);
    return status;
}

//
// Created by wdarr on 8/30/2020.
//

#include <gtk/gtk.h>

GtkWidget *g_lbl_hello;
GtkWidget *g_lbl_count;

int main(int argc, char *argv[])
{
    GtkBuilder *builder;
    GtkWidget *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("glade/window_main.glade");

    gtk_builder_connect_signals(builder, NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));

    g_lbl_hello = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_hello"));
    g_lbl_count = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_count"));

    g_object_unref(builder);

    gtk_window_maximize(GTK_WINDOW(window));

    gtk_widget_show(window);

    gtk_main();

    return 0;
}

// Call on button click
void on_btn_count_clicked()
{
    static unsigned int count =0;
    char str_count[30] = {0};

    gtk_label_set_text(GTK_LABEL(g_lbl_hello), "Hello, world!");
    count++;
    sprintf(str_count, "%d", count);

    gtk_label_set_text(GTK_LABEL(g_lbl_count), str_count);
}

// Called on window close
void on_window_main_destroy()
{
    gtk_main_quit();
}

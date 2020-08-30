//
// Created by wdarr on 8/30/2020.
//

#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    GtkBuilder *builder;
    GtkWidget *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("glade/window_main.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));

    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    gtk_window_maximize(GTK_WINDOW(window));

    gtk_widget_show(window);

    gtk_main();

    return 0;
}

// Called on window close
void on_window_main_destroy()
{
    gtk_main_quit();
}

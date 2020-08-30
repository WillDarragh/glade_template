//
// Created by wdarr on 8/30/2020.
//

#include <gtk/gtk.h>

// Custom struct to hold our two buttons
typedef struct {
	GtkWidget *w_lbl_hello;
	GtkWidget *w_lbl_count;
} w_labels;

int main(int argc, char *argv[])
{
    GtkBuilder *builder;
    GtkWidget *window;

    // Instantiate our struct
    w_labels *labels = g_slice_new(w_labels);

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("glade/window_main.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));

    // Get pointers to label widgets
    labels->w_lbl_hello = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_hello"));
    labels->w_lbl_count = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_count"));

    gtk_builder_connect_signals(builder, labels);

    g_object_unref(builder);

    gtk_window_maximize(GTK_WINDOW(window));

    gtk_widget_show(window);

    gtk_main();

    g_slice_free(w_labels, labels);

    return 0;
}

// Call on button click wihout using globals
void on_btn_count_clicked(GtkButton *button, w_labels *labels)
{
    static gint count = 0;

    // glib data types
    GDateTime *time;
    gchar *time_str;
    gchar *count_str;

    time = g_date_time_new_now_local();
    time_str = g_date_time_format(time, "%H:%M:%S");

    count++;
    count_str = g_strdup_printf("%d", count);

    gtk_label_set_text(GTK_LABEL(labels->w_lbl_hello), time_str);
    gtk_label_set_text(GTK_LABEL(labels->w_lbl_count), count_str);

    // glib free up space
    g_free(time_str);
    g_free(count_str);
    g_date_time_unref(time);
}

// Called on window close
void on_window_main_destroy()
{
    gtk_main_quit();
}

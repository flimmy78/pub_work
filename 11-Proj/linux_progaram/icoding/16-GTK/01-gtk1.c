/*******************************************************************
 *   > File Name: 01-gtk1.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 26 May 2017 01:39:58 PM CST
 ******************************************************************/

#include <stdio.h>
#include <gtk/gtk.h>

int main(int argc, char* argv[])
{
    CtkWidget *window;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_show(window);
    gtk_main();

    return 0;
}

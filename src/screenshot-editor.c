#include <stdlib.h>
#include <goocanvas.h>
#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <string.h>
#include <stdio.h>


#include "../config.h"

static gboolean on_rect_button_press (GooCanvasItem  *view,
                                      GooCanvasItem  *target,
                                      GdkEventButton *event,
                                      gpointer        data);

static gboolean on_delete_event      (GtkWidget      *window,
                                      GdkEvent       *event,
                                      gpointer        unused_data);


int
main (int argc, char *argv[])
{
  GtkWidget *window, *scrolled_win, *canvas;
  GooCanvasItem *root, *rect_item, *text_item, *image_item;

	GdkPixbuf *pb;

  /* Initialize GTK+. */
  gtk_set_locale ();
  gtk_init (&argc, &argv);
	


	pb=gdk_pixbuf_new_from_file("test-screenshot.png", NULL);


	if(!pb) {
		printf("error: gdk_pixbuf_new_from_file");
		exit(1);
	}

  /* Create the window and widgets. */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size (GTK_WINDOW (window), 740, 700);
  gtk_widget_show (window);
  g_signal_connect (window, "delete_event", (GtkSignalFunc) on_delete_event,
                    NULL);

  scrolled_win = gtk_scrolled_window_new (NULL, NULL);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolled_win),
                                       GTK_SHADOW_IN);
  gtk_widget_show (scrolled_win);
  gtk_container_add (GTK_CONTAINER (window), scrolled_win);

  canvas = goo_canvas_new ();
  gtk_widget_set_size_request (canvas, 640, 600);
  goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 1000, 1000);
  gtk_widget_show (canvas);
  gtk_container_add (GTK_CONTAINER (scrolled_win), canvas);

  root = goo_canvas_get_root_item (GOO_CANVAS (canvas));

	image_item = goo_canvas_image_new (root, pb, 0, 0, NULL);

  /* Add a few simple items. */
  rect_item = goo_canvas_rect_new (root, 20, 20, 200, 200,
                                   "line-width", 5.0,
                                   "radius-x", 10.0,
                                   "radius-y", 5.0,
                                   "stroke-color", "red",
                                   NULL);
                                   
  GooCanvasItem *polyline0 = goo_canvas_polyline_new_line (root,
                                                        100.0, 100.0,
                                                        500.0, 500.0,
                                                        "stroke-color", "red",
                                                        "line-width", 5.0,
                                                        "start-arrow", TRUE,
                                                        NULL);
                            

  //text_item = goo_canvas_text_new (root, PACKAGE_STRING, 300, 300, -1,
                                   //GTK_ANCHOR_CENTER,
                                   //"font", "Sans 24px",
                                   //NULL);
  //goo_canvas_item_rotate (text_item, 45, 300, 300);

  /* Connect a signal handler for the rectangle item. */
  g_signal_connect (rect_item, "button_press_event",
                    (GtkSignalFunc) on_rect_button_press, NULL);

  /* Pass control to the GTK+ main event loop. */
  gtk_main ();

  return 0;
}
 

/* This handles button presses in item views. We simply output a message to
   the console. */
static gboolean
on_rect_button_press (GooCanvasItem  *item,
                      GooCanvasItem  *target,
                      GdkEventButton *event,
                      gpointer        data)
{
  g_print ("rect item received button press event\n");
  return TRUE;
}


/* This is our handler for the "delete-event" signal of the window, which
   is emitted when the 'x' close button is clicked. We just exit here. */
static gboolean
on_delete_event (GtkWidget *window,
                 GdkEvent  *event,
                 gpointer   unused_data)
{
  exit (0);
}

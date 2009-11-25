#include <gtk/gtk.h>
#include <time.h>
#include <stdio.h>

double inter, sinter, timestop, timetotal, minutes, hours, sminutes, shours;
char timestring[255];
int timeout;
gboolean running;

GTimer *newtime;
GTimer *daytime;

void
on_start_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_stop_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_reset_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_window1_visibility_notify_event     (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

gboolean
on_timer_motion_notify_event           (GtkWidget       *widget,
                                        GdkEventMotion  *event,
                                        gpointer         user_data);

void
on_timer_grab_focus                    (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_show_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

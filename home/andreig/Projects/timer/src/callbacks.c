#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <time.h>
#include <stdio.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

	void
on_start_clicked                       (GtkButton       *button,
		gpointer         user_data)
{
	GtkWidget * label = lookup_widget(GTK_WIDGET(button), "timer");
	gtk_label_set_text(GTK_LABEL(label),"Timer Started.");

	newtime = g_timer_new();
	running = 1;
	timeout = gtk_timeout_add(1000,on_show_clicked,button);
}


	void
on_stop_clicked                        (GtkButton       *button,
		gpointer         user_data)
{

	if (running) {
		g_timer_stop(newtime);
		timestop += g_timer_elapsed(newtime, NULL);
		running = 0;
		gtk_timeout_remove(timeout);
	}

	sprintf(timestring,"Total Time: %02.0lf:%02.0lf:%02.0lf", hours, minutes, timetotal);
	GtkWidget * label = lookup_widget(GTK_WIDGET(button), "timer");
	gtk_label_set_text(GTK_LABEL(label),timestring);
}


	void
on_show_clicked                        (GtkButton       *button,
		gpointer         user_data)
{
	if (running) {
		inter = g_timer_elapsed(newtime, NULL);
		sinter = inter;
		timetotal = timestop + inter;

		minutes = timetotal / 60.0;
		timetotal -= (int) minutes*60.0;
		minutes = (int) minutes;
		hours = minutes / 60.0;
		minutes -= (int) hours*60;
		hours = (int) hours;

		sminutes = sinter / 60.0;
		sinter -= (int) sminutes*60.0;
		sminutes = (int) sminutes;
		shours = sminutes / 60.0;
		sminutes -= (int) shours*60;
		shours = (int) shours;
	}

	sprintf(timestring,"Session: Time: %02.0lf:%02.0lf:%02.0lf / Total Time: %02.0lf:%02.0lf:%02.0lf",shours, sminutes,sinter, hours, minutes, timetotal);
	GtkWidget * label = lookup_widget(GTK_WIDGET(button), "timer");
	gtk_label_set_text(GTK_LABEL(label),timestring);
}

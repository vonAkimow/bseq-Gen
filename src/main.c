#include "main.h"

/* Структура адресов виджетов окна помощи */
typedef struct {

    GtkWidget *w_help_window;

} help_widgets;

/* Структура адресов виджетов главного окна */
typedef struct {

    /* Спин - кнопки */
    GtkWidget*  w_prime_sbtn;
    GtkWidget*  w_s1_sbtn1;
    GtkWidget*  w_s2_sbtn1;
    GtkWidget*  w_s3_sbtn1;
    GtkWidget*  w_s4_sbtn1;

    /* Радиокнопки */
    GtkWidget*  w_s1_button;
    GtkWidget*  w_s2_button;
    GtkWidget*  w_s3_button;
    GtkWidget*  w_s4_button;

} main_widgets;


int main(int argc, char *argv[])
{
    GtkBuilder      *builder;
    GtkWidget       *window;

    /* Выделяем память под экземпляры структур */
    main_widgets     *widgets0 = g_slice_new(main_widgets);
    help_widgets     *widgets1 = g_slice_new(help_widgets);

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("glade/Hello.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));

    /* Заполняем экземпляр адресами виджетов*/
    widgets0->w_prime_sbtn = GTK_WIDGET(gtk_builder_get_object(builder,"prime_sbtn"));
    widgets0->w_s1_sbtn1 = GTK_WIDGET(gtk_builder_get_object(builder,"s1_sbtn1"));
    widgets0->w_s2_sbtn1 = GTK_WIDGET(gtk_builder_get_object(builder,"s2_sbtn1"));
    widgets0->w_s3_sbtn1 = GTK_WIDGET(gtk_builder_get_object(builder,"s3_sbtn1"));
    widgets0->w_s4_sbtn1 = GTK_WIDGET(gtk_builder_get_object(builder,"s4_sbtn1"));

    widgets0->w_s1_button = GTK_WIDGET(gtk_builder_get_object(builder,"s1_button"));
    widgets0->w_s2_button = GTK_WIDGET(gtk_builder_get_object(builder,"s2_button"));
    widgets0->w_s3_button = GTK_WIDGET(gtk_builder_get_object(builder,"s3_button"));
    widgets0->w_s4_button = GTK_WIDGET(gtk_builder_get_object(builder,"s4_button"));

    gtk_builder_connect_signals(builder, widgets0);


    g_object_unref(builder);

    gtk_widget_show(window);

    gtk_main();

    g_slice_free(help_widgets, widgets1);
    g_slice_free(main_widgets, widgets0);

    return 0;
}

/*Колбэк по нажатию кнопки "Таблица простых чисел"*/
void help_button_clicked(GtkWidget *widget, help_widgets* app_wgts)
{
    GtkBuilder      *builder1;
    builder1 = gtk_builder_new_from_file("glade/Help.glade");
    app_wgts->w_help_window = GTK_WIDGET(gtk_builder_get_object(builder1, "help_window"));
    g_object_unref(builder1);
    gtk_widget_show(app_wgts->w_help_window);
}

/*Колбэк по нажатию кнопки "Применить настройки" */
void apply_button_clicked(GtkWidget *widget, main_widgets* app_wgts)
{

    /* Сначала определяем выбранную радиокнопку */
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wgts->w_s1_button)))  /* 1 СДВИГ */
    {
        g_print("Catched1!\n");

        /* Считываем значения соответствующих спин кнопок */
        uint16_t length = 0, shift1 = 0;
        char len[5] = {0};
        char sht1[5] = {0};

        /* Прочитали значения кнопок  w_prime_sbtn и w_s1_sbtn1*/
        length = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_prime_sbtn));
        shift1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s1_sbtn1));

        g_snprintf(len,sizeof(len),"%d\n",length);
        g_snprintf(sht1,sizeof(sht1),"%d\n",shift1);

        g_print(len);
        g_print(sht1);
    }

    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wgts->w_s2_button)))  /* 2 СДВИГА */
    {

        g_print("Catched2!\n");


        uint16_t length = 0, shift1 = 0, shift2 = 0;
        char len[5] = {0};
        char sht1[5] = {0};
        char sht2[5] = {0};


        length = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_prime_sbtn));
        shift1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s1_sbtn1));
        shift2 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s2_sbtn1));

        g_snprintf(len,sizeof(len),"%d\n",length);
        g_snprintf(sht1,sizeof(sht1),"%d\n",shift1);
        g_snprintf(sht2,sizeof(sht2),"%d\n",shift2);

        g_print(len);
        g_print(sht1);
        g_print(sht2);
    }

    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wgts->w_s3_button)))  /* 3 СДВИГА */
    {

        g_print("Catched3!\n");


        uint16_t length = 0, shift1 = 0, shift2 = 0, shift3 = 0;
        char len[5] = {0};
        char sht1[5] = {0};
        char sht2[5] = {0};
        char sht3[5] = {0};


        length = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_prime_sbtn));
        shift1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s1_sbtn1));
        shift2 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s2_sbtn1));
        shift3 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s3_sbtn1));

        g_snprintf(len,sizeof(len),"%d\n",length);
        g_snprintf(sht1,sizeof(sht1),"%d\n",shift1);
        g_snprintf(sht2,sizeof(sht2),"%d\n",shift2);
        g_snprintf(sht3,sizeof(sht3),"%d\n",shift3);

        g_print(len);
        g_print(sht1);
        g_print(sht2);
        g_print(sht3);
    }

    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wgts->w_s4_button)))  /* 4 СДВИГА */
    {

        g_print("Catched4!\n");


        uint16_t length = 0, shift1 = 0, shift2 = 0, shift3 = 0, shift4 = 0;
        char len[5] = {0};
        char sht1[5] = {0};
        char sht2[5] = {0};
        char sht3[5] = {0};
        char sht4[5] = {0};


        length = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_prime_sbtn));
        shift1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s1_sbtn1));
        shift2 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s2_sbtn1));
        shift3 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s3_sbtn1));
        shift4 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s4_sbtn1));

        g_snprintf(len,sizeof(len),"%d\n",length);
        g_snprintf(sht1,sizeof(sht1),"%d\n",shift1);
        g_snprintf(sht2,sizeof(sht2),"%d\n",shift2);
        g_snprintf(sht3,sizeof(sht3),"%d\n",shift3);
        g_snprintf(sht4,sizeof(sht4),"%d\n",shift4);

        g_print(len);
        g_print(sht1);
        g_print(sht2);
        g_print(sht3);
        g_print(sht4);
    }

}

/*Колбэк по закрытию главного окна*/
void main_destroy()
{
    gtk_main_quit();
}




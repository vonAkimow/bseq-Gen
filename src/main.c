#include "main.h"



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

    /* Кнопки */
    GtkWidget*  w_generate_button;

} main_widgets;


int main(int argc, char *argv[])
{
    GtkBuilder      *builder;
    GtkWidget       *window;

    /* Выделяем память под экземпляры структур */
    main_widgets     *widgets0 = g_slice_new(main_widgets);


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

    widgets0->w_generate_button = GTK_WIDGET(gtk_builder_get_object(builder,"generate_button"));

    gtk_builder_connect_signals(builder, widgets0);


    g_object_unref(builder);

    gtk_widget_show(window);

    gtk_main();

    /* Освобождаем память, выделенную под экземпляр структуры */
    g_slice_free(main_widgets, widgets0);

    return 0;
}


/*#################################################
        ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ ДЛЯ КОЛБЭКОВ       */

    volatile uint8_t flag = 0;
    volatile uint32_t number = 0, shift1 = 0, shift2 = 0, shift3 = 0, shift4 = 0;

 /*##############################################*/



/*#################################################
  Колбэк по нажатию кнопки "Таблица простых чисел"*/
void help_button_clicked()
{
    /* Структура адресов виджетов окна помощи */
    typedef struct {

        GtkWidget *w_help_window;

    } help_widgets;

    /* Выделяем память под экземпляр структуры */
    help_widgets     *widgets1 = g_slice_new(help_widgets);

    GtkBuilder      *builder1;
    builder1 = gtk_builder_new_from_file("glade/Help.glade");
    widgets1->w_help_window = GTK_WIDGET(gtk_builder_get_object(builder1, "help_window"));

    g_object_unref(builder1);
    gtk_widget_show(widgets1->w_help_window);

    /* Освобождаем память, выделенную под экземпляр структуры */
    g_slice_free(help_widgets, widgets1);
}

/*#################################################
   Колбэк по нажатию кнопки "Применить настройки" */
void apply_button_clicked(GtkWidget *widget, main_widgets* app_wgts)
{

    /* Сначала определяем выбранную радиокнопку */
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wgts->w_s1_button)))  /* 1 СДВИГ */
    {
        g_print("SHIFTS1!\n");

        /* Считываем значения соответствующих спин кнопок */
        char len[5] = {0};
        char sht1[5] = {0};

        /* Прочитали значения кнопок  w_prime_sbtn и w_s1_sbtn1*/
        number = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_prime_sbtn));
        shift1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s1_sbtn1));

        g_snprintf(len,sizeof(len),"%d\n",number);
        g_snprintf(sht1,sizeof(sht1),"%d\n",shift1);

        g_print(len);
        g_print(sht1);


        flag = 1;
        gtk_widget_set_sensitive(app_wgts->w_generate_button, TRUE);
    }

    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wgts->w_s2_button)))  /* 2 СДВИГА */
    {

        g_print("SHIFTS2!\n");

        char len[5] = {0};
        char sht1[5] = {0};
        char sht2[5] = {0};

        number= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_prime_sbtn));
        shift1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s1_sbtn1));
        shift2 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s2_sbtn1));

        g_snprintf(len,sizeof(len),"%d\n",number);
        g_snprintf(sht1,sizeof(sht1),"%d\n",shift1);
        g_snprintf(sht2,sizeof(sht2),"%d\n",shift2);

        g_print(len);
        g_print(sht1);
        g_print(sht2);


        flag = 2;
        gtk_widget_set_sensitive(app_wgts->w_generate_button, TRUE);
    }

    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wgts->w_s3_button)))  /* 3 СДВИГА */
    {

        g_print("SHIFTS3!\n");

        char len[5] = {0};
        char sht1[5] = {0};
        char sht2[5] = {0};
        char sht3[5] = {0};


        number = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_prime_sbtn));
        shift1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s1_sbtn1));
        shift2 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s2_sbtn1));
        shift3 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s3_sbtn1));

        g_snprintf(len,sizeof(len),"%d\n",number);
        g_snprintf(sht1,sizeof(sht1),"%d\n",shift1);
        g_snprintf(sht2,sizeof(sht2),"%d\n",shift2);
        g_snprintf(sht3,sizeof(sht3),"%d\n",shift3);

        g_print(len);
        g_print(sht1);
        g_print(sht2);
        g_print(sht3);


        flag = 3;
        gtk_widget_set_sensitive(app_wgts->w_generate_button, TRUE);

    }

    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wgts->w_s4_button)))  /* 4 СДВИГА */
    {

        g_print("SHIFTS4!\n");

        char len[5] = {0};
        char sht1[5] = {0};
        char sht2[5] = {0};
        char sht3[5] = {0};
        char sht4[5] = {0};


        number = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_prime_sbtn));
        shift1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s1_sbtn1));
        shift2 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s2_sbtn1));
        shift3 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s3_sbtn1));
        shift4 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s4_sbtn1));

        g_snprintf(len,sizeof(len),"%d\n",number);
        g_snprintf(sht1,sizeof(sht1),"%d\n",shift1);
        g_snprintf(sht2,sizeof(sht2),"%d\n",shift2);
        g_snprintf(sht3,sizeof(sht3),"%d\n",shift3);
        g_snprintf(sht4,sizeof(sht4),"%d\n",shift4);

        g_print(len);
        g_print(sht1);
        g_print(sht2);
        g_print(sht3);
        g_print(sht4);

        flag = 4;
        gtk_widget_set_sensitive(app_wgts->w_generate_button, TRUE);
    }

}

/*#################################################
        Колбэк по нажатию кнопки "Сгенерировать" */
void generate_button_clicked(GtkWidget *widget, main_widgets* app_wgts)
{

    g_print("GEEENERATE!!!\n");
    gtk_widget_set_sensitive(app_wgts->w_generate_button, FALSE);


    if (flag == 1)
    {

        uint8_t* BaseSequence = (uint8_t*)calloc(number, sizeof(uint8_t)); /*выделили память для динамического массива (=последовательность)*/
        uint8_t* Sequence1 = (uint8_t*)calloc(number, sizeof(uint8_t));

        MakePrimeSequence(BaseSequence, number);
        MakePrimeSequence(Sequence1, number);
        DisplaySequence(BaseSequence,number,"Prime sequence b1(k): ");

        RightShifts(Sequence1, number, shift1);

        SeqPSeq(BaseSequence, Sequence1, number);
        printf("\n");
        printf("Length: %i \n", number);
        printf("Shifters: %d\n",flag);
        DisplaySequence(BaseSequence, number, "B-Sequence1 : ");
        CountI(BaseSequence, number, 1);
        CountI(BaseSequence, number, 0);

        free(Sequence1); /*освобождаем выделенную память*/

        g_print("\nflag1!\n");
        flag = 0;
    }




    else if (flag == 2)
    {

        uint8_t* BaseSequence = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence1 = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence2 = (uint8_t*)calloc(number, sizeof(uint8_t));

        MakePrimeSequence(BaseSequence, number);
        MakePrimeSequence(Sequence1, number);
        MakePrimeSequence(Sequence2, number);
        DisplaySequence(BaseSequence,number,"Prime sequence b2(k): ");
        g_print("\nflag2!\n");

        RightShifts(Sequence1, number, shift1);//S1>>shift1
        RightShifts(Sequence2, number, shift2);//S2>>shift2

        SeqPSeq(Sequence1, Sequence2, number);//S1+S2
        SeqPSeq(BaseSequence, Sequence1, number);//S1+S2+b(k)
        printf("\n");
        printf("Length: %i \n", number);
        printf("Shifters: %d\n",flag);
        DisplaySequence(BaseSequence, number, "B-Sequence2 : ");
        CountI(BaseSequence, number, 1);
        CountI(BaseSequence, number, 0);

        free(Sequence1);
        free(Sequence2);

        g_print("\nflag2!\n");
        flag = 0;
    }


    else if (flag == 3)
    {

        uint8_t* BaseSequence = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence1 = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence2 = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence3 = (uint8_t*)calloc(number, sizeof(uint8_t));

        MakePrimeSequence(BaseSequence, number);
        MakePrimeSequence(Sequence1, number);
        MakePrimeSequence(Sequence2, number);
        MakePrimeSequence(Sequence3, number);
        DisplaySequence(BaseSequence,number,"Prime sequence b3(k): ");



        RightShifts(Sequence1, number, shift1);//S1>>shift1
        RightShifts(Sequence2, number, shift2);//S2>>shift2
        RightShifts(Sequence3, number, shift3);//S3>>shift3
        printf("\n");

        SeqPSeq(Sequence1, Sequence2, number);//S1+S2
        SeqPSeq(Sequence3, Sequence1, number); //S1+S2+S3
        SeqPSeq(BaseSequence, Sequence3, number);//S1+S2+S3+b(k)
        printf("\n");
        printf("Length: %i \n", number);
        printf("Shifters: %d\n",flag);
        DisplaySequence(BaseSequence, number, "B-Sequence3 : ");
        CountI(BaseSequence, number, 1);
        CountI(BaseSequence, number, 0);

        free(Sequence1);
        free(Sequence2);
        free(Sequence3);

        g_print("\nflag3!\n");
        flag = 0;
    }


    else if (flag == 4)
    {

        uint8_t* BaseSequence = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence1 = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence2 = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence3 = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence4 = (uint8_t*)calloc(number, sizeof(uint8_t));

        MakePrimeSequence(BaseSequence, number);//b(k)
        MakePrimeSequence(Sequence1, number);//S1
        MakePrimeSequence(Sequence2, number);//S2
        MakePrimeSequence(Sequence3, number);//S3
        MakePrimeSequence(Sequence4, number);//S4
        DisplaySequence(BaseSequence,number,"Prime sequence b4(k): ");

        RightShifts(Sequence1, number, shift1); //S1>>shift1
        RightShifts(Sequence2, number, shift2); //S2>>shift2
        RightShifts(Sequence3, number, shift3); //S3>>shift3
        RightShifts(Sequence4, number, shift4); //S4>>shift4

        SeqPSeq(Sequence1, Sequence2, number); //S1+S2
        SeqPSeq(Sequence3, Sequence1, number); //S1+S2+S3
        SeqPSeq(Sequence4, Sequence3, number); //S1+S2+S3+S4
        SeqPSeq(BaseSequence, Sequence4, number); //S1+S2+S3+S4+b(k)
        printf("\n");
        printf("Length: %i \n", number);
        printf("Shifters: %d\n",flag);
        DisplaySequence(BaseSequence, number, "B-Sequence4 :\n");
        printf("\n");
        CountI(BaseSequence, number, 1);
        CountI(BaseSequence, number, 0);

        free(Sequence1);
        free(Sequence2);
        free(Sequence3);
        free(Sequence4);

        g_print("\nflag4!\n");
        flag = 0;
    }
    else
    {
        g_print("ERROR!!!");
        flag = 0;
    }


}

/*#################################################
                Колбэк по закрытию главного окна*/
void main_destroy()
{
    gtk_main_quit();
}




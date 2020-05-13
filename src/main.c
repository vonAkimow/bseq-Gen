#include "main.h"


/* Структура адресов виджетов главного окна */
typedef struct {

    /* Спин - кнопки 1*/
    GtkWidget*  w_prime_sbtn;
    GtkWidget*  w_s1_sbtn1;
    GtkWidget*  w_s2_sbtn1;
    GtkWidget*  w_s3_sbtn1;
    GtkWidget*  w_s4_sbtn1;

    /* Спин - кнопки 2*/
    GtkWidget*  w_s1_sbtn2;
    GtkWidget*  w_s2_sbtn2;
    GtkWidget*  w_s3_sbtn2;
    GtkWidget*  w_s4_sbtn2;

    /* Радиокнопки 1*/
    GtkWidget*  w_s1_button;
    GtkWidget*  w_s2_button;
    GtkWidget*  w_s3_button;
    GtkWidget*  w_s4_button;

    /* Радиокнопки 2*/
    GtkWidget*  w_s1_button2;
    GtkWidget*  w_s2_button2;
    GtkWidget*  w_s3_button2;
    GtkWidget*  w_s4_button2;

    /* Кнопки */
    GtkWidget*  w_generate_button;
    GtkWidget*  w_pacf_button;
    GtkWidget*  w_aacf_button;
    GtkWidget*  w_pvcf_button;
    GtkWidget*  w_avcf_button;
    GtkWidget*  w_generate_button1;


    /* Текстовый буфер*/
    GtkTextBuffer* w_output_buffer;
    GtkTextView* w_text_view;

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

    widgets0->w_s1_sbtn2 = GTK_WIDGET(gtk_builder_get_object(builder,"s1_sbtn2"));
    widgets0->w_s2_sbtn2 = GTK_WIDGET(gtk_builder_get_object(builder,"s2_sbtn2"));
    widgets0->w_s3_sbtn2 = GTK_WIDGET(gtk_builder_get_object(builder,"s3_sbtn2"));
    widgets0->w_s4_sbtn2 = GTK_WIDGET(gtk_builder_get_object(builder,"s4_sbtn2"));

    widgets0->w_s1_button = GTK_WIDGET(gtk_builder_get_object(builder,"s1_button"));
    widgets0->w_s2_button = GTK_WIDGET(gtk_builder_get_object(builder,"s2_button"));
    widgets0->w_s3_button = GTK_WIDGET(gtk_builder_get_object(builder,"s3_button"));
    widgets0->w_s4_button = GTK_WIDGET(gtk_builder_get_object(builder,"s4_button"));

    widgets0->w_s1_button2 = GTK_WIDGET(gtk_builder_get_object(builder,"s1_button2"));
    widgets0->w_s2_button2 = GTK_WIDGET(gtk_builder_get_object(builder,"s2_button2"));
    widgets0->w_s3_button2 = GTK_WIDGET(gtk_builder_get_object(builder,"s3_button2"));
    widgets0->w_s4_button2 = GTK_WIDGET(gtk_builder_get_object(builder,"s4_button2"));

    widgets0->w_generate_button = GTK_WIDGET(gtk_builder_get_object(builder,"generate_button"));
    widgets0->w_generate_button1 = GTK_WIDGET(gtk_builder_get_object(builder,"generate_button1"));
    widgets0->w_pacf_button = GTK_WIDGET(gtk_builder_get_object(builder,"pacf_button"));
    widgets0->w_aacf_button = GTK_WIDGET(gtk_builder_get_object(builder,"aacf_button"));
    widgets0->w_pvcf_button = GTK_WIDGET(gtk_builder_get_object(builder,"pvcf_button"));
    widgets0->w_avcf_button = GTK_WIDGET(gtk_builder_get_object(builder,"avcf_button"));

    widgets0->w_output_buffer = GTK_TEXT_BUFFER(gtk_builder_get_object(builder,"output_buffer"));
    widgets0->w_text_view = GTK_TEXT_VIEW(gtk_builder_get_object(builder,"text_view"));

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
    volatile uint8_t* AA_Sequence;
    volatile uint8_t* PA_Sequence;
    volatile uint8_t* AV_Sequence1;
    volatile uint8_t* AV_Sequence2;
    volatile uint8_t* PV_Sequence1;
    volatile uint8_t* PV_Sequence2;


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

        /* Прочитали значения кнопок  w_prime_sbtn и w_s1_sbtn1*/
        number = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_prime_sbtn));
        shift1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s1_sbtn1));

        flag = 1;
        gtk_widget_set_sensitive(app_wgts->w_generate_button, TRUE);
    }

    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wgts->w_s2_button)))  /* 2 СДВИГА */
    {

        number= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_prime_sbtn));
        shift1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s1_sbtn1));
        shift2 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s2_sbtn1));

        flag = 2;
        gtk_widget_set_sensitive(app_wgts->w_generate_button, TRUE);
    }

    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wgts->w_s3_button)))  /* 3 СДВИГА */
    {

        number = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_prime_sbtn));
        shift1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s1_sbtn1));
        shift2 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s2_sbtn1));
        shift3 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s3_sbtn1));

        flag = 3;
        gtk_widget_set_sensitive(app_wgts->w_generate_button, TRUE);

    }

    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wgts->w_s4_button)))  /* 4 СДВИГА */
    {

        number = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_prime_sbtn));
        shift1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s1_sbtn1));
        shift2 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s2_sbtn1));
        shift3 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s3_sbtn1));
        shift4 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s4_sbtn1));

        flag = 4;
        gtk_widget_set_sensitive(app_wgts->w_generate_button, TRUE);
    }

    gtk_widget_set_sensitive(app_wgts->w_aacf_button, FALSE); /*Кнопки блока статистической обработки становятся нечувствительными*/
    gtk_widget_set_sensitive(app_wgts->w_pacf_button, FALSE);
    gtk_widget_set_sensitive(app_wgts->w_generate_button1, FALSE);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Настройки применены, теперь можно сгенерировать последовательность \n",-1);
}

/*#################################################
        Колбэк по нажатию кнопки "Сгенерировать" */
void generate_button_clicked(GtkWidget *widget, main_widgets* app_wgts)
{
    uint8_t* BaseSequence = (uint8_t*)calloc(number, sizeof(uint8_t)); /*выделили память для динамического массива (=последовательность)*/
    uint8_t* PAKFSequence = (uint8_t*)calloc(number, sizeof(uint8_t));
    uint8_t* AAKFSequence = (uint8_t*)calloc(number, sizeof(uint8_t));
    uint8_t* PVKFSequence = (uint8_t*)calloc(number, sizeof(uint8_t));
    uint8_t* AVKFSequence = (uint8_t*)calloc(number, sizeof(uint8_t));
    char* BS = (char*)calloc(number+1,sizeof(char));/*Строка для вывода последовательности в текстовый буфер*/
    char ones[13] = {0};
    char zeros[13] = {0};
    GtkTextBuffer	*buffer;
    GtkTextIter	end;


    gtk_widget_set_sensitive(app_wgts->w_generate_button, FALSE);


    if (flag == 1)
    {

        uint8_t* Sequence1 = (uint8_t*)calloc(number, sizeof(uint8_t));

        MakePrimeSequence(BaseSequence, number);
        MakePrimeSequence(Sequence1, number);

        RightShifts(Sequence1, number, shift1);//S1>>shift1

        SeqPSeq(BaseSequence, Sequence1, number);//S1+S2
        CountI(BaseSequence, number, 1);
        CountI(BaseSequence, number, 0);

        IntToString(BS,BaseSequence,number);/*Преобразование массива чисел в строку*/

        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> B - последовательность(1): \n",-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,BS,-1);

        uint16_t count1 = CountI(BaseSequence, number, 1);

        sprintf(ones, "<1> - %d, ",count1);
        sprintf(zeros, "<0> - %d.",number - count1);

        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Сбалансированность : \n",-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,ones,-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,zeros,-1);

        buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(app_wgts->w_text_view));/*Скроллим в конец теста*/
        gtk_text_buffer_get_end_iter(buffer, &end);
        gtk_text_view_scroll_to_iter(GTK_TEXT_VIEW(app_wgts->w_text_view), &end, 0.0, FALSE, 0.0,0.0);

        for(uint16_t z = 0; z < number; z++)
        {
            PAKFSequence[z] = BaseSequence[z];
            AAKFSequence[z] = BaseSequence[z];
            PVKFSequence[z] = BaseSequence[z];
            AVKFSequence[z] = BaseSequence[z];
        }

        AA_Sequence = AAKFSequence;
        PA_Sequence = PAKFSequence;
        AV_Sequence1 = AVKFSequence;
        PV_Sequence1 = PVKFSequence;


        free(Sequence1); /*освобождаем выделенную память*/
        free(BS);
        free(BaseSequence);

        flag = 0;
    }

    else if (flag == 2)
    {

        uint8_t* Sequence1 = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence2 = (uint8_t*)calloc(number, sizeof(uint8_t));

        MakePrimeSequence(BaseSequence, number);
        MakePrimeSequence(Sequence1, number);
        MakePrimeSequence(Sequence2, number);

        RightShifts(Sequence1, number, shift1);//S1>>shift1
        RightShifts(Sequence2, number, shift2);//S2>>shift2

        SeqPSeq(Sequence1, Sequence2, number);//S1+S2
        SeqPSeq(BaseSequence, Sequence1, number);//S1+S2+b(k)
        CountI(BaseSequence, number, 1);
        CountI(BaseSequence, number, 0);

        IntToString(BS,BaseSequence,number);/*Преобразование массива чисел в строку*/

        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> B - последовательность(1): \n",-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,BS,-1);

        uint16_t count1 = CountI(BaseSequence, number, 1);

        sprintf(ones, "<1> - %u, ",count1);
        sprintf(zeros, "<0> - %u.",number - count1);

        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Сбалансированность : \n",-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,ones,-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,zeros,-1);

        buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(app_wgts->w_text_view));/*Скроллим в конец теста*/
        gtk_text_buffer_get_end_iter(buffer, &end);
        gtk_text_view_scroll_to_iter(GTK_TEXT_VIEW(app_wgts->w_text_view), &end, 0.0, FALSE, 0.0,0.0);

        for(uint16_t z=0; z < number; z++)
        {
            PAKFSequence[z] = BaseSequence[z];
            AAKFSequence[z] = BaseSequence[z];
            PVKFSequence[z] = BaseSequence[z];
            AVKFSequence[z] = BaseSequence[z];
        }

        AA_Sequence = AAKFSequence;
        PA_Sequence = PAKFSequence;
        AV_Sequence1 = AVKFSequence;
        PV_Sequence1 = PVKFSequence;

        free(Sequence1);
        free(Sequence2);
        free(BS);
        free(BaseSequence);

        flag = 0;
    }

    else if (flag == 3)
    {

        uint8_t* Sequence1 = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence2 = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence3 = (uint8_t*)calloc(number, sizeof(uint8_t));

        MakePrimeSequence(BaseSequence, number);
        MakePrimeSequence(Sequence1, number);
        MakePrimeSequence(Sequence2, number);
        MakePrimeSequence(Sequence3, number);

        RightShifts(Sequence1, number, shift1);//S1>>shift1
        RightShifts(Sequence2, number, shift2);//S2>>shift2
        RightShifts(Sequence3, number, shift3);//S3>>shift3

        SeqPSeq(Sequence1, Sequence2, number);//S1+S2
        SeqPSeq(Sequence3, Sequence1, number); //S1+S2+S3
        SeqPSeq(BaseSequence, Sequence3, number);//S1+S2+S3+b(k)
        CountI(BaseSequence, number, 1);
        CountI(BaseSequence, number, 0);

        IntToString(BS,BaseSequence,number);/*Преобразование массива чисел в строку*/

        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> B - последовательность(1): \n",-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,BS,-1);

        uint16_t count1 = CountI(BaseSequence, number, 1);

        sprintf(ones, "<1> - %u, ",count1);
        sprintf(zeros, "<0> - %u.",number - count1);

        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Сбалансированность : \n",-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,ones,-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,zeros,-1);

        buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(app_wgts->w_text_view));/*Скроллим в конец теста*/
        gtk_text_buffer_get_end_iter(buffer, &end);
        gtk_text_view_scroll_to_iter(GTK_TEXT_VIEW(app_wgts->w_text_view), &end, 0.0, FALSE, 0.0,0.0);

        for(uint16_t z=0; z < number; z++)
        {
            PAKFSequence[z] = BaseSequence[z];
            AAKFSequence[z] = BaseSequence[z];
            PVKFSequence[z] = BaseSequence[z];
            AVKFSequence[z] = BaseSequence[z];
        }

        AA_Sequence = AAKFSequence;
        PA_Sequence = PAKFSequence;
        AV_Sequence1 = AVKFSequence;
        PV_Sequence1 = PVKFSequence;

        free(Sequence1);
        free(Sequence2);
        free(Sequence3);
        free(BS);
        free(BaseSequence);

        flag = 0;
    }


    else if (flag == 4)
    {

        uint8_t* Sequence1 = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence2 = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence3 = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence4 = (uint8_t*)calloc(number, sizeof(uint8_t));

        MakePrimeSequence(BaseSequence, number);//b(k)
        MakePrimeSequence(Sequence1, number);//S1
        MakePrimeSequence(Sequence2, number);//S2
        MakePrimeSequence(Sequence3, number);//S3
        MakePrimeSequence(Sequence4, number);//S4

        RightShifts(Sequence1, number, shift1); //S1>>shift1
        RightShifts(Sequence2, number, shift2); //S2>>shift2
        RightShifts(Sequence3, number, shift3); //S3>>shift3
        RightShifts(Sequence4, number, shift4); //S4>>shift4

        SeqPSeq(Sequence1, Sequence2, number); //S1+S2
        SeqPSeq(Sequence3, Sequence1, number); //S1+S2+S3
        SeqPSeq(Sequence4, Sequence3, number); //S1+S2+S3+S4
        SeqPSeq(BaseSequence, Sequence4, number); //S1+S2+S3+S4+b(k)
        CountI(BaseSequence, number, 1);
        CountI(BaseSequence, number, 0);

        IntToString(BS,BaseSequence,number);/*Преобразование массива чисел в строку*/

        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> B - последовательность(1): \n",-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,BS,-1);

        uint16_t count1 = CountI(BaseSequence, number, 1);

        sprintf(ones, "<1> - %u, ",count1);
        sprintf(zeros, "<0> - %u.",number - count1);

        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Сбалансированность : \n",-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,ones,-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,zeros,-1);

        buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(app_wgts->w_text_view));/*Скроллим в конец теста*/
        gtk_text_buffer_get_end_iter(buffer, &end);
        gtk_text_view_scroll_to_iter(GTK_TEXT_VIEW(app_wgts->w_text_view), &end, 0.0, FALSE, 0.0,0.0);

        for(uint16_t z=0; z < number; z++)
        {
            PAKFSequence[z] = BaseSequence[z];
            AAKFSequence[z] = BaseSequence[z];
            PVKFSequence[z] = BaseSequence[z];
            AVKFSequence[z] = BaseSequence[z];
        }

        AA_Sequence = AAKFSequence;
        PA_Sequence = PAKFSequence;
        AV_Sequence1 = AVKFSequence;
        PV_Sequence1 = PVKFSequence;


        free(Sequence1);
        free(Sequence2);
        free(Sequence3);
        free(Sequence4);
        free(BS);
        free(BaseSequence);

        flag = 0;
    }
    else
    {
        g_print("ERROR!!!");
        flag = 0;        g_print("\nfla32g4!\n");
    }

    gtk_widget_set_sensitive(app_wgts->w_aacf_button, TRUE);/*Кнопки блока статистической обработки становятся чувствительными*/
    gtk_widget_set_sensitive(app_wgts->w_pacf_button, TRUE);

    gtk_widget_set_sensitive(app_wgts->w_generate_button1, TRUE);

    gtk_widget_set_sensitive(app_wgts->w_s1_button2, TRUE);
    gtk_widget_set_sensitive(app_wgts->w_s2_button2, TRUE);
    gtk_widget_set_sensitive(app_wgts->w_s3_button2, TRUE);
    gtk_widget_set_sensitive(app_wgts->w_s4_button2, TRUE);

    gtk_widget_set_sensitive(app_wgts->w_s1_sbtn2, TRUE);
    gtk_widget_set_sensitive(app_wgts->w_s2_sbtn2, TRUE);
    gtk_widget_set_sensitive(app_wgts->w_s3_sbtn2, TRUE);
    gtk_widget_set_sensitive(app_wgts->w_s4_sbtn2, TRUE);

}


/*#################################################
        Колбэк по нажатию кнопки "Сгенерировать2" */
void generate_button1_clicked(GtkWidget *widget, main_widgets* app_wgts)
{
    gtk_widget_set_sensitive(app_wgts->w_generate_button1, FALSE);

    uint8_t* BaseSequence = (uint8_t*)calloc(number, sizeof(uint8_t)); /*выделили память для динамического массива (=последовательность)*/
    uint8_t* PVKFSequence = (uint8_t*)calloc(number, sizeof(uint8_t));
    uint8_t* AVKFSequence = (uint8_t*)calloc(number, sizeof(uint8_t));
    char*              BS = (char*)calloc(number+1,sizeof(char));/*Строка для вывода последовательности в текстовый буфер*/
    char ones[13] = {0};
    char zeros[13] = {0};
    GtkTextBuffer	*buffer;
    GtkTextIter	end;

        /* Сначала определяем выбранную радиокнопку */
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wgts->w_s1_button2)))  /* 1 СДВИГ */
    {

        /* Считываем значения соответствующих спин кнопок */

        shift1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s1_sbtn2));

        uint8_t* Sequence1 = (uint8_t*)calloc(number, sizeof(uint8_t));

        MakePrimeSequence(BaseSequence, number);
        MakePrimeSequence(Sequence1, number);

        RightShifts(Sequence1, number, shift1);//S1>>shift1

        SeqPSeq(BaseSequence, Sequence1, number);//S1+S2
        CountI(BaseSequence, number, 1);
        CountI(BaseSequence, number, 0);

        IntToString(BS,BaseSequence,number);/*Преобразование массива чисел в строку*/

        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n\n> B - последовательность(2): \n",-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,BS,-1);

        uint16_t count1 = CountI(BaseSequence, number, 1);

        sprintf(ones, "<1> - %d, ",count1);
        sprintf(zeros, "<0> - %d.",number - count1);

        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Сбалансированность : \n",-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,ones,-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,zeros,-1);


        buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(app_wgts->w_text_view));/*Скроллим в конец теста*/
        gtk_text_buffer_get_end_iter(buffer, &end);
        gtk_text_view_scroll_to_iter(GTK_TEXT_VIEW(app_wgts->w_text_view), &end, 0.0, TRUE, 0.0,0.0);

        for(uint16_t z = 0; z < number; z++)
        {
            AVKFSequence[z] = BaseSequence[z];
            PVKFSequence[z] = BaseSequence[z];
        }

        AV_Sequence2 = AVKFSequence;
        PV_Sequence2 = PVKFSequence;

        free(Sequence1); /*освобождаем выделенную память*/
        free(BS);
        free(BaseSequence);

    }

    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wgts->w_s2_button2)))  /* 2 СДВИГА */
    {

        shift1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s1_sbtn2));
        shift2 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s2_sbtn2));

        uint8_t* Sequence1 = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence2 = (uint8_t*)calloc(number, sizeof(uint8_t));

        MakePrimeSequence(BaseSequence, number);
        MakePrimeSequence(Sequence1, number);
        MakePrimeSequence(Sequence2, number);

        RightShifts(Sequence1, number, shift1);//S1>>shift1
        RightShifts(Sequence2, number, shift2);//S2>>shift2

        SeqPSeq(Sequence1, Sequence2, number);//S1+S2
        SeqPSeq(BaseSequence, Sequence1, number);//S1+S2+b(k)
        CountI(BaseSequence, number, 1);
        CountI(BaseSequence, number, 0);

        IntToString(BS,BaseSequence,number);/*Преобразование массива чисел в строку*/

        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n\n> B - последовательность(2): \n",-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,BS,-1);

        uint16_t count1 = CountI(BaseSequence, number, 1);

        sprintf(ones, "<1> - %u, ",count1);
        sprintf(zeros, "<0> - %u.",number - count1);

        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Сбалансированность : \n",-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,ones,-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,zeros,-1);

        buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(app_wgts->w_text_view));/*Скроллим в конец теста*/
        gtk_text_buffer_get_end_iter(buffer, &end);
        gtk_text_view_scroll_to_iter(GTK_TEXT_VIEW(app_wgts->w_text_view), &end, 0.0, TRUE, 0.0,0.0);

        for(uint16_t z=0; z < number; z++)
        {
            AVKFSequence[z] = BaseSequence[z];
            PVKFSequence[z] = BaseSequence[z];
        }

        AV_Sequence2 = AVKFSequence;
        PV_Sequence2 = PVKFSequence;

        free(Sequence1);
        free(Sequence2);
        free(BS);
        free(BaseSequence);

    }

    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wgts->w_s3_button2)))  /* 3 СДВИГА */
    {
        shift1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s1_sbtn2));
        shift2 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s2_sbtn2));
        shift3 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s3_sbtn2));

        uint8_t* Sequence1 = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence2 = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence3 = (uint8_t*)calloc(number, sizeof(uint8_t));

        MakePrimeSequence(BaseSequence, number);
        MakePrimeSequence(Sequence1, number);
        MakePrimeSequence(Sequence2, number);
        MakePrimeSequence(Sequence3, number);

        RightShifts(Sequence1, number, shift1);//S1>>shift1
        RightShifts(Sequence2, number, shift2);//S2>>shift2
        RightShifts(Sequence3, number, shift3);//S3>>shift3

        SeqPSeq(Sequence1, Sequence2, number);//S1+S2
        SeqPSeq(Sequence3, Sequence1, number); //S1+S2+S3
        SeqPSeq(BaseSequence, Sequence3, number);//S1+S2+S3+b(k)
        CountI(BaseSequence, number, 1);
        CountI(BaseSequence, number, 0);

        IntToString(BS,BaseSequence,number);/*Преобразование массива чисел в строку*/

        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n\n> B - последовательность(2): \n",-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,BS,-1);

        uint16_t count1 = CountI(BaseSequence, number, 1);

        sprintf(ones, "<1> - %u, ",count1);
        sprintf(zeros, "<0> - %u.",number - count1);

        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Сбалансированность : \n",-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,ones,-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,zeros,-1);

        buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(app_wgts->w_text_view));/*Скроллим в конец теста*/
        gtk_text_buffer_get_end_iter(buffer, &end);
        gtk_text_view_scroll_to_iter(GTK_TEXT_VIEW(app_wgts->w_text_view), &end, 0.0, TRUE, 0.0,0.0);

        for(uint16_t z=0; z < number; z++)
        {
            AVKFSequence[z] = BaseSequence[z];
            PVKFSequence[z] = BaseSequence[z];
        }

        AV_Sequence2 = AVKFSequence;
        PV_Sequence2 = PVKFSequence;

        free(Sequence1);
        free(Sequence2);
        free(Sequence3);
        free(BS);
        free(BaseSequence);

    }

    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wgts->w_s4_button2)))  /* 4 СДВИГА */
    {

        shift1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s1_sbtn2));
        shift2 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s2_sbtn2));
        shift3 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s3_sbtn2));
        shift4 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(app_wgts->w_s4_sbtn2));

        uint8_t* Sequence1 = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence2 = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence3 = (uint8_t*)calloc(number, sizeof(uint8_t));
        uint8_t* Sequence4 = (uint8_t*)calloc(number, sizeof(uint8_t));


        MakePrimeSequence(BaseSequence, number);//b(k)
        MakePrimeSequence(Sequence1, number);//S1
        MakePrimeSequence(Sequence2, number);//S2
        MakePrimeSequence(Sequence3, number);//S3
        MakePrimeSequence(Sequence4, number);//S4

        RightShifts(Sequence1, number, shift1); //S1>>shift1
        RightShifts(Sequence2, number, shift2); //S2>>shift2
        RightShifts(Sequence3, number, shift3); //S3>>shift3
        RightShifts(Sequence4, number, shift4); //S4>>shift4

        SeqPSeq(Sequence1, Sequence2, number); //S1+S2
        SeqPSeq(Sequence3, Sequence1, number); //S1+S2+S3
        SeqPSeq(Sequence4, Sequence3, number); //S1+S2+S3+S4
        SeqPSeq(BaseSequence, Sequence4, number); //S1+S2+S3+S4+b(k)
        CountI(BaseSequence, number, 1);
        CountI(BaseSequence, number, 0);

        IntToString(BS,BaseSequence,number);/*Преобразование массива чисел в строку*/

        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n\n> B - последовательность(2): \n",-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,BS,-1);

        uint16_t count1 = CountI(BaseSequence, number, 1);

        sprintf(ones, "<1> - %u, ",count1);
        sprintf(zeros, "<0> - %u.",number - count1);

        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Сбалансированность : \n",-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,ones,-1);
        gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,zeros,-1);

        buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(app_wgts->w_text_view));/*Скроллим в конец теста*/
        gtk_text_buffer_get_end_iter(buffer, &end);
        gtk_text_view_scroll_to_iter(GTK_TEXT_VIEW(app_wgts->w_text_view), &end, 0.0, TRUE, 0.0,0.0);

        for(uint16_t z=0; z < number; z++)
        {
            AVKFSequence[z] = BaseSequence[z];
            PVKFSequence[z] = BaseSequence[z];
        }

        AV_Sequence2 = AVKFSequence;
        PV_Sequence2 = PVKFSequence;


        free(Sequence1);
        free(Sequence2);
        free(Sequence3);
        free(Sequence4);
        free(BS);
        free(BaseSequence);

    }

    gtk_widget_set_sensitive(app_wgts->w_avcf_button, TRUE);/*Кнопки блока статистической обработки становятся чувствительными*/
    gtk_widget_set_sensitive(app_wgts->w_pvcf_button, TRUE);
}


/*#################################################
                Колбэк по нажатию кнопки очистки*/
void clear_textbuffer_clicked(GtkWidget *widget, main_widgets* app_wgts)
{
    GtkTextIter	start, end;
    GtkTextBuffer	*buffer;

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(app_wgts->w_text_view));
    gtk_text_buffer_get_bounds(buffer, &start, &end);
	gtk_text_buffer_delete(buffer, &start, &end);
}


/*#################################################
                Колбэк по нажатию кнопки "ПАКФ" */

void pacf_button_clicked(GtkWidget *widget, main_widgets* app_wgts)
{
    gtk_widget_set_sensitive(app_wgts->w_pacf_button, FALSE);
    int16_t* pacf = (int16_t*)calloc(number, sizeof(int16_t));/*массив значений ПАКФ*/
    int16_t Umin = 0, Umax = 0, nUmin = 0, nUmax = 0;
    char Exp[7] = {0};
    char AbsExp[7] = {0};
    char Umi[20] = {0};
    char Uma[20] = {0};
    char Sigm[7] = {0};
    char AbsSigm[7] = {0};
    char MaxP[7] = {0};
    char AvrP[7] = {0};

    PACF((int8_t*)PA_Sequence, number, pacf);/*Расчёт ПАКФ*/

    for (uint16_t k = 1; k < number; ++k)
	{
		if (pacf[k] > Umax)
		{
			Umax = pacf[k];
		}
	}
	nUmax = CountD(pacf, number, Umax);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n ************ПАКФ************ ",-1);
	gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Максимальный боковой выброс : \n",-1);
    sprintf(Uma, " %d - %d раз(а)",Umax,nUmax);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,Uma,-1);

	for (uint16_t s  = 1; s < number; ++s)
	{
		if (pacf[s] < Umin)
		{
			Umin = pacf[s];
		}
	}
	nUmin = CountD(pacf, number, Umin);
	gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Минимальный боковой выброс : \n",-1);
    sprintf(Umi, " %d - %d раз(а)",Umin,nUmin);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,Umi,-1);

    double        Mu = ExpVal(pacf,number,false);
    double     absMu = ExpVal(pacf,number,true);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Математическое ожидание боковых выбросов : \n",-1);
    sprintf(Exp, " %.3f",Mu);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,Exp,-1);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Математическое ожидание модуля боковых выбросов : \n",-1);
    sprintf(AbsExp, " %.3f",absMu);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,AbsExp,-1);

    double  absSigma = SigmaVal(pacf,number,absMu);
    double     Sigma = SigmaVal(pacf,number,Mu);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> СКО боковых выбросов : \n",-1);
    sprintf(Sigm, " %.3f",Sigma);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,Sigm,-1);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> СКО модуля боковых выбросов : \n",-1);
    sprintf(AbsSigm, " %.3f",absSigma);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,AbsSigm,-1);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Максимальный нормированный уровень боковых выбросов : \n",-1);
    sprintf(MaxP, " %d%c",MaxPeakLevel(Umin,Umax,number),'%');
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,MaxP,-1);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Средний нормированный уровень боковых выбросов : \n",-1);
    sprintf(AvrP, " %.2f%c",AveragePeakLevel(absMu,number),'%');
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,AvrP,-1);

    /*ПОСТРОЕНИЕ ГРАФИКА ПАКФ*/
    int16_t * x = g_malloc(number * sizeof(int16_t));/*массив значений сдвигов для построения графика*/

    for (uint16_t k = 0; k < number; k++)
    {
      x[k] = k;
    }

    char slength[46];
    sprintf(slength, "set key title \"Длина: %d\" textcolor lt 8\n",number);

    FILE *pipe = popen("gnuplot -persist", "w"); // pipe - дескриптор канала (открыли поток)

    if (pipe != NULL)
    {

        /*Настройка gnuplot*/
        fprintf(pipe,  "set title font \"Helvetica,16\"\n");
        fprintf(pipe,  "set xlabel font \"Helvetica,11\"\n");
        fprintf(pipe,  "set ylabel font \"Helvetica,11\"\n");
        fprintf(pipe, "set title \"График периодической автокорреляционной функции\" textcolor lt 8\n");
        fprintf(pipe, slength);
        fprintf(pipe, "set mxtics 5\n");/*5 дополнительных делений между х[i] и х[i+1]*/
        fprintf(pipe, "set mytics 5\n");
        fprintf(pipe, "set zeroaxis \n");
        fprintf(pipe, "set border 3\n");/*Отображаем только x,y линии осей*/
        fprintf(pipe, "set xtics nomirror\n");/*Убираем штрихи на вспомогательных осях*/
        fprintf(pipe, "set ytics nomirror\n");
        fprintf(pipe, "set grid\n");/*Включили сетку*/
        fprintf(pipe, "set xlabel \"Значение сдвига, i\" textcolor  lt 8\n");
        fprintf(pipe, "set ylabel \"Значение ПАКФ, y\" textcolor lt 8\n");
        fprintf(pipe, "plot '-' u 1:2 w l lt 7 lw 1 title 'y[i]'\n");/*Строим график по точкам, соединяя их линией: (x[i]\ty[i]\n), толщина линии - lw,lt - цвет */

        for(uint32_t i =0; i < number; i++)
        {
            fprintf(pipe, "%d\t%d\n", x[i], pacf[i]);
        }

        fprintf(pipe, "%s\n", "e");
        pclose(pipe);/*Закрыли поток*/

    }

    free((void*)PA_Sequence);
    free(pacf);
    free(x);
}

/*#################################################
                Колбэк по нажатию кнопки "ААКФ" */

void aacf_button_clicked(GtkWidget *widget, main_widgets* app_wgts)
{
    gtk_widget_set_sensitive(app_wgts->w_aacf_button, FALSE);
    int16_t* aacf = (int16_t*)calloc(number, sizeof(int16_t));/*массив значений ААКФ*/
    int16_t Umin = 0, Umax = 0, nUmin = 0, nUmax = 0;
    char Exp[7] = {0};
    char AbsExp[7] = {0};
    char Umi[20] = {0};
    char Uma[20] = {0};
    char Sigm[7] = {0};
    char AbsSigm[7] = {0};
    char MaxP[7] = {0};
    char AvrP[7] = {0};

    AACF((int8_t*)AA_Sequence, number, aacf);/*Расчёт ПАКФ*/

    for (uint16_t k = 1; k < number; ++k)
	{
		if (aacf[k] > Umax)
		{
			Umax = aacf[k];
		}
	}
	nUmax = CountD(aacf, number, Umax);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n ************ААКФ************ ",-1);
	gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Максимальный боковой выброс : \n",-1);
    sprintf(Uma, " %d - %d раз(а)",Umax,nUmax);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,Uma,-1);


	for (uint16_t s  = 1; s < number; ++s)
	{
		if (aacf[s] < Umin)
		{
			Umin = aacf[s];
		}
	}
	nUmin = CountD(aacf, number, Umin);
	gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Минимальный боковой выброс : \n",-1);
    sprintf(Umi, " %d - %d раз(а)",Umin,nUmin);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,Umi,-1);

    double        Mu = ExpVal(aacf,number,false);
    double     absMu = ExpVal(aacf,number,true);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Математическое ожидание боковых выбросов : \n",-1);
    sprintf(Exp, " %.3f",Mu);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,Exp,-1);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Математическое ожидание модуля боковых выбросов : \n",-1);
    sprintf(AbsExp, " %.3f",absMu);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,AbsExp,-1);

    double  absSigma = SigmaVal(aacf,number,absMu);
    double     Sigma = SigmaVal(aacf,number,Mu);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> СКО боковых выбросов : \n",-1);
    sprintf(Sigm, " %.3f",Sigma);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,Sigm,-1);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> СКО модуля боковых выбросов : \n",-1);
    sprintf(AbsSigm, " %.3f",absSigma);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,AbsSigm,-1);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Максимальный нормированный уровень боковых выбросов : \n",-1);
    sprintf(MaxP, " %d%c",MaxPeakLevel(Umin,Umax,number),'%');
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,MaxP,-1);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Средний нормированный уровень боковых выбросов : \n",-1);
    sprintf(AvrP, " %.2f%c",AveragePeakLevel(absMu,number),'%');
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,AvrP,-1);

	/*ПОСТРОЕНИЕ ГРАФИКА AАКФ*/
    int16_t * x = g_malloc(number* sizeof(int16_t));/*массив значений сдвигов для построения графика*/

    for (uint16_t k = 0; k < number; k++)
    {
      x[k] = k;
    }

     char slength[46];
     sprintf(slength, "set key title \"Длина: %d\" textcolor lt 8\n",number);


    FILE *pipe = popen("gnuplot -persist", "w"); // pipe - дескриптор канала (открыли поток)

    if (pipe != NULL)
    {

        /*Настройка gnuplot*/
        fprintf(pipe,  "set title font \"Helvetica,16\"\n");
        fprintf(pipe,  "set xlabel font \"Helvetica,11\"\n");
        fprintf(pipe,  "set ylabel font \"Helvetica,11\"\n");
        fprintf(pipe, "set title \"График апериодической автокорреляционной функции\" textcolor lt 8\n");
        fprintf(pipe, slength);
        fprintf(pipe, "set mxtics 5\n");/*5 дополнительных делений между х[i] и х[i+1]*/
        fprintf(pipe, "set mytics 5\n");
        fprintf(pipe, "set zeroaxis \n");
        fprintf(pipe, "set border 3\n");/*Отображаем только x,y линии осей*/
        fprintf(pipe, "set xtics nomirror\n");/*Убираем штрихи на вспомогательных осях*/
        fprintf(pipe, "set ytics nomirror\n");
        fprintf(pipe, "set grid\n");/*Включили сетку*/
        fprintf(pipe, "set xlabel \"Значение сдвига, i\" textcolor  lt 8\n");
        fprintf(pipe, "set ylabel \"Значение ААКФ, y\" textcolor lt 8\n");
        fprintf(pipe, "plot '-' u 1:2 w l lt 7 lw 1 title 'y[i]'\n");/*Строим график по точкам, соединяя их линией: (x[i]\ty[i]\n), толщина линии - lw,lt - цвет */

        for(uint32_t i =0; i < number; i++)
        {
            fprintf(pipe, "%d\t%d\n", x[i], aacf[i]);
        }

        fprintf(pipe, "%s\n", "e");
        pclose(pipe);/*Закрыли поток*/

    }
    free((void*)AA_Sequence);
    free(aacf);
    free(x);
}


/*#################################################
                Колбэк по нажатию кнопки "ПВКФ" */
void pvcf_button_clicked(GtkWidget *widget, main_widgets* app_wgts)
{
    gtk_widget_set_sensitive(app_wgts->w_pvcf_button, FALSE);

    int16_t* pvcf = (int16_t*)calloc(number, sizeof(int16_t));/*массив значений ПВКФ*/
    int16_t Umin = 0, Umax = 0, nUmin = 0, nUmax = 0;
    char Exp[7] = {0};
    char AbsExp[7] = {0};
    char Umi[20] = {0};
    char Uma[20] = {0};
    char Sigm[7] = {0};
    char AbsSigm[7] = {0};
    char MaxP[7] = {0};
    char AvrP[7] = {0};

    PVCF((int8_t*)PV_Sequence1, (int8_t*)PV_Sequence2, number, pvcf);/*Расчёт ПВКФ*/

	for (uint16_t k = 1; k < number; ++k)
	{
		if (pvcf[k] > Umax)
		{
			Umax = pvcf[k];
		}
	}
	nUmax = CountD(pvcf, number, Umax);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n ************ПВКФ************ ",-1);
	gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Максимальный боковой выброс : \n",-1);
    sprintf(Uma, " %d - %d раз(а)",Umax,nUmax);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,Uma,-1);


	for (uint16_t s  = 1; s < number; ++s)
	{
		if (pvcf[s] < Umin)
		{
			Umin = pvcf[s];
		}
	}
	nUmin = CountD(pvcf, number, Umin);
	gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Минимальный боковой выброс : \n",-1);
    sprintf(Umi, " %d - %d раз(а)",Umin,nUmin);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,Umi,-1);

    double        Mu = ExpVal(pvcf,number,false);
    double     absMu = ExpVal(pvcf,number,true);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Математическое ожидание боковых выбросов : \n",-1);
    sprintf(Exp, " %.3f",Mu);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,Exp,-1);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Математическое ожидание модуля боковых выбросов : \n",-1);
    sprintf(AbsExp, " %.3f",absMu);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,AbsExp,-1);

    double  absSigma = SigmaVal(pvcf,number,absMu);
    double     Sigma = SigmaVal(pvcf,number,Mu);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> СКО боковых выбросов : \n",-1);
    sprintf(Sigm, " %.3f",Sigma);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,Sigm,-1);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> СКО модуля боковых выбросов : \n",-1);
    sprintf(AbsSigm, " %.3f",absSigma);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,AbsSigm,-1);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Максимальный нормированный уровень боковых выбросов : \n",-1);
    sprintf(MaxP, " %d%c",MaxPeakLevel(Umin,Umax,number),'%');
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,MaxP,-1);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Средний нормированный уровень боковых выбросов : \n",-1);
    sprintf(AvrP, " %.2f%c",AveragePeakLevel(absMu,number),'%');
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,AvrP,-1);


	/*ПОСТРОЕНИЕ ГРАФИКА ПВКФ*/
    int16_t * x = g_malloc(number * sizeof(int16_t));/*массив значений сдвигов для построения графика*/

    for (uint16_t k = 0; k < number; k++)
    {
      x[k] =k;

    }

    char slength[46];
    sprintf(slength, "set key title \"Длина: %d\" textcolor lt 8\n",number);

    FILE *pipe = popen("gnuplot -persist", "w"); // pipe - дескриптор канала (открыли поток)

    if (pipe != NULL)
    {

        /*Настройка gnuplot*/
        fprintf(pipe,  "set title font \"Helvetica,16\"\n");
        fprintf(pipe,  "set xlabel font \"Helvetica,11\"\n");
        fprintf(pipe,  "set ylabel font \"Helvetica,11\"\n");
        fprintf(pipe, "set title \"График периодической взаимной корреляционной функции\" textcolor lt 8\n");
        fprintf(pipe, slength);
        fprintf(pipe, "set mxtics 5\n");/*5 дополнительных делений между х[i] и х[i+1]*/
        fprintf(pipe, "set mytics 5\n");
        fprintf(pipe, "set zeroaxis \n");
        fprintf(pipe, "set border 3\n");/*Отображаем только x,y линии осей*/
        fprintf(pipe, "set xtics nomirror\n");/*Убираем штрихи на вспомогательных осях*/
        fprintf(pipe, "set ytics nomirror\n");
        fprintf(pipe, "set grid\n");/*Включили сетку*/
        fprintf(pipe, "set xlabel \"Значение сдвига, i\" textcolor  lt 8\n");
        fprintf(pipe, "set ylabel \"Значение ПВКФ, y\" textcolor lt 8\n");
        fprintf(pipe, "plot '-' u 1:2 w l lt 7 lw 1 title 'y[i]'\n");/*Строим график по точкам, соединяя их линией: (x[i]\ty[i]\n), толщина линии - lw,lt - цвет */

        for(uint32_t i =0; i < number; i++)
        {
            fprintf(pipe, "%d\t%d\n", x[i], pvcf[i]);
        }

        fprintf(pipe, "%s\n", "e");
        pclose(pipe);/*Закрыли поток*/

    }

	free((void*)PV_Sequence1);
	free((void*)PV_Sequence2);
    free(pvcf);
    free(x);
}

/*#################################################
                Колбэк по нажатию кнопки "АВКФ" */
void avcf_button_clicked(GtkWidget *widget, main_widgets* app_wgts)
{
    gtk_widget_set_sensitive(app_wgts->w_avcf_button, FALSE);
    int16_t* avcf = (int16_t*)calloc(number, sizeof(int16_t));/*массив значений АВКФ*/
    int16_t Umin = 0, Umax = 0, nUmin = 0, nUmax = 0;
    char Exp[7] = {0};
    char AbsExp[7] = {0};
    char Umi[20] = {0};
    char Uma[20] = {0};
    char Sigm[7] = {0};
    char AbsSigm[7] = {0};
    char MaxP[7] = {0};
    char AvrP[7] = {0};

    AVCF((int8_t*)AV_Sequence1, (int8_t*)AV_Sequence2, number, avcf);/*Расчёт АВКФ*/

    for (uint16_t k = 1; k < number; ++k)
	{
		if (avcf[k] > Umax)
		{
			Umax = avcf[k];
		}
	}
	nUmax = CountD(avcf, number, Umax);

	gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n ************АВКФ************ ",-1);
	gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Максимальный боковой выброс : \n",-1);
    sprintf(Uma, " %d - %d раз(а)",Umax,nUmax);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,Uma,-1);

	for (uint16_t s  = 1; s < number; ++s)
	{
		if (avcf[s] < Umin)
		{
			Umin = avcf[s];
		}
	}
	nUmin = CountD(avcf, number, Umin);
	gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Минимальный боковой выброс : \n",-1);
    sprintf(Umi, " %d - %d раз(а)",Umin,nUmin);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,Umi,-1);

    double        Mu = ExpVal(avcf,number,false);
    double     absMu = ExpVal(avcf,number,true);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Математическое ожидание боковых выбросов : \n",-1);
    sprintf(Exp, " %.3f",Mu);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,Exp,-1);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Математическое ожидание модуля боковых выбросов : \n",-1);
    sprintf(AbsExp, " %.3f",absMu);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,AbsExp,-1);

    double  absSigma = SigmaVal(avcf,number,absMu);
    double     Sigma = SigmaVal(avcf,number,Mu);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> СКО боковых выбросов : \n",-1);
    sprintf(Sigm, " %.3f",Sigma);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,Sigm,-1);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> СКО модуля боковых выбросов : \n",-1);
    sprintf(AbsSigm, " %.3f",absSigma);
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,AbsSigm,-1);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Максимальный нормированный уровень боковых выбросов : \n",-1);
    sprintf(MaxP, " %d%c",MaxPeakLevel(Umin,Umax,number),'%');
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,MaxP,-1);

    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,"\n> Средний нормированный уровень боковых выбросов : \n",-1);
    sprintf(AvrP, " %.2f%c",AveragePeakLevel(absMu,number),'%');
    gtk_text_buffer_insert_at_cursor(app_wgts->w_output_buffer,AvrP,-1);

    /*ПОСТРОЕНИЕ ГРАФИКА АВКФ*/
	int16_t * x = g_malloc(number * sizeof(int16_t));/*массив значений сдвигов для построения графика*/

    for (uint16_t k = 0; k < number; k++)
    {
      x[k] = k;
    }

    char slength[46];
    sprintf(slength, "set key title \"Длина: %d\" textcolor lt 8\n",number);

    FILE *pipe = popen("gnuplot -persist", "w"); // pipe - дескриптор канала (открыли поток)

    if (pipe != NULL)
    {

        /*Настройка gnuplot*/
        fprintf(pipe,  "set title font \"Helvetica,16\"\n");
        fprintf(pipe,  "set xlabel font \"Helvetica,11\"\n");
        fprintf(pipe,  "set ylabel font \"Helvetica,11\"\n");
        fprintf(pipe, "set title \"График апериодической взаимной корреляционной функции\" textcolor lt 8\n");
        fprintf(pipe, slength);
        fprintf(pipe, "set mxtics 5\n");/*5 дополнительных делений между х[i] и х[i+1]*/
        fprintf(pipe, "set mytics 5\n");
        fprintf(pipe, "set zeroaxis \n");
        fprintf(pipe, "set border 3\n");/*Отображаем только x,y линии осей*/
        fprintf(pipe, "set xtics nomirror\n");/*Убираем штрихи на вспомогательных осях*/
        fprintf(pipe, "set ytics nomirror\n");
        fprintf(pipe, "set grid\n");/*Включили сетку*/
        fprintf(pipe, "set xlabel \"Значение сдвига, i\" textcolor  lt 8\n");
        fprintf(pipe, "set ylabel \"Значение АВКФ, y\" textcolor lt 8\n");
        fprintf(pipe, "plot '-' u 1:2 w l lt 7 lw 1 title 'y[i]'\n");/*Строим график по точкам, соединяя их линией: (x[i]\ty[i]\n), толщина линии - lw,lt - цвет */

        for(uint32_t i =0; i < number; i++)
        {
            fprintf(pipe, "%d\t%d\n", x[i], avcf[i]);
        }

        fprintf(pipe, "%s\n", "e");
        pclose(pipe);/*Закрыли поток*/

    }

	free((void*)AV_Sequence1);
	free((void*)AV_Sequence2);
    free(avcf);
    free(x);

}


/*#################################################
                Колбэк по закрытию главного окна*/
void main_destroy()
{
    gtk_main_quit();
}


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<unistd.h>
#include<Funktionsgenerator_staticlib.h>


char *file_name;
int option;
double frequenzy = 10;
double period;
double amplitude = 5;
double resolution = 10;
double rec_time = 5;


void help(void) {

    printf("Version 1.0 \n");
    printf("Autor: Fabian Hilbich\n");
    printf("Dieses Programm, gibt die Funktionswerte einer Rechteckspannung in die Konsole und in eine .txt Datei aus.\n");
    printf("Die Ausgabe erfolgt in form von Integerwerten, also nur Ganzzahlig, in Volt vom Oberen bis Unteren Pegel der gewünschten Amplitude . \n");
    printf("Zur Berechung können dem Programm folgende Werte übergeben werden:\n");
    printf("Optionen: \n");
    printf("-h	Hilfe \n");
    printf("-d	'DATEIPFAD' mit diesem Befehl muss der Dateipfad angegeben werden. \n");
    printf("-f	Frequenz in ganzen Hertz (Hz) (default 10Hz)\n");
    printf("-a	Amplitude in ganzen Volt (V) (default 5V) \n");
    printf("-t	Aufnahmezeit in sek (default 5 sek) \n");
    printf("-r	Auflösung des Signals pro Periode (default 10) \n");
}



int main (int argc,char *argv[]) {

    while((option = getopt(argc, argv, "h d: f: a: t: r: ")) != -1)
    {
        switch(option)
        {
        case 'h':
            help();
            break;
        case 'd':
            file_name = optarg;
            break;
        case 'f':
            frequenzy=atoi(optarg);
            printf("Frequenz: %.2f Hz\n", frequenzy);
            period=1.0/frequenzy;
            printf("Periodendauer: %.4f sek \n", period);
            break;
        case 'a':
            amplitude=atoi(optarg);
            printf("Amplitude: %.0f V \n", amplitude);
            break;
        case 't':
            rec_time=atoi(optarg);
            printf("Aufnahmezeit: %.2f sek \n", rec_time);
            break;
        case 'r':
            resolution=atoi(optarg);
            printf("Auflösung: %.0f increments \n", resolution);
            break;
        }
    }
    FILE *output_stream;
    output_stream = fopen(file_name, "w+");

    if (output_stream == NULL) // test for files not existing.
    {
        printf("Error! Datei nicht gefunden\n");
        exit(-1);
    }


    Funktionsgenerator(frequenzy,amplitude,resolution,rec_time, output_stream);


    fclose(output_stream);

    printf("Für Hilfe Programm mit -h ausführen. \n");

    return 0;
}
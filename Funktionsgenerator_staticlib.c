#include<stdio.h>
#include<math.h>
#include<stdlib.h>


void Funktionsgenerator(double frequenzy, double amplitude,double resolution, double rec_time, FILE *output_stream) {


    int out_value;
    double out_time = 0;
    double period = (1.0/frequenzy);
    double step_width = (period/resolution);
    int increments_upper_amp = (period/step_width)/2;
    int increments_lower_amp = (period/step_width)/2;

    while (rec_time >= 0) {
        for (int i=1 ; i<=increments_lower_amp ; ++i) {
            out_value = amplitude;
            printf("%.4f s        %i V \n",out_time,out_value);
            fprintf(output_stream, "%.4f s        %i V \n",out_time,out_value);
            out_time = out_time + step_width;
            rec_time = (rec_time-step_width);
        }
        for (int i=1 ; i<=increments_lower_amp ; ++i) {
            out_value = (amplitude*-1.0);
            printf("%.4f s       %i V \n",out_time,out_value);
            fprintf(output_stream, "%.4f s       %i V \n",out_time,out_value);
            out_time = out_time + step_width;
            rec_time = (rec_time-step_width);
        }

    }
    return;
}

/*!
    \author Beke János
    \details Megpróbálunk egy felfüggesztést imitálni.
    \param
*/

#include <stdio.h> // define the header file

#define MAXBUFLEN 1000000

/*!
    \brief Általános függvénydefiníció
    \param x : független változó (vízszintes tengely.)
*/
typedef float (*Operation)(float x);

const float g = 9.81;

const float m_wheel = 20;
const float m_chassis = 480;

/*!
    \brief elemi időegység
*/
float d_t = 0.01;
/*!
    \brief a függvény kezdeti és végső ideje.
*/
float t_0 = 0;
float t_e = 10;

/*
Függőleges irányú sebesség
*/
float v_vert;

/* A függőleges irányú erő (lengés)csillapítási összetevője. EZ a függőleges irányú
sebességtől függ
*/

float f_vert;

/* A függőleges irányú elmozdulás.
 */
float v_dist;

// A függőleges irányú erő rugóeró összetevője.
float F_rugo;

/* A függőleges irányú elmozdulás és a kifejtett erő függvénye. Rugó.
Most a legegyszerűbb, egyenes arányosság a benyomódás és a rugóerő között.
 */

float f_vert_per_v_dist(float v_dist)
{
    return v_dist * 200;
}

float U_spring(float k, float x)
{
    return (0.5 * k * (x * x));
}

/*
A függőleges irányú sebesség-erő függvényének definiálása. Lengéscsillapító.
Egyenes arányosság a függőleges sebesség és a visszatartó erő között.
*/

float f_vert_per_v_vert(float v_vert)
{
    return v_vert * 20;
}

/*!
Sebesség kiszámítása. */
float v(float s_vert, float d_t)
{
    return (s_vert / d_t);
}

const char *roadfileName = "fekvorendor.txt";

const char *outfile_name = "resfekvorendor.csv";

float roadbuffer[MAXBUFLEN];

int main()
{
    FILE *roadfile;
    float F_csill;
    float F_rugo;
    float F_grav = m_chassis * g;
    float F_all;
    int t_e_int;

    printf("Suspension program:\n");

    printf("Load %s file.\n", roadfileName);

    roadfile = fopen(roadfileName, "r");
    if (roadfile == NULL)
    {
        printf("Nem olvasható be %s", roadfileName); // print the statement.
        return 1;
    }

    fscanf(roadfile, "%f", &t_e);
    t_e_int = t_e;

    float next_float;

    /*!
        \brief Beolvasás a roadbufferbe.
    */

    for (int t = 0; t < t_e; t++)
    {
        fscanf(roadfile, "%f", &next_float);
        roadbuffer[t] = next_float;
        printf("t: data %f\n", roadbuffer[t]);
    }

    fclose(roadfile);

    FILE *outfile;
    outfile = fopen(outfile_name, "w+");
    if (outfile == NULL)
    {
        printf("Nem hozható létre %s", outfile_name); // print the statement.
        return 1;
    }

    fprintf(outfile, "IDŐ, ÚTX, DELTAX, FX\n");

    float delta_x;

    for (int i = 1; i < t_e; i++)
    {

        delta_x = roadbuffer[i] - roadbuffer[i - 1];
        float v_x = v(delta_x, 1);
        F_csill = f_vert_per_v_vert(v_x);
        F_rugo = f_vert_per_v_dist(delta_x);
        F_all = F_csill + F_rugo + F_grav;
        fprintf(outfile, " %d, %f, %f, %f\n", i, roadbuffer[i], delta_x, F_all);
    }

    fclose(outfile);
}

// A felfüggesztés
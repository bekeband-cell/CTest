
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
 */

float f_vert_per_v_dist(float v_dist)
{
    return v_dist * 0.01;
}

/*
A függőleges irányú sebesség-erő függvényének definiálása. Lengéscsillapító.
*/

float f_vert_per_v_vert(float v_vert)
{
    return v_vert * 0.1;
}

/*!
Sebesség kiszámítása. */
float v(float s_vert, float d_t)
{
    return (s_vert / d_t);
}

const char *roadfileName = "fekvorendor.txt";

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

    for (int t = 0; t < t_e; t++)
    {
        //        s_vert =
        //            F_csill = f_vert_per_v_vert(v(s_vert, d_t));
        fscanf(roadfile, "%f", &roadbuffer[t]);
    }

    for (int i = 0; i < t_e; i++)
    {
        printf("%f\n", roadbuffer[i]);
    }

    fclose(roadfile);
}

// A felfüggesztés

/*!
    \author Beke János
    \details Megpróbálunk egy felfüggesztést imitálni.
    \param
*/

#include <stdio.h> // define the header file

/*!
    \brief Általános függvénydefiníció
    \param x : független változó (vízszintes tengely.)
*/
typedef float (*Operation)(float x);

const float g = 9.81;

const float m_wheel = 20;
const float m_chassis = 480;

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

// Ez a karosszéria súlyereje.
float F_grav;

/* A függőleges irányú elmozdulás és a kifejtett erő összefüggésének definiálása.
 */

float f_vert_per_v_dist(float v_dist)
{
    return v_dist * 0.01;
}

/*
A függőleges irányú sebesség függvényének definiálása.
*/

float f_vert_per_v_vert(float v_vert)
{
    return v_vert * 0.1;
}

int main()
{
    F_grav = m_chassis * g;
    printf("Suspension program:\n");
    printf("F_grav = %f\n", F_grav);
}

// A felfüggesztés
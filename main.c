#include <stdio.h> // define the header file

/*! \brief Osszetett_BSc_MSc_feladat_2022_v2.pdf
  4.2.1 példa
*/

const int max_sample = 100;

float v_0 = 8;      // Kezdeti sebesség     (m/s)
float F_e = 0.1;    // A testre ható erő    (N : kgm/s2)
float m = 0.005;    // A test tömege (kg)
float startx = 0.1; // A kezdeti pozícója a testnek.
float d_t = 0.01;
float max_t = 1.2;

float v_t; // Sebesség (eredmény)  (m/s)
float a_m; // A test gyorsulása. (kgm/s2/kg : m/s2)
float x_t; // Elmozdulás

/*!
    float getnextv(float m, float F, float v_prev)
    A sebességfüggvény következő értéke.
  \param m  float tomeg
  \param F  float gyorsitoero
  \param v_prev float aktuális sebesség
  \return A test sebessége, amelyre a t idő elteltével szert tesz.
*/

float getnextv(float t, float m, float F)
{
  return (((F / m) * t));
}

/*!
    float getnextx(float t, float m, float F, float v_prev)
    Az elmozdulásfüggvény következő értéke.
  \param t  float ido
  \param m  float tomeg
  \param F  float gyorsitoero
  \param v_prev float
  \return A test elmozdulása t idő alatt.
*/

float getnextx(float t, float v)
{
  return ((1.0 / 2.0) * v * t);
}

int main() // define the main function
{

  const char *outfile_name = "result.csv";

  printf("Welcome to mathematic examples.\n"); // print the statement.

  FILE *outfile;
  outfile = fopen(outfile_name, "w+");
  if (outfile == NULL)
  {
    printf("Nem hozható létre %s", outfile_name); // print the statement.
    return 1;
  }

  fprintf(outfile, "TIME  VEL LONG.\n");

  /*
    v_0-lal indítunk.
    */

  float v = v_0;
  float v_next;
  float x_next;
  float st_v0 = 0;
  x_t = startx;

  for (float i = 0; i < max_t; i += d_t)
  {
    fprintf(outfile, " %f, %f, %f, %f\n", i, v, x_t, st_v0);
    v_next = getnextv(d_t, m, F_e);

    x_next = ((1.0 / 2.0) * (F_e / m) * (d_t * d_t)) + (v * d_t) + x_t;
    v += v_next;

    //    x_next = getnextx(d_t, v);
    x_t = x_next;
    st_v0 += v_0 * d_t;
  }

  fclose(outfile);
  printf("End of mathematic examples.\n"); // print the statement.
  return 0;
}
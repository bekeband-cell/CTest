#include <stdio.h> // define the header file

/*! \brief Osszetett_BSc_MSc_feladat_2022_v2.pdf
  4.2.1 példa
*/

float v_0 = 8;      // Kezdeti sebesség     (m/s)
float F_e = 0.1;    // A testre ható erő    (N : kgm/s2)
float m = 0.005;    // A test tömege (kg)
float startx = 0.1; // A kezdeti pozícója a testnek.
float d_t = 0.01;
float min_t = 1.1;
float max_t = 1.2;

float v_t; // Sebesség (eredmény)  (m/s)
float a_m; // A test gyorsulása. (kgm/s2/kg : m/s2)
float x_t; // Elmozdulás

/*!
    float getnextv(float t, float m, float F)
    A sebességfüggvény következő értéke.
  \param t  float idő (tizedes)
  \param F  float gyorsitoero
  \param m  a gyorsítandó tömeg.
  \return A test sebességnövekedése, amelyre a t idő elteltével szert tesz.
*/

float getnextv(float t, float m, float F)
{
  return (((F / m) * t));
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

  // idő: mp-ben, sebesség, kezdősebességből adódó távolság, gyorsolásból adódó távolság,
  // össz. távolság

  fprintf(outfile, "IDŐ, SEBESSÉG, KEZD_TÁVOLSÁG, GYORS_TÁVOLSÁG, ÖSSZ_TÁVOLSÁG\n");

  /*
    v_0-lal indítunk.
    */

  float v = v_0;
  float v_next;
  float x_next;
  float st_v0 = 0;
  float x_all;
  x_t = startx;

  for (float i = min_t; i < max_t; i += d_t)
  {
    x_all = st_v0 + x_t;
    fprintf(outfile, " %f, %f, %f, %f, %f\n", i, v, st_v0, x_t, x_all);
    // A következő sebesség kiszámítása.
    v_next = getnextv(d_t, m, F_e);
    // A következő távolság kiszámítása. (növekmény)
    x_next = (((1.0 / 2.0) * (F_e / m) * (d_t * d_t)) + (v * d_t) + x_t);
    // A következő sebesség az előző és a növekmény.
    v += v_next;
    st_v0 += v_0 * d_t;
    x_t = x_next;
  }

  fclose(outfile);
  printf("End of mathematic examples.\n"); // print the statement.
  return 0;
}
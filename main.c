#include <stdio.h> // define the header file

/*! \brief Osszetett_BSc_MSc_feladat_2022_v2.pdf
  4.2.1 példa
*/

float v_0 = 10; // Kezdeti sebesség     (m/s)
float F_e = 50; // A testre ható erő    (N : kgm/s2)
float m = 20;   // A test tömege (kg)

float v_t; // Sebesség (eredmény)  (m/s)
float a_m; // A test gyorsulása. (kgm/s2/kg : m/s2)
float x_t; // Elmozdulás

/*!
    float getnextv(float t, float m, float F, float v_prev)
    A sebességfüggvény következő értéke.
  \param t  float ido
  \param m  float tomeg
  \param F  float gyorsitoero
  \param v_prev float aktuális sebesség
  \return A test sebessége, amelyre a t idő elteltével szert tesz.
*/
float getnextv(float t, float m, float F, float v_prev)
{
}

int main() // define the main function
{

  const char *outfile_name = "result.csv";

  printf("Welcome to mathematic examples.\n"); // print the statement.

  FILE *outfile;
  outfile = fopen(outfile_name, "w");
  if (outfile == NULL)
  {
    printf("Nem hozható létre %s", outfile_name); // print the statement.
    return 1;
  }

    fprintf(outfile, "Out to outfile text.\n");

  fclose(outfile);
  printf("End of mathematic examples.\n"); // print the statement.
  return 0;
}
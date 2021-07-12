#include "rgb_matrix.h"
#include "rgb_stuff.h"

/* MAKE SURE TO ADD THE LINE "SRC += rgb_stuff.c" IN YOUR rules.mk FILE! */

/* Color setting funcs--Assume the index arrays have -1 as a sentinel */
void loop_color_set(const int indices[], uint8_t color[]) {
  for (int i = 0; indices[i] != -1 ; i++) 
    rgb_matrix_set_color(indices[i], color[0], color[1], color[2]);
}

void l_c_s_wrapper(const int per_layer_ind[][NUM_LIGHTS], uint8_t palette[][NUM_RGB]) {
  for (int i = 0; i < NUM_FG; i++)
    loop_color_set(per_layer_ind[i], palette[i]);
}

/* Code to change specified led colors on layer change, using the above function */
void rgb_matrix_indicators_user(void) {
  
  uint8_t palette[NUM_FG + 1][NUM_RGB];

  for (int i = 0; i <= NUM_FG; i++)
    for (int j = 0; j < 3; j++)
      palette[i][j] = NORM[i][j]; // NORM is the palette defined in rgb_stuff.h

  /* Set background. Assumes background is the last defined color in the palette */
  for (int i = 0; i < NUM_LIGHTS; i++) 
    rgb_matrix_set_color(i, palette[NUM_FG][0], palette[NUM_FG][1], palette[NUM_FG][2]);

  /* USER-RELEVANT PART STARTS HERE 
   * 
   * Set colormaps on layer change.
   * 
   * The default case corresponds to the BASE colormap from rgb_stuff.h.
   * To assign additional colormaps to different layers, add entries like
   * the following before the default case:
   *
   *   case <_KEYMAP_LAYER_NAME>:
   *     l_c_s_wrapper(<COLORMAP_NAME>, palette);
   *     break;
   *   case <_ANOTHER_KEYMAP_LAYER_NAME>:
   *     l_c_s_wrapper(<ANOTHER_COLORMAP_NAME>, palette);
   *     break;
   *
   *   ...
   *
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
  switch (biton32(layer_state)) {
    default:
      l_c_s_wrapper(ABC, palette);
      break;
  }
}
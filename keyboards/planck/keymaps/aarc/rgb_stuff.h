#ifndef RGB_STUFF_H
#define RGB_STUFF_H

#define NUM_LIGHTS 49
#define NUM_FG 3 // Number of foreground colors 
#define NUM_RGB 3

/* MAKE SURE TO ADD THE LINE "SRC += rgb_stuff.c" IN YOUR rules.mk FILE! */

/* ,-----------------------------------------------------------.
 * |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | 11 |
 * |----+----+----+----+----+----+----+----+----+----+----+----|
 * | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 |
 * |----+----+----+----+----+----+----+----+----+----+----+----|
 * | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 | 32 | 33 | 34 | 35 |
 * |----+----+----+----+----+----+----+----+----+----+----+----|
 * | 36 | 37 | 38 | 39 | 40 | 41,42,43| 44 | 45 | 46 | 47 | 48 |
 * `-----------------------------------------------------------'
 *
 * Set indices below of LED's you want for each colormap.
 *
 * For each layer, the same indices are used for both regular and dark palettes.  
 * Note: use 41 and 43 for GRID layout, 42 for MIT.
 * 
 * I //THINK// it's possible to add more foreground colors by altering NUM_FG and appending the 
 * arrays below, but this is untested. 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* Set R, G, and B of the COLORS to be used. For example, RED is {0xff, 0x00, 0x00} */
const uint8_t NORM[][NUM_RGB] = {
    {0xff, 0x60, 0x00}, // Color A
    {0xff, 0x00, 0x34}, // Color B
    {0x80, 0x00, 0xff}, // Color C
    {0x00, 0x00, 0x00}  // Background
};

/* Set colormap INDICES below.
 *
 * For each colormap you define, you need to create an array containing the indices you want
 * each color to apply to. 
 *
 * Each array MUST end with a -1, or else the setting functions won't loop. For example:
 *
 *   const int ABC[][NUM_LIGHTS] = {
 *     {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, -1},
 *     {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, -1},
 *     {24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, -1}
 *   };
 *
 * The above entry will create a colormap called ABC, which applies color A to the top row, 
 * color B to the next row, color C to the next row, and leaves Background for the bottom row.
 *
 * Any LED whose index doesn't appear in the array for a given colormap will automatically get the 
 * background color. For example, if your background color is RED and your array is empty (save 
 * for -1's), then the whole board will light up RED.
 *
 * Having the background color be BLACK (off) is probably what you want, otherwise it would require
 * special processing to disable a given LED. 
 *
 * Since this code is mostly thrown together, I don't yet have a clean way of handling adding
 * layers. You have to go into rgb_stuff.c and add the appropriate case. See that file for info.
 * Look for the comment // USER-RELEVANT PART STARTS HERE //
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* Add elements to the arrays to get started: */
const int BASE[][NUM_LIGHTS] = {
 {-1},
 {-1},
 {-1}
};

#endif
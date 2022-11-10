/* @source lab_4 ****************************************************
**
 * This lab is to introduce the micro:Bit, how to compile programs and 
 * flash the unit and some basic programming.
 *
 * @author Copyright (C) 2022  Cameron.C
 * @version 1.0   __description of version__
 * @modified __EditDate__  __EditorName__  __description of edit__
 * @@
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
**
******************************************************************************/


/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */

#include "MicroBit.h"

/* ==================================================================== */
/* ============================ constants ============================= */
/* ==================================================================== */

/* Grid borders */
const int rightBorder = 4;
const int topBorder = 0;
const int leftBorder = 0;
const int bottomBorder = 4;

/* ==================================================================== */
/* ======================== global variables ========================== */
/* ==================================================================== */

/* LED locations */
int xLoc = 0;
int yLoc = 0;

/* Hit information */
int xBorderHit = 0;
int yBorderHit = 0;

/* Inertia direction */
int xInertia = 1;
int yInertia = 1;

/* ==================================================================== */
/* ============================== data ================================ */
/* ==================================================================== */

MicroBit uBit;

/* Messages */
ManagedString errorMessage("Sorry there is an error");

/* ==================================================================== */
/* ==================== function prototypes =========================== */
/* ==================================================================== */

void basicFunction();
void taskProgramOne();
void taskProgramTwo();
void taskProgramThree();
int gToPix(int g);
int levelDevice(int g);

/* @prog __lab_4 ****************************************************
**
 * Task 1:
 * Modify this program to move the blinking led around the display.
 * Task 2:
 * Access readings and move a pixel on the display as a type of tiltmeter.
 * Task 3:
 * Produce a program that moves the pixel as if it had inertia,
**
******************************************************************************/

int main() 
{
    /* Initialse Micro:Bit */
    uBit.init();
    uBit.display.setDisplayMode(DISPLAY_MODE_GREYSCALE);

    // taskProgramOne();
    // taskProgramTwo();
    taskProgramThree();
}

/* ==================================================================== */
/* ============================ functions ============================= */
/* ==================================================================== */

void basicFunction()
{
    while(1)
    {
        uBit.display.image.setPixelValue(2, 2, 255);
        uBit.sleep(1000);
        uBit.display.image.setPixelValue(2, 2, 0);
        uBit.sleep(1000);  
    }
};

void taskProgramOne()
{
    while(1)
    {
        /* Blink at a given location */
        uBit.display.image.setPixelValue(xLoc, yLoc, 255);
        uBit.sleep(500);
        uBit.display.image.setPixelValue(xLoc, yLoc, 0);
        uBit.sleep(500);
        
        /* Go right */
        if (xLoc < rightBorder && yLoc == topBorder) {
            xLoc ++;
        /* Go down */
        } else if (xLoc == rightBorder && yLoc < bottomBorder) {
            yLoc ++;
        /* Go left */
        } else if (xLoc > leftBorder && yLoc == bottomBorder) {
            xLoc --;
        /* Go up */
        } else if (xLoc == leftBorder && yLoc > topBorder) {
            yLoc --;
        } else {
            uBit.display.scroll(errorMessage);
        }
        
    }
};

void taskProgramTwo()
{
    while(1)
    {
        /* Query the accelerometer's X and Y values */
        int px = gToPix(uBit.accelerometer.getX());
        int py = gToPix(uBit.accelerometer.getY());
        
        /* Clear the grid, display the points */
        uBit.display.image.clear();
        uBit.display.image.setPixelValue(px, py, 255);

        uBit.sleep(100);
    }
};

void taskProgramThree()
{
    while(1)
    {
        /* Query the accelerometer's X and Y values */
        int px = gToPix(uBit.accelerometer.getX());
        int py = gToPix(uBit.accelerometer.getY());
        
        /* Clear the grid, display the points */
        uBit.display.image.clear();
        uBit.display.image.setPixelValue(px, py, 255);

        uBit.sleep(100);
        
        /* Wall boundaries */
        /* Check if hit left/right wall */
        if (px == leftBorder || px == rightBorder) {
            xBorderHit = 1;
            yBorderHit = 0;
            xInertia *= -1;
        } else if (py == topBorder || py == bottomBorder) {
            xBorderHit = 0;
            yBorderHit = 1;
            xInertia *= -1;
        } else {
            continue;
        }
        
        
        /* Need if statment to check level */
        /* "keeps moving when the micro:Bit returns to level." */
        if (levelDevice(uBit.accelerometer.getX()) == 1 && levelDevice(uBit.accelerometer.getY()) == 1) {        
            /* Slow it down due to the interiia of pix */
            /* X dir */
            if (px >= leftBorder && px <= rightBorder && xBorderHit) {
                px += xInertia;
            }
            /* Y dir */
            if (py >= topBorder && py <= bottomBorder && yBorderHit) {
                py += yInertia;
            }
        }
        
        /* Clear the grid, display the points */
        uBit.display.image.clear();
        uBit.display.image.setPixelValue(px, py, 255);

        uBit.sleep(100);
    }
};

/* Accelerometer (Without Events) */
int gToPix(int g)
{
    int v = 2;
    if ( g < -200) v--;
    if ( g < -500) v--;
    if ( g > 200) v++;
    if ( g > 500) v++;

    return v;
};

int levelDevice(int g)
{
    /* Check for level */
    /* -200 < g < 200 */
    if (g > -200 && g < 200){
        return 1;
    } else {
        return 0;
    }
};


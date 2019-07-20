/**
  ******************************************************************************
  * @file    main.c
  * @author  XinLi
  * @version v1.0
  * @date    13-September-2018
  * @brief   Main program body.
  ******************************************************************************
  * @attention
  *
  * <h2><center>Copyright &copy; 2018 XinLi</center></h2>
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <https://www.gnu.org/licenses/>.
  *
  ******************************************************************************
  */

/* Header includes -----------------------------------------------------------*/
#include "LinearFunction.h"
#include <stdio.h>
#include <windows.h>

/* Macro definitions ---------------------------------------------------------*/
/* Type definitions ----------------------------------------------------------*/
typedef struct
{
  float x;
  float y;
}Point;

/* Variable declarations -----------------------------------------------------*/
/* Variable definitions ------------------------------------------------------*/
/* Function declarations -----------------------------------------------------*/
/* Function definitions ------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None.
  * @return None.
  */
int main(void)
{
  for(;;)
  {
    Point pointA = {.x = 2.5f, .y = 3.4f};
    Point pointB = {.x = 5.6f, .y = 4.3f};
    Point pointC = {.x = 7.8f, .y = 1.5f};
    Point pointD = {.x = 4.6f};
    Point pointE = {.y = 9.7f};
    
    LinearFunction lineAB = {0};
    LinearFunction lineAC = {0};
    LinearFunction lineCD = {0};
    
    LinearFunction_TwoPointInit(&lineAB, pointA.x, pointA.y, pointB.x, pointB.y);
    LinearFunction_TwoPointInit(&lineAC, pointA.x, pointA.y, pointC.x, pointC.y);
    LinearFunction_PointSlopeInit(&lineCD, pointC.x, pointC.y, LinearFunction_GetSlope(&lineAB));
    
    pointD.y = LinearFunction_GetOrdinate(&lineCD, pointD.x);
    pointE.x = LinearFunction_GetAbscissa(&lineAC, pointE.y);
    
	printf("A(%f, %f)\t", pointA.x, pointA.y);
	printf("B(%f, %f)\t", pointB.x, pointB.y);
	printf("C(%f, %f)\t", pointC.x, pointC.y);
	printf("D(%f, %f)\t", pointD.x, pointD.y);
	printf("E(%f, %f)\n", pointE.x, pointE.y);
    
	printf("AB(y = %fx + %f)\t", LinearFunction_GetSlope(&lineAB), LinearFunction_GetIntercept(&lineAB));
	printf("AC(y = %fx + %f)\t", LinearFunction_GetSlope(&lineAC), LinearFunction_GetIntercept(&lineAC));
	printf("CD(y = %fx - %f)\n", LinearFunction_GetSlope(&lineCD), LinearFunction_GetIntercept(&lineCD) * (-1.0f));
    
	printf("|AB| = %f\t", LinearFunction_PointToPointDistance(pointA.x, pointA.y, pointB.x, pointB.y));
	printf("∠BAC = %f rad\n", LinearFunction_TwoLineAngle(&lineAB, &lineAC));
	printf("点 E 到直线 AB 的距离等于 %f\n", LinearFunction_PointToLineDistance(&lineAB, pointE.x, pointE.y));
    printf("直线 AB 到直线 CD 的距离等于 %f\n\n", LinearFunction_LineToLineDistance(&lineAB, &lineCD));
    
    Sleep(5000);
  }
}

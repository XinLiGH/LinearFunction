/**
  ******************************************************************************
  * @file    LinearFunction.h
  * @author  XinLi
  * @version v1.0
  * @date    13-September-2018
  * @brief   Header file for LinearFunction.c module.
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

#ifndef __LINEARFUNCTION_H
#define __LINEARFUNCTION_H

#ifdef __cplusplus
extern "C" {
#endif

/* Header includes -----------------------------------------------------------*/
/* Macro definitions ---------------------------------------------------------*/
/* Type definitions ----------------------------------------------------------*/
typedef struct
{
  float slope;
  float intercept;
}LinearFunction;

/* Variable declarations -----------------------------------------------------*/
/* Variable definitions ------------------------------------------------------*/
/* Function declarations -----------------------------------------------------*/
void LinearFunction_PointSlopeInit(LinearFunction *function, float x, float y, float slope);
void LinearFunction_TwoPointInit(LinearFunction *function, float x1, float y1, float x2, float y2);

void LinearFunction_SetSlope(LinearFunction *function, float slope);
void LinearFunction_SetIntercept(LinearFunction *function, float intercept);

float LinearFunction_GetSlope(LinearFunction *function);
float LinearFunction_GetIntercept(LinearFunction *function);

float LinearFunction_GetAbscissa(LinearFunction *function, float y);
float LinearFunction_GetOrdinate(LinearFunction *function, float x);

float LinearFunction_PointToPointDistance(float x1, float y1, float x2, float y2);
float LinearFunction_PointToLineDistance(LinearFunction *function, float x, float y);
float LinearFunction_LineToLineDistance(LinearFunction *function1, LinearFunction *function2);
float LinearFunction_TwoLineAngle(LinearFunction *function1, LinearFunction *function2);

/* Function definitions ------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __LINEARFUNCTION_H */

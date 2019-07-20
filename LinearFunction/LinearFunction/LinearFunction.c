/**
  ******************************************************************************
  * @file    LinearFunction.c
  * @author  XinLi
  * @version v1.0
  * @date    13-September-2018
  * @brief   Linear function module source file.
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
#include <math.h>

/* Macro definitions ---------------------------------------------------------*/
/* Type definitions ----------------------------------------------------------*/
/* Variable declarations -----------------------------------------------------*/
/* Variable definitions ------------------------------------------------------*/
/* Function declarations -----------------------------------------------------*/
/* Function definitions ------------------------------------------------------*/

/**
  * @brief  Linear function point slope initialize.
  * @param  [in] function: Linear function data type.
  * @param  [in] x:        The abscissa of the point.
  * @param  [in] y:        The ordinate of the point.
  * @param  [in] slope:    Linear function slope.
  * @return None.
  */
void LinearFunction_PointSlopeInit(LinearFunction *function, float x, float y, float slope)
{
  function->slope     = slope;
  function->intercept = y - x * slope;
}

/**
  * @brief  Linear function two point initialize.
  * @param  [in] function: Linear function data type.
  * @param  [in] x1:       The abscissa of the point.
  * @param  [in] y1:       The ordinate of the point.
  * @param  [in] x2:       The abscissa of the point.
  * @param  [in] y2:       The ordinate of the point.
  * @return None.
  */
void LinearFunction_TwoPointInit(LinearFunction *function, float x1, float y1, float x2, float y2)
{
  function->slope     = (y2 - y1) / (x2 - x1);
  function->intercept = y1 - x1 * (y2 - y1) / (x2 - x1);
}

/**
  * @brief  Linear function set slope.
  * @param  [in] function: Linear function data type.
  * @param  [in] slope:    Linear function slope.
  * @return None.
  */
void LinearFunction_SetSlope(LinearFunction *function, float slope)
{
  function->slope = slope;
}

/**
  * @brief  Linear function set intercept.
  * @param  [in] function:  Linear function data type.
  * @param  [in] intercept: Linear function intercept.
  * @return None.
  */
void LinearFunction_SetIntercept(LinearFunction *function, float intercept)
{
  function->intercept = intercept;
}

/**
  * @brief  Linear function get slope.
  * @param  [in] function: Linear function data type.
  * @return Linear function slope.
  */
float LinearFunction_GetSlope(LinearFunction *function)
{
  return function->slope;
}

/**
  * @brief  Linear function get intercept.
  * @param  [in] function: Linear function data type.
  * @return Linear function intercept.
  */
float LinearFunction_GetIntercept(LinearFunction *function)
{
  return function->intercept;
}

/**
  * @brief  Linear function get abscissa.
  * @param  [in] function: Linear function data type.
  * @param  [in] y:        The ordinate of the point on the linear function.
  * @return The abscissa of the point on the linear function.
  */
float LinearFunction_GetAbscissa(LinearFunction *function, float y)
{
  return (y - function->intercept) / function->slope;
}

/**
  * @brief  Linear function get ordinate.
  * @param  [in] function: Linear function data type.
  * @param  [in] x:        The abscissa of the point on the linear function.
  * @return The ordinate of the point on the linear function.
  */
float LinearFunction_GetOrdinate(LinearFunction *function, float x)
{
  return function->slope * x + function->intercept;
}

/**
  * @brief  Point to point distance.
  * @param  [in] x1: The abscissa of the point.
  * @param  [in] y1: The ordinate of the point.
  * @param  [in] x2: The abscissa of the point.
  * @param  [in] y2: The ordinate of the point.
  * @return Point to point distance.
  */
float LinearFunction_PointToPointDistance(float x1, float y1, float x2, float y2)
{
  return hypotf(x1 - x2, y1 - y2);
}

/**
  * @brief  Point to line distance.
  * @param  [in] function: Linear function data type.
  * @param  [in] x:        The abscissa of the point.
  * @param  [in] y:        The ordinate of the point.
  * @return Point to line distance.
  */
float LinearFunction_PointToLineDistance(LinearFunction *function, float x, float y)
{
  return fabsf(function->slope * x - y + function->intercept) / hypotf(function->slope, -1.0f);
}

/**
  * @brief  Line to line distance.
  * @param  [in] function1: Linear function data type.
  * @param  [in] function2: Linear function data type.
  * @return Line to line distance.
  */
float LinearFunction_LineToLineDistance(LinearFunction *function1, LinearFunction *function2)
{
  if(function1->slope == function2->slope)
  {
    return fabsf(function1->intercept - function2->intercept) / hypotf(function1->slope, -1.0f);
  }
  else
  {
    return 0.0f;
  }
}

/**
  * @brief  Two line angle.
  * @param  [in] function1: Linear function data type.
  * @param  [in] function2: Linear function data type.
  * @return Two line angle, unit: rad.
  */
float LinearFunction_TwoLineAngle(LinearFunction *function1, LinearFunction *function2)
{
  return acosf(fabsf(function1->slope * function2->slope + 1.0f) / (hypotf(function1->slope, -1.0f) * hypotf(function2->slope, -1.0f)));
}

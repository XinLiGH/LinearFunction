# LinearFunction

线性函数，C语言方式实现。程序中涉及到线性函数的概念，详细介绍见维基百科[Linear function](https://en.wikipedia.org/wiki/Linear_function)。

## 开发环境

* 操作系统：Windows 10 专业版
* IDE：Visual Studio 2017 专业版

## API

* void LinearFunction_PointSlopeInit(LinearFunction *function, float x, float y, float slope)
* void LinearFunction_TwoPointInit(LinearFunction *function, float x1, float y1, float x2, float y2)
* void LinearFunction_SetSlope(LinearFunction *function, float slope)
* void LinearFunction_SetIntercept(LinearFunction *function, float intercept)
* float LinearFunction_GetSlope(LinearFunction *function)
* float LinearFunction_GetIntercept(LinearFunction *function)
* float LinearFunction_GetAbscissa(LinearFunction *function, float y)
* float LinearFunction_GetOrdinate(LinearFunction *function, float x)
* float LinearFunction_PointToPointDistance(float x1, float y1, float x2, float y2)
* float LinearFunction_PointToLineDistance(LinearFunction *function, float x, float y)
* float LinearFunction_LineToLineDistance(LinearFunction *function1, LinearFunction *function2)
* float LinearFunction_TwoLineAngle(LinearFunction *function1, LinearFunction *function2)

## 运行效果

![](https://github.com/XinLiGH/LinearFunction/raw/master/LinearFunction/LinearFunction/LinearFunction.jpg)

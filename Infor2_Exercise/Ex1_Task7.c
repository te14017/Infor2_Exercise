//
//  Ex1_Task7.c
//  Infor2_Exercise
//
//  Created by 谭特 on 17/2/25.
//  Copyright © 2017年 谭特. All rights reserved.
//

#include <stdio.h>
#include <math.h>

void printPair(double x, double y) {
    printf("(%f, %f)\n", x, y);
}

// diagonal from lower-left to upper-right
void printDiag1(double x, double y, double pace) {
    printPair(x+pace, y+pace);
    printPair(x+3*pace, y+pace);
    printPair(x+5*pace, y+pace);
    printPair(x+5*pace, y+3*pace);
    printPair(x+3*pace, y+3*pace);
    printPair(x+pace, y+3*pace);
    printPair(x+pace, y+5*pace);
    printPair(x+3*pace, y+5*pace);
    printPair(x+5*pace, y+5*pace);
}

// diagonal from upper-left to lower-right
void printDiag2(double x, double y, double pace) {
    printPair(x+pace, y-pace);
    printPair(x+3*pace, y-pace);
    printPair(x+5*pace, y-pace);
    printPair(x+5*pace, y-3*pace);
    printPair(x+3*pace, y-3*pace);
    printPair(x+pace, y-3*pace);
    printPair(x+pace, y-5*pace);
    printPair(x+3*pace, y-5*pace);
    printPair(x+5*pace, y-5*pace);
}

// diagonal from lower-right to upper-left
void printDiag3(double x, double y, double pace) {
    printPair(x-pace, y+pace);
    printPair(x-3*pace, y+pace);
    printPair(x-5*pace, y+pace);
    printPair(x-5*pace, y+3*pace);
    printPair(x-3*pace, y+3*pace);
    printPair(x-pace, y+3*pace);
    printPair(x-pace, y+5*pace);
    printPair(x-3*pace, y+5*pace);
    printPair(x-5*pace, y+5*pace);
}

// diagonal from upper-right to lower-left
void printDiag4(double x, double y, double pace) {
    printPair(x-pace, y-pace);
    printPair(x-3*pace, y-pace);
    printPair(x-5*pace, y-pace);
    printPair(x-5*pace, y-3*pace);
    printPair(x-3*pace, y-3*pace);
    printPair(x-pace, y-3*pace);
    printPair(x-pace, y-5*pace);
    printPair(x-3*pace, y-5*pace);
    printPair(x-5*pace, y-5*pace);
}


void drawHilbertCurveII(double x0, double y0, double xm, double ym, int iter) {
    double pace = fabs(x0-xm)/6;
    if(iter == 1) {
        if(x0 < xm && y0 < ym) {
            printDiag1(x0, y0, pace);
        }
        if(x0 < xm && y0 > ym) {
            printDiag2(x0, y0, pace);
        }
        if(x0 > xm && y0 < ym) {
            printDiag3(x0, y0, pace);
        }
        if(x0 > xm && y0 > ym) {
            printDiag4(x0, y0, pace);
        }
    } else {
        if(x0 < xm && y0 < ym) {
            drawHilbertCurveII(x0, y0, x0+2*pace, y0+2*pace, iter-1);
            drawHilbertCurveII(x0+2*pace, y0+2*pace, x0+4*pace, y0, iter-1);
            drawHilbertCurveII(x0+4*pace, y0, x0+6*pace, y0+2*pace, iter-1);
            drawHilbertCurveII(x0+6*pace, y0+2*pace, x0+4*pace, y0+4*pace, iter-1);
            drawHilbertCurveII(x0+4*pace, y0+4*pace, x0+2*pace, y0+2*pace, iter-1);
            drawHilbertCurveII(x0+2*pace, y0+2*pace, x0, y0+4*pace, iter-1);
            drawHilbertCurveII(x0, y0+4*pace, x0+2*pace, y0+6*pace, iter-1);
            drawHilbertCurveII(x0+2*pace, y0+6*pace, x0+4*pace, y0+4*pace, iter-1);
            drawHilbertCurveII(x0+4*pace, y0+4*pace, x0+6*pace, y0+6*pace, iter-1);
        }
        if(x0 < xm && y0 > ym) {
            drawHilbertCurveII(x0, y0, x0+2*pace, y0-2*pace, iter-1);
            drawHilbertCurveII(x0+2*pace, y0-2*pace, x0+4*pace, y0, iter-1);
            drawHilbertCurveII(x0+4*pace, y0, x0+6*pace, y0-2*pace, iter-1);
            drawHilbertCurveII(x0+6*pace, y0-2*pace, x0+4*pace, y0-4*pace, iter-1);
            drawHilbertCurveII(x0+4*pace, y0-4*pace, x0+2*pace, y0-2*pace, iter-1);
            drawHilbertCurveII(x0+2*pace, y0-2*pace, x0, y0-4*pace, iter-1);
            drawHilbertCurveII(x0, y0-4*pace, x0+2*pace, y0-6*pace, iter-1);
            drawHilbertCurveII(x0+2*pace, y0-6*pace, x0+4*pace, y0-4*pace, iter-1);
            drawHilbertCurveII(x0+4*pace, y0-4*pace, x0+6*pace, y0-6*pace, iter-1);
        }
        if(x0 > xm && y0 < ym) {
            drawHilbertCurveII(x0, y0, x0-2*pace, y0+2*pace, iter-1);
            drawHilbertCurveII(x0-2*pace, y0+2*pace, x0-4*pace, y0, iter-1);
            drawHilbertCurveII(x0-4*pace, y0, x0-6*pace, y0+2*pace, iter-1);
            drawHilbertCurveII(x0-6*pace, y0+2*pace, x0-4*pace, y0+4*pace, iter-1);
            drawHilbertCurveII(x0-4*pace, y0+4*pace, x0-2*pace, y0+2*pace, iter-1);
            drawHilbertCurveII(x0-2*pace, y0+2*pace, x0, y0+4*pace, iter-1);
            drawHilbertCurveII(x0, y0+4*pace, x0-2*pace, y0+6*pace, iter-1);
            drawHilbertCurveII(x0-2*pace, y0+6*pace, x0-4*pace, y0+4*pace, iter-1);
            drawHilbertCurveII(x0+4*pace, y0+4*pace, x0-6*pace, y0+6*pace, iter-1);
        }
        if(x0 > xm && y0 > ym) {
            drawHilbertCurveII(x0, y0, x0-2*pace, y0-2*pace, iter-1);
            drawHilbertCurveII(x0-2*pace, y0-2*pace, x0-4*pace, y0, iter-1);
            drawHilbertCurveII(x0-4*pace, y0, x0-6*pace, y0-2*pace, iter-1);
            drawHilbertCurveII(x0-6*pace, y0-2*pace, x0-4*pace, y0-4*pace, iter-1);
            drawHilbertCurveII(x0-4*pace, y0-4*pace, x0-2*pace, y0-2*pace, iter-1);
            drawHilbertCurveII(x0-2*pace, y0-2*pace, x0, y0-4*pace, iter-1);
            drawHilbertCurveII(x0, y0-4*pace, x0-2*pace, y0-6*pace, iter-1);
            drawHilbertCurveII(x0-2*pace, y0-6*pace, x0-4*pace, y0-4*pace, iter-1);
            drawHilbertCurveII(x0+4*pace, y0-4*pace, x0-6*pace, y0-6*pace, iter-1);
        }
    }
}

int main(){
    // test cases
//    drawHilbertCurveII(1, 1, 7, 7, 1);
    drawHilbertCurveII(1, 1, 7, 7, 2);
    return 0;
}
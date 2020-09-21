
//
//  MCLineSimplificationUtil.h
//
//  Created by Daniel Cascais on 5/19/11.
//  Copyright 2011 SAP SE. All rights reserved.
//
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#pragma once

/*
 * Struct that contains the reduced plot data.
 */
typedef struct MCLineReductionData
{
    float* reducedXValues;
    float* reducedYValues;
    unsigned int length;
} MCLineReductionData;

typedef struct MCReductionPoint
{
    unsigned int index;
    float x;
    float y;
    float size;
    
    struct MCReductionPoint * next;
    struct MCReductionPoint * prev;
    
    struct MCReductionPoint * bigger;
    struct MCReductionPoint * smaller;
    
} MCReductionPoint;

MCLineReductionData simplifyLine(float* xPts, float* yPts, unsigned int length, float tolerance);
MCLineReductionData poly(float* xPts, float* yPts, unsigned int length, float tolerance);
void simplifyLineSegment(float* xPts, float* yPts, float tolerance, int startIndex, int endIndex, bool* verticesMap);
//float distanceSquared(float x1, float y1, float x2, float y2);
int indexOfFloat(float* array, int startIndex, int endIndex);
int lastIndexOfFloat(float* array, int startIndex, int endIndex);


MCLineReductionData simplifyPolygon(float* polygonX, float* polygonY, unsigned int length, float epsilon);
float adjustParameter(float epsilon, float polygonSize);
void recalcSize(MCReductionPoint * obj, unsigned int lastIndex, MCReductionPoint * refObj);
void insertIntoSizeList(MCReductionPoint * currObj, MCReductionPoint * refObj);
MCLineReductionData selection(float minSize, unsigned int origLength);
float triangleArea(MCReductionPoint * currObj);
bool notSmallestInList(MCReductionPoint * obj);
bool notBiggestInList(MCReductionPoint * Object);

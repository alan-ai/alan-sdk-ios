//
//  MCValuePlotData.h
//  ChartKit
//
//  Created by Daniel Cascais on 9/5/12.
//
//

#pragma once

#include <stdio.h>
#include "MCGeometry.h"

//------------------------------------------------------------------------------
//
// Data type. Indicates what data is being provided and how to handle it.
//
//------------------------------------------------------------------------------

typedef enum MCDataType
{
    MCDataUnknown = 0,
    MCData1DType  = 1,
    MCData2DType  = 2,
    MCData3DType  = 3,
    MCData4DType  = 4
    
} MCDataType;


//------------------------------------------------------------------------------
//
// Plot data type
//
//------------------------------------------------------------------------------

typedef enum MCPlotType
{
    MCUndefinedPlotType = 0,
    MCBasePlotType      = 1,
    MCPointPlotType     = 2,
    MCRectPlotType      = 3,
    MCEllipsePlotType   = 4,
    MCPieWedgePlotType  = 5

} MCPlotType;


//------------------------------------------------------------------------------
//
// Base plot data
//
//------------------------------------------------------------------------------

#ifndef MCBasePlotDataFields
#define MCBasePlotDataFields MCPoint pos; unsigned int series; unsigned int index; bool isCorrupt;
#endif

struct MCBasePlotData { MCBasePlotDataFields };
typedef struct MCBasePlotData MCBasePlotData;


//------------------------------------------------------------------------------
//
// Point plot data
//
//------------------------------------------------------------------------------

#ifndef MCPointDataFields
#define MCPointDataFields MCBasePlotDataFields double value;
#define MC_POINT_BASE_FIELDS union                                             \
        {                                                                      \
            struct { MCBasePlotDataFields };                                   \
            MCBasePlotData base;                                               \
        }
#endif

struct MCPointData
{
    // Extend MCBasePlotData
    MC_POINT_BASE_FIELDS;

    double value;
};
typedef struct MCPointData MCPointData;


//------------------------------------------------------------------------------
//
// Rect plot data
//
//------------------------------------------------------------------------------

#ifndef MCRectDataFields
#define MCRectDataFields MCPointDataFields MCRect rect;
#define MC_RECT_BASE_FIELDS union                                              \
        {                                                                      \
            struct { MCPointDataFields };                                      \
            MCBasePlotData base;                                               \
        }
#endif

struct MCRectData
{
    // Extend MCPointData
    MC_RECT_BASE_FIELDS;

    MCRect rect;
};
typedef struct MCRectData MCRectData;


//------------------------------------------------------------------------------
//
// Ellipse plot data
//
//------------------------------------------------------------------------------

#ifndef MCEllipseDataFields
#define MCEllipseDataFields MCPointDataFields MCRect rect; double values[3];
#endif

struct MCEllipseData
{
    // Extend MCBasePlotData
    MC_POINT_BASE_FIELDS;

    MCRect rect;
    double values[3];
};
typedef struct MCEllipseData MCEllipseData;


//------------------------------------------------------------------------------
//
// Plot data used to pass around when it could be any type.
//
//------------------------------------------------------------------------------

#ifndef MCPlotDataFields
#define MCPlotDataFields MCRectDataFields double values[3];
#endif

struct MCPlotData
{
    MCPlotType type;
    
    union
    {
        struct { MCPlotDataFields };
        MCBasePlotData baseData;
        MCPointData pointData;
        MCRectData rectData;
        MCEllipseData ellipseData;
    };
};
typedef struct MCPlotData MCPlotData;


//------------------------------------------------------------------------------
//
// Utility
//
//------------------------------------------------------------------------------

//--------------------------------------
//  Base
//--------------------------------------

#ifndef MCBasePlotDataInitFields
#define MCBasePlotDataInitFields {NAN, NAN}, 0, 0, true
#endif

static const MCBasePlotData MCBasePlotDataInit = {MCBasePlotDataInitFields};

static inline MCPoint MCPlotDataGetPosition(MCPlotData* plotData) {
    return plotData->pos;
}

//--------------------------------------
//  Point
//--------------------------------------

static inline MCPointData MCPointDataMake(unsigned int series,
                                          unsigned int index,
                                          double value,
                                          float x,
                                          float y,
                                          bool isCorrupt);

static inline MCPointData MCPointDataMake(unsigned int series,
                                          unsigned int index,
                                          double value,
                                          float x,
                                          float y,
                                          bool isCorrupt)
{
    MCPointData point;

    point.value = value;
    
    point.pos.x = x;
    point.pos.y = y;
    point.series = series;
    point.index = index;
    point.isCorrupt = isCorrupt;

    return point;
}

//--------------------------------------
//  Rect
//--------------------------------------

static inline MCRectData MCRectDataMake(unsigned int series,
                                        unsigned int index,
                                        double value,
                                        float x,
                                        float y,
                                        float width,
                                        float height,
                                        bool isCorrupt);

static inline MCRectData MCRectDataMake(unsigned int series,
                                        unsigned int index,
                                        double value,
                                        float x,
                                        float y,
                                        float width,
                                        float height,
                                        bool isCorrupt)
{
    MCRectData rect;

    rect.value = value;
    rect.rect.origin.x = x;
    rect.rect.origin.y = y;
    rect.rect.size.width = width;
    rect.rect.size.height = height;
    
    rect.pos.x = x + width * 0.5f;
    rect.pos.y = y + height * 0.5f;
    rect.series = series;
    rect.index = index;
    rect.isCorrupt = isCorrupt;
    
    return rect;
}

//--------------------------------------
//  Ellipse
//--------------------------------------

static inline MCEllipseData MCEllipseDataMake(unsigned int series,
                                              unsigned int index,
                                              const double values[3],
                                              float x,
                                              float y,
                                              float radius,
                                              bool isCorrupt);

static inline MCEllipseData MCEllipseDataMake(unsigned int series,
                                              unsigned int index,
                                              const double values[3],
                                              float x,
                                              float y,
                                              float diameter,
                                              bool isCorrupt)
{
    MCEllipseData ellipse;

    MCFloat radius = diameter * 0.5f;

    if (NULL == values)
    {
        ellipse.values[0] = NAN;
        ellipse.values[1] = NAN;
        ellipse.values[2] = NAN;
    }
    else
    {
        ellipse.values[0] = values[0];
        ellipse.values[1] = values[1];
        ellipse.values[2] = values[2];
    }

    ellipse.rect.origin.x = x - radius;
    ellipse.rect.origin.y = y + radius;
    ellipse.rect.size.width = diameter;
    ellipse.rect.size.height = diameter;
    
    ellipse.pos.x = x;
    ellipse.pos.y = y;
    ellipse.series = series;
    ellipse.index = index;
    ellipse.isCorrupt = isCorrupt;
    
    return ellipse;
}

//--------------------------------------
//  Plot data
//--------------------------------------

static const MCPlotData MCPlotDataNull =
{
    MCUndefinedPlotType,                // type
    {                                   // union
        {       
            {NAN, NAN},                 // pos
            0,                          // series
            0,                          // index
            true,                       // isCorrupt
            NAN,                        // value
            {{NAN, NAN}, {NAN, NAN}},   // rect
            {NAN, NAN, NAN}             // values[3]
        }
    }
};

static inline bool MCPlotDataIsNull(MCPlotData plotData)
{
    return plotData.type == MCUndefinedPlotType &&
           isnan(plotData.pos.x) &&
           isnan(plotData.pos.y) &&
           plotData.series == 0 &&
           plotData.index == 0 &&
           plotData.isCorrupt == true &&
           isnan(plotData.value) &&
           isnan(plotData.rect.origin.x) &&
           isnan(plotData.rect.origin.y) &&
           isnan(plotData.rect.size.width) &&
           isnan(plotData.rect.size.height) &&
           isnan(plotData.values[0]) &&
           isnan(plotData.values[1]) &&
           isnan(plotData.values[2]);
}

// TODO:DC MERGE pie wedge data into the above setup. 
//------------------------------------------------------------------------------
//
// Pie wedge data struct
//
//------------------------------------------------------------------------------

struct MCPieWedgeData
{
    unsigned int index;
    double value;
    double absValue;
    float percent;
    float startAngle;
    float midAngle;
    float endAngle;
    bool isOther;
    bool isRenderable;
};
typedef struct MCPieWedgeData MCPieWedgeData;

static inline MCPieWedgeData MCPieWedgeDataMake(unsigned int index,
                                                double value,
                                                double absValue,
                                                float percent,
                                                float startAngle,
                                                float midAngle,
                                                float endAngle,
                                                bool isOther,
                                                bool isRenderable);

static inline MCPieWedgeData MCPieWedgeDataMake(unsigned int index,
                                                double value,
                                                double absValue,
                                                float percent,
                                                float startAngle,
                                                float midAngle,
                                                float endAngle,
                                                bool isOther,
                                                bool isRenderable)
{
    MCPieWedgeData wedge;

    wedge.index = index;
    wedge.value = value;
    wedge.absValue = absValue;
    wedge.percent = percent;
    wedge.startAngle = startAngle;
    wedge.midAngle = midAngle;
    wedge.endAngle = endAngle;
    wedge.isOther = isOther;
    wedge.isRenderable = isRenderable;

    return wedge;
}

static inline void MCPrintPoint(MCPointData* point)
{
    printf("\n{\n\tpos : {x : %f, y : %f}, \n\tseries : %i,\n\tindex : %i,\n\tisCorrupt : %s,\n\tvalue : %f\n}", point->pos.x, point->pos.y, point->series, point->index, point->isCorrupt ? "true" : "false", point->value);
}

static inline void MCPrintRect(MCRectData* rect)
{
    printf("\n{\n\tpos : \t\t{x : %f, y : %f}, \t\n\tseries : \t%i,\n\tindex : \t%i,\n\tisCorrupt : %s,\n\tvalue : \t%f,\n\trect : \t\t{origin : {x : %f, y : %f}, size : {width : %f, height : %f}}\n}", rect->pos.x, rect->pos.y, rect->series, rect->index, rect->isCorrupt ? "true" : "false", rect->value, rect->rect.origin.x, rect->rect.origin.y, rect->rect.size.width, rect->rect.size.height);
}

static inline void MCPrintEllipse(MCEllipseData* ellipse)
{
    printf("\n{\n\tpos : {x : %f, y : %f}, \n\tseries : %i,\n\tindex : %i,\n\tisCorrupt : %s,\n\tvalue x : %f,\n\tvalue y : %f,\n\tvalue z : %f,\n\trect : {origin : {x : %f, y : %f}, size : {width : %f, height : %f}}\n}", ellipse->pos.x, ellipse->pos.y, ellipse->series, ellipse->index, ellipse->isCorrupt ? "true" : "false", ellipse->values[0], ellipse->values[1], ellipse->values[2], ellipse->rect.origin.x, ellipse->rect.origin.y, ellipse->rect.size.width, ellipse->rect.size.height);
}

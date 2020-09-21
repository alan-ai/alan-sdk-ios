/*
 *  MCColorUtil.h *
 *  Created by Daniel Cascais on 3/19/11.
 *  Copyright 2011 SAP SE. All rights reserved.
 *
 */

#ifndef MC_COLOR_UTIL_H
#define MC_COLOR_UTIL_H


#include <math.h>
#include "MCMathUtils.h"

#define HEX_TO_RGB_RED(hex) ((hex >> 16) & 0xFF) / 255.0f
#define HEX_TO_RGB_GREEN(hex) ((hex >> 8) & 0xFF) / 255.0f
#define HEX_TO_RGB_BLUE(hex) (hex & 0xFF) / 255.0f

#define HEX_TO_RGBA_RED(hex) ((hex >> 24) & 0xFF) / 255.0f
#define HEX_TO_RGBA_GREEN(hex) ((hex >> 16) & 0xFF) / 255.0f
#define HEX_TO_RGBA_BLUE(hex) ((hex >> 8) & 0xFF) / 255.0f
#define HEX_TO_RGBA_ALPHA(hex) (hex & 0xFF) / 255.0f

#define RGB_TO_RGBA(hex) ((hex << 0x8) + 0xFF)
#define RGBA_TO_RGB(hex) (hex >> 8)

/**
 * Takes 3 color components and returns the single HEX representation
 * input: 3 unsigned integers that represent the red,blue and green color channels
 * output: unsigned int
 */
#define RGB_TO_HEX(red,green,blue) ((red << 16) | (green << 8) | (blue))

/**
 *  Performs a linear brightness adjustment of an RGB color.
 *
 *  The same amount is added to the red, green, and blue channels of the RGB color.
 *  Each color channel is limited to the range 0 through 255.
 *
 *  @param rgb RGB hex color to be brightened.
 *
 *  @param brightness Amount of brightness added to the separate RGB color components.
 *  The range for this parameter is -255 to 255;
 *  -255 returns black while 255 returns white.
 *  0 returns the original color.
 *
 *  @return RGB color with adjusted brightness.
 */
static inline unsigned int MCColorUtilLinearBrightnessAdjustment(unsigned int rgb, int brightness)
{
    // If the brightness change is none, return color as is.
    if (brightness == 0)
    {
        return rgb;
    }
    
    // If the brightness is set to be below or at black, return black.
    if (brightness <= -255)
    {
        return 0x000000;
    }
    
    // If the brightness is set to be above or at white, return white.
    if (brightness >= 255)
    {
        return 0xFFFFFF;
    }
    
    // Extract RGB color components.
    unsigned int r = (rgb >> 0x10) & 0xFF;
    unsigned int g = (rgb >> 0x08) & 0xFF;
    unsigned int b = rgb & 0xFF;
    
    // Add the brightness to the color components and clamp to valid values between black and white.
    r = MCMaxUnsignedInt(0x00, MCMinUnsignedInt(0xFF, r + brightness));
    g = MCMaxUnsignedInt(0x00, MCMinUnsignedInt(0xFF, g + brightness));
    b = MCMaxUnsignedInt(0x00, MCMinUnsignedInt(0xFF, b + brightness));
    
    // Reasemmble the color components.
    rgb = (r << 16) | (g << 8) | b;

    return rgb;
}

/**
 *  Performs a linear brightness scaling of an RGB color.
 *
 *  The same amount is added to the red, green, and blue channels of the RGB color.
 *
 *  @param rgb RGB hex color to be brightened.
 *
 *  @param scale Amount of brightness scaling added to the separate RGB color components.
 *  The range for this parameter is -1 to 1;
 *  -1 returns black while 1 returns white.
 *  0 returns the original color.
 *
 *  @return RGB color with adjusted brightness scale.
 */
static inline unsigned int MCColorUtilLinearBrightnessScaling(unsigned int rgb, MCFloat scale)
{
    // If the scale change change is none, return color as is.
    if (scale == 0.0f)
    {
        return rgb;
    }
    
    // If the scale is set to be below or at black, return black.
    if (scale <= -1.0f)
    {
        return 0x000000;
    }
    
    // If the scale is set to be above or at white, return white.
    if (scale >= 1.0f)
    {
        return 0xFFFFFF;
    }
    
    // Adjust scale to be between -255 and 255
    int brightness = roundf(255 * scale);
    
    rgb = MCColorUtilLinearBrightnessAdjustment(rgb, brightness);
    
    return rgb;
}

typedef struct
{
    MCFloat red;
    MCFloat green;
    MCFloat blue;
    MCFloat alpha;
} MCPlotColor;

/**
 *  Performs a linear brightness scaling of an RGB color.
 *
 *  The same amount is added to the red, green, and blue channels of the RGB color.
 *
 *  @param rgb RGB hex color to be brightened.
 *
 *  @param scale Amount of brightness scaling added to the separate RGB color components.
 *  The range for this parameter is -1 to 1;
 *  -1 returns black while 1 returns white.
 *  0 returns the original color.
 *
 *  @return MCPlotColor with adjusted brightness scale.
 */
static inline MCPlotColor MCColorUtilLinearBrightnessScaledColor(MCPlotColor color, MCFloat scale)
{
    // Extract RGB color components.
    MCPlotColor plotColor = {color.red, color.green, color.blue, 0xff};
    
    // If the scale change change is none, return color as is.
    if (scale == 0.0f)
    {
        return plotColor;
    }
    
    // If the scale is set to be below or at black, return black.
    if (scale <= -1.0f)
    {
        MCPlotColor plotColor = {0x00, 0x00, 0x00, 0xff};
        return plotColor;
    }
    
    // If the scale is set to be above or at white, return white.
    if (scale >= 1.0f)
    {
        MCPlotColor plotColor = {0xff, 0xff, 0xff, 0xff};
        return plotColor;
    }
    
    // Adjust scale to be between -255 and 255
    int brightness = roundf(255 * scale);
    int rgb = ((int)plotColor.red << 16) | ((int)plotColor.green << 8) | (int)plotColor.blue;
    rgb = MCColorUtilLinearBrightnessAdjustment(rgb, brightness);
    
    plotColor.red = HEX_TO_RGB_RED(rgb);
    plotColor.green = HEX_TO_RGB_GREEN(rgb);
    plotColor.blue = HEX_TO_RGB_BLUE(rgb);
    
    return plotColor;
}

typedef unsigned int MCColor;

/* Splits the input color into its red, green, blue and alpha.
 * input: Color in Hex representation and alpha component as float
 * output: An Array with each component
 */
static inline void MCColorUtilSplitHexToRGBAComponents(MCFloat components[4], unsigned int hexColor, float alphaComponent){
    components[0] = HEX_TO_RGB_RED(hexColor);
    components[1] = HEX_TO_RGB_GREEN(hexColor);
    components[2] = HEX_TO_RGB_BLUE(hexColor);
    components[3] = alphaComponent;
}


//struct MCColorRGBA {
//    Byte a;  // alpha channel to indicate RGB.control true (!= 0) / false (== 0)
//    Byte b;  // blue  channel
//    Byte g;  // green channel
//    Byte r;  // red   channel
//
//};
//typedef struct MCColorRGBA MCColorRGBA;
//
//union MCColor {
//    MCColorRGBA rgba;
//    unsigned int value;
//};
//typedef union MCColor MCColor;

#endif

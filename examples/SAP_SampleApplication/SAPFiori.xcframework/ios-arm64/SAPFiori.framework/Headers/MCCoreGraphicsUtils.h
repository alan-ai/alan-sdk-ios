//
//  MCCoreGraphics.h
//  ChartKit
//
//  Created by Callaghan, Brett on 10/26/17.
//
//

#import <CoreGraphics/CoreGraphics.h>


#ifndef MCCoreGraphics_h
#define MCCoreGraphics_h

CGColorRef MCCreateCGColorWithRGBAValue(unsigned int colorValue) CF_RETURNS_RETAINED;

CGColorRef MCCreateCGColorWithRGBValue(unsigned int colorValue, float alpha) CF_RETURNS_RETAINED;

CGColorRef MCCreateCGColorWithRGBValueInColorSpace(unsigned int colorValue, float alpha, CGColorSpaceRef colorSpace) CF_RETURNS_RETAINED;

void MCCoreGraphicsSetRGBStrokeColor(CGContextRef context, unsigned int colorValue, float alpha);
void MCCoreGraphicsSetRGBFillColor(CGContextRef context, unsigned int colorValue, float alpha);

#endif /* MCCoreGraphics_h */

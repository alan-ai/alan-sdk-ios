//
//  MMAbbreviatedNumberFormatter.h
//
//  Created by Brett Callaghan on 1/31/12.
//  Copyright (c) 2012 SAP SE. All rights reserved.
//

#import <Foundation/Foundation.h>


/*!
 @details	This class encapsulates the number formatting business logic employed by Roambi visualizations. It was created to replace NSNumberFormatter category methods that mutate the properties of the formatter when rendering strings for given values. Mutating formatters is very expensive because the formatter must be "recompiled" after doing so. Instead of mutating a single formatter, this method creates and caches formatters for each of the value ranges.
 
    Performance for 1000 double values:
    iPad 2: 0.069460 vs 0.452441 (+651%)
    iPad 1: 0.116445 vs 0.999230 (+858%)
 */
@interface MMAbbreviatedNumberFormatter : NSObject
{
@private
    NSNumberFormatter *_numberFormatter;
    BOOL _isPercent;
    BOOL _appendMagnitude;
    double _divisor;
    NSString *_magnitude;
    
	// Derived formatters created from the original.
	NSNumberFormatter *_100PlusNumberFormatter;
	NSNumberFormatter *_10To100NumberFormatter;
	NSNumberFormatter *_0To10NumberFormatter;
	NSNumberFormatter *_scientificNumberFormatter;
}

/*!
 @brief     Initializes the receiver with the number formatter that is used as the basis for the derived formatters this object creates.
 */
- (id)initWithNumberFormatter:(NSNumberFormatter *)formatter;

/*!
 @details   This method provides shortened strings with the magnitude of the value suffixed (100k, 1.12m, etc). These strings are primarily used as axis/value labels in charts where we have limited screen real estate.
 */
- (NSString *)abbreviatedStringForDouble:(double)doubleValue;

/*!
 @details   This method provides shortened strings with the magnitude of the value suffixed (100k, 1.12m, etc) with up to 6 digits.
 */
- (NSString *)abbreviatedStringForDouble6:(double)doubleValue;

/*
 @details   This method limits the amount of fraction digits used when formatting the value. Values 100 or greater have none (100.233 -> 100). Values < 100 but >= 10 have one (23.2). Values less than 10 but greater than .001 have two (7.43). For other values scientific notation is employed.
 */
- (NSString *)stringForDouble:(double)doubleValue;

/**
 Default is YES.
 */
@property (nonatomic) BOOL appendMagnitude;

/**
 Allows you to specify a value to be used when defining magnitude... such as the max value of the displayed range of a chart.
 */
- (void)setMagnitudeWithValue:(double)value;

/**
 String that defines the magnitude of the value. This property is set using the setMagnitudeWithValue: method.
 */
@property (nonatomic, readonly, retain) NSString *magnitude;
@end


/*!
 @details   Many existing widgets use the NSNumberFormatter category methods. We provide these category methods so that those widgets do not have to be refactored to create and store their own abbreviated number formatters.
 */
@interface NSNumberFormatter (MMAbbreviatedNumberFormatter)

@property (nonatomic, readonly)  MMAbbreviatedNumberFormatter *abbreviatedFormatter;

/*!
 @brief     If you mutate the NSNumberFormatter you need to ensure that the abbreviated number formatter is reset so that a new one will be created and adopt the changes you've made to the receiver.
 */
- (void)resetAbbreviatedFormatter;
@end

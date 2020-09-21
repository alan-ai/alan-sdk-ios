//
//  MCMathUtils.h
//
//  Created by Daniel Cascais on 8/11/11.
//  Copyright 2011 SAP SE. All rights reserved.
//

#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "MCGeometry.h"

//------------------------------------------------------------------------------
//
// Unsigned int
//
//------------------------------------------------------------------------------

static inline unsigned int MCMinUnsignedInt(const unsigned int a, const unsigned int b)
{
    return a < b ? a : b;
}

static inline unsigned int MCMaxUnsignedInt(const unsigned int a, const unsigned int b)
{
    return a > b ? a : b;
}

static inline unsigned int MCDeltaUnsignedInt(const unsigned int a, const unsigned int b)
{
    return MCMaxUnsignedInt(a, b) - MCMinUnsignedInt(a, b);
}

static inline unsigned int MCClampUnsignedInt(unsigned int value, unsigned int min, unsigned int max)
{
    if (value > max ) return max;
    if (value < min ) return min;
    
    return value;
}

//static inline unsigned int MCWrapUnsignedInt(unsigned int value, unsigned int min, unsigned int max)
//{
//    max -= min;
//    
//    value = (value - min) % max;
//    
////    if (value < 0)
////    {
////        value += max;
////    }
//    
//    return min + value;
//}

//------------------------------------------------------------------------------
//
// Int
//
//------------------------------------------------------------------------------

static inline int MCMinInt(const int a, const int b)
{
    return a < b ? a : b;
}

static inline int MCMaxInt(const int a, const int b)
{
    return a > b ? a : b;
}

static inline int MCDeltaInt(const int a, const int b)
{
    return MCMaxInt(a, b) - MCMinInt(a, b);
}

static inline int MCClampInt(int value, int min, int max)
{
    if (value > max ) return max;
    if (value < min ) return min;
    
    return value;
}

static inline int MCWrapInt(int value, int min, int max)
{
    int tempMax = max;
    max = MCMaxInt(min, max);
    min = MCMinInt(min, tempMax);
    
    int range = max - min + 1;

    if (value < min)
    {
        value += range * ((min - value) / range + 1);
    }

    return min + (value - min) % range;
    
    // Old and decrepit logic below.
//    max -= min;
//    
//    if (max == 0)
//    {
//        return 0;
//    }
//    
//    value = (value - min) % max;
//    
//    if (value < 0)
//    {
//        value += max;
//    }
//    
//    return min + value;
}

//------------------------------------------------------------------------------
//
// Long
//
//------------------------------------------------------------------------------
static inline long MCClampLong(long value, long min, long max)
{
    if (value > max ) return max;
    if (value < min ) return min;
    
    return value;
}

//------------------------------------------------------------------------------
//
// Float
//
//------------------------------------------------------------------------------

static inline float MCAbsFloat(const float A)
{
	return ((A) < 0 ? (-(A)) : (A));
}

static inline float MCClampFloat(float value, float min, float max)
{
    if (value > max ) return max;
    if (value < min ) return min;
    
    return value;
}

static inline float MCWrapFloat(float value, float min, float max)
{
    max -= min;
    
    value = fmodf(value - min, max);
    
    if (value < 0.0f)
    {
        value += max;
    }
    
    return min + value;
}

static inline float MCContainsFloat(float value, float min, float max)
{
	return (fabsf(value) > fabsf(min) && fabsf(value) < fabsf(max));
}

//TODO: Remove this function in favor of v2 below.
static inline MCFloat MCDistanceBetweenPoints(float x1, float y1, float x2, float y2)
{
    float xDist = x2 - x1;
    float yDist = y2 - y1;
    float distance = sqrtf((xDist * xDist) + (yDist * yDist));
    
    return distance;
}

static inline MCFloat MCDistanceBetweenPoints2(const MCPoint* p1, const MCPoint* p2)
{
    MCFloat xDist = p2->x - p1->x;
    MCFloat yDist = p2->y - p1->y;
    MCFloat distance = sqrtf((xDist * xDist) + (yDist * yDist));

    return distance;
}

//------------------------------------------------------------------------------
//
// Double
//
//------------------------------------------------------------------------------

static inline double MCAbsDouble(const double A)
{
	return ((A) < 0 ? (-(A)) : (A));
}

static inline double MCClampDouble(double value, double min, double max)
{
    if (value > max ) return max;
    if (value < min ) return min;
    
    return value;
}

static inline double MCWrapDouble(double value, double min, double max)
{
    max -= min;
    
    value = fmod(value - min, max);
    
    if (value < 0.0)
    {
        value += max;
    }
    
    return min + value;
}

//------------------------------------------------------------------------------
//
// CGFloat
//
//------------------------------------------------------------------------------
#ifdef CGFLOAT_IS_DOUBLE
#if CGFLOAT_IS_DOUBLE == 1
#define MCAbsCGFloat(a) MCAbsDouble(a)
#else
#define MCAbsCGFloat(a) MCAbsFloat(a)
#endif
#endif

//------------------------------------------------------------------------------
//
// Statistics
//
//------------------------------------------------------------------------------

/*
 * Based on John D. Cook's implementation of the mean, variance and standard
 * deviation, which in turn was based on Donald Knuth's implementation.
 * More info here: http://www.johndcook.com/standard_deviation.html
 */
static inline void MCCalculateMeanVarianceStandardDeviationWithStride(const double* data, unsigned int dataCount, const size_t stride,
                                                                      unsigned int* validDataCount,
                                                                      double* mean,
                                                                      double* variance,
                                                                      double* standardDeviation)
{
    if (NULL == data || dataCount == 0 || stride < 1)
    {
        *validDataCount = 0;
        *mean = NAN;
        *variance = NAN;
        *standardDeviation = NAN;
        
        return;
    }
    
    unsigned char* charData = (unsigned char*)data;

    unsigned int m_n = 0;
    double m_oldM;
    double m_newM;
    double m_oldS;
    double m_newS;

    for (unsigned int i = 0; i < dataCount; ++i, charData += stride)
    {
        double x = *((double*)charData);

        if (isnan(x) || isinf(x))
        {
            continue;
        }

        m_n++;

        // See Knuth TAOCP vol 2, 3rd edition, page 232
        if (m_n == 1)
        {
            m_oldM = m_newM = x;
            m_oldS = 0.0;
        }
        else
        {
            m_newM = m_oldM + (x - m_oldM) / m_n;
            m_newS = m_oldS + (x - m_oldM) * (x - m_newM);

            // set up for next iteration
            m_oldM = m_newM;
            m_oldS = m_newS;
        }
    }

    if (m_n == 0)
    {
        *validDataCount = 0;
        *mean = NAN;
        *variance = NAN;
        *standardDeviation = NAN;

        return;
    }

    *validDataCount = m_n;
    *mean = (m_n > 0) ? m_newM : 0.0;
    *variance = ((m_n > 1) ? m_newS / (m_n - 1) : 0.0);
    *standardDeviation = sqrt(*variance);
}

static inline void MCCalculateMeanVarianceStandardDeviation(const double* data, unsigned int dataCount,
                                                            unsigned int* validDataCount,
                                                            double* mean,
                                                            double* variance,
                                                            double* standardDeviation)
{
    MCCalculateMeanVarianceStandardDeviationWithStride(data, dataCount, sizeof(double), validDataCount, mean, variance, standardDeviation);
}

static inline double MCCalculateMedianWithStride(const double* data, unsigned int dataCount, const size_t stride)
{
    if (NULL == data || dataCount == 0 || stride < 1)
    {
        return NAN;
    }
    
    double* sortedData = (double*)malloc(sizeof(double) * dataCount);
	if( sortedData == NULL )
	{
		abort();
	}

    unsigned int validDataCount = 0;

    unsigned char* charData = (unsigned char*)data;
    
    // Curate the data.
    for (unsigned int i = 0; i < dataCount; ++i, charData += stride)
    {
        double value = *((double*)charData);
        
        if (isnan(value) || isinf(value))
        {
            continue;
        }
        
        sortedData[validDataCount] = value;
        
        validDataCount++;
    }
    
    // Sort the data.
    for (int i = validDataCount - 1; i > 0; --i)
    {
        for (unsigned int j = 0; j < i; ++j)
        {
            if (sortedData[j] > sortedData[j + 1])
            {
                double value = sortedData[j];
                sortedData[j] = sortedData[j + 1];
                sortedData[j + 1] = value;
            }
        }
    }
    
    // Middle or average of middle values in the sorted array.
    double median = 0.0;
    
    if (validDataCount > 0)
    {
        if ((validDataCount % 2) == 0)
        {
            median = (sortedData[validDataCount / 2] + sortedData[(validDataCount / 2) - 1]) / 2.0;
        }
        else
        {
            median = sortedData[validDataCount / 2];
        }
    }
    
    free(sortedData);
    
    return median;
}

static inline double MCCalculateMedian(const double* data, unsigned int dataCount)
{
    return MCCalculateMedianWithStride(data, dataCount, sizeof(double));
}

/*
static inline double MCCalculateMode(const double* data, unsigned int dataCount)
{
    // Allocate an int array of the same size to hold the
    // repetition count
    int* ipRepetition = new int[dataCount];
    
    for (int i = 0; i < iSize; ++i)
    {
        ipRepetition[i] = 0;
        int j = 0;
        bool bFound = false;
        
        while ((j < i) && (daArray[i] != daArray[j]))
        {
            if (daArray[i] != daArray[j])
            {
                ++j;
            }
        }
        
        ++(ipRepetition[j]);
    }
    
    int iMaxRepeat = 0;
    
    for (int i = 1; i < iSize; ++i)
    {
        if (ipRepetition[i] > ipRepetition[iMaxRepeat])
        {
            iMaxRepeat = i;
        }
    }
    
    delete [] ipRepetition;
    
    return daArray[iMaxRepeat];
}
*/
static inline double MCCalculateMeanWithStride(const double* data, unsigned int dataCount, const size_t stride)
{
    if (NULL == data || dataCount == 0 || stride < 1)
    {
        return NAN;
    }
    
    unsigned int validDataCount = 0;
    double sum = 0.0;
    
    unsigned char* charData = (unsigned char*)data;
    
    for (unsigned int i = 0; i < dataCount; ++i, charData += stride)
    {
        double value = *((double*)charData);
        
        if (isnan(value))
        {
            continue;
        }

        validDataCount++;
        sum += value;
    }
    
    return sum / validDataCount;
}

static inline double MCCalculateMean(const double* data, unsigned int dataCount)
{
    return MCCalculateMeanWithStride(data, dataCount, sizeof(double));
}

static inline double MCCalculateStandardDeviationWithStride(const double* data, const unsigned int dataCount, const size_t stride)
{
    if (NULL == data || dataCount == 0 || stride < 1)
    {
        return NAN;
    }
    
    unsigned int validDataCount = 0;
    double mean = MCCalculateMeanWithStride(data, dataCount, stride);
    double dv;
    double deviationSum = 0.0;

    unsigned char* charData = (unsigned char*)data;
    
    for (unsigned int i = 0; i < dataCount; ++i, charData += stride)
    {
        double value = *((double*)charData);
        
        if (isnan(value))
        {
            continue;
        }
        
        validDataCount++;
        dv = value - mean;
        deviationSum += dv * dv;
    }
    
    return sqrt(1.0 / ((double) validDataCount - 1.0) * deviationSum);
}

static inline double MCCalculateStandardDeviation(const double* data, const unsigned int dataCount)
{
    return MCCalculateStandardDeviationWithStride(data, dataCount, sizeof(double));
}

static inline double MCCalculateStandardDeviationOfMeanWithStride(const double* data, unsigned int dataCount, const size_t stride)
{
    if (NULL == data || dataCount == 0 || stride < 1)
    {
        return NAN;
    }
    
    unsigned int validDataCount = 0;

    unsigned char* charData = (unsigned char*)data;
    
    for (unsigned int i = 0; i < dataCount; ++i, charData += stride)
    {
        if (isnan(*((double*)charData)))
        {
            continue;
        }
        
        validDataCount++;
    }
    
    return MCCalculateStandardDeviationWithStride(data, dataCount, stride) / sqrt(validDataCount);
}

static inline double MCCalculateStandardDeviationOfMean(const double* data, unsigned int dataCount)
{
    return MCCalculateStandardDeviationOfMeanWithStride(data, dataCount, sizeof(double));
}

/**
 * @brief Calculates a range between two values.
 * @param min Minimum value used to calculate range.
 * @param max Maximum value used to calculate range.
 * @param adjustToValue Value used to adjust the range if the range is zero.
 */
static inline double MCCalculateRange(double min, double max, double adjustToValue)
{
    if (isnan(min) || isnan(max))
    {
        // Either it's NAN or a specified value.
        return adjustToValue;
    }
    
    double range = fmax(min, max) - fmin(min, max);
    
    if (!isnan(adjustToValue))
    {
        if (range == 0.0)
        {
            if (min >= 0.0 && max >= min)
            {
                max += adjustToValue;
            }
            else if (max <= 0.0 && min <= max)
            {
                min -= adjustToValue;
            }
            
            range = fmax(min, max) - fmin(min, max);
        }
    }
    
    return range;
}

/**
 *  Searches for key in array.
 *
 *  @param key A float value that is to be searched for.
 *  @param values Array of values to search the key in.
 *  @param valueCount An int idicating the value count.
 *
 *  @return A boolean. True if the key is found in the array, otherwise, false.
 */
static inline bool MCBinarySearch(int key, const int* values, int valueCount)
{
	/*
	 *  Variables used for the binary search.
	 */
	int leftIndex = 0;
	int rightIndex = valueCount - 1;
	int midIndex;
	int currentValue;
	
	/*
	 *  Make sure we search within a range that's big enough to hold a value.
	 */
	while(leftIndex <= rightIndex)
	{
		/*
		 *  The mid index is the (floored) index that's in the middle between
		 *  the left and right indices, which will change below as we go through
		 *  the search.
		 *
		 *  Using unsigned ints we don't need the below.
		 *  midIndex = leftIndex + (rightIndex - leftIndex) / 2;
		 *
		 *  Aparently, the bit shif is faster, so we won't use the below.
		 *  midIndex = (leftIndex + rightIndex) / 2;
		 */
		midIndex = (leftIndex + rightIndex) >> 1;
		
		currentValue = values[midIndex];
		
		/*
		 *  Found a match, let's return the value immediately.
		 */
		if(currentValue == key)
		{
			return true;
		}
		
		/*
		 *  The key is smaller than the current value. Let's increase the right
		 *  index to our mid index (- 1), reducing our search range (see top of
		 *  loop).
		 */
		else if (key < currentValue)
		{
			rightIndex = midIndex - 1;
		}
		
		/*
		 *  The key is greater than the current value. Let's reduce the left
		 *  index to our mid index (+ 1), reducing our search range (see top of
		 *  loop).
		 */
		else if(key > currentValue)
		{
			leftIndex = midIndex + 1;
		}
	}
    
    return false;
}

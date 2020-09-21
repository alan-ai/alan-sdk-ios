/*
 *  MCAxisType.h
 *
 *  Created by Daniel Cascais on 3/21/11.
 *  Copyright 2011 SAP SE. All rights reserved.
 *
 */

#pragma once

/**
 * Enum that enumerates the different chart types supported.
 */
typedef enum MCAxisType
{
    MC_AXIS_NUMERIC,
    MC_AXIS_LINEAR,
    MC_AXIS_LOGARITHMIC,
    MC_AXIS_CATEGORY,
    MC_AXIS_DATE_TIME
}MCAxisType;

//
//  MCInputDelegate.h
//  ChartKit
//
//  Created by Daniel Cascais on 5/3/13.
//
//

#pragma once

#include "MCSelectedState.h"

/* Closure that serves a callback that provides selection update based on parameters */
struct MCInputDelegate
{
    void* (*callback) (const MCSelectedState* selectionState, void* info);
    void *info;
};

typedef struct MCInputDelegate MCInputDelegate;

//
//  MCChartInteractionKind.h
//  ChartKit
//
//  Created by Daniel Cascais on 7/28/12.
//  Copyright (c) 2012 SAP SE. All rights reserved.
//
//

#pragma once

typedef enum MCChartInteractionKind
{
    MCChartInteractionKindUndefined,
    
    // Fast and fully CG rendered, including labels and gridlines.
    MCChartInteractionKindStatic,
    
    // Plot is CGrendered, selection is represented with CALayers, labels are
    // CATextLayers and gridlines are CAShapeLayers
    MCChartInteractionKindSelectable,
    
    // Plot is rendered through CAShapeLayers and can have transitions. The rest
    // is represented as in the selectable chart kind.
    MCChartInteractionKindDancing,
    
    // This is specific for pie charts and other polar charts that spin.
    MCChartInteractionKindSpinning
}
MCChartInteractionKind;

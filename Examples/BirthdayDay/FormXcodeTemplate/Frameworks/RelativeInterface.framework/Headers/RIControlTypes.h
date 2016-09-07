//
//  RIControlTypes.h
//  RelativeInterface
//
//  Created by Max Weisel on 1/20/14.
//  Copyright (c) 2014 RelativeWave. All rights reserved.
//

typedef enum {
    RIControlEventTouchDown             = 1 <<  0,  // sent for each new touch
    RIControlEventTouchDownRepeat       = 1 <<  1,  // sent for each repeat touch (tapCount > 1)
    RIControlEventTouchDragInside       = 1 <<  2,
    RIControlEventTouchDragOutside      = 1 <<  3,
    RIControlEventTouchDragEnter        = 1 <<  4,
    RIControlEventTouchDragExit         = 1 <<  5,
    RIControlEventTouchUpInside         = 1 <<  6,
    RIControlEventTouchUpOutside        = 1 <<  7,
    RIControlEventTouchCancel           = 1 <<  8,
    
    RIControlEventValueChanged          = 1 << 12,  // used for continuous controls
    
    RIControlEventAllTouchEvents      = 0x00000FFF,
    RIControlEventAllEvents           = 0xFFFFFFFF
} RIControlEvents;

typedef enum {
    RIControlStateNormal        = 0,
    RIControlStateHighlighted   = 1 << 0,
    RIControlStateDisabled      = 1 << 1,
} RIControlState;

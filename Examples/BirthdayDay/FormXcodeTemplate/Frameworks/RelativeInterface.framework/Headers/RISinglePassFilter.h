//
//  RISinglePassFilter.h
//  RelativeInterface
//
//  Created by Max Weisel on 5/7/14.
//  Copyright (c) 2014 RelativeWave. All rights reserved.
//

#import "RIFilter.h"

@interface RISinglePassFilter : RIFilter

- (id)initWithFilter:(RIFilter *)filter pass:(int)pass;

@end

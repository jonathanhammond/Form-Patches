//
//  PMRFeedbackOutputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMROutputPort.h"

@interface PMRFeedbackOutputPort : PMROutputPort

@property (nonatomic, strong) id defaultValue;
@property (nonatomic, readonly) id value;

@end

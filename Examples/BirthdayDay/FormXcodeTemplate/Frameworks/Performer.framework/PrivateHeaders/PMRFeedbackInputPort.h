//
//  PMRFeedbackInputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRInputPort.h"

@interface PMRFeedbackInputPort : PMRInputPort

@property (nonatomic, strong) id value;

- (void)pm_dirtyConnectedPatches;

@end

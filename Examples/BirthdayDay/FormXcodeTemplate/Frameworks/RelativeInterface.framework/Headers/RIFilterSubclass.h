//
//  RIFilterSubclass.h
//  RelativeInterface
//
//  Created by vector on 8/28/15.
//  Copyright (c) 2015 Google, Inc. All rights reserved.
//

// "Protected" methods of RIFilter, meant for use only by subclasses.

@interface RIFilter ()

// Allow subclasses to announce to all observers that they have changed
// Only useful for subclassses of RIFilter that are conceptually "mutable"
- (void)announceChange;

@end
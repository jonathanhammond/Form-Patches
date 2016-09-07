//
//  PMRPatchInternal.h
//  Performer
//
//  Created by Max Weisel on 6/30/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRPatch.h"
#import "PMRProcessContext.h"

@class PMNode;

@interface PMRPatch ()

@property (nonatomic, weak) PMNode *node;

@property (nonatomic, weak) PMRProcessContext *pmr_currentContext;

// TODO: Should this be public? Is it possible to replace existing occurrences in PMRPatch subclasses with "- (void)setShouldProcessNextFrame" ?
- (void)setNeedsProcessing;

// TODO: I'd like to make this public if it's really needed.
- (void)frameEnd;

// This is needed for some special patches. It should not be public.
- (void)hierarchyWillChange;
- (void)hierarchyDidChange;

- (void)pmr_setupPorts;

@end

//
//  PMSubviewGroup.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMGroup.h"

// Override delegate
#import "PMSubviewGroupOverrideDelegate.h"

@interface PMSubviewGroup : PMGroup

@property (nonatomic, readonly) NSArray *subviewNodes;
@property (nonatomic, readonly) RIView *view;

// TODO: This is a hack to fix viewIndex inside of replicators. The whole view hierarchy system should be refactored in order to support viewIndex properly.
@property (nonatomic, weak) id<PMSubviewGroupOverrideDelegate> overrideViewDelegate;

extern NSString *const PMSubviewGroupSubviewOrderDidChange;

// TODO: This is used by the view when the view index changes. I really don't like this. It forces an entire rebuild of subview order vs just moving the view to its new spot.
- (void)setViewOrderDirty;

@end

//
//  PMSubviewGroupOverrideDelegate.h
//  Performer
//
//  Created by Max Weisel on 8/6/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol PMSubviewGroupOverrideDelegate <NSObject>

@required
- (void)overrideViewDelegateShouldRebuildViewHierarchy;

@end

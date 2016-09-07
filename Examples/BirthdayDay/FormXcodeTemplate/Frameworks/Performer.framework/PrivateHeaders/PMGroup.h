//
//  PMGroup.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PMNode;
@class PMGroupProcessor;
@class PMRProcessContext;

@interface PMGroup : NSObject <NSCoding>

// Used only for swapping graph types.
- (instancetype)initWithGroup:(PMGroup *)group;
- (instancetype)initWithGroup:(PMGroup *)group deepCopy:(BOOL)deepCopy;

@property (nonatomic, readonly) NSString *uniqueKey;

// Hierarchy
@property (nonatomic, weak) PMNode *node;
@property (nonatomic, readonly) NSArray *subnodes;
- (PMNode *)subnodeForKey:(NSString *)uniqueKey;

- (void)hierarchyWillChange;
- (void)hierarchyDidChange;

// Delta Updates
- (void)addNode:(PMNode *)node;
- (void)removeNode:(PMNode *)node;

extern NSString *const PMGroupAddNodeNotification;
extern NSString *const PMGroupRemoveNodeNotification;
- (BOOL)pm_registerDeltaUpdateNotifications;
- (BOOL)pm_unregisterDeltaUpdateNotifications;

// Copying
- (id)deepCopy;

// Views
- (void)subnodeViewTypeDidChange:(PMNode *)node;

// Processing
- (void)setNodeNeedsProcessing:(PMNode *)node;
- (void)processGroup:(PMRProcessContext *)context;

@end

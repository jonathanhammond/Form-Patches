//
//  PMNode.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PMGroup.h"
#import "PMPort.h"
#import "PMParameter.h"

@class PMGraph;

@class PMRPatch;
@class PMNodeProcessor;
@class PMRProcessContext;

@interface PMNode : NSObject <NSCoding>

@property (nonatomic, readonly) NSString *uniqueKey;

// Hierarchy
@property (nonatomic, readonly) PMGraph *graph;
@property (nonatomic, weak) PMGroup *parentGroup;
@property (nonatomic, readonly) PMGroup *subnodeGroup;
- (void)hierarchyWillChange;
- (void)hierarchyDidChange;

// Ports / Parameters
- (PMPort *)portForKey:(NSString *)uniqueKey;
- (PMParameter *)parameterForKey:(NSString *)uniqueKey;

// Copying
- (id)deepCopy;

// Delta Updates
- (BOOL)pm_registerDeltaUpdateNotifications;
- (BOOL)pm_unregisterDeltaUpdateNotifications;

// Patch
@property (nonatomic, readonly) PMRPatch *patch;
- (NSDictionary *)pmr_patchPortsByKey;
- (PMRPort *)pmr_patchPortForKey:(NSString *)uniqueKey;
- (NSDictionary *)pmr_patchParametersbyKey;
- (PMRParameter *)pmr_patchParameterForKey:(NSString *)uniqueKey;

// Processing
@property (nonatomic, readonly) PMNodeProcessor *processor;
- (BOOL)isConsumerNode;
- (BOOL)pmr_isConsumerNode;
- (void)pm_setOutputsNeedProcessing;
- (void)pm_setNeedsProcessing;
- (void)inputPortValueDirty:(PMPort *)port;
- (void)fireFrameEnd;
- (void)processPatchAndSubnodes:(PMRProcessContext *)context;

// Delta Updates
extern NSString *const PMNodeAddPortNotification;
extern NSString *const PMNodeRemovePortNotification;
extern NSString *const PMNodeAddParameterNotification;
extern NSString *const PMNodeRemoveParameterNotification;
extern NSString *const PMNodeSubnodeGroupClassDidChangeNotification;

extern NSString *const PMNodeAddConnectionNotification;

@end

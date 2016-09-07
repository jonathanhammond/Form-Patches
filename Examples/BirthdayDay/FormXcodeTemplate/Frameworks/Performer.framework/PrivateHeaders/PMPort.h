//
//  PMPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PMNode;
@class PMConnection;
@class PMRPort;
@class PMRProcessContext;
@class PMOutputProcessor;

// Specifies which side of the patch a port sits on.
typedef enum {
    FMRPortOrientationUnknown = 0,
    FMRPortOrientationInput  = 1,
    FMRPortOrientationOutput = 2,
} FMRPortOrientation;

// Specifies how many connections can be connected to a specific port. Generally, output ports have a one-to-many relationship while input ports have a one-to-one relationship.
typedef enum {
    FMRPortConnectionRelationshipUnknown = 0,
    FMRPortConnectionRelationshipOneToMany = 1,
    FMRPortConnectionRelationshipOneToOne  = 2
} FMRPortConnectionRelationship;

@interface PMPort : NSObject <NSCoding>

@property (nonatomic, readonly) NSString *uniqueKey;
@property (nonatomic, weak) PMNode *node;
@property (nonatomic, readonly) FMRPortOrientation orientation;
@property (nonatomic, readonly) FMRPortConnectionRelationship connectionRelationship;

// Copying
@property (nonatomic, readonly) NSString *processClassName;
- (id)deepCopy;

// Connections
@property (nonatomic, readonly) NSArray *connections;
- (BOOL)canConnectToPort:(PMPort *)port;
- (BOOL)acceptsNewConnections;
- (BOOL)connectConnection:(PMConnection *)connection;
- (BOOL)disconnectConnection:(PMConnection *)connection;

// Patch Port
@property (nonatomic, readonly) PMRPort *patchPort;
- (NSArray *)pmr_connectedPatchPorts;

// Delta Updates
extern NSString *const PMPortEffectiveValueDidChangeNotification;
extern NSString *const PMOutputPortBeginMonitoringValueNotification;
extern NSString *const PMOutputPortEndMonitoringValueNotification;
extern NSString *const PMOutputPortBroadcastValueNotification;
extern NSString *const PMOutputPortMonitoredValueNotification;

// Processing
@property (nonatomic, readonly) PMOutputProcessor *processor;

// TODO: Remove this unless things besides the processors call this.
- (void)setNeedsProcessing;

@end

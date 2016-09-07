//
//  PMConnection.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PMNode;
@class PMPort;

@interface PMConnection : NSObject <NSCoding>


+ (instancetype)connectPort:(PMPort *)port connectionKey:(NSString *)connectionKey parentNodeKey:(NSString *)parentNodeKey
              outputPortKey:(NSString *)outputPortKey outputNodeKey:(NSString *)outputNodeKey outputPortKeyPath:(NSArray *)outputPortKeyPath
               inputPortKey:(NSString *)inputPortKey   inputNodeKey:(NSString *)inputNodeKey   inputPortKeyPath:(NSArray *)inputPortKeyPath;
+ (void)breakConnection:(PMConnection *)connection;

// Replicator
+ (void)rebuildConnectionsForPort:(PMPort *)port;
+ (void)breakInvalidConnectionsForPort:(PMPort *)port;


- (instancetype)initWithUniqueKey:(NSString *)uniqueKey
                       outputPort:(PMPort *)outputPort
                        inputPort:(PMPort *)inputPort
                       parentNode:(PMNode *)parentNode
                outputPortKeyPath:(NSArray *)outputPortKeyPath
                 inputPortKeyPath:(NSArray *)inputPortKeyPath;

@property (nonatomic, readonly) NSString *uniqueKey;

@property (nonatomic, readonly, weak) PMPort *outputPort;
@property (nonatomic, readonly, weak) PMPort *inputPort;

@property (nonatomic, readonly, weak) PMNode *parentNode;
@property (nonatomic, readonly) NSArray *outputPortKeyPath;
@property (nonatomic, readonly) NSArray *inputPortKeyPath;

extern NSString *const PMConnectionRemoveConnectionNotification;

@end

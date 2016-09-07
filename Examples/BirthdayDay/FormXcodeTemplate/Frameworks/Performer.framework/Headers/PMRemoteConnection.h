//
//  PMRemoteConnection.h
//  Performer
//
//  Created by ederle on 6/17/15.
//  Copyright (c) 2015 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol PMRemoteConnectionDelegate;

@protocol PMRemoteConnection <NSObject>
@property (weak, nonatomic) id<PMRemoteConnectionDelegate> delegate;

// send message to other end of connection
- (void)sendMessage:(NSDictionary *)message;

// close the connection
- (void)closeConnection;

@end

@protocol PMRemoteConnectionDelegate <NSObject>

// Received message over connection
- (void)remoteConnection:(id<PMRemoteConnection>)connection
      didReceieveMessage:(NSDictionary *)message;

// Connection was closed
- (void)didCloseRemoteConnection:(id<PMRemoteConnection>)connection;

@end

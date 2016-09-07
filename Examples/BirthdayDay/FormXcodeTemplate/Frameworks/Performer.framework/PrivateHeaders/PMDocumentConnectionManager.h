//
//  PMDocumentConnectionManager.h
//  Perform
//
//  Created by ederle on 4/10/15.
//  Copyright (c) 2015 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Performer/PMDocumentPresentationCoordinator.h>
#import <Performer/PMDocumentCacheManager.h>

/**
 * Starts a server and opens PMRDocumentViewController's when a 
 * new connection arrives from Form app through the presentation
 * coordinator. The server connection is then handed off the 
 * view controller to manage the rest of it's document change
 * events. When the view controller closes, the connection manager
 * will restart the server to create a clean disconnect/connect
 * with the Form app to reset state.
 */
@interface PMDocumentConnectionManager : NSObject

- (id)initWithPresentationCoordinator:(PMDocumentPresentationCoordinator *)presentationCoordinator
                         cacheManager:(PMDocumentCacheManager *)cacheManager;

// close and relaunch the server
- (void)restartServer;

// close all sockets
- (void)shutdownServer;

@end

//
//  PMDeviceServer.h
//  Perform
//
//  Created by Max Weisel on 3/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>

// Server Delegate
#import "PMDeviceServerDelegate.h"

@interface PMDeviceServer : NSObject

@property (nonatomic, weak) id<PMDeviceServerDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithStatusPort:(uint16_t)statusPort
                       AndDataPort:(uint16_t)dataPort
                     AndDeviceName:(NSString *)name;

- (void)shutdown;

// sends disconnect and closes any accepcted sockets
- (void)disconnectDataSocket;

- (void)beginBroadcasting;
- (void)stopBroadcasting;

@property (nonatomic, readonly, getter = isBroadcasting) BOOL broadcasting;
@property (nonatomic, readonly) BOOL connected;

@end

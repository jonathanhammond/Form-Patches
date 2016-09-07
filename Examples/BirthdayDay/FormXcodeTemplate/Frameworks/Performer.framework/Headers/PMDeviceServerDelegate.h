//
//  PMDeviceServerDelegate.h
//  Perform
//
//  Created by Max Weisel on 3/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PMRemoteConnection.h"

@protocol PMDeviceServerDelegate <NSObject>

- (void)serverDidStartNewConnection:(id<PMRemoteConnection>)connection;

@end

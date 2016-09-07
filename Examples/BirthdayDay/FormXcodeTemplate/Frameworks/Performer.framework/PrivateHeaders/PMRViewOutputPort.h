//
//  PMRViewOutputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRValueOutputPort.h"

#import "PMRemoteGroupNode.h"

@interface PMRViewOutputPort : PMRValueOutputPort

@property (nonatomic, weak) PMRemoteGroupNode *remoteGroupNode;

@end

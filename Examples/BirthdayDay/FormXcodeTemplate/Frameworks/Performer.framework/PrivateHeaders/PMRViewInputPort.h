//
//  PMRViewInputPort.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import "PMRValueInputPort.h"

@class PMRemoteGroupNode;

@interface PMRViewInputPort : PMRValueInputPort

@property (nonatomic, readonly, weak) PMRemoteGroupNode *remoteGroupNode;

@end

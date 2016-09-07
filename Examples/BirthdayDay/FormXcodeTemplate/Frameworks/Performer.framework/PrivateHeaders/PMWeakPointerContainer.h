//
//  PMWeakPointerContainer.h
//  Performer
//
//  Created by Max Weisel on 3/31/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PMWeakPointerContainer : NSObject

- (instancetype)initWithObject:(id)object;

@property (nonatomic, readonly, weak) id object;

@end

//
//  FMKeyedUnarchiverDelegate.h
//  Form
//
//  Created by Chris Osborn on 7/10/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>

@class FMKeyedUnarchiver;

@protocol FMKeyedUnarchiverDelegate <NSObject>

- (Class)unarchiver:(FMKeyedUnarchiver *)unarchiver cannotDecodeObjectOfClassName:(NSString *)name;

@end

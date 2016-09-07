//
//  PMParameter.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PMNode;
@class PMRParameter;

@interface PMParameter : NSObject <NSCoding>

- (instancetype)initWithParameter:(PMParameter *)parameter deepCopy:(BOOL)deepCopy;

@property (nonatomic, readonly) NSString *uniqueKey;
@property (nonatomic, weak) PMNode *node;

// Copying
@property (nonatomic, readonly) NSString *processClassName;
- (id)deepCopy;

// Patch
@property (nonatomic, strong) PMRParameter *patchParameter;

@end

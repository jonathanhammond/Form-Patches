//
//  PMRParameter.h
//  Performer
//
//  Created by Max Weisel on 7/1/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 The PMRParameter class represents a parameter on a patch. Parameters are used to expose editable values that should not be changed at runtime. (e.g. Number of dimensions on a spring). Generally parameters are used for values that will dynamically change the input or output ports on a patch.
 
 */
@interface PMRParameter : NSObject

///---------------------------------------------------------------------------------------
/// @name Properties
///---------------------------------------------------------------------------------------

/*!
 @brief The unqiue key of the parameter.
 @details This property represents the unique key of the parameter.
 */
@property (nonatomic, readonly) NSString *uniqueKey;

@end

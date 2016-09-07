//
//  PMRProcessContext.h
//  Performer
//
//  Created by Max Weisel on 6/25/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 The PMRPatch class represents state that is unique to the currently processing frame.
 
 */
@interface PMRProcessContext : NSObject

///---------------------------------------------------------------------------------------
/// @name Properties
///---------------------------------------------------------------------------------------

/*!
 @brief A double that represents the delta time of the frame.
 @details This property represents the amount of time in seconds since the last frame was drawn. This should be used for calculations in animations.
 */
@property (nonatomic, readonly) double deltaTime;

/*!
 @brief A timestamp of when the currently drawing frame will be presented.
 @details A CFTimeInterval that represents when the current drawing frame will be displayed. This value should be used for any video syncing with AVFoundation.
 */
@property (nonatomic, readonly) CFTimeInterval videoSync;

@end

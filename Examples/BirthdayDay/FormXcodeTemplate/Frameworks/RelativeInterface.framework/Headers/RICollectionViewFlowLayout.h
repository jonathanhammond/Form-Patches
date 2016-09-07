//
//  RICollectionViewFlowLayout.h
//  RelativeInterface
//
//  Created by Max Weisel on 9/11/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

#import "RICollectionViewLayout.h"

typedef enum {
    RIScrollDirectionVertical,
    RIScrollDirectionHorizontal
} RIScrollDirection;

/*!
 The RICollectionViewFlowLayout class is an RICollectionViewLayout subclass that automatically lays out all items in a grid-like fashion.
 
 Items can scroll vertically or horizontally.
 */

@interface RICollectionViewFlowLayout : RICollectionViewLayout

///---------------------------------------------------------------------------------------
/// @name Layout
///---------------------------------------------------------------------------------------

/*!
 @brief An enum that specifies the scroll direction of the layout.
 @details This value is used to layout items horizontally or vertically.
 
 The default value of this property is RIScrollDirectionVertical.
 */
@property (nonatomic, assign) RIScrollDirection scrollDirection;

/*!
 @brief A value that represents the size of each item in the collection.
 @details This value is used to size each RICollectionViewItem.
 */
@property (nonatomic, assign) RISize3F itemSize;

// TODO: Implement itemSpacing;

@end

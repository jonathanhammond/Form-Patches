//
//  RICollectionViewLayoutItem.h
//  RelativeInterface
//
//  Created by Max Weisel on 9/9/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

// External
#import <Foundation/Foundation.h>

// Geometry Types
#import "RIGeometry.h"

// Collection View Item Index
#import "RICollectionViewItemIndex.h"

/*!
 The RICollectionViewLayoutItem class is used to represent a single item in an RICollectionViewLayout.
 
 Custom layouts should subclass this object to provide information for laying out RICollectionViewItems. Whenever an item is first displayed on screen, it is passed its corresponding layout item via -[RICollectionViewItem applyLayoutItem:].
 */

@interface RICollectionViewLayoutItem : NSObject

///---------------------------------------------------------------------------------------
/// @name Creating a layout item
///---------------------------------------------------------------------------------------

/*!
 @brief Creates a new layout item with the specified item index.
 @details This method initializes an RICollectionViewLayoutItem with the specified item index.
 @param itemIndex The itemIndex that this item should represent.
 */
- (id)initWithItemIndex:(RICollectionViewItemIndex *)itemIndex;


///---------------------------------------------------------------------------------------
/// @name Index
///---------------------------------------------------------------------------------------

/*!
 @brief The item index that this layout item represents.
 @details This property holds the item index that the layout item represents in its layout.
 */
@property (nonatomic, readonly) RICollectionViewItemIndex *itemIndex;


///---------------------------------------------------------------------------------------
/// @name Layout
///---------------------------------------------------------------------------------------

/*!
 @brief The origin of the item.
 @details This property details the origin of the item. RICollectionView automatically applies it to the appropriate RICollectionViewItem.
 */
@property (nonatomic, assign) RIPoint3F origin3;

/*!
 @brief The size of the item.
 @details This property details the size of the item. RICollectionView automatically applies it to the appropriate RICollectionViewItem.
 */
@property (nonatomic, assign) RISize3F size3;

@end

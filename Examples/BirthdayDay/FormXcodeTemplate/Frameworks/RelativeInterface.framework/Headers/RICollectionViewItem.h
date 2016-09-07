//
//  RICollectionViewItem.h
//  RelativeInterface
//
//  Created by Max Weisel on 9/9/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

#import "RIView.h"

@class RICollectionViewLayoutItem;

/*!
 The RICollectionViewItem class is used to represent a single item on screen inside of an RICollectionView.
 
 RICollectionViewItem's should not be created directly. Instead, they should be retrieved from the collection view using the -[RICollectionView dequeueItemWithIdentifier:] method.
 */

@interface RICollectionViewItem : RIView

///---------------------------------------------------------------------------------------
/// @name State
///---------------------------------------------------------------------------------------

/*!
 @brief A boolean value indicating whether the item is currently highlighted.
 @details This property represents the highlighted state of the item. It is automatically updated by the collection view.
 */
@property (nonatomic, assign) BOOL highlighted;

/*!
 @brief A boolean value indicating whether the item is currently selected.
 @details This property represents the selected state of the item. It is automatically updated by the collection view.
 */
@property (nonatomic, assign) BOOL selected;


///---------------------------------------------------------------------------------------
/// @name Item Reuse
///---------------------------------------------------------------------------------------

/*!
 @brief A string that represents the identifier used to register the item class for reuse.
 @details This property is automatically set by the collection view upon creating the item.
 */
@property (nonatomic, readonly, copy) NSString *reuseIdentifier;

/*!
 @brief Prepare the item to be reused.
 @details This method is called by the collection view just before dequeuing an item for reuse.
 */
- (void)prepareForReuse;

/*!
 @brief Apply a layout item to the receiving collection view item.
 @details Custom RICollectionViewItem subclasses should use this method to apply their corresponding layout items. RICollectionView automatically sets the origin and size.
 
 The default implementation of this method does nothing.
 @param layoutItem The layout item to apply to the receiving collection view item.
 */
- (void)applyLayoutItem:(RICollectionViewLayoutItem *)layoutItem;

@end

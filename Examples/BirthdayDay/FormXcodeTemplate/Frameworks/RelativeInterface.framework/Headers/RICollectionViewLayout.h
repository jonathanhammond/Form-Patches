//
//  RICollectionViewLayout.h
//  RelativeInterface
//
//  Created by Max Weisel on 9/9/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

// External
#import <Foundation/Foundation.h>

// Geometry Types
#import "RIGeometryTypes.h"

@class RICollectionView;

/*!
 The RICollectionViewLayout class is used to describe a layout of items in a collection.
 
 RelativeInterface includes two prebuilt layouts:
 RICollectionViewListLayout - A layout that functions as a vertical scrolling list of items. (Similar to Apple's UITableView)
 RICollectionViewFlowLayout - A layout that automatically lays out all items in a grid-like fashion. Items can scroll vertically or horizontally.
 */

@interface RICollectionViewLayout : NSObject

/*!
 @brief The collection view associated with the layout
 @details A weak reference to the collection view associated with the layout.
 */
@property (nonatomic, readonly, weak) RICollectionView *collectionView;


///---------------------------------------------------------------------------------------
/// @name Method overrides
///---------------------------------------------------------------------------------------

/*!
 @brief Prepares the layout for use.
 @details Called by the collection view to instruct the layout to prepare. Subclasses should override this method to prepare any information needed to create the layout.
 */
- (void)prepareLayout;

/*!
 @brief Returns the size of the layout.
 @details Called by the collection view to retrieve the size of the layout area. Subclasses should override this method and return the area that the layout occupies in the collection view.
 */
- (RISize2F)layoutContentSize;

/*!
 @brief Returns an array of layout items in a given content area.
 @details Called by the collection view to retrieve the layout items for a specific section of the layout. Subclasses should override this method and return an NSArray of RICollectionViewLayoutItems that detail the position of each item that exist in the given content area.
 @param contentArea The rect that represents the area to be displayed.
 */
- (NSArray *)layoutItemsForContentArea:(RIRect2F)contentArea;

/*!
 @brief Returns whether or not the layout should be invalidated upon changing the content area.
 @details Called by the collection view whenever the visible content bounds change. Subclasses should override this method and return YES or NO based on the new content area.
 
 The default implementation returns NO.
 @param contentArea The rect that represents the area to be displayed.
 */
- (BOOL)shouldInvalidateLayoutForContentAreaChange:(RIRect2F)contentArea;

/*!
 @brief Invalidates the layout.
 @details Calling this method effectively invalidates a layout object. This will cause RICollectionView to call -prepareLayout, -layoutContentSize and -layoutItemsForContentArea: again.
 */
- (void)invalidateLayout;

@end

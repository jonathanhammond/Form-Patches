//
//  RICollectionViewItemIndex.h
//  RelativeInterface
//
//  Created by Max Weisel on 9/12/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 The RICollectionViewItemIndex class is used to represent a single item's index in a collection.
 
 RICollectionView uses this class when requesting RICollectionViewItems and RICollectionViewLayoutItems from its data source / layout objects respectively.
 */

@interface RICollectionViewItemIndex : NSObject <NSCopying>

///---------------------------------------------------------------------------------------
/// @name Creating an index
///---------------------------------------------------------------------------------------

/*!
 @brief Creates a new item index with the specified section and index.
 @details This method initializes an RICollectionViewItemIndex with the specified section / index pair.
 @param section The section to point to.
 @param index The index to point to.
 */
+ (id)itemIndexWithSection:(int)section index:(int)index;

/*!
 @brief Creates a new item index with the specified section and index.
 @details This method initializes an RICollectionViewItemIndex with the specified section / index pair.
 @param section The section to point to.
 @param index The index to point to.
 */
- (id)initWithSection:(int)section index:(int)index;

/*!
 @brief An integer that represents the section that the item index belongs to.
 */
@property (nonatomic, readonly) int section;

/*!
 @brief An integer that represents the index that the item index belongs to.
 */
@property (nonatomic, readonly) int index;



@end

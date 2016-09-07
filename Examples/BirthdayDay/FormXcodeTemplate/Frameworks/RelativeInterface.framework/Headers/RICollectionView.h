//
//  RICollectionView.h
//  RelativeInterface
//
//  Created by Max Weisel on 9/9/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

#import "RIScrollView.h"
#import "RICollectionViewLayout.h"
#import "RICollectionViewDataSource.h"
#import "RICollectionViewDelegate.h"

/*!
 The RICollectionView class is used to display a collection of items on screen using a dynamic layout.
 
 RICollectionView involves a few key classes:
 
 RICollectionViewItem - An RIView subclass that is positioned by the collection view on screen.
 
 RICollectionViewLayout - An object that tells the collection view where to position each RICollectionViewItem.
    RICollectionViewLayoutItem - An object that is used to represent a single RICollectionViewItem in a particular layout.
 
 RICollectionViewDataSource - A protocol used to describe the class that will provide various information about the items to display on screen.
 RICollectionViewDelegate - A protocol used to describe the class that will receive messages regarding interaction with the content.
 
 RICollectionView comes with two premade layouts:
 RICollectionViewListLayout - A layout that functions as a vertical scrolling list of items. (Similar to Apple's UITableView)
 RICollectionViewFlowLayout - A layout that automatically lays out all items in a grid-like fashion. Items can scroll vertically or horizontally.
 */

@interface RICollectionView : RIScrollView

///---------------------------------------------------------------------------------------
/// @name Creating a collection view
///---------------------------------------------------------------------------------------

/*!
 @brief Creates a new collection view with a designated layout.
 @details This method initializes an RICollectionView with the specified layout.
 @param layout The RICollectionViewLayout object used to initialize the collection view.
 */
- (id)initWithLayout:(RICollectionViewLayout *)layout;


///---------------------------------------------------------------------------------------
/// @name Setting the info sources
///---------------------------------------------------------------------------------------

/*!
 @brief The layout used by the collection view.
 @details This property references the RICollectionViewLayout object that the collection view will retrieve layout information from.
 */
@property (nonatomic, strong) RICollectionViewLayout *layout;

/*!
 @brief The data source used by the collection view.
 @details This property references an object that implements the RICollectionViewDataSource protocol. The data source is responsible for providing information like the number of sections, the number of items per section and the RICollectionViewItem objects themselves.
 */
@property (nonatomic, weak) id <RICollectionViewDataSource> dataSource;

/*!
 @brief The delegate used by the collection view.
 @details This property references an object that implements the RICollectionViewDelegate protocol. The delegate is responsible for handling things like item selection/deselection and highlight/unhighlight of items in the collection view.
 */
@property (nonatomic, weak) id <RICollectionViewDelegate> delegate;

/*!
 @brief Forces the collection view to reload all information from the data source.
 @details This method forces the collection view to reload all information from its data source and invalidates the current layout.
 @note Calling reloadData will cause the collection view to only load data once per run loop.
 */
- (void)reloadData;


///---------------------------------------------------------------------------------------
/// @name Configuration
///---------------------------------------------------------------------------------------

/*!
 @brief A boolean value that determines whether or not multiple items can be selected at the same time.
 @details This property sets if multiple items can be selected at the same time. If disabled, when a new item is selected, previously selected items will be deselected.
 
 The default value is NO.
 */
@property (nonatomic, assign) BOOL allowsMultipleSelection;


///---------------------------------------------------------------------------------------
/// @name Item Reuse
///---------------------------------------------------------------------------------------

/*!
 @brief Register an RICollectionViewItem class for use with the collection view.
 @details This method is used to register a class to be used inside of RICollectionView. Once registered, items may be dequeued using the -[RICollectionView dequeueItemWithIdentifier:] method.
 @param itemClass The class to register.
 @param identifier The identifier used to retrieve the item when dequeuing.
 */
- (void)registerItemClass:(Class)itemClass reuseIdentifier:(NSString *)identifier;

/*!
 @brief Dequeues a collection item with the given identifier.
 @details This method is used to dequeue an RICollectionViewItem for use with the collection view.
 
 The most common use of this method is to get a new item to pass to the collection view via the RICollectionViewDataSource's -collectionView:ItemAtIndex: method.
 
 If an RICollectionViewItem is not available for reuse, a new one will be created by calling [[itemClass alloc] init] on the class that is registered with the identifier passed.
 @param identifier The identifier used to retrieve an item.
 */
- (RICollectionViewItem *)dequeueItemWithIdentifier:(NSString *)identifier;

///---------------------------------------------------------------------------------------
/// @name Info
///---------------------------------------------------------------------------------------

/*!
 @brief Returns the number of sections in the collection view.
 @details This method returns the number of sections in the collection view. If data has not been pulled from the data source, it will request it and return the appropriate value.
 */
- (int)numberOfSections;

/*!
 @brief Returns the number of items in a particular section in the collection view.
 @details This method returns the number of rows in a particular sections in the collection view. If data has not been pulled from the data source, it will request it and return the appropriate value.
 @param section The section to grab the number of items from.
 */
- (int)numberOfItemsInSection:(int)section;


///---------------------------------------------------------------------------------------
/// @name Selection
///---------------------------------------------------------------------------------------

/*!
 @brief Selects a collection view item at a particular index.
 @details This method selects an item at a particular index. If allowsMultipleSelection is set to NO, any other selected items will be deselected silently.
 @param itemIndex The item index to select.
 */
- (void)selectItemAtIndex:(RICollectionViewItemIndex *)itemIndex;

/*!
 @brief Deselects a collection view item at a particular index.
 @details This method deselects an item at a particular index.
 @param itemIndex The item index to deselect.
 */
- (void)deselectItemAtIndex:(RICollectionViewItemIndex *)itemIndex;

@end

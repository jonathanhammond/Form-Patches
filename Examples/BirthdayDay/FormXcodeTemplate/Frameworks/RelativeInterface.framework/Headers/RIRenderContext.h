//
//  RIRenderContext.h
//  RelativeInterface
//
//  Created by Max Weisel on 11/20/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

// External
#import <Foundation/Foundation.h>

/*!
 The RIRenderContext class represents a single OpenGL context.
 
 RIRenderContext is used to execute all OpenGL commands asynchronously to take advantage of multi-core devices for CPU<->GPU data transfer. All OpenGL commands that are meant for RelativeInterface should be executed via a render context.
 
 All commands submitted to render contexts created by an RIApplication should be dispatched from the main thread. The main thread is used as a synchronization point to ensure blocks are executed in proper order.
 */

@interface RIRenderContext : NSObject

///---------------------------------------------------------------------------------------
/// @name Getting the active render context
///---------------------------------------------------------------------------------------

/*!
 @brief The active render context.
 @details Use this method to retrieve the active render context. You will rarely need to create a render context. In almost all cases, the context created by RIApplication is the context you should submit render commands to.
 
 This method retrieves the last activated context. If inside of a clock tick, layoutSubviews, or draw method, activeContext will return the appropriate render context for the application that is currently rendering.
 */
+ (RIRenderContext *)activeContext;

///---------------------------------------------------------------------------------------
/// @name Creating a render context
///---------------------------------------------------------------------------------------

/*!
 @brief Create a new render context that shares resources with another context.
 @details Use this method to create a new render context.
 
 Pass in another render context to allow blocks executed on it to operate on resources created with other contexts (images, shaders, etc).
 @param renderContext The render context to share resources with.
 */
- (id)initWithSharedContext:(RIRenderContext *)renderContext;

/*!
 @brief Execute a block of OpenGL commands on the render context.
 @details Use this method to execute a block of OpenGL commands on the render context.
 
 All blocks are executed asynchronously and in the order they are dispatched to the render context.
 
 If -[RIRenderContext dispatchBlock] is called from inside of a block that is being executed by the render context, it is executed synchronously.
 @param block The block of render commands to execute.
 */
- (void)dispatchBlock:(void (^)(void))block;

@end

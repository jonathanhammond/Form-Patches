//
//  RIApplication.h
//  RelativeInterface
//
//  Created by Max Weisel on 11/19/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

// External
#import <Foundation/Foundation.h>
#import "RIPlatform.h"
#import RIExternalFramework(RISystemUIFramework, RISystemView.h)

// Window
#import "RIWindow.h"

// Render Context
#import "RIRenderContext.h"

// Animation Clock
#import "RIAnimationClock.h"

// Caches
#import "RIImageCache.h"
#import "RIShaderCache.h"

/*!
 The RIApplication class manages all rendering and interaction.
 
 An RIApplication instance manages the bridge between a RelativeInterface application and the native window environment. The final rendered output is displayed in the renderView. All interaction that occurs on the renderView is handled by RIApplication and passed to the RIWindow.
 
 Most applications will only need a single RIApplication, however, applications that wish to run multiple screens can utilize multiple instances of RIApplication.
 
 Every RIApplication has a unique renderContext and animationClock. In most cases, it is safe to use the -[RIRenderContext activeContext] and -[RIAnimationClock activeClock] methods to retrieve the appropriate instance. RIApplication exposes properties for both if you need to reference them directly.
 
 RIApplication creates all RIRenderContexts under the same sharegroup. This means it is safe to share assets (images, shaders, etc) between multiple RIApplication instances.
 */

@interface RIApplication : NSObject


///---------------------------------------------------------------------------------------
/// @name Application render
///---------------------------------------------------------------------------------------

/*!
 @brief The application render view.
 @details The application render view is a view that is made to be inserted into the native window environment.
 
 In addition to displaying the rendered output, the renderView also acts as an input for all interaction events.
 */
@property (nonatomic, readonly) RISystemView *renderView;


///---------------------------------------------------------------------------------------
/// @name Application window
///---------------------------------------------------------------------------------------

/*!
 @brief The application window.
 @details This is the entry point for all view in an RIApplication. In order for a view to render, it needs to be added as a subview of an application's window.
 
 The RIWindow has no superview. It owns the application's projection matrix and is responsible for unprojecting all interaction.
 */
@property (nonatomic, readonly) RIWindow *window;


///---------------------------------------------------------------------------------------
/// @name Rendering
///---------------------------------------------------------------------------------------

/*!
 @brief A Boolean value used to pause and resume rendering.
 @details Use this property to pause rendering without clearing the screen.
 
 Normally this property is used with UIApplicationDelegate applicationWillResignActive & applicationDidBecomeActive)
 
 The default value is NO.
 
 @note Pausing the application does not stop GPU access. Use the active property of RIApplication instead.
 */
@property (nonatomic, getter = isPaused) BOOL paused;

/*!
 @brief A Boolean value used to start and stop rendering.
 
 @details Use this property to stop rendering and cease all GPU access. This is particularly useful to prevent the application from being killed for background GPU access.
 
 Normally this property is used with UIApplicationDelegate applicationDidEnterBackground & applicationWillEnterForeground)
 
 The default value is NO.
 */
@property (nonatomic, getter = isActive) BOOL active;


/*!
 @brief A render context used for the application's rendering.
 @details All OpenGL commands are executed via an RIRenderContext object in RelativeInterface. Every application has its own render context.
 
 It is recommended that the render context be retrieved via -[RIRenderContext activeContext]. This allows for one to write custom drawing code that can execute independently of a single RIApplication instance.
 */
@property (nonatomic, readonly) RIRenderContext *renderContext;


///---------------------------------------------------------------------------------------
/// @name Animation
///---------------------------------------------------------------------------------------

/*!
 @brief An animation clock that is synced to the renderer.
 @details The application's animation clock is used to schedule updates that should occur once per frame.
 
 Every tick of the animation clock comes before the layout and draw phases of each frame.
 */
@property (nonatomic, readonly) RIAnimationClock *animationClock;


///---------------------------------------------------------------------------------------
/// @name Caches
///---------------------------------------------------------------------------------------

/*!
 @brief An image cache used by the application.
 @details Each application maintains a reference to a shared image cache. Normally, you do not need to access the image cache directly, but it can be useful for manually adding images to the cache.
 
 See RIImage for more information on when the cache is used automatically.
 */
@property (nonatomic, readonly) RIImageCache *imageCache;

/*!
 @brief A shader cache used by the application.
 @details Each application maintains a reference to a shared shader cache. Normally, you do not need to access the shader cache directly, but it can be useful for manually adding shaders to the cache.
 
 See RIShader for more information on when the cache is used automatically.
 */
@property (nonatomic, readonly) RIShaderCache *shaderCache;

@end

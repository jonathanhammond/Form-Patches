//
//  PMRPatch.h
//  Performer
//
//  Created by Max Weisel on 6/24/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PMRPort;
@class PMRProcessContext;

/*!
 The PMRPatch class represents a patch in Form's viewer.
 
 PMRPatch is made to be subclassed. Each patch subclass performs the following:
 - Loads ports and parameters defined by its matching FMRNode subclass.
 - Processes values from its inputs and stores them in its outputs.
 
 */
@interface PMRPatch : NSObject

///---------------------------------------------------------------------------------------
/// @name Ports
///---------------------------------------------------------------------------------------

/*!
 @brief This method is called when a patch is created or ports are added / removed.
 @details Override this method to in order to set up all of your ports. Ports are automatically created by the system, this method is your entry point to create references to each port for use later.
 
 The default implementation will automatically load ports into properties that have the same name as the uniqueKey. For patches that have a dynamic number of ports, override this method and use -[PMRPatch portForUniqueKey:] to retrieve and store reach port.
 */
- (void)setupPorts;

/*!
 @brief This method returns a PMRPort instance for a specific uniqueKey.
 @details Use this method to retrieve a port by its uniqueKey (created in the node subclass).
 @param uniqueKey The uniqueKey of the port.
 */
- (id)portForUniqueKey:(NSString *)uniqueKey;

///---------------------------------------------------------------------------------------
/// @name Parameters
///---------------------------------------------------------------------------------------

/*!
 @brief This method is called when a patch is created or parameters are added / removed.
 @details Override this method to in order to set up all of your parameters. Parameters are automatically created by the system, this method is your entry point to create references to each parameter for use later.
 
 The default implementation will automatically load parameters into properties that have the same name as the uniqueKey. For patches that have a dynamic number of parameters, override this method and use -[PMRPatch parameterForUniqueKey:] to retrieve and store reach parameter.
 */
- (void)setupParameters;

/*!
 @brief This method returns a PMRParameter instance for a specific uniqueKey.
 @details Use this method to retrieve a parameter by its uniqueKey (created in the node subclass).
 @param uniqueKey The uniqueKey of the parameter.
 */
- (id)parameterForUniqueKey:(NSString *)uniqueKey;


///---------------------------------------------------------------------------------------
/// @name Properties
///---------------------------------------------------------------------------------------

/*!
 @brief A boolean value that determines whether this patch is a consumer patch.
 @details The Form runtime works to only process patches whose output ports are used by other patches. However, sometimes it is necessary for a patch to process regardless of whether its outputs are being used for the current frame. these are patches that have persistent state (Switch, Sample & Hold, etc).
 
 The default implementation of this property returns YES for patches with no output ports.
 */
@property (nonatomic, readonly, getter = isConsumerPatch) BOOL consumerPatch;


///---------------------------------------------------------------------------------------
/// @name Processing
///---------------------------------------------------------------------------------------

/*!
 @brief This method processes the patch for a single frame.
 @details When the Form runtime has determined that this patch needs to run, it will call this method. Subclasses should override this method and do all of their processing in it.
 @param context A PMRProcessContext object that includes information about the currently processing frame.
 */
- (void)processPatchWithContext:(PMRProcessContext *)context;

/*!
 @brief This method processes the patch for a single frame.
 @details When the Form runtime has determined that this patch needs to run, it will call this method. Subclasses should override this method and do all of their processing in it.
 
 This method is exactly the same as -[PMRPatch processPatchWithContext:] only it is called for the output ports whose values are required to process other patches. If calculating a specific value is very expensive, this method can be used to only do heavy processing when a particular port's value is needed.
 @param context A PMRProcessContext object that includes information about the currently processing frame.
 */
- (void)processOutput:(PMRPort *)outputPort context:(PMRProcessContext *)context;

/*!
 @brief This method marks the patch to be processed on the next frame.
 @details This method should be called by subclasses who wish to mark a patch's output port values as dirty. Upon doing so, the patch will be reevaluated on the next frame.
 */
- (void)setShouldProcessNextFrame;

/*!
 @brief This method is called by the Form runtime when an input port value is marked dirty.
 @details The default implementation of this method calls -[PMRPatch setShouldProcessNextFrame]. If processing a patch is expensive, extra logic can be added to this method to determine whether or not new input should require the patch to reprocess.
 */
- (void)inputPortValueDirty:(PMRPort *)port;

@end

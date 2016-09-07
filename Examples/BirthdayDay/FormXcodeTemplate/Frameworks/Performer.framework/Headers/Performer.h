//
//  Performer.h
//  Performer
//
//  Created by Max Weisel on 4/28/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

// RelativeInterface
#if TARGET_OS_IPHONE
#  import <RelativeInterface/RelativeInterface.h>
#elif TARGET_OS_MAC
#  import <RelativeInterfaceMac/RelativeInterfaceMac.h>
#endif

// Patch
#import "PMRPatch.h"
#import "PMRViewPatch.h"

// Ports
#import "PMRPort.h"
#import "PMRInputPort.h"
#import "PMROutputPort.h"
#import "PMRValueInputPort.h"
#import "PMRValueOutputPort.h"
#import "PMRPrimitiveInputPort.h"
#import "PMRPrimitiveOutputPort.h"
#import "PMRAngleInputPort.h"
#import "PMRImageInputPort.h"
#import "PMRImageOutputPort.h"
#import "PMRArrayInputPort.h"
#import "PMRArrayOutputPort.h"
#import "PMRDictionaryInputPort.h"
#import "PMRDictionaryOutputPort.h"
#import "PMRFilterInputPort.h"
#import "PMRFilterOutputPort.h"

// Parameters
#import "PMRBooleanParameter.h"
#import "PMRIndexParameter.h"
#import "PMRNumberParameter.h"
#import "PMRColorParameter.h"
#import "PMRStringParameter.h"
#import "PMRImageParameter.h"

// Process Context
#import "PMRProcessContext.h"

// Document
#import "PMRDocument.h"

// Utility
#import "PMRErrors.h"
#import "PMRMacros.h"
#import "PMRVersion.h"

// Connections
#import "PMDeviceServer.h"
#import "PMDeviceServerDelegate.h"

#import "PMPresentationController.h"

#if TARGET_OS_IPHONE
#  import "PMPresentationController.h"
#  import "PMRDocumentViewController.h"
#endif

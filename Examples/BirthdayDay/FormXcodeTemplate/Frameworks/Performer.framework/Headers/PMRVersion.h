//
//  PMRVersion.h
//  Performer
//
//  Created by Chris Osborn on 10/15/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

typedef struct {
    int version;
} PMRDeviceProtocolVersion;

PMRDeviceProtocolVersion PMRCurrentDeviceProtocolVersion();

NSString *PMRStringFromDeviceProtocolVersion(PMRDeviceProtocolVersion deviceProtocolVersion);
PMRDeviceProtocolVersion PMRDeviceProtocolVersionFromString(NSString *versionString);

//
//  FMVersion.h
//  Form
//
//  Created by Chris Osborn on 7/10/14.
//  Copyright (c) 2014 Relative Wave. All rights reserved.
//

// Document Version

typedef struct {
    int majorVersion;
    int minorVersion;
    int patchVersion;
} FMVersion;

FMVersion FMCurrentVersion();

NSString *FMStringFromVersion(FMVersion version);
FMVersion FMVersionFromString(NSString *versionString);

// Device Protocol Version

typedef struct {
    int version;
} FMDeviceProtocolVersion;

FMDeviceProtocolVersion FMCurrentDeviceProtocolVersion();

NSString *FMStringFromDeviceProtocolVersion(FMDeviceProtocolVersion deviceProtocolVersion);
FMDeviceProtocolVersion FMDeviceProtocolVersionFromString(NSString *versionString);

BOOL FMDeviceProtocolVersionIsCompatible(FMDeviceProtocolVersion deviceProtocolVersionA,
                                         FMDeviceProtocolVersion deviceProtocolVersionB);

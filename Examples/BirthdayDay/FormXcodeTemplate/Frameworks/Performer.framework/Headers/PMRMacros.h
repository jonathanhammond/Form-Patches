//
//  PMRMacros.h
//  Performer
//
//  Created by osbornc on 2/18/15.
//  Copyright (c) 2015 Relative Wave. All rights reserved.
//

#ifndef Performer_PMRMacros_h
#define Performer_PMRMacros_h

#if !defined(PMR_COUNT)
#define PMR_COUNT(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))
#endif

#if !defined(PMR_STR) && !defined(PMR_STR_) && !defined(PMRStringValue)
#define PMR_STR(x) #x
#define PMR_STR_(x) PMR_STR(x)
#define PMRStringValue(text) @ PMR_STR_(text)
#endif

#endif

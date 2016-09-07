//
//  RIGeometryFunctions.h
//  RelativeInterface
//
//  Created by Max Weisel on 11/25/13.
//  Copyright (c) 2013 RelativeWave. All rights reserved.
//

// Base
#import "RIBase.h"

// External Types
#import <GLKit/GLKMatrix4.h>

// Types
#import "RIGeometryTypes.h"

//// Points

// Make
RI_INLINE RIPoint2F RIPointMake2F(float x, float y) {
#ifdef __cplusplus
    RIPoint2F point = RIPoint2F(x, y);
#else
    RIPoint2F point = {.x = x, .y = y};
#endif
    return point;
}

RI_INLINE RIPoint2D RIPointMake2D(double x, double y) {
#ifdef __cplusplus
    RIPoint2D point = RIPoint2D(x, y);
#else
    RIPoint2D point = {.x = x, .y = y};
#endif
    return point;
}

RI_INLINE RIPoint2I RIPointMake2I(int x, int y) {
#ifdef __cplusplus
    RIPoint2I point = RIPoint2I(x, y);
#else
    RIPoint2I point = {.x = x, .y = y};
#endif
    return point;
}

RI_INLINE RIPoint3F RIPointMake3F(float x, float y, float z) {
#ifdef __cplusplus
    RIPoint3F point = RIPoint3F(x, y, z);
#else
    RIPoint3F point = {.x = x, .y = y, .z = z};
#endif
    return point;
}

// Compare
RI_INLINE BOOL RIPointIsEqualToPoint2F(RIPoint2F p1, RIPoint2F p2) {
    return (p1.x == p2.x && p1.y == p2.y);
}

RI_INLINE BOOL RIPointIsEqualToPoint2D(RIPoint2D p1, RIPoint2D p2) {
    return (p1.x == p2.x && p1.y == p2.y);
}

RI_INLINE BOOL RIPointIsEqualToPoint2I(RIPoint2I p1, RIPoint2I p2) {
    return (p1.x == p2.x && p1.y == p2.y);
}

RI_INLINE BOOL RIPointIsEqualToPoint3F(RIPoint3F p1, RIPoint3F p2) {
    return (p1.x == p2.x && p1.y == p2.y && p1.z == p2.z);
}

// Normalize
RI_INLINE RIPoint2F RIPointNormalize2F(RIPoint2F p) {
    float d = sqrtf((p.x * p.x) + (p.y * p.y));
    p.x /= d;
    p.y /= d;
    return p;
}

RI_INLINE RIPoint3F RIPointNormalize3F(RIPoint3F p) {
    float d = sqrtf((p.x * p.x) + (p.y * p.y) + (p.z * p.z));
    p.x /= d;
    p.y /= d;
    p.z /= d;
    return p;
}

// Negate
RI_INLINE RIPoint2F RIPointNegate2F(RIPoint2F p) {
    return RIPointMake2F(-p.x, -p.y);
}

RI_INLINE RIPoint3F RIPointNegate3F(RIPoint3F p) {
    return RIPointMake3F(-p.x, -p.y, -p.z);
}

// Add
RI_INLINE RIPoint2F RIPointAdd2F(RIPoint2F p1, RIPoint2F p2) {
    return RIPointMake2F(p1.x + p2.x, p1.y + p2.y);
}

RI_INLINE RIPoint3F RIPointAdd3F(RIPoint3F p1, RIPoint3F p2) {
    return RIPointMake3F(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
}

// Subtract
RI_INLINE RIPoint2F RIPointSubtract2F(RIPoint2F p1, RIPoint2F p2) {
    return RIPointMake2F(p1.x - p2.x, p1.y - p2.y);
}

RI_INLINE RIPoint3F RIPointSubtract3F(RIPoint3F p1, RIPoint3F p2) {
    return RIPointMake3F(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
}

// Multiply
RI_INLINE RIPoint2F RIPointMultiply2F(RIPoint2F p1, RIPoint2F p2) {
    return RIPointMake2F(p1.x * p2.x, p1.y * p2.y);
}

RI_INLINE RIPoint3F RIPointMultiply3F(RIPoint3F p1, RIPoint3F p2) {
    return RIPointMake3F(p1.x * p2.x, p1.y * p2.y, p1.z * p2.z);
}

// Divide
RI_INLINE RIPoint2F RIPointDivide2F(RIPoint2F p1, RIPoint2F p2) {
    return RIPointMake2F(p1.x / p2.x, p1.y / p2.y);
}

RI_INLINE RIPoint3F RIPointDivide3F(RIPoint3F p1, RIPoint3F p2) {
    return RIPointMake3F(p1.x / p2.x, p1.y / p2.y, p1.z / p2.z);
}

// Scale
RI_INLINE RIPoint2F RIPointScale2F(RIPoint2F p1, float s) {
    return RIPointMake2F(p1.x * s, p1.y * s);
}

RI_INLINE RIPoint3F RIPointScale3F(RIPoint3F p1, float s) {
    return RIPointMake3F(p1.x * s, p1.y * s, p1.z * s);
}

// Cross Product
RI_INLINE RIPoint3F RIPointCrossProduct3F(RIPoint3F p1, RIPoint3F p2) {
    RIPoint3F crossProduct;
	crossProduct.x = (p1.y * p2.z) - (p1.z * p2.y);
	crossProduct.y = (p1.z * p2.x) - (p1.x * p2.z);
	crossProduct.z = (p1.x * p2.y) - (p1.y * p2.x);
	return crossProduct;
}

// Dot Product
RI_INLINE float RIPointDotProduct3F(RIPoint3F p1, RIPoint3F p2) {
    return (p1.x*p2.x + p1.y*p2.y + p1.z*p2.z);
}


//// Sizes

// Make
RI_INLINE RISize2F RISizeMake2F(float width, float height) {
#ifdef __cplusplus
    RISize2F size = RISize2F(width, height);
#else
    RISize2F size = {.width = width, .height = height};
#endif
    return size;
}

RI_INLINE RISize2I RISizeMake2I(int width, int height) {
#ifdef __cplusplus
    RISize2I size = RISize2I(width, height);
#else
    RISize2I size = {.width = width, .height = height};
#endif
    return size;
}

RI_INLINE RISize3F RISizeMake3F(float width, float height, float depth) {
#ifdef __cplusplus
    RISize3F size = RISize3F(width, height, depth);
#else
    RISize3F size = {.width = width, .height = height, .depth = depth};
#endif
    return size;
}

// Compare
RI_INLINE BOOL RISizeIsEqualToSize2F(RISize2F s1, RISize2F s2) {
    return (s1.width  == s2.width && s1.height == s2.height);
}

RI_INLINE BOOL RISizeIsEqualToSize2I(RISize2I s1, RISize2I s2) {
    return (s1.width  == s2.width && s1.height == s2.height);
}

RI_INLINE BOOL RISizeIsEqualToSize3F(RISize3F s1, RISize3F s2) {
    return (s1.width  == s2.width  &&
            s1.height == s2.height &&
            s1.depth  == s2.depth);
}

// Scale
RI_INLINE RISize2F RISizeScale2F(RISize2F p1, float s) {
    return RISizeMake2F(p1.width * s, p1.height * s);
}

RI_INLINE RISize3F RISizeScale3F(RISize3F p1, float s) {
    return RISizeMake3F(p1.width * s, p1.height * s, p1.depth * s);
}


//// Rects

// Make
RI_INLINE RIRect2F RIRectMake2F(RIPoint2F origin, RISize2F size) {
#ifdef __cplusplus
    RIRect2F rect = RIRect2F(origin, size);
#else
    RIRect2F rect = {.origin = origin, .size = size};
#endif
    return rect;
}

RI_INLINE RIRect2I RIRectMake2I(RIPoint2I origin, RISize2I size) {
#ifdef __cplusplus
    RIRect2I rect = RIRect2I(origin, size);
#else
    RIRect2I rect = {.origin = origin, .size = size};
#endif
    return rect;
}


//// Rays

// Make
RI_INLINE RIRay2F RIRayMake2F(RIPoint2F startPoint, RIPoint2F direction) {
#ifdef __cplusplus
    RIRay2F ray = RIRay2F(startPoint, direction);
#else
    RIRay2F ray = {.startPoint = startPoint, .direction = direction};
#endif
    return ray;
}

RI_INLINE RIRay3F RIRayMake3F(RIPoint3F startPoint, RIPoint3F direction) {
#ifdef __cplusplus
    RIRay3F ray = RIRay3F(startPoint, direction);
#else
    RIRay3F ray = {.startPoint = startPoint, .direction = direction};
#endif
    return ray;
}

// Plane Intersection
RIPoint3F RIRayPlaneIntersection3F(RIRay3F ray, RIPlane plane);


//// Planes

// Make
RI_INLINE RIPlane RIPlaneMake(RIPoint3F normal, float distance) {
#ifdef __cplusplus
    RIPlane plane = RIPlane(normal, distance);
#else
    RIPlane plane = {.normal = normal, .distance = distance};
#endif
    return plane;
}

// Compare
RI_INLINE BOOL RIPlaneIsEqualToPlane(RIPlane plane1, RIPlane plane2) {
    return RIPointIsEqualToPoint3F(plane1.normal, plane2.normal) && plane1.distance == plane2.distance;
}

// Transform
RIPlane RIPlaneApplyTransform(RIPlane plane, GLKMatrix4 matrix);


//// Matrices

// Matrix Math
GLKMatrix4 RIMatrix4Invert(GLKMatrix4 matrix, bool *isInvertible);

// Projection
GLKVector3 RIMathProject(GLKVector3 object, GLKMatrix4 model, GLKMatrix4 projection, int *viewport);
GLKVector3 RIMathUnproject(GLKVector3 window, GLKMatrix4 model, GLKMatrix4 projection, int *viewport, bool *success);


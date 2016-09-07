//
//  geometry.h
//  RelativeInterface
//
//  Created by Max Weisel on 8/10/15.
//  Copyright (c) 2015 Google, Inc. All rights reserved.
//

#ifndef RELATIVEINTERFACE_GEOMETRY_H_
#define RELATIVEINTERFACE_GEOMETRY_H_

#ifdef __cplusplus
#include <cmath>
#endif
#include <GLKit/GLKMathTypes.h>

#ifdef __cplusplus
namespace RelativeInterface {
#endif

//// Points
struct Point2 {
#ifdef __cplusplus
public:
    static const Point2 kZero;
    static const Point2 kNull;
    
    Point2() : x(0.0f), y(0.0f) {}
    Point2(float x, float y) : x(x), y(y) {}
    
    // Normalize
    Point2 Normalize() {
        float d = sqrtf(x*x + y*y);
        return Point2(x / d, y / d);
    }
    
    // Negate
    Point2 Negate() { return Point2(-x, -y); }
    
    // Operators
    Point2 operator +(const Point2 &p) { return Point2(x + p.x, y + p.y); }
    Point2 operator -(const Point2 &p) { return Point2(x - p.x, y - p.y); }
    Point2 operator *(float a)         { return Point2(x * a, y * a); }
    Point2 operator *(const Point2 &p) { return Point2(x * p.x, y * p.y); }
    Point2 operator /(float a)         { return Point2(x / a, y / a); }
    Point2 operator /(const Point2 &p) { return Point2(x / p.x, y / p.y); }
    bool   operator==(const Point2 &p) { return (x == p.x) && (y == p.y); }
#endif
    float x;
    float y;
};

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
typedef RelativeInterface::Point2 RIPoint2F;
#else
typedef struct Point2 Point2;
typedef struct Point2 RIPoint2F;
#endif

#ifdef __cplusplus
namespace RelativeInterface {
#endif

struct Point2I {
#ifdef __cplusplus
public:
    static const Point2I kZero;
    
    Point2I() : x(0), y(0) {}
    Point2I(int x, int y) : x(x), y(y) {}
    
    // Negate
    Point2I Negate() { return Point2I(-x, -y); }
    
    // Operators
    Point2I operator +(const Point2I &p) { return Point2I(x + p.x, y + p.y); }
    Point2I operator -(const Point2I &p) { return Point2I(x - p.x, y - p.y); }
    Point2I operator *(int a)            { return Point2I(x * a, y * a); }
    Point2I operator *(const Point2I &p) { return Point2I(x * p.x, y * p.y); }
    Point2I operator /(int a)            { return Point2I(x / a, y / a); }
    Point2I operator /(const Point2I &p) { return Point2I(x / p.x, y / p.y); }
    bool    operator==(const Point2I &p) { return (x == p.x) && (y == p.y); }
#endif
    int x;
    int y;
};

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
typedef RelativeInterface::Point2I RIPoint2I;
#else
typedef struct Point2I Point2I;
typedef struct Point2I RIPoint2I;
#endif

#ifdef __cplusplus
namespace RelativeInterface {
#endif

struct Point2D {
#ifdef __cplusplus
public:
    static const Point2D kZero;
    
    Point2D() : x(0.0), y(0.0) {}
    Point2D(double x, double y) : x(x), y(y) {}
    
    // Normalize
    Point2D Normalize() {
        double d = sqrtf(x*x + y*y);
        return Point2D(x / d, y / d);
    }
    
    // Negate
    Point2D Negate() { return Point2D(-x, -y); }
    
    // Operators
    Point2D operator +(const Point2D &p) { return Point2D(x + p.x, y + p.y); }
    Point2D operator -(const Point2D &p) { return Point2D(x - p.x, y - p.y); }
    Point2D operator *(double a)         { return Point2D(x * a, y * a); }
    Point2D operator *(const Point2D &p) { return Point2D(x * p.x, y * p.y); }
    Point2D operator /(double a)         { return Point2D(x / a, y / a); }
    Point2D operator /(const Point2D &p) { return Point2D(x / p.x, y / p.y); }
    bool    operator==(const Point2D &p) { return (x == p.x) && (y == p.y); }
#endif
    double x;
    double y;
};

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
typedef RelativeInterface::Point2D RIPoint2D;
#else
typedef struct Point2D Point2D;
typedef struct Point2D RIPoint2D;
#endif

#ifdef __cplusplus
namespace RelativeInterface {
#endif

struct Point3 {
#ifdef __cplusplus
public:
    static const Point3 kZero;
    static const Point3 kNull;
    
    Point3() : x(0.0f), y(0.0f), z(0.0f) {}
    Point3(float x, float y, float z) : x(x), y(y), z(z) {}
    
    // Normalize
    Point3 Normalize() {
        float d = sqrtf(x*x + y*y + z*z);
        return Point3(x / d, y / d, z / d);
    }
    
    // Negate
    Point3 Negate() { return Point3(-x, -y, -z); }
    
    // Cross Product
    Point3 Cross(const Point3 &p) {
        float x = (y * p.z) - (z * p.y);
        float y = (z * p.x) - (x * p.z);
        float z = (x * p.y) - (y * p.x);
        return Point3(x, y, z);
    }
    
    // Dot Product
    float Dot(const Point3 &p) { return (x*p.x + y*p.y + z*p.z); }
    
    // Operators
    Point3 operator +(const Point3 &p) { return Point3(x + p.x, y + p.y, z + p.z); }
    Point3 operator -(const Point3 &p) { return Point3(x - p.x, y - p.y, z - p.z); }
    Point3 operator *(float a)         { return Point3(x * a, y * a, z * a); }
    Point3 operator *(const Point3 &p) { return Point3(x * p.x, y * p.y, z * p.z); }
    Point3 operator /(float a)         { return Point3(x / a, y / a, z / a); }
    Point3 operator /(const Point3 &p) { return Point3(x / p.x, y / p.y, z / p.z); }
    bool   operator==(const Point3 &p) { return (x == p.x) && (y == p.y) && (z == p.z); }
#endif
    float x;
    float y;
    float z;
};

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
typedef RelativeInterface::Point3 RIPoint3F;
#else
typedef struct Point3 Point3;
typedef struct Point3 RIPoint3F;
#endif

#ifdef __cplusplus
namespace RelativeInterface {
#endif

//// Sizes
struct Size2 {
#ifdef __cplusplus
public:
    static const Size2 kZero;
    
    Size2() : width(0.0f), height(0.0f) {}
    Size2(float width, float height) : width(width), height(height) {}
    
    // Operators
    Size2 operator *(float a)        { return Size2(width * a, height * a); }
    bool  operator==(const Size2 &s) { return (width == s.width) && (height == s.height); }
#endif
    float width;
    float height;
};

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
typedef RelativeInterface::Size2 RISize2F;
#else
typedef struct Size2 Size2;
typedef struct Size2 RISize2F;
#endif

#ifdef __cplusplus
namespace RelativeInterface {
#endif

struct Size2I {
#ifdef __cplusplus
public:
    static const Size2I kZero;
    
    Size2I() : width(0), height(0) {}
    Size2I(float width, float height) : width(width), height(height) {}
    
    // Operators
    Size2I operator *(float a)         { return Size2I(width * a, height * a); }
    bool   operator==(const Size2I &s) { return (width == s.width) && (height == s.height); }
#endif
    int width;
    int height;
};

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
typedef RelativeInterface::Size2I RISize2I;
#else
typedef struct Size2I Size2I;
typedef struct Size2I RISize2I;
#endif

#ifdef __cplusplus
namespace RelativeInterface {
#endif

struct Size3 {
#ifdef __cplusplus
public:
    static const Size3 kZero;
    
    Size3() : width(0.0f), height(0.0f), depth(0.0f) {}
    Size3(float width, float height, float depth) : width(width), height(height), depth(depth) {}
    
    // Operators
    Size3 operator *(float a)        { return Size3(width * a, height * a, depth * a); }
    bool  operator==(const Size3 &s) { return (width == s.width) && (height == s.height) && (depth == s.depth); }
#endif
    float width;
    float height;
    float depth;
};

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
typedef RelativeInterface::Size3 RISize3F;
#else
typedef struct Size3 Size3;
typedef struct Size3 RISize3F;
#endif

#ifdef __cplusplus
namespace RelativeInterface {
#endif

//// Rects
struct Rect2 {
#ifdef __cplusplus
public:
    static const Rect2 kZero;
    
    Rect2() {}
    Rect2(Point2 origin, Size2 size) : origin(origin), size(size) {}
    Rect2(float x, float y, float width, float height) : origin(Point2(x, y)), size(Size2(width, height)) {}
    
    // Operators
    bool operator==(const Rect2 &r) { return (origin == r.origin) && (size == r.size); }
#endif
    Point2 origin;
    Size2 size;
};

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
typedef RelativeInterface::Rect2 RIRect2F;
#else
typedef struct Rect2 Rect2;
typedef struct Rect2 RIRect2F;
#endif

#ifdef __cplusplus
namespace RelativeInterface {
#endif

struct Rect2I {
#ifdef __cplusplus
public:
    static const Rect2I kZero;
    
    Rect2I() {}
    Rect2I(Point2I origin, Size2I size) : origin(origin), size(size) {}
    Rect2I(int x, int y, int width, int height) : origin(Point2I(x, y)), size(Size2I(width, height)) {}
    
    // Operators
    bool operator==(const Rect2I &r) { return (origin == r.origin) && (size == r.size); }
#endif
    Point2I origin;
    Size2I size;
};

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
typedef RelativeInterface::Rect2I RIRect2I;
#else
typedef struct Rect2I Rect2I;
typedef struct Rect2I RIRect2I;
#endif

#ifdef __cplusplus
namespace RelativeInterface {
#endif

//// Rays
struct Ray2 {
#ifdef __cplusplus
public:
    static const Ray2 kZero;
    static const Ray2 kNull;
    
    Ray2() {}
    Ray2(Point2 startPoint, Point2 direction) : startPoint(startPoint), direction(direction) {}
    
    // Operators
    bool operator==(const Ray2 &r) { return (startPoint == r.startPoint) && (direction == r.direction); }
#endif
    Point2 startPoint;
    Point2 direction;
};
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
typedef RelativeInterface::Ray2 RIRay2F;
#else
typedef struct Ray2 Ray2;
typedef struct Ray2 RIRay2F;
#endif

#ifdef __cplusplus
namespace RelativeInterface {
#endif

struct Ray3 {
#ifdef __cplusplus
public:
    static const Ray3 kZero;
    static const Ray3 kNull;
    
    Ray3() {}
    Ray3(Point3 startPoint, Point3 direction) : startPoint(startPoint), direction(direction) {}
    
    // Operators
    bool operator==(const Ray3 &r) { return (startPoint == r.startPoint) && (direction == r.direction); }
#endif
    Point3 startPoint;
    Point3 direction;
};

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
typedef RelativeInterface::Ray3 RIRay3F;
#else
typedef struct Ray3 Ray3;
typedef struct Ray3 RIRay3F;
#endif

#ifdef __cplusplus
namespace RelativeInterface {
#endif

//// Planes
struct Plane {
#ifdef __cplusplus
public:
    Plane() {}
    Plane(Point3 normal, float distance) : normal(normal), distance(distance) {}
    
    Point3 RayIntersection(Ray3 ray);
    Plane ApplyTransform(GLKMatrix4 matrix);
    
    // Operators
    bool operator==(const Plane &p) { return (normal == p.normal) && (distance == p.distance); }
#endif
    Point3 normal;
    float distance;
};

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
typedef RelativeInterface::Plane RIPlane;
#else
typedef struct Plane Plane;
typedef struct Plane RIPlane;
#endif

//// Coordinate System
// TODO: Do we want to rename these types or? How do we treat things that should stay structs? I'm afraid to remove the RI prefix.
typedef enum {
    RICoordinateSystemTopLeftOrigin = 0,
    RICoordinateSystemBottomLeftOrigin
} RICoordinateSystem;

typedef struct {
    RIPoint2F origin;
    RISize2F size;
} RICoordinateSpace;

//// Textured Quads
typedef struct {
    RIPoint2F position;
    RIPoint2F texCoord;
} RIVertexPositionTexCoord2F;

typedef struct {
    RIPoint3F position;
    RIPoint2F texCoord;
} RIVertexPositionTexCoord3F;

#endif // RELATIVEINTERFACE_GEOMETRY_H_

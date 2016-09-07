//
//  color.h
//  RelativeInterface
//
//  Created by Max Weisel on 8/11/15.
//  Copyright (c) 2015 Google, Inc. All rights reserved.
//

#ifndef RELATIVEINTERFACE_COLOR_H_
#define RELATIVEINTERFACE_COLOR_H_

#ifdef __cplusplus
namespace RelativeInterface {
#endif

struct ColorRGB;
struct ColorRGBA;
struct ColorHSB;
struct ColorHSBA;

struct ColorRGB {
#ifdef __cplusplus
public:
    static const ColorRGB kBlack;
    static const ColorRGB kDarkGray;
    static const ColorRGB kLightGray;
    static const ColorRGB kWhite;
    static const ColorRGB kGray;
    static const ColorRGB kRed;
    static const ColorRGB kGreen;
    static const ColorRGB kBlue;
    static const ColorRGB kCyan;
    static const ColorRGB kYellow;
    static const ColorRGB kMagenta;
    static const ColorRGB kOrange;
    static const ColorRGB kPurple;
    static const ColorRGB kBrown;
    static const ColorRGB kClear;
    
    ColorRGB() {}
    ColorRGB(float red, float green, float blue) : red(red), green(green), blue(blue) {}
    ColorRGB(int hexCode) : red(((hexCode >> 16) & 0xFF) / 255.0), green(((hexCode >> 8)  & 0xFF) / 255.0), blue((hexCode & 0xFF) / 255.0) {}
    
    ColorRGBA ToRGBA(float alpha);
    ColorHSB ToHSB();
    
    // Operators
    bool operator==(const ColorRGB &c) { return (red == c.red && green == c.green && blue == c.blue); }
#endif
    float red;
    float green;
    float blue;
};

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
typedef RelativeInterface::ColorRGB RIColorRGB;
#else
typedef struct ColorRGB ColorRGB;
typedef struct ColorRGB RIColorRGB;
#endif

#ifdef __cplusplus
namespace RelativeInterface {
#endif

struct ColorRGBA {
#ifdef __cplusplus
public:
    static const ColorRGBA kBlack;
    static const ColorRGBA kDarkGray;
    static const ColorRGBA kLightGray;
    static const ColorRGBA kWhite;
    static const ColorRGBA kGray;
    static const ColorRGBA kRed;
    static const ColorRGBA kGreen;
    static const ColorRGBA kBlue;
    static const ColorRGBA kCyan;
    static const ColorRGBA kYellow;
    static const ColorRGBA kMagenta;
    static const ColorRGBA kOrange;
    static const ColorRGBA kPurple;
    static const ColorRGBA kBrown;
    static const ColorRGBA kClear;
    
    ColorRGBA() {}
    ColorRGBA(float red, float green, float blue, float alpha) : red(red), green(green), blue(blue), alpha(alpha) {}
    ColorRGBA(int hexCode, float alpha) : red(((hexCode >> 16) & 0xFF) / 255.0), green(((hexCode >> 8)  & 0xFF) / 255.0), blue((hexCode & 0xFF) / 255.0), alpha(alpha) {}
    
    ColorRGB ToRGB() { return ColorRGB(red, green, blue); }
    ColorHSBA ToHSBA();
    
    // Operators
    bool operator==(const ColorRGBA &c) { return (red == c.red && green == c.green && blue == c.blue && alpha == c.alpha); }
#endif
    float red;
    float green;
    float blue;
    float alpha;
};

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
typedef RelativeInterface::ColorRGBA RIColorRGBA;
#else
typedef struct ColorRGBA ColorRGBA;
typedef struct ColorRGBA RIColorRGBA;
#endif

#ifdef __cplusplus
namespace RelativeInterface {
#endif

struct ColorHSB {
#ifdef __cplusplus
public:
    ColorHSB() {}
    ColorHSB(float hue, float saturation, float brightness) : hue(hue), saturation(saturation), brightness(brightness) {}
    
    ColorHSBA ToHSBA(float alpha);
    ColorRGB ToRGB();
    
    // Operators
    bool operator==(const ColorHSB &c) { return (hue == c.hue && saturation == c.saturation && brightness == c.brightness); }
#endif
    float hue;
    float saturation;
    float brightness;
};

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
typedef RelativeInterface::ColorHSB RIColorHSB;
#else
typedef struct ColorHSB ColorHSB;
typedef struct ColorHSB RIColorHSB;
#endif

#ifdef __cplusplus
namespace RelativeInterface {
#endif

struct ColorHSBA {
#ifdef __cplusplus
public:
    ColorHSBA() {}
    ColorHSBA(float hue, float saturation, float brightness, float alpha) : hue(hue), saturation(saturation), brightness(brightness), alpha(alpha) {}
    
    ColorHSB ToHSB() { return ColorHSB(hue, saturation, brightness); }
    ColorRGBA ToRGBA();
    
    // Operators
    bool operator==(const ColorHSBA &c) { return (hue == c.hue && saturation == c.saturation && brightness == c.brightness && alpha == c.alpha); }
#endif
    float hue;
    float saturation;
    float brightness;
    float alpha;
};

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
typedef RelativeInterface::ColorHSBA RIColorHSBA;
#else
typedef struct ColorHSBA ColorHSBA;
typedef struct ColorHSBA RIColorHSBA;
#endif

#ifdef __cplusplus
namespace RelativeInterface {
#endif

#ifdef __cplusplus
inline ColorRGBA ColorRGB::ToRGBA(float alpha) { return ColorRGBA(red, green, blue, alpha); }
inline ColorHSBA ColorHSB::ToHSBA(float alpha) { return ColorHSBA(hue, saturation, brightness, alpha); }
#endif

#ifdef __cplusplus
}
#endif

#endif // RELATIVEINTERFACE_COLOR_H_

// Generated by Apple Swift version 2.2 (swiftlang-703.0.18.8 clang-703.0.31)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
@import CocoaAsyncSocket;
@import Security;
@import CoreLocation;
@import Foundation;
@import Foundation.NSURLSession;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class CocoaMQTTWill;
@class CocoaMQTTMessage;
@class GCDAsyncSocket;
@class NSData;
@class NSError;


/// Main CocoaMQTT Class
///
/// Notice: GCDAsyncSocket need delegate to extend NSObject
SWIFT_CLASS("_TtC15LocationTracker9CocoaMQTT")
@interface CocoaMQTT : NSObject <GCDAsyncSocketDelegate>
@property (nonatomic, copy) NSString * _Nonnull host;
@property (nonatomic) uint16_t port;
@property (nonatomic, copy) NSString * _Nonnull clientId;
@property (nonatomic, copy) NSString * _Nullable username;
@property (nonatomic, copy) NSString * _Nullable password;
@property (nonatomic) BOOL secureMQTT;
@property (nonatomic) BOOL backgroundOnSocket;
@property (nonatomic) BOOL cleanSess;
@property (nonatomic) uint16_t keepAlive;
@property (nonatomic, strong) CocoaMQTTWill * _Nullable willMessage;
- (nonnull instancetype)initWithClientId:(NSString * _Nonnull)clientId host:(NSString * _Nonnull)host port:(uint16_t)port OBJC_DESIGNATED_INITIALIZER;
- (BOOL)connect;
- (uint16_t)publish:(CocoaMQTTMessage * _Nonnull)message;
- (uint16_t)unsubscribe:(NSString * _Nonnull)topic;
- (void)ping;
- (void)disconnect;
- (void)socket:(GCDAsyncSocket * _Null_unspecified)sock didConnectToHost:(NSString * _Null_unspecified)host port:(uint16_t)port;
- (void)socket:(GCDAsyncSocket * _Null_unspecified)sock didReceiveTrust:(SecTrustRef _Null_unspecified)trust completionHandler:(void (^ _Null_unspecified)(BOOL))completionHandler;
- (void)socketDidSecure:(GCDAsyncSocket * _Null_unspecified)sock;
- (void)socket:(GCDAsyncSocket * _Null_unspecified)sock didWriteDataWithTag:(NSInteger)tag;
- (void)socket:(GCDAsyncSocket * _Null_unspecified)sock didReadData:(NSData * _Null_unspecified)data withTag:(NSInteger)tag;
- (void)socketDidDisconnect:(GCDAsyncSocket * _Null_unspecified)sock withError:(NSError * _Null_unspecified)err;
@end



/// MQTT Message
SWIFT_CLASS("_TtC15LocationTracker16CocoaMQTTMessage")
@interface CocoaMQTTMessage : NSObject
@property (nonatomic, copy) NSString * _Nonnull topic;
@property (nonatomic, readonly, copy) NSString * _Nullable string;
@end



/// MQTT Will Message
SWIFT_CLASS("_TtC15LocationTracker13CocoaMQTTWill")
@interface CocoaMQTTWill : CocoaMQTTMessage
- (nonnull instancetype)initWithTopic:(NSString * _Nonnull)topic message:(NSString * _Nonnull)message OBJC_DESIGNATED_INITIALIZER;
@end

@class CLLocation;

SWIFT_PROTOCOL("_TtP15LocationTracker23LocationTrackerDelegate_")
@protocol LocationTrackerDelegate
@optional
- (void)currentLocation:(CLLocation * _Nonnull)location;
@end

@class CLLocationManager;

SWIFT_CLASS("_TtC15LocationTracker19LocationTrackerFile")
@interface LocationTrackerFile : NSObject <CLLocationManagerDelegate>
@property (nonatomic, strong) id <LocationTrackerDelegate> _Null_unspecified delegate;
@property (nonatomic, copy) NSString * _Nonnull host;
@property (nonatomic) uint16_t portNumber;
@property (nonatomic) double slotTime;
@property (nonatomic) float maxSpeed;
@property (nonatomic) double maxAccuracy;
@property (nonatomic) double maxDistance;
@property (nonatomic, copy) NSString * _Nonnull accessToken;
@property (nonatomic, copy) NSString * _Nonnull uniqueKey;
+ (LocationTrackerFile * _Nonnull)sharedInstance;
+ (CLLocationManager * _Nonnull)sharedLocationManager;
- (CLLocation * _Nonnull)getCurrentLocation;
- (void)startLocationTracking;
- (void)stopLocationTracking;
- (void)locationManager:(CLLocationManager * _Nonnull)manager didUpdateLocations:(NSArray<CLLocation *> * _Nonnull)locations;
@end


SWIFT_CLASS("_TtC15LocationTracker9MqttClass")
@interface MqttClass : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


@interface MqttClass (SWIFT_EXTENSION(LocationTracker))
- (void)mqtt:(CocoaMQTT * _Nonnull)mqtt didConnect:(NSString * _Nonnull)host port:(NSInteger)port;
- (void)mqtt:(CocoaMQTT * _Nonnull)mqtt didPublishMessage:(CocoaMQTTMessage * _Nonnull)message id:(uint16_t)id;
- (void)mqtt:(CocoaMQTT * _Nonnull)mqtt didPublishAck:(uint16_t)id;
- (void)mqtt:(CocoaMQTT * _Nonnull)mqtt didReceiveMessage:(CocoaMQTTMessage * _Nonnull)message id:(uint16_t)id;
- (void)mqtt:(CocoaMQTT * _Nonnull)mqtt didSubscribeTopic:(NSString * _Nonnull)topic;
- (void)mqtt:(CocoaMQTT * _Nonnull)mqtt didUnsubscribeTopic:(NSString * _Nonnull)topic;
- (void)mqttDidPing:(CocoaMQTT * _Nonnull)mqtt;
- (void)mqttDidReceivePong:(CocoaMQTT * _Nonnull)mqtt;
- (void)mqttDidDisconnect:(CocoaMQTT * _Nonnull)mqtt withError:(NSError * _Nullable)err;
@end


@interface NSMutableArray (SWIFT_EXTENSION(LocationTracker))
@end

@class NSURLRequest;

@interface NSURLSession (SWIFT_EXTENSION(LocationTracker))

/// Return data from synchronous URL request
+ (NSData * _Nullable)requestSynchronousData:(NSURLRequest * _Nonnull)request;

/// Return data synchronous from specified endpoint
+ (NSData * _Nullable)requestSynchronousDataWithURLString:(NSString * _Nonnull)requestString;

/// Return JSON synchronous from URL request
+ (id _Nullable)requestSynchronousJSON:(NSURLRequest * _Nonnull)request;

/// Return JSON synchronous from specified endpoint
+ (id _Nullable)requestSynchronousJSONWithURLString:(NSString * _Nonnull)requestString;
@end

#pragma clang diagnostic pop